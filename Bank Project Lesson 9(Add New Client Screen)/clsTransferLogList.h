#pragma once
#include<iostream>
#include<iomanip>
#include<vector>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsString.h"
class clsTransferLogList:protected clsScreen
{
	struct sTransferlog {
		string Date="";
		string SAcct="";
		string DAcct="";
		double Amount=0;
		double SBalance=0;
		double DBalance=0;
		string username="";
	};
	static sTransferlog _LineToTransferStruct(string line) {
		sTransferlog sLog;
		vector<string>transferlog=clsString::split(line,"#//#");
		sLog.Date = transferlog[0];
		sLog.SAcct = transferlog[1];
		sLog.DAcct = transferlog[2];
		sLog.Amount =stod( transferlog[3]);
		sLog.SBalance = stod(transferlog[4]);
		sLog.DBalance = stod(transferlog[5]);
		sLog.username = transferlog[6];
		return sLog;
	}
	static void _PrintTransferLogLine(sTransferlog slog) {
		cout <<"\n" << setw(8) << left << "" << "|" << setw(23) << left << slog.Date;
		cout << "|" << setw(10) << left << slog.SAcct;
		cout << "|" << setw(10) << left << slog.DAcct;
		cout << "|" << setw(10) << left << slog.Amount;
		cout << "|" << setw(15) << left << slog.SBalance;
		cout << "|" << setw(15) << left << slog.DBalance;
		cout << "|" << setw(10) << left << slog.username;
	}

public:
	static void _ShowTransferLogListScreen() {
		vector<string>TransferList = clsBankClient::GetTransferLogList();
		string Title = "\n\t\t\t\t\t       Transfer Log List Screen";
		string subTitle = "(" + to_string(TransferList.size()) + ") Record(s)";
		clsScreen::_DrawScreenHeader(Title, subTitle);
		cout << setw(8) << left << "" << "\n\t__________________________________________________________________________________________________\n";
		cout << setw(8) << left << "" << "|" << setw(23) << left << "Date/Time";
		cout << "|" << setw(10) << left << "s.Acct";
		cout << "|" << setw(10) << left << "d.Acct";
		cout << "|" << setw(10) << left << "Amount";
		cout << "|" << setw(15) << left << "s.Balance";
		cout << "|" << setw(15) << left << "d.Balance" ;
		cout << "|" << setw(10) << left << "user";
		cout << setw(8) << left << "" << "\n\t__________________________________________________________________________________________________\n";
		if (TransferList.size() == 0) {
			cout << "\n\t\t\t\t\t\tNo Transfer Log In System yet" << endl;
		}
		else {
			sTransferlog logline;
			for (string& line : TransferList) {
				logline = _LineToTransferStruct(line);
				_PrintTransferLogLine(logline);
		}

		}
		cout << setw(8) << left << "" << "\n\t__________________________________________________________________________________________________\n";
	}
};

