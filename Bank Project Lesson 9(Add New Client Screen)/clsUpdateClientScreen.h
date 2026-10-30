#pragma once
#include<iostream>
#include"clsMainScreen.h"
using namespace std;
class clsUpdateClientScreen :protected clsScreen
{
	static void _ReadClientInfo(clsBankClient& client) {
		client.FirstName = clsInputValidate::ReadString("\nplease enter First Name?");
		client.LastName = clsInputValidate::ReadString("please enter Last Name?");
		client.Email = clsInputValidate::ReadString("please enter Email?");
		client.Phone = clsInputValidate::ReadString("please enter Phone?");
		client.PinCode = clsInputValidate::ReadString("please enter Pincode?");
		client.AccountBalance = clsInputValidate::ReadDblNumber("\nplease enter Account Balance?");
	}
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
	static void ShowUpdateClientScreen() {
		if (!CheckAccessRights(clsUser::enPermissions::pUpdateClient)) {
			return;
		}
		clsScreen::_DrawScreenHeader("Update Client Screen");
		string AccountNumber = "";
		AccountNumber = clsInputValidate::ReadString("\nplease enter Account Number?");
		
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			AccountNumber = clsInputValidate::ReadString("\nAccount Number is not Exist,please enter new Account Number?");
		}
		clsBankClient client = clsBankClient::Find(AccountNumber);
		_PrintClient(client);

		char c='n';
		cout << "are you sure you want to Update that Client?(y,n)";
		cin >> c;
		
		if (tolower(c) == 'y') {
			cout << "\n\nUpdate Client Info\n";
			cout << "_________________________________";
			_ReadClientInfo(client);
			clsBankClient::enSaveResults SaveResult;
			SaveResult = client.Save();
			switch (SaveResult) {
			case clsBankClient::enSaveResults::enSucceeded: {
				cout << "\nclient added successfully\n";
				_PrintClient(client);
				break;
			}
			case clsBankClient::enSaveResults::svFaildEmptyObject: {
				cout << "\nError account was not saved because it's Empty\n";
				break;
			}
			case clsBankClient::enSaveResults::enFaildAccountNumberExists: {
				cout << "\nError account was not saved because Account Number Exists\n";
				break;
			}
			}

		}

	}
};

