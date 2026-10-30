#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsUser.h"
class clsListUserScreen:protected clsScreen
{
	static void _PrintUserRecordLine(clsUser User) {

		cout << setw(8) << left << "" << "|" << setw(15) << left << User.UserName;
		cout << "|" << setw(20) << left << User.FullName();
		cout << "|" << setw(12) << left << User.Phone;
		cout << "|" << setw(25) << left << User.Email;
		cout << "|" << setw(12) << left << User.Password;
		cout << "|" << setw(15) << left << User.Permissions<< endl;
	}
public:
	static void _ShowUsersScreen() {
		vector<clsUser>clients = clsUser::GetUserList();
		string Title = "\n\t\t\t\t\t       User List Screen";
		string subTitle = "(" + to_string(clients.size()) + ") User(s)";
		clsScreen::_DrawScreenHeader(Title, subTitle);
		cout << setw(8) << left << "" << "\n\t__________________________________________________________________________________________________\n";
		cout << setw(8) << left << "" << "|" << setw(15) << left << "UserName";
		cout << "|" << setw(20) << left << "FullName()";
		cout << "|" << setw(12) << left << "Phone";
		cout << "|" << setw(25) << left << "Email";
		cout << "|" << setw(12) << left << "Password";
		cout << "|" << setw(15) << left << "Permissions" << endl;
		cout << setw(8) << left << "" << "\n\t__________________________________________________________________________________________________\n";
		if (clients.size() == 0) {
			cout << "\n\t\t\t\t\t\tNo Users In System yet" << endl;
		}
		else {
			for (clsUser& c : clients) {
				_PrintUserRecordLine(c);
			}

		}
		cout << setw(8) << left << "" << "\n\t__________________________________________________________________________________________________\n";
	}
};

