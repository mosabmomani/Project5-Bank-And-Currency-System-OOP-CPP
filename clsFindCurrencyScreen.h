#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"
class clsFindCurrencyScreen:protected clsScreen
{
	static void _PrintCurrencyCard(clsCurrency currency) {
	
	cout << "Currency Card:\n";
	cout << "_______________________________________\n";
	cout << "Country  : " << currency.Country()<<endl;
	cout << "Code     : " << currency.CurrencyCode()<<endl;
	cout << "Name     : " << currency.CurrencyName()<<endl;
	cout << "Rate(1$) : " << currency.Rate()<<endl;
	cout << "_______________________________________\n";
	}
	static void _ShowResults(clsCurrency currency) {
		if (!currency.isEmpty()) {
			cout << "\nCurrency Found\n\n";
			_PrintCurrencyCard(currency);
		}
		else
			cout << "\nCurrency was not Found\n\n";
	}

public:
	static void FindCurrencyScreen() {
		_DrawScreenHeader("Find Currency Screen");
		cout << "\n\nFindBy: [1]Code or [2]Country?\n";
		int c;
		cin >> c;
		if (c == 1) {
			string Code = clsInputValidate::ReadString("please enter CurrencyCode?");
		clsCurrency currency=clsCurrency::FindByCode(Code);
		_ShowResults(currency);

		}
		else {
			string Country = clsInputValidate::ReadString("please enter Country?");
			clsCurrency currency = clsCurrency::FindByCountry(Country);
			_ShowResults(currency);
		}
		
	}
};

