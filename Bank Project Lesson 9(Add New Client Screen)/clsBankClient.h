#pragma once
#include<iostream>
#include <string>
#include<vector>
#include<fstream>
#include"clsPerson.h"
#include"clsString.h"

class clsBankClient :public clsPerson
{
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkForDelete = false;
	static clsBankClient _ConvertLineToClientObject(string line, string seperater = "#//#") {
		vector<string>vClientData; 
		vClientData = clsString::split(line, seperater);
		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2]
			, vClientData[3], vClientData[4], vClientData[5], stof(vClientData[6]));

	}
	static string _ConvertClientObjectToLine(clsBankClient client, string seperator = "#//#") {
		string line = "";
		line += client.FirstName + seperator;
		line += client.LastName + seperator;
		line += client.Email + seperator;
		line += client.Phone + seperator;
		line += client.getAccountNumber() + seperator;
		line += client.PinCode + seperator;
		line += to_string(client.AccountBalance);
		return line;
	}
	static vector<clsBankClient>_LoadClientDataFromFile() {
		vector<clsBankClient>vClientsData;
		fstream myFile;

		myFile.open("ClientData.txt", ios::in);
		if (myFile.is_open()) {
			string line;
			while (getline(myFile, line)) {
				clsBankClient client = _ConvertLineToClientObject(line);
				vClientsData.push_back(client);

			}
			myFile.close();
		}
		return vClientsData;

	}
	static void _SaveClientDataToFile(vector<clsBankClient>clientsdata) {
		fstream myFile;

		myFile.open("ClientData.txt", ios::out);
		if (myFile.is_open()) {
			string line;
			for (clsBankClient& c : clientsdata) {
				if (c._MarkForDelete == false) {
					line = _ConvertClientObjectToLine(c);
					myFile << line << endl;
				}
			}
			myFile.close();
		}
	}
	 void _Update() {
		vector<clsBankClient>_vClients = _LoadClientDataFromFile();
		for (clsBankClient& c : _vClients) {
			if (c.getAccountNumber() == getAccountNumber()) {
				c = *this;
				break;
			}
		}
		_SaveClientDataToFile(_vClients);

	}
	void _AddDataLineToFile(string line) {
		fstream myFile;
		myFile.open("ClientData.txt", ios::out | ios::app);
		if (myFile.is_open()) {
			myFile << line << endl;
		}
		myFile.close();
	}
	void _AddNew() {
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	static clsBankClient _GetEmptyClientObject() {
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	static string _PrepareTransferLogDataLine(clsBankClient clientfrom, clsBankClient clientto, double Amount,string spreter="#//#") {
		string linedata = "";
		linedata += clsDate::GetSystemDateTimeString()+spreter;
		linedata += clientfrom.getAccountNumber() + spreter;
		linedata += clientto.getAccountNumber() + spreter;
		linedata += to_string(Amount) + spreter;
		linedata +=to_string( clientfrom.AccountBalance) + spreter;
		linedata += to_string(clientto.AccountBalance) + spreter;
		linedata += CurrentUser.UserName;

		return linedata;
	}
public:

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber
		, string PinCode, float AcountBalance) :clsPerson(FirstName, LastName, Email, Phone) {
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AcountBalance;
		
	}
	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	string getAccountNumber() {
		return _AccountNumber;
	}

	void setPinCode(string PinCode) {
		_PinCode = PinCode;
	}
	string getPinCode() {
		return _PinCode;
	}
	__declspec(property(get = getPinCode, put = setPinCode))string PinCode;

	void setAccountBalance(double Balance) {
		_AccountBalance = Balance;
	}
	float getAccountBalance() {
		return _AccountBalance;
	}
	__declspec(property(get = getAccountBalance, put = setAccountBalance))float AccountBalance;

	
	static clsBankClient Find(string AccountNumber) {
		fstream myFile;
		myFile.open("ClientData.txt", ios::in);
		if (myFile.is_open()) {
			string line;
			while (getline(myFile, line)) {
				clsBankClient Client = _ConvertLineToClientObject(line);
				if (Client.getAccountNumber() == AccountNumber) {
					myFile.close();
					return Client;
				}
			}
			myFile.close();
		}
		return _GetEmptyClientObject();
	}
	static clsBankClient Find(string AccountNumber, string PinCode) {
		fstream myFile;
		myFile.open("ClientData.txt", ios::in);
		if (myFile.is_open()) {
			string line;
			while (getline(myFile, line)) {
				clsBankClient Client = _ConvertLineToClientObject(line);
				if ((Client.getAccountNumber() == AccountNumber) && (Client.getPinCode() == PinCode)) {
					myFile.close();
					return Client;
				}
			}
			myFile.close();
		}
		return _GetEmptyClientObject();
	}
	static bool IsClientExist(string AccountNumber) {
		clsBankClient Client1 = Find(AccountNumber);
		return (!Client1.IsEmpty());
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
			if (clsBankClient::IsClientExist(_AccountNumber)) {
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
	static clsBankClient GetAddNewObject(string AccountNumber) {
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}
	static vector<clsBankClient>GetClientList() {
		return _LoadClientDataFromFile();
	}
	static double TotalBalances() {
		vector<clsBankClient>clients = _LoadClientDataFromFile();
		double Total = 0;
		for (clsBankClient& c : clients) {
			Total += c.AccountBalance;
		}
		return Total;
	}
	bool Delete() {
		vector<clsBankClient>vclients = _LoadClientDataFromFile();
		for (clsBankClient& c : vclients) {
			if (c.getAccountNumber() == _AccountNumber) {
				c._MarkForDelete = true;
				break;
			}
		}
		_SaveClientDataToFile(vclients);
		*this = _GetEmptyClientObject();
		return true;
	}
	void Deposit(double Amount) {
		_AccountBalance += Amount;
		Save();
	}
	bool Withdraw(double Amount) {
		if (Amount > _AccountBalance) {
			return false;
		}
		
		_AccountBalance -= Amount;
		Save();
		return true;
	}

	static void SaveTransferRegister(clsBankClient clientfrom, clsBankClient clientto, double Amount) {
		string linedata="";
		
		fstream myFile;
		myFile.open("TransferLog.txt",ios::out | ios::app);
		if (myFile.is_open()) {
			linedata = _PrepareTransferLogDataLine(clientfrom, clientto, Amount);
			myFile << linedata << endl;
			myFile.close();
		}
	}

	static vector<string>GetTransferLogList() {
		fstream myFile;
		
		myFile.open("TransferLog.txt", ios::in);
		if (myFile.is_open()) {
			vector<string>TransferLoge;
			string line;
			while (getline(myFile, line)) {
				TransferLoge.push_back(line);
			}
			myFile.close();
			return TransferLoge;
		}
		
	}
};

