#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"clsString.h"
class clsCurrency
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1 };

	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLineCurrencyObject(string line, string seperater = "#//#") {
		vector<string>vCurrencyData;
		vCurrencyData = clsString::split(line, seperater);
		return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1],
			vCurrencyData[2], stod(vCurrencyData[3]));

	}
	static string _ConvertCurrencyObjectToLine(clsCurrency currency, string seperator = "#//#") {
		string stCurrencyRecord = "";
		stCurrencyRecord += currency.Country() + seperator;
		stCurrencyRecord += currency.CurrencyCode() + seperator;
		stCurrencyRecord += currency.CurrencyName() + seperator;
		stCurrencyRecord += to_string(currency.Rate());
		return stCurrencyRecord;
	}
	static vector<clsCurrency>_LoadCurrencyDataFromFile() {
		vector<clsCurrency>vcurrency;
		fstream myFile;
		myFile.open("Currencies.txt", ios::in);
		if (myFile.is_open()) {
			string line;

			while (getline(myFile, line)) {
				clsCurrency currency = _ConvertLineCurrencyObject(line);
				vcurrency.push_back(currency);
			}
			myFile.close();
		}
		return vcurrency;
	}
	static void _SaveCurrencyDataToFile(vector<clsCurrency>vcurrency) {
		fstream myFile;
		myFile.open("Currencies.txt", ios::out);
		if (myFile.is_open()) {
			string DataLine;
			for (clsCurrency& c : vcurrency) {
				DataLine = _ConvertCurrencyObjectToLine(c);
				myFile << DataLine << endl;
			}
			myFile.close();
		}
	}
	void _Update() {
		vector<clsCurrency>vcurrencys;
		vcurrencys = _LoadCurrencyDataFromFile();
		for (clsCurrency& c : vcurrencys) {
			if (c.CurrencyCode() == _CurrencyCode) {
				c = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(vcurrencys);
	}
	static clsCurrency _GetEmptyCurrencyObject() {
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}


public:
	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate) {
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}
	static vector<clsCurrency>GetAllUSDRates() {
		return _LoadCurrencyDataFromFile();
	}
	bool isEmpty() {
		return (_Mode == enMode::EmptyMode);
	}
	string Country() {
		return _Country;
	}
	string CurrencyCode() {
		return _CurrencyCode;
	}
	string CurrencyName() {
		return _CurrencyName;
	}
	void UpdateRate(float Rate) {
		_Rate = Rate;
		_Update();
	}
	float Rate() {
		return _Rate;
	}
	static clsCurrency FindByCode(string CurrencyCode) {
		CurrencyCode = clsString::UpperAllLetters(CurrencyCode);
		fstream myFile;
		myFile.open("Currencies.txt", ios::in);
		if (myFile.is_open()) {
			string line;
			while (getline(myFile, line)) {
				clsCurrency currency = _ConvertLineCurrencyObject(line);
				if (currency.CurrencyCode() == CurrencyCode) {
					myFile.close();
					return currency;
				}

			}
			myFile.close();
		}
		return _GetEmptyCurrencyObject();
	}
	static clsCurrency FindByCountry(string Country) {
		Country = clsString::UpperAllLetters(Country);
		fstream myFile;
		myFile.open("Currencies.txt", ios::in);
		if (myFile.is_open()) {
			string line;
			while (getline(myFile, line)) {
				clsCurrency currency = _ConvertLineCurrencyObject(line);
				if (clsString::UpperAllLetters(currency.Country()) == Country) {
					myFile.close();
					return currency;
				}

			}
			myFile.close();
		}
		return _GetEmptyCurrencyObject();
	}
	static bool IsCurrencyExist(string CurrnctCode) {
		clsCurrency c = FindByCode(CurrnctCode);
		return (!c.isEmpty());
	}
	static vector<clsCurrency>GetCurrenciesList() {
		return _LoadCurrencyDataFromFile();
	}
	float ConvertToUSD(float Amount) {
		return (float)(Amount / Rate());
	}
	float ConvertToOtherCurrency(float Amount, clsCurrency currency2) {
		float AmountInUSD = ConvertToUSD(Amount);
		if (currency2.CurrencyCode() == "USD") {
			return AmountInUSD;
		}
		return (float)(AmountInUSD * currency2.Rate());

	}

};


