#pragma once
#include<iostream>
#include<fstream>
#include"clsDate.h"
#include"Global.h"
#include"clsString.h"
#include"clsutility.h"
#include<vector>
using namespace std;
class clsLoginFile :protected clsScreen
{
	static string _PrepareLoginRecord(string seprator="#//#") {
		
		string line = "";
		line += clsDate::GetSystemDateTimeString()+seprator;
		line += CurrentUser.UserName+seprator;
		line += clsutility::EncryptionText( CurrentUser.Password,2)+seprator;
		line += to_string( CurrentUser.Permissions);
		return line;
	}

	static vector<string> _loadLoginRegisterFromFile() {
		fstream myFile;
		myFile.open("LoginRegister.txt", ios::in);
		string line = "";
		vector<string>vloginRegistr;
		if (myFile.is_open()) {

			while (getline(myFile, line)) {
				vloginRegistr.push_back(line);
			}
			myFile.close();
		}
		return vloginRegistr;
	}
	static void _PrintUserLoginRegister(string line,string sepretor="#//#") {
		vector<string>vlogin = clsString::split(line,sepretor);
		cout << setw(25) << left << "" << "| " << left << setw(25) << vlogin[0];
		cout << "| " << left << setw(15) << vlogin[1];
		cout << "| " << left << setw(15) <<clsutility::DecryptoinText( vlogin[2],2);
		cout << "| " << left << setw(15) << vlogin[3]<<endl;

	}
public:
	static void _SaveRegisterLogin() {
		fstream myFile;
		string line =_PrepareLoginRecord();
		myFile.open("LoginRegister.txt", ios::out | ios::app);
		if (myFile.is_open()) {

			myFile << line << endl;
		}
		myFile.close();

	}
	static void _ShowLoginRegisterScreen() {
		vector<string>VloginRegister = _loadLoginRegisterFromFile();
		if (!CheckAccessRights(clsUser::enPermissions::pLoginRejister)) {
			return;
		}
		string sebtitle = "("+to_string(VloginRegister.size())+") Record(s)";
		_DrawScreenHeader("Login Register List Screen",sebtitle);

		cout << setw(25) << left << "" << "\n\t\t___________________________________________________________________________________\n";
		cout << setw(25) << left << "" << "| " << left << setw(25) << "Date/Time";
		cout << "| " << left << setw(15) << "UserName";
		cout << "| " << left << setw(15) << "Permissions";
		cout << "| " << left << setw(15) << "Password\n";
		cout << setw(25) << left << "" << "\n\t\t___________________________________________________________________________________\n";
		if (VloginRegister.size() == 0) {
			cout << "No Login Register Available \n";
		}
		else
		{
			for (string& line : VloginRegister) {
				_PrintUserLoginRegister(line);
			}
		}
	
		cout << setw(25) << left << "" << "\n\t\t___________________________________________________________________________________\n";

	}

};

