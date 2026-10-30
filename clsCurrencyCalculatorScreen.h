#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"
class clsCurrencyCalculatorScreen :protected clsScreen
{
	static void _PrintCurrencyCard(clsCurrency currency) {

		cout << "_______________________________________\n";
		cout << "Country  : " << currency.Country() << endl;
		cout << "Code     : " << currency.CurrencyCode() << endl;
		cout << "Name     : " << currency.CurrencyName() << endl;
		cout << "Rate     : " << currency.Rate() << endl;
		cout << "_______________________________________\n";
	}
	static string _ReadCurrencyCode() {
		string Code = clsInputValidate::ReadString("please enter Currency Code? ");
		while (!clsCurrency::IsCurrencyExist(Code)) {
			Code = clsInputValidate::ReadString("Currency Code Was not Found,please enter Currency Code? ");
		}
		return Code;
	}
	static void _PrintCalculationsResults(clsCurrency currencyfrom, clsCurrency currencyto, float Amount) {
		cout << "Convert From:\n";
		_PrintCurrencyCard(currencyfrom);
		float AmountInUSD = currencyfrom.ConvertToUSD(Amount);
		cout << Amount << " " << currencyfrom.CurrencyCode() << " = " << AmountInUSD << "USD\n";
		if (currencyto.CurrencyCode() == "USD") {
			return;
		}
		cout << "\nConvert From USD to :\n";
		_PrintCurrencyCard(currencyto);
		float AmountInCurrencyto = currencyfrom.ConvertToOtherCurrency(Amount, currencyto);
		cout << Amount << " " << currencyfrom.CurrencyCode() << " = " <<
			AmountInCurrencyto << currencyto.CurrencyCode() << endl;
	}

public:
	static void _ShowCurrencyCalculatorScreen() {
		char Answer = 'y';
		while (tolower(Answer) == 'y') {
			system("cls");
			_DrawScreenHeader("Currency Calculator Screen");
			clsCurrency currency1 = clsCurrency::FindByCode(_ReadCurrencyCode());
			clsCurrency currency2 = clsCurrency::FindByCode(_ReadCurrencyCode());
			float Amount = clsInputValidate::ReadDblNumber("Enter Amount to Exchange: ");
			_PrintCalculationsResults(currency1, currency2, Amount);
			cout << "do you want to do anther calculation ?y/n?";
			cin >> Answer;

		}
	}

};

