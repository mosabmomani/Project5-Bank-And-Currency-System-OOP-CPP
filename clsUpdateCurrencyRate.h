#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"
class clsUpdateCurrencyRateScreen :protected clsScreen
{
	static void _PrintCurrencyCard(clsCurrency currency) {

		cout << "Currency Card:\n";
		cout << "_______________________________________\n";
		cout << "Country  : " << currency.Country() << endl;
		cout << "Code     : " << currency.CurrencyCode() << endl;
		cout << "Name     : " << currency.CurrencyName() << endl;
		cout << "Rate     : " << currency.Rate() << endl;
		cout << "_______________________________________\n";
	}
public:
	static void ShowUpdateCurrencyRateScreen() {
		_DrawScreenHeader("Update Currency Rate Screen");

		string Code = clsInputValidate::ReadString("please enter Currency code : ");
		while (!clsCurrency::IsCurrencyExist(Code)) {
			Code = clsInputValidate::ReadString("please enter Currency code : ");
		}
		clsCurrency currency = clsCurrency::FindByCode(Code);
		_PrintCurrencyCard(currency);

		cout << "\n\nAre you sure you want to update rate of this currency?y/n?";
		char Answer = 'n';
		cin >> Answer;
		if (tolower(Answer) == 'y') {
			cout << "Update currency Rate:";
			cout << "\n_____________________________\n";
			float Rate=clsInputValidate::ReadDblNumber("enter new Rate: ");
			currency.UpdateRate(Rate);
			cout << "\ncurrency Rate was Update successfully\n";
			_PrintCurrencyCard(currency);
		}
		

	}
};

