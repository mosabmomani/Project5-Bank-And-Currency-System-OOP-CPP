#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
using namespace std;
class clsTransferScreen :clsScreen
{
	static void _PrintClientCard(clsBankClient client) {
		cout << "Client Card:\n";
		cout << "________________________\n";
		cout << "Full Name     : " << client.FullName()<<endl;
		cout << "Account Number: " << client.getAccountNumber()<<endl;
		cout << "Balance       : " << client.AccountBalance << endl;
		cout << "________________________\n";
	}
	static string _ReadAccountNumber(string massage="from?") {
		string AccountNumber = "";
		AccountNumber = clsInputValidate::ReadString("please enter Account Number to Transfer "+massage);
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			AccountNumber = clsInputValidate::ReadString("\nAccount number in not found,please enter another Account Number?");
		}
		return AccountNumber;

	}

public:
	static void TransferScreen() {
		_DrawScreenHeader("Transfer Screen");
		string AccountNumber = "";
		double Amount ;
		AccountNumber = _ReadAccountNumber();
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClientCard(Client1);

		AccountNumber = _ReadAccountNumber("to?");
		clsBankClient Client2 = clsBankClient::Find(AccountNumber);
		while (Client1.getAccountNumber() == Client2.getAccountNumber()) {
			cout << "you con,t transfer to the same Account";
			Client2 = clsBankClient::Find(_ReadAccountNumber("to?"));
		}
		_PrintClientCard(Client2);

		Amount = clsInputValidate::ReadDblNumber("please enter Transfer Amount ?");
		while (Amount > Client1.AccountBalance) {
		Amount = clsInputValidate::ReadDblNumber("The amount exceeds your balance. Please enter another choice? ?");
		}
		

		cout << "are you sure you want to preform this transaction?";
		char Answer = 'n';
		cin >> Answer;

		if (tolower(Answer) == 'y') {
			Client1.Withdraw(Amount);
			Client2.Deposit(Amount);
			cout << "Transfer done successfully \n";
			clsBankClient::SaveTransferRegister(Client1, Client2, Amount);
			_PrintClientCard(Client1);
			_PrintClientCard(Client2);
		}
		else {
			cout << "\t Operation was cancelled\n";
		}

	}
};

