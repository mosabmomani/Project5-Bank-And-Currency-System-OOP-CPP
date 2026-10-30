#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"
class clsClientListScreen :protected clsScreen
{
	static void _PrintClientRecordLine(clsBankClient client) {

		cout << setw(8) << left << "" << "|" << setw(15) << left << client.getAccountNumber();
		cout << "|" << setw(20) << left << client.FullName();
		cout << "|" << setw(12) << left << client.Phone;
		cout << "|" << setw(25) << left << client.Email;
		cout << "|" << setw(12) << left << client.PinCode;
		cout << "|" << setw(15) << left << client.AccountBalance << endl;
	}
public:
	static void _ShowClientsScreen() {
		if (!CheckAccessRights(clsUser::enPermissions::pListClient)) {
			return;
		}
		vector<clsBankClient>clients = clsBankClient::GetClientList();
		string Title = "\n\t\t\t\t\t       Client List Screen";
		string subTitle = "(" + to_string(clients.size()) + ") Client(s)";
		clsScreen::_DrawScreenHeader(Title, subTitle);
		cout << setw(8) << left << "" << "\n\t__________________________________________________________________________________________________\n";
		cout << setw(8) << left << "" << "|" << setw(15) << left << "Account Number";
		cout << "|" << setw(20) << left << "FullName()";
		cout << "|" << setw(12) << left << "Phone";
		cout << "|" << setw(25) << left << "Email";
		cout << "|" << setw(12) << left << "PinCode";
		cout << "|" << setw(15) << left << "AccountBalance" << endl;
		cout << setw(8) << left << "" << "\n\t__________________________________________________________________________________________________\n";
		if (clients.size() == 0) {
			cout << "\n\t\t\t\t\t\tNo Client In System yet" << endl;
		}
		else {
			for (clsBankClient& c : clients) {
				_PrintClientRecordLine(c);
			}

		}
		cout << setw(8) << left << "" << "\n\t__________________________________________________________________________________________________\n";
	}
};


