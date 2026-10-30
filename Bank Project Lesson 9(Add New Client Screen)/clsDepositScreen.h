#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
using namespace std;
class clsDepositScreen:protected clsScreen 
{
private:
	static void _PrintClient(clsBankClient client) {
		cout << "\nClient Card:\n";
		cout << "--------------------------------------\n";
		cout << "\nFirst Name     : " << client.FirstName;
		cout << "\nLast Name      : " << client.LastName;
		cout << "\nFull Name      : " << client.FullName();
		cout << "\nEmail          : " << client.Email;
		cout << "\nPhone          : " << client.Phone;
		cout << "\nAccount Number : " << client.getAccountNumber();
		cout << "\nPinCode        : " << client.PinCode;
		cout << "\nAccount Balance: " << client.AccountBalance << endl;
		cout << "--------------------------------------\n";
	}
public:
	static void ShowDepositScreen() {
		_DrawScreenHeader("Deposit Screen");
		string AccountNumber = "";
		AccountNumber = clsInputValidate::ReadString("please enter Account Number?");
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			AccountNumber = clsInputValidate::ReadString("the account number is not exist,please enter Account Number?");
		}
		clsBankClient client = clsBankClient::Find(AccountNumber);
		_PrintClient(client);
		double Amount;
		Amount = clsInputValidate::ReadDblNumber("please enter Deposit Amount ");
		 
		cout << "are you sure you want to preform this transition?";
		char Answer='n';
		cin >> Answer;

		if (tolower(Answer) == 'y') {
			client.Deposit(Amount);
			cout << "Amount Deposited successfully \n";
			cout << "new balance is " << client.AccountBalance << endl;
		}
		else {
			cout << "\t Operation was cancelled\n";
		}

	}
};

