#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"Global.h"
#include"clsInputValidate.h"
#include"clsMainScreen.h"
#include"clsLoginFile.h"
using namespace std;
class clsLoginScreen :protected clsScreen
{
private:
	static bool _Login() {
		
		bool LoginFaild = false;
		string UserName, Password;
		short Trials = 3;
		do {
			if (LoginFaild) {
				cout << "\n Invlaid Username/password!\n";
				Trials--;
				cout << "\nyou have " << Trials << " Trial(s) to login.\n";
			}
			if (Trials == 0) {
				cout << "\n\nyou are locked after 3 fouled trials\n";
				return false;
			}
			UserName = clsInputValidate::ReadString("please enter username?");
			Password = clsInputValidate::ReadString("please enter password?");
			CurrentUser = clsUser::Find(UserName, Password);
			LoginFaild = CurrentUser.IsEmpty();
		} while (LoginFaild);
		clsLoginFile::_SaveRegisterLogin();
			clsMainScreen::ShowMainMenu();
			return true;
		
	}
public:
	static bool _ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("Login Screen");
		return _Login();
	}
};

