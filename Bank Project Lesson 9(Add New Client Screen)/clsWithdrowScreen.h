#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
class clsWithdrowScreen:protected clsScreen
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
	static void ShowWithdrawScreen() {
		_DrawScreenHeader("Withdraw Screen");
		string AccountNumber = "";
		AccountNumber = clsInputValidate::ReadString("\nplease enter Account Number?");
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			AccountNumber = clsInputValidate::ReadString("\nAccount Number is not Exist,please enter Account Number?");
		}
		clsBankClient client = clsBankClient::Find(AccountNumber);
		_PrintClient(client);
		double Amount=0 ;
		Amount = clsInputValidate::ReadDblNumber("please enter withdraw Amount?");
		cout << "\nare you sure you want to perform this transaction?(y,n)";
		char Answer = 'n';
		cin >> Answer;
		if (tolower(Answer) == 'y') {
			if (client.Withdraw(Amount)) {
				cout << "\nAmount Withdraw Successfully\n";
				cout << "New Balance Is : " << client.AccountBalance;
			}
			else
			{
				cout << "cannot withdraw ,insuffecient balance\n";
				cout << "\nAmount to Withdraw is " << Amount;
				cout << "\nyour Balance is " << client.AccountBalance;
			}

		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}
		
	}
};

