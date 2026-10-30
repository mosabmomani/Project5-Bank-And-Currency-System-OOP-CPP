#pragma once
#include <iostream>
#include<string>
//#include "clsdate.h"
#include"clsString.h"
using namespace std;
class clsInputValidate
{
public:
	static bool IsNumberBetween(short value, short from, short to) {
		return (value >= from && value <= to) ? true : false;
	}
	static bool IsNumberBetween(int value, int from, int to) {
		return (value >= from && value <= to) ? true : false;
	}
	static bool IsNumberBetween(double value, double from, double to) {
		return (value >= from && value <= to) ? true : false;
	}
	static bool IsNumberBetween(float value, float from, float to) {
		return (value >= from && value <= to) ? true : false;
	}
	
	static int ReadIntNumber(string massage = "invalid number,enter again\n") {
		int number;

		while (!(cin >> number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << massage;
		}
		return number;
	}
	static string ReadString(string massage = "please enter a string? ") {
		string s1;
		cout <<endl<< massage ;
		getline(cin >> ws, s1);
		return s1;
	}
	static double ReadDblNumber(string massege = "please enter a number ?") {
		double number;
		cout << massege;
		while (!(cin >> number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "invalid number,enter again\n";
			;
		}
		return number;
	}
	static int  ReadIntNumberBetween(int from, int to, string massage = "number is not in the range,enter again") {
		cout << "\t\t\t\tplease enter number between " << from << " and " << to << "?";
		int number = ReadIntNumber();
		while (number<from || number>to) {
			cout << massage;
			number = ReadIntNumber();
		}
		return number;
	}
	static double ReadDblNumberBetween(double from, double to, string massage = "number is not in the range,enter again") {
		double number = ReadDblNumber();
		while (number<from || number>to) {
			cout << massage;
			number = ReadDblNumber();
		}
		return number;
	}

	static string NumberToText(long long number) {
    if (number == 0) {
        return " ";
    }
    if (number <= 19) {
        string arr[] = {"one","tow","three","four","five","six","seven","ehate","namin",
            "tin","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","naintin"
        };
        return arr[number-1];
    }
    if (number <= 99) {
        string arr2[] = { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
        
        return arr2[(number / 10) - 2] +" "+ NumberToText(number % 10);
    }
    if (number <= 999) {
   
        return NumberToText(number / 100) + " hundreds " + NumberToText(number % 100);
    }
    if (number <= 999999) {
       
        return NumberToText(number / 1000) + " thousands " + NumberToText(number % 1000);
    }
    if (number <= 999999999) {
        
        return NumberToText(number / 1000000) + " millions " + NumberToText(number % 1000000);
    }
    if (number <= 999999999999) {
       
        return NumberToText(number / 1000000000) + " billions " + NumberToText(number % 1000000000);
    }
    else {
        return "out of rang ";
    }

}
};

