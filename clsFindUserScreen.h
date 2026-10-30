#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUser.h"
using namespace std;
class clsFindUserScreen:protected clsScreen
{
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

public:
	static void ShowFindUserScreen() {
		clsScreen::_DrawScreenHeader("\tFind User Screen");
		string UserName = "";
		UserName = clsInputValidate::ReadString("\nplease enter UserName? ");

		while (!clsUser::IsUserExist(UserName)) {
			UserName = clsInputValidate::ReadString("\nUserName is not Exist,please enter new UserName?");
		}
		clsUser User = clsUser::Find(UserName);

		if (User.IsEmpty()) {
			cout << "\nUser wase not found\n";
		}
		else {
			cout << "\nUser wase founded\n";
		}
		_PrintUser(User);

	}
};

