#pragma once
#include<iostream>
#include<iomanip>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
class clsTotalBalances:protected clsScreen
{
private:
	static void _PrintClientRecordBalanceLine(clsBankClient client) {
		cout << setw(25) << left << "" << "| " << left << setw(15) << client.getAccountNumber();
		cout << "| " << setw(40) << left << client.FullName();
		cout << "| " << setw(12) << left << client.AccountBalance<<endl;
	}

public:
	static void ShowTotalBalanceScreen() {
		vector<clsBankClient>vclient = clsBankClient::GetClientList();
		string Title = "\t Balance List Screen.";
		string SubTitle = "\t   (" + to_string(vclient.size()) + ") client(s).";
		_DrawScreenHeader(Title, SubTitle);
		cout << setw(25) << left << "" << "\n\t\t___________________________________________________________________________________\n";
		cout << setw(25) << left << "" << "| " << left << setw(15) << "Account Number";
		cout<< "| " << left << setw(15) << "Client Name";
		cout << "| " << left << setw(15) << "Balance\n";
		cout << setw(25) << left << "" << "\n\t\t___________________________________________________________________________________\n";
		double TotalBalance = clsBankClient::TotalBalances();
		if (vclient.size() == 0) {
			cout << "\t\t\t\t\t No Client Available  in the System";
		}
		else
		{
			for (clsBankClient& c : vclient) {
				_PrintClientRecordBalanceLine(c);
			}
			cout << setw(25) << left << "" << "\n\t\t___________________________________________________________________________________\n";
			cout << setw(35)<<left<<"" <<"Total Balances = "<< TotalBalance << endl;
			cout << setw(25) << left << "" << clsInputValidate::NumberToText(TotalBalance);
		}
	}
};

