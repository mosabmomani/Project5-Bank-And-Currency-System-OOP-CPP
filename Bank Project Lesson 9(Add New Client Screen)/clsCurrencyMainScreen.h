#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrenciesListScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyRate.h"
#include"clsCurrencyCalculatorScreen.h"
class clsCurrencyMainScreen :protected clsScreen
{
	enum enCurrencyOption {
		eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3,
		CurrencyCalculator = 4, eShowMainMenue = 5
	};
	static void _ShowListCurrencies() {
		
		clsCurrenciesListScreen::ShowCurrenciesList();
		
	}
	static void _ShowFindCurrency() {
		clsFindCurrencyScreen::FindCurrencyScreen();
		
	}
	static void _ShowUpdateRate() {
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
		
	}
	static void _ShowCurrencyCalculator() {
		clsCurrencyCalculatorScreen::_ShowCurrencyCalculatorScreen();
	}
	static void _GoBackToCurrencyMenu() {
		cout << "press any key to Go Back To Currency Menu";
		system("pause>0");
		ShowCurrencyScreen();
	}
	static void _performCurrencyMenuOption(enCurrencyOption option) {
		switch (option) {
		case enCurrencyOption::eListCurrencies: {
			system("cls");
			_ShowListCurrencies();
			_GoBackToCurrencyMenu();
			break;
		}
		case enCurrencyOption::eFindCurrency: {
			system("cls");
			_ShowFindCurrency();
			_GoBackToCurrencyMenu();
				break;
		}
		case enCurrencyOption::eUpdateRate: {
			system("cls");
			_ShowUpdateRate();
			_GoBackToCurrencyMenu();
			break;
		}
		case enCurrencyOption::CurrencyCalculator: {
			system("cls");
			_ShowCurrencyCalculator();
			_GoBackToCurrencyMenu();
			break;
		}
		
		case enCurrencyOption::eShowMainMenue: {

			break;
		}

		}

	}

public:

	static void ShowCurrencyScreen() {

		system("cls");
		_DrawScreenHeader("\t Currency Exchange Screen");

		cout << setw(42) << left << "" << "====================================\n";
		cout << setw(42) << left << "" << "\tCurrency Exchange Menu\n";
		cout << setw(42) << left << "" << "====================================\n";
		cout << setw(42) << left << "" << "\t[1] List currencies \n";
		cout << setw(42) << left << "" << "\t[2] Find Currency \n";
		cout << setw(42) << left << "" << "\t[3] Update Rate \n";
		cout << setw(42) << left << "" << "\t[4] Currency Calculator\n";
		cout << setw(42) << left << "" << "\t[5] Main Menu \n";
		cout << setw(42) << left << "" << "====================================\n";
		_performCurrencyMenuOption(enCurrencyOption(clsInputValidate::ReadIntNumberBetween(1, 5)));
	}
};

