#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsDate.h"
#include"Global.h"
using namespace std;
class clsScreen
{
protected:
	static void _DrawScreenHeader(string Title, string SubTitle = "") {
		
		cout << "\t\t\t\t-----------------------------------------------------";
		cout << "\n\t\t\t\t\t\t" << Title<<endl;
		if (SubTitle != "")
			cout << "\n\t\t\t\t\t\t " << SubTitle<<endl;
		cout << "\n\t\t\t\t---------------------------------------------------";
		cout << "\n\n\t\t\t\t\t\tUser: "<<CurrentUser.UserName;
		cout << "\n\n\t\t\t\t\t\tDate: " << clsDate::DateToString(clsDate())<<endl;
	}
	static bool CheckAccessRights(clsUser::enPermissions permissoon) {
		if (!CurrentUser.CheckAccessPermission(permissoon)) {
			cout << "\t\t\t\t\t_________________________________________________";
			cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin\n";
			cout << "\t\t\t\t\t_________________________________________________\n";
			return false;
		}
		else {
			return true;
		}
	}
};


