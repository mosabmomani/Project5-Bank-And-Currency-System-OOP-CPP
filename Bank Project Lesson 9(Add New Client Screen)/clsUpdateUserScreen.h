#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUser.h"
using namespace std;
class clsUpdateUserScreen:protected clsScreen
{
	static void _ReadUserInfo(clsUser& User) {
		User.FirstName = clsInputValidate::ReadString("please enter First Name?");
		User.LastName = clsInputValidate::ReadString("please enter Last Name?");
		User.Email = clsInputValidate::ReadString("please enter Email?");
		User.Phone = clsInputValidate::ReadString("please enter Phone?");
		User.Password = clsInputValidate::ReadString("please enter Password?");
		User.Permissions = _ReadPermissionsToSet();
	}
	static void _PrintUser(clsUser User) {
		cout << "\nUser Card:\n";
		cout << "--------------------------------------\n";
		cout << "\nFirst Name     : " << User.FirstName;
		cout << "\nLast Name      : " << User.LastName;
		cout << "\nFull Name      : " << User.FullName();
		cout << "\nEmail          : " << User.Email;
		cout << "\nPhone          : " << User.Phone;
		cout << "\nUserName       : " << User.UserName;
		cout << "\nPassword       : " << User.Password;
		cout << "\nPermissions    : " << User.Permissions << endl;
		cout << "--------------------------------------\n";
	}
	static int _ReadPermissionsToSet() {
		int Permissions = 0;
		char answer = 'n';
		cout << "\ndo you want to give full access?(y,n)";
		cin >> answer;
		if (tolower(answer) == 'y') {
			return clsUser::enPermissions::pAll;
		}
		cout << "\ndo you want to give access to:\n";
		cout << "\nShow Client List?y/n? ";
		cin >> answer;
		if (tolower(answer) == 'y') {
			Permissions += clsUser::enPermissions::pListClient;
		}
		cout << "\nAdd New Client ?y/n? ";
		cin >> answer;
		if (tolower(answer) == 'y') {
			Permissions += clsUser::enPermissions::pAddNewClient;
		}
		cout << "\nDelete Client ?y/n? ";
		cin >> answer;
		if (tolower(answer) == 'y') {
			Permissions += clsUser::enPermissions::pDeleteClient;
		}
		cout << "\nUpdate Client ?y/n? ";
		cin >> answer;
		if (tolower(answer) == 'y') {
			Permissions += clsUser::enPermissions::pUpdateClient;
		}
		cout << "\nFind Client ?y/n? ";
		cin >> answer;
		if (tolower(answer) == 'y') {
			Permissions += clsUser::enPermissions::pFindClient;
		}
		cout << "\nTransaction ?y/n? ";
		cin >> answer;
		if (tolower(answer) == 'y') {
			Permissions += clsUser::enPermissions::pTranactions;
		}
		cout << "\nManage Users ?y/n? ";
		cin >> answer;
		if (tolower(answer) == 'y') {
			Permissions += clsUser::enPermissions::pManageUser;
		}
		cout << "\nLogin Register ?y/n? ";
		cin >> answer;
		if (tolower(answer) == 'y') {
			Permissions += clsUser::enPermissions::pLoginRejister;
		}
		return Permissions;
	}
public:

	static void ShowUpdateUserScreen() {
		clsScreen::_DrawScreenHeader("Update User Screen");
		string UserName = "";
		UserName = clsInputValidate::ReadString("\please enter UserName?");

		while (!clsUser::IsUserExist(UserName)) {
			UserName = clsInputValidate::ReadString("\nUserName is not Exist,please enter new UserName?");
		}
		clsUser User = clsUser::Find(UserName);
		_PrintUser(User);

		char c = 'n';
		cout << "are you sure you want to Update that User?(y,n)";
		cin >> c;

		if (tolower(c) == 'y') {
			cout << "\n\nUpdate User Info\n";
			cout << "_________________________________";
			_ReadUserInfo(User);
			clsUser::enSaveResults SaveResult;
			SaveResult = User.Save();
			switch (SaveResult) {
			case clsUser::enSaveResults::enSucceeded: {
				cout << "\nUser added successfully\n";
				_PrintUser(User);
				break;
			}
			case clsUser::enSaveResults::svFaildEmptyObject: {
				cout << "\nError account was not saved because it's Empty\n";
				break;
			}
			case clsUser::enSaveResults::enFaildAccountNumberExists: {
				cout << "\nError account was not saved because UserName Exists\n";
				break;
			}
			}

		}

	}
};

