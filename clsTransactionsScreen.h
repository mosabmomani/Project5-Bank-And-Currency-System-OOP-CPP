#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsDepositScreen.h"
#include"clsWithdrowScreen.h"
#include"clsTotalBalances.h"
#include"clsTransferScreen.h"
#include"clsTransferLogList.h"
using namespace std;
class clsTransactionsScreen:protected clsScreen
{
private:
	enum enTransactionMenueOptions{eDeposit=1,eWitharw=2,eShowTotalBalance=3,
		eTransfer=4,eShowTransferLog=5,eShowMainMenue=6};
	static void _ShowDepositScreen() {
		clsDepositScreen::ShowDepositScreen();
	}
	static void _ShowWithdrawScreen() {
		clsWithdrowScreen::ShowWithdrawScreen();
	}
	static void _ShowTotalBalancesScreen() {
		clsTotalBalances::ShowTotalBalanceScreen();
	}
	static void _ShowTransferScreen() {
		clsTransferScreen::TransferScreen();
	}
	static void _ShowTransferLogScreen() {
		clsTransferLogList::_ShowTransferLogListScreen();
	}
	static void _GoBackToTransactionsMenu() {
		cout << "\npress any key to go back to Transactions Menu  \n";
		system("pause>0");
		ShowTransactionMenu();
	}
	static void _performTransactionsMenuOption(enTransactionMenueOptions enOption) {
		switch (enOption) {
		case enTransactionMenueOptions::eDeposit: {
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case enTransactionMenueOptions::eWitharw: {
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case enTransactionMenueOptions::eShowTotalBalance: {
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case enTransactionMenueOptions::eTransfer: {
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case enTransactionMenueOptions::eShowTransferLog: {
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case enTransactionMenueOptions::eShowMainMenue : {
			
			break;
		}

		}

	}

public:
	static void ShowTransactionMenu() {
		if (!CheckAccessRights(clsUser::enPermissions::pTranactions)) {
			return;
		}
		system("cls");
		_DrawScreenHeader("\t Transaction Screen");

		cout << setw(42) << left << "" << "====================================\n";
		cout << setw(42) << left << "" << "\tTransaction Menu\n";
		cout << setw(42) << left << "" << "====================================\n";
		cout << setw(42) << left << "" << "\t[1] Deposit \n";
		cout << setw(42) << left << "" << "\t[2] Withdraw  \n";
		cout << setw(42) << left << "" << "\t[3] Total Balance \n";
		cout << setw(42) << left << "" << "\t[4] Transfer \n";
		cout << setw(42) << left << "" << "\t[5] Transfer Log List \n";
		cout << setw(42) << left << "" << "\t[6] Main Menu \n";
		cout << setw(42) << left << "" << "====================================\n";

		_performTransactionsMenuOption(enTransactionMenueOptions(clsInputValidate::ReadIntNumberBetween(1, 6)));
	}
};

