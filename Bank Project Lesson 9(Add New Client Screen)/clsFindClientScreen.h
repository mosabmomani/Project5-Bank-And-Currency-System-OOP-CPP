#pragma once
#include<iostream>
#include "clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
class clsFindClientScreen:protected clsScreen
{
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
	static void ShowFindClientScreen() {
		if (!CheckAccessRights(clsUser::enPermissions::pFindClient)) {
			return;
		}
		clsScreen::_DrawScreenHeader("\tFind Client Screen");
		string AccountNumber = "";
		AccountNumber = clsInputValidate::ReadString("\please enter Account Number? ");
		
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			AccountNumber = clsInputValidate::ReadString("\nAccount Number is not Exist,please enter new Account Number?");
		}
		clsBankClient client = clsBankClient::Find(AccountNumber);
		
		if (client.IsEmpty()) {
			cout << "\nClient wase not found\n";
		}
		else {
			cout << "\nClient wase founded\n";
		}
		_PrintClient(client);

	}
	
};

