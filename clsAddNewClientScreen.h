#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
using namespace std;
class clsAddNewClientScreen:protected clsScreen 
{
	static void _ReadClientInfo(clsBankClient& client) {
	client.FirstName=	clsInputValidate::ReadString("please enter First Name?");
	client.LastName =	clsInputValidate::ReadString("please enter Last Name?");
	client.Email=	clsInputValidate::ReadString("please enter Email?");
	client.Phone= clsInputValidate::ReadString("please enter Phone?");
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
	static void ShowAddNewClientScreen() {
		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient)) {
			return;
		}
		_DrawScreenHeader("Add New Client Screen");
		string AccountNumber = "";
		AccountNumber = clsInputValidate::ReadString("\nplease enter Account Number?");
		while (clsBankClient::IsClientExist(AccountNumber)) {
			AccountNumber = clsInputValidate::ReadString("Account Number is already used,Choose enother Account Number?");
		}
		clsBankClient newClient = clsBankClient::GetAddNewObject(AccountNumber);
		_ReadClientInfo(newClient);
		clsBankClient::enSaveResults SaveResult;
		SaveResult = newClient.Save();
		switch (SaveResult) {
		case clsBankClient::enSaveResults::enSucceeded: {
			cout << "\nclient added successfully\n";
			_PrintClient(newClient);
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
};

