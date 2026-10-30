#pragma once
#include<iostream>
#include"clsdate.h"
using namespace std;
class clsutility
{
public:
	static void srond() {
		srand((unsigned)time(NULL));
	}
	static int RandomNumber(int from, int to) {
		int random = rand() % (to - from + 1) + from;
		return random;
	}
	static void swap(int& number1, int& number2) {
		int temp = 0;
		temp = number1;
		number1 = number2;
		number2 = temp;
	}
	static void swap(double& number1, double& number2) {
		double temp = 0;
		temp = number1;
		number1 = number2;
		number2 = temp;
	}
	static void swap(bool& a, bool& b) {
		bool temp = 0;
		temp = a;
		a = b;
		b = temp;
	}
	static void swap(char& a, char& b) {
		char temp = ' ';
		temp = a;
		a = b;
		b = temp;
	}
	static void swap(string& s1, string& s2) {
		string temp = " ";
		temp = s1;
		s1 = s2;
		s2 = temp;
	}
	static void swap(clsDate& a, clsDate& b) {
		clsDate::SwapDates(a, b);
	}

	enum enchartype { samallLetter = 1, captalLetter = 2, digit = 3, Mix = 4, specialchracter = 5 };

	static char GetRandomCharacter(enchartype type) {
		if (enchartype::Mix == type) {
			type = enchartype(RandomNumber(1, 3));
		}
		switch (type) {

		case enchartype::samallLetter:
			return char(RandomNumber(97, 122));
		case enchartype::captalLetter:
			return char(RandomNumber(65, 90));
		case enchartype::digit:
			return char(RandomNumber(48, 57));
		default:
			return char(RandomNumber(33, 47));
		}

	}
	static string GenerateRandomWord(enchartype chartype, short length) {
		string word = "";
		for (short m = 0; m < length; m++) {

			word += GetRandomCharacter(chartype);
		}

		return word;

	}
	static string GenerateKey(enchartype chartype) {
		string key = "";
		key = key + GenerateRandomWord(chartype, 4) + "-";
		key = key + GenerateRandomWord(chartype, 4) + "-";
		key = key + GenerateRandomWord(chartype, 4) + "-";
		key = key + GenerateRandomWord(chartype, 4) + "\n";
		return key;
	}
	static void GenerateKey(enchartype chartype, int number) {
		for (short k = 1; number >= k; k++) {
			cout << "kye[" << k << "]" << GenerateKey(chartype);
		}
	}
	static void FillArrayWithRandom(int e[], int arrlength, int from, int to) {

		for (int i = 0; i < arrlength; i++) {
			e[i] = RandomNumber(from, to);
		}
	}
	static void FillArraywithRandomWordS(string e[], short arrlength, enchartype type, short wordlength) {
		string word;
		for (int i = 0; i < arrlength; i++) {
			e[i] = GenerateRandomWord(type, wordlength);
		}
	}
	static void FillArraywithRandomWordS(string e[], short arrlength, enchartype type) {
		string word;
		for (int i = 0; i < arrlength; i++) {
			e[i] = GenerateKey(type);
		}
	}
	static void shufflearray(int arr[100], int arrlength) {
		cout << "\narray elementes aftar shuffle: \n";
		for (int i = 0; i < arrlength; i++) {
			swap(arr[RandomNumber(1, arrlength) - 1], arr[RandomNumber(1, arrlength) - 1]);
		}

	}
	static void shufflearray(string arr[100], int arrlength) {
		cout << "\narray elementes aftar shuffle: \n";
		for (int i = 0; i < arrlength; i++) {
			swap(arr[RandomNumber(1, arrlength) - 1], arr[RandomNumber(1, arrlength) - 1]);
		}

	}
	static string Tabs(short numberofTabs) {
		string t = "";
		for (short i = 0; i < numberofTabs; i++) {
			t = t + "\t";
		}
		return t;
	}
	static string EncryptionText(string name, short encryotionkey=2) {

		for (int i = 0; i <= name.length(); i++) {
			name[i] = char((int)name[i] + encryotionkey);
		}
		return name;
	}
	static string DecryptoinText(string name, short encryotionkey=2) {


		for (int i = 0; i <= name.length(); i++) {
			name[i] = char((int)name[i] - encryotionkey);
		}
		return name;
	}
};


