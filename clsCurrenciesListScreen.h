#pragma once
#include<iostream>
#include<vector>
#include<iomanip>
#include"clsScreen.h"
#include"clsCurrency.h"
class clsCurrenciesListScreen:protected clsScreen
{
	static void _PrintCurrencyline(clsCurrency currencies) {
		
		cout << setw(8) << left << ""<<"|" << setw(30) << left << currencies.Country();
		cout << "|" << setw(5) << left << currencies.CurrencyCode();
		cout << "|" << setw(40) << left << currencies.CurrencyName();
		cout << "|" << setw(12) << left << currencies.Rate() << endl;
	}



public:
	static void ShowCurrenciesList() {
		vector<clsCurrency>Currencies = clsCurrency::GetCurrenciesList();
		string SubTitle;
		SubTitle += "(" + to_string(Currencies.size()) + ") currency";
		_DrawScreenHeader(" Currencies List Screen ",SubTitle);

		cout << setw(8) << left << "" << "\n\t__________________________________________________________________________________________________\n";
		cout << setw(8) << left << "" << "|" << setw(30) << left << "Country";
		cout << "|" << setw(5) << left << "Code";
		cout << "|" << setw(40) << left << "Name";
		cout << "|" << setw(12) << left << "Rate(1$)"<<endl;
		cout << setw(8) << left << "" << "\n\t__________________________________________________________________________________________________\n";
		if (Currencies.size() == 0) {
			cout << "\t\t\tNo Currencies Available in the System ";
}
		else
		{
			for (clsCurrency& c : Currencies) {
				_PrintCurrencyline(c);
			}
		}
		cout << setw(8) << left << "" << "\n\t__________________________________________________________________________________________________\n";
	
	}
};

