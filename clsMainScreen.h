#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include"clsManageUsersMenue.h"
#include"clsLoginFile.h"
#include"clsCurrencyMainScreen.h"
#include"Global.h"
using namespace std;
class clsMainScreen :protected clsScreen
{
private:
	enum  enMainMenueOptions {
		eListClient = 1, eAddClient = 2, eDeleteClient = 3, eUpdateClient = 4,
		eFindClient = 5, eShowTransactionsScreen = 6, eManageScreen = 7,eLoginRegister=8,eCurrencyScrren=9, eExit = 10
	};
	static short ReadMainMenuOption() {
		cout << setw(15) << left << "";
		short choice = clsInputValidate::ReadIntNumberBetween(1, 10, "Enter Number Between 1 to 10?");
		return choice;
	}
	static void _GoBackToMainMenu() {
		cout << "press any key to go back to main menu\n";
		system("pause>0");
		ShowMainMenu();
	}
	static void _ShowAllClientsScreen() {
		clsClientListScreen::_ShowClientsScreen();
	}
	static void _ShowAddNewClientsScreen() {
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}
	static void _ShowDeleteClientScreen() {
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}
	static void _ShowUpdateClientScreen() {
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}
	static void _ShowFindClientScreen() {
		clsFindClientScreen::ShowFindClientScreen();
	}
	static void _ShowTransactionsClientScreen() {
		clsTransactionsScreen::ShowTransactionMenu();
	}
	static void _ShowMangeUsersScreen() {
		clsManageUsersScreen::ShowManageUsersMenu();
	}

	static void _ShowLoginRegisterScreen() {
		clsLoginFile::_ShowLoginRegisterScreen();
	}
	static void _ShowCurrencyExchangeScreen() {
		clsCurrencyMainScreen::ShowCurrencyScreen();
	}
	static void _ShowLogoutScreen() {
		CurrentUser = clsUser::Find("", "");
	}

	static void _ProcessMainMenuOption(enMainMenueOptions Option) {
		switch (Option) {
		case enMainMenueOptions::eListClient: {
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenueOptions::eAddClient: {
			system("cls");
			_ShowAddNewClientsScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenueOptions::eDeleteClient: {
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenueOptions::eUpdateClient: {
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenueOptions::eFindClient: {
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenueOptions::eShowTransactionsScreen: {
			system("cls");
			_ShowTransactionsClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenueOptions::eManageScreen: {
			system("cls");
			_ShowMangeUsersScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenueOptions::eLoginRegister: {
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenueOptions::eCurrencyScrren: {
			system("cls");
			_ShowCurrencyExchangeScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenueOptions::eExit: {
			system("cls");
			_ShowLogoutScreen();
			break;
		}
		}

	}
public:
	static void ShowMainMenu() {

		system("cls");
		_DrawScreenHeader("Main Menu");
		cout << setw(40) << left << "" << "========================================\n";
		cout << setw(40) << left << "" << "\t\tMain Menu\n";
		cout << setw(40) << left << "" << "========================================\n";
		cout << setw(41) << left << "" << "[1] Show Clients List\n";
		cout << setw(41) << left << "" << "[2] Add New Client List\n";
		cout << setw(41) << left << "" << "[3] Delete Client \n";
		cout << setw(41) << left << "" << "[4] Update Client \n";
		cout << setw(41) << left << "" << "[5] Find Client \n";
		cout << setw(41) << left << "" << "[6] Transactions \n";
		cout << setw(41) << left << "" << "[7] Manage Users \n";
		cout << setw(41) << left << "" << "[8] Login Register \n";
		cout << setw(41) << left << "" << "[9] Currency Exchange \n";
		cout << setw(41) << left << "" << "[10] Logout \n";
		cout << setw(40) << left << "" << "========================================\n";
		_ProcessMainMenuOption((enMainMenueOptions)ReadMainMenuOption());

	}

};



