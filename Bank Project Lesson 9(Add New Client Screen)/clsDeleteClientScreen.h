#pragma once
#include<iostream>
#include"clsScreen.h"
#include "clsBankClient.h"
#include"clsInputValidate.h"
using namespace std;
class clsDeleteClientScreen:protected clsScreen
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
	static void ShowDeleteClientScreen() {
		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient)) {
			return;
		}
		_DrawScreenHeader("Delete Client Screen");
		string AccountNumber = "";
		AccountNumber = clsInputValidate::ReadString("\nplease enter Account Number?");
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			AccountNumber = clsInputValidate::ReadString("Account Number is't not found,please enter Account Number?");
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);
		char y;
		cout << "are you sure you want to Delete this Client(Y,N)\n";
		cin >> y;
		if (tolower(y) == 'y') {
			if (Client.Delete()) {
				cout << "Client Deleted Successfully\n";
				_PrintClient(Client);
			}
			else {
				cout << "Erorr Client was not Deleted\n";
			}
		}
	}
};

