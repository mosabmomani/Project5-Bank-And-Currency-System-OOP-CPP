#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUser.h"
using namespace std;
class clsDeleteUserScreen :protected clsScreen
{
	static void _PrintUser(clsUser User) {
		cout << "\nClient Card:\n";
		cout << "--------------------------------------\n";
		cout << "\nFirst Name     : " << User.FirstName;
		cout << "\nLast Name      : " << User.LastName;
		cout << "\nFull Name      : " << User.FullName();
		cout << "\nEmail          : " << User.Email;
		cout << "\nPhone          : " << User.Phone;
		cout << "\nAccount Number : " << User.UserName;
		cout << "\nPinCode        : " << User.Password;
		cout << "\nAccount Balance: " << User.Permissions << endl;
		cout << "--------------------------------------\n";
	}
public:
	static void ShowDeleteUserScreen() {
		_DrawScreenHeader("Delete User Screen");
		string UserName = "";
		UserName = clsInputValidate::ReadString("\nplease enter UserName?");
		while (!clsUser::IsUserExist(UserName)) {
			UserName = clsInputValidate::ReadString("UserName is't not found,please enter UserName?");
		}
		clsUser Client = clsUser::Find(UserName);
		_PrintUser(Client);
		char y;
		cout << "are you sure you want to Delete this User(Y,N)?\n";
		cin >> y;
		if (tolower(y) == 'y') {
			if (Client.Delete()) {
				cout << "User Deleted Successfully\n";
				_PrintUser(Client);
			}
			else {
				cout << "Erorr User was not Deleted\n";
			}
		}
	}
};

