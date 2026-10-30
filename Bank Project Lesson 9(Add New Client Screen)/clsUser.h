#pragma once
#pragma once
#include<iostream>
#include <string>
#include<vector>
#include<fstream>
#include"clsPerson.h"
#include"clsString.h"
#include"clsutility.h"
class clsUser:public clsPerson
{
private:
	
	enum enMode{EmptyMode=0,UpdateMode=1,AddNewMode=2};
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;
	bool _MarkForDelete = false;
	static clsUser _ConvertLineToUserObject(string line, string seperater = "#//#") {
		vector<string>vClientData;
		vClientData = clsString::split(line, seperater);
		return clsUser(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2]
			, vClientData[3], vClientData[4], clsutility::DecryptoinText(vClientData[5],2), stoi(vClientData[6]));
	}
	static string _ConvertLineToUserObject(clsUser user, string seperator = "#//#") {
		string line = "";
		line += user.FirstName + seperator;
		line += user.LastName + seperator;
		line += user.Email + seperator;
		line += user.Phone + seperator;
		line += user.UserName + seperator;
		line += clsutility::EncryptionText(user.Password,2) + seperator;
		line += to_string(user.Permissions);
		return line;
	}
	static vector<clsUser>_LoadUserDataFromFile() {
		vector<clsUser>vUsers;
		fstream myFile;

		myFile.open("Users.txt", ios::in);
		if (myFile.is_open()) {
			string line;
			while (getline(myFile, line)) {

				clsUser User = _ConvertLineToUserObject(line);
				vUsers.push_back(User);

			}
			myFile.close();
		}
		return vUsers;

	}
	static void _SaveUserDataToFile(vector<clsUser>Usersdata) {
		fstream myFile;

		myFile.open("Users.txt", ios::out);
		if (myFile.is_open()) {
			string line;
			for (clsUser& c : Usersdata) {
				if (c._MarkForDelete == false) {
					
					line = _ConvertLineToUserObject(c);
					myFile << line << endl;
				}
			}
			myFile.close();
		}
	}
	void _Update() {
		vector<clsUser>_vUsers = _LoadUserDataFromFile();
		for (clsUser & c : _vUsers) {
			if (c.UserName == UserName) {
				c = *this;
				break;
			}
		}
		_SaveUserDataToFile(_vUsers);

	}
	void _AddDataLineToFile(string line) {
		fstream myFile;
		myFile.open("Users.txt", ios::out | ios::app);
		if (myFile.is_open()) {
			myFile << line << endl;
		}
		myFile.close();
	}
	void _AddNew() {
		_AddDataLineToFile(_ConvertLineToUserObject(*this));
	}
	static clsUser _GetEmptyUserObject() {
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
public:
	enum enPermissions {
		pAll = -1, pListClient = 1, pAddNewClient = 2, pDeleteClient = 4, pUpdateClient = 8
		, pFindClient = 16, pTranactions = 32, pManageUser = 64,pLoginRejister=128
	};
	clsUser(enMode Mode, string FirstNmae, string LastName, string Email, string Phone
		, string UserName, string Password, int permissions) :
		clsPerson(FirstNmae, LastName, Email, Phone) {
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = permissions;
	}
	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	void setUserName(string UserName) {
		_UserName = UserName;
	}
	string getUserName() {
		return _UserName;
	}
	__declspec(property(get = getUserName, put = setUserName))string UserName;
	
	void setPassword(string Password) {
		_Password = Password;
	}
	string getPassword() {
		return _Password;
	}
	__declspec(property(get = getPassword, put = setPassword))string Password;

	void setPermissions(int Permissions) {
		_Permissions = Permissions;
	}
	int getPermissions() {
		return _Permissions;
	}
	__declspec(property(get = getPermissions, put = setPermissions))int Permissions;

	static clsUser Find(string UserName) {
		fstream myFile;
		myFile.open("Users.txt", ios::in);
		if (myFile.is_open()) {
			string line;
			while (getline(myFile, line)) {
				clsUser user = _ConvertLineToUserObject(line);
				if (user.UserName == UserName) {
					myFile.close();
					return user;
				}
			}
			myFile.close();
		}
		return _GetEmptyUserObject();
	}
	static clsUser Find(string UserName,string Password) {
		fstream myFile;
		myFile.open("Users.txt", ios::in);
		if (myFile.is_open()) {
			string line;
			while (getline(myFile, line)) {
				clsUser user = _ConvertLineToUserObject(line);
				if (user.UserName == UserName && user.Password==Password) {
					myFile.close();
					return user;
				}
			}
			myFile.close();
		}
		return _GetEmptyUserObject();
	}
	static bool IsUserExist(string UserName) {
		clsUser user1 = Find(UserName);
		return (!user1.IsEmpty());
	}
	enum enSaveResults { svFaildEmptyObject = 0, enSucceeded = 1, enFaildAccountNumberExists = 2 };

	enSaveResults Save() {
		switch (_Mode) {
		case enMode::EmptyMode: {
			return enSaveResults::svFaildEmptyObject;
		}
		case enMode::UpdateMode: {
			_Update();
			return enSaveResults::enSucceeded;
		}
		case enMode::AddNewMode: {
			if (clsUser::IsUserExist(_UserName)) {
				return enSaveResults::enFaildAccountNumberExists;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::enSucceeded;

			}
		}
		}
	}

	static clsUser GetAddNewObject(string UserName) {
			return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
		}
	static vector<clsUser>GetUserList() {
			return _LoadUserDataFromFile();
		}
	bool Delete() {
		vector<clsUser>vUsers = _LoadUserDataFromFile();
		for (clsUser & c : vUsers) {
			if (c.UserName == _UserName) {
				c._MarkForDelete = true;
				break;
			}
		}
		_SaveUserDataToFile(vUsers);
		*this = _GetEmptyUserObject();
		return true;
	}
	bool CheckAccessPermission(enPermissions permission) {
		if (this->Permissions == enPermissions::pAll) {
			return true;
		}
		if ((this->Permissions & permission) == permission)
			return true;
		else
			return false;
	}

};

