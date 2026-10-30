#pragma once
#include <iostream>
#include<vector>
using namespace std;
class clsString
{
	string _value;
public:
	clsString() {
		_value = "";
	}

	clsString(string value) {
		_value = value;
	}
	void setstring(string value) {
		_value = value;
	}
	string getstring() {
		return _value;
	}
	__declspec(property(get = getstring, put = setstring))string value;

	static short CountWordsInString(string s, string delim = " ") {
		short pos = 0;
		string word;
		short count = 0;
		while ((pos = s.find(delim)) != std::string::npos) {
			word = s.substr(0, pos);
			if (word != "") {
				count++;
			}
			s.erase(0, pos + delim.length());
		}
		if (s != "") {
			count++;
		}
		return count;
	}
	short CountWordsInString() {
		return CountWordsInString(_value);
	}

	static string PrintFerstLettar(string name) {
		bool isfirstname = true;
		string word = "";
		for (short i = 0; i < name.length(); i++) {

			{
				if (name[i] != ' ' && isfirstname) {
					if (name[i] == ' ') {
						continue;
					}
					else {
						word += name[i] + " ";
					}

				}
				isfirstname = (name[i] == ' ' ? true : false);
			}
		}
		return word;
	}
	string PrintFerstLettar() {
		return PrintFerstLettar(_value);
	}

	static string UpperFirstLetterofEachWord(string s) {
		bool isfirstletter = true;
		string word = "";
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != ' ' && isfirstletter) {

				word += char(toupper(s[i]));
			}
			else {
				word += s[i];
			}
			isfirstletter = ((s[i] == ' ') ? true : false);
		}
		return word;
	}
	void UpperFirstLetterofEachWord() {
		_value = UpperFirstLetterofEachWord(_value);
	}

	static string LowerFirstLettertofEachWord(string s) {
		bool isfirstletter = true;
		string word = "";
		for (short i = 0; i < s.length(); i++) {

			if (isfirstletter && s[i] != 0) {
				word += char(tolower(s[i]));
			}
			else
				word += s[i];

			isfirstletter = (s[i] == ' ') ? true : false;
		}
		return word;
	}
	void LowerFirstLettertofEachWord() {
		_value = LowerFirstLettertofEachWord(_value);
	}

	static string LowerAllLetters(string s) {

		for (short i = 0; i < s.length(); i++) {
			s[i] = tolower(s[i]);
		}
		return s;
	}
	void LowerAllLetters() {
		_value = LowerAllLetters(_value);
	}

	static string UpperAllLetters(string s) {

		for (short i = 0; i < s.length(); i++) {
			s[i] = toupper(s[i]);
		}
		return s;
	}
	void UpperAllLetters() {
		_value = UpperAllLetters(_value);
	}

	static char InvertCharcter(char c) {
		return isupper(c) ? tolower(c) : toupper(c);
	}

	static string InvertAllLetters(string s) {
		for (short i = 0; i < s.length(); i++) {
			s[i] = InvertCharcter(s[i]);
		}
		return s;
	}
	void InvertAllLetters() {
		_value = InvertAllLetters(_value);
	}

	static void CountSmallAndCapitalLetters(string s) {
		short smallletters = 0;
		short capitalletters = 0;
		for (short i = 0; i < s.length(); i++) {
			if (s[i] == ' ') {
				continue;
			}
			isupper(s[i]) ? capitalletters++ : smallletters++;

		}
		cout << "Capital Letters : " << capitalletters << endl;
		cout << "Small Letters : " << smallletters << endl;
	}
	void CountSmallAndCapitalLetters() {
		CountSmallAndCapitalLetters(_value);
	}

	static short CountSpecificLetter(string s, char c, bool matchcase = true) {
		short count = 0;
		for (int i = 0; i < s.length(); i++) {
			if (matchcase) {
				if (s[i] == c) {
					count++;
				}
			}
			else {
				if (tolower(s[i]) == tolower(c)) {
					count++;
				}
			}

		}
		return count;
	}
	short CountSpecificLetter(char c, bool matchcase = true) {
		return CountSpecificLetter(_value, c, matchcase);
	}

	static bool isVowles(char c) {
		c = tolower(c);
		return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
	}

	static short CountVowels(string s) {
		short count = 0;
		for (short i = 0; i < s.length(); i++) {
			if (isVowles(s[i])) {
				count++;
			}
		}
		return count;
	}
	short CountVowels() {
		return CountVowels(_value);
	}

	static string printvowels(string s) {
		string word = "";

		for (short i = 0; i < s.length(); i++) {
			if (isVowles(s[i])) {
				word += s[i] + "  ";
			}
		}
		return word;
	}
	string printvowels() {
		return printvowels(_value);
	}

	static void PrintEachWordSpritly(string s) {
		cout << "your string woord are \n";
		string delim = " ";
		short pos = 0;
		string sword;
		while ((pos = s.find(delim)) != std::string::npos) {
			sword = s.substr(0, pos);
			if (sword != "") {
				cout << sword << endl;
			}
			s.erase(0, pos + delim.length());
		}
		if (s != " ") {
			cout << s << endl;
		}

	}
	void PrintEachWordSpritly() {
		PrintEachWordSpritly(_value);
	}

	static vector<string>split(string s, string spliter = " ") {
		vector<string> vsplit;
		short tokens = 0;
		short pos = 0;
		string sword;
		while ((pos = s.find(spliter)) != std::string::npos) {
			sword = s.substr(0, pos);
			if (sword != "") {

				vsplit.push_back(sword);
			}
			s.erase(0, pos + spliter.length());
		}
		if (s != "") {

			vsplit.push_back(s);

		}

		return vsplit;
	}
	vector<string>split(string spliter = " ") {
		return split(_value, spliter);
	}

	static string TirmLeft(string s) {
		for (short i = 0; i < s.length(); i++) {
			if (s[i] != ' ') {
				return s.substr(i, s.length() - i);
			}
		}
		return "";
	}
	void TirmLeft() {
		_value = TirmLeft(_value);
	}

	static string TirmRight(string s) {
		for (short i = s.length() - 1; i >= 0; i--) {
			if (s[i] != ' ') {
				return s.substr(0, i + 1);

			}
		}
		return "";
	}
	void TirmRight() {
		_value = TirmRight(_value);
	}

	static string Tirm(string s) {

		return (TirmRight(TirmLeft(s)));
	}
	void Tirm() {
		_value = Tirm(_value);
	}

	static string JoinString(vector<string>vname, string delim = " ") {
		string names = "";
		for (string& name : vname) {

			names = names + name + delim;
		}
		return names.substr(0, names.length() - delim.length());

	}
	static string JoinString(string arrname[], short arrsize, string delim = " ") {
		string names = "";
		for (short i = 0; i < arrsize; i++) {

			names = names + arrname[i] + delim;
		}
		return names.substr(0, names.length() - delim.length());

	}

	static string RevereWords(string s) {

		string sword = "";
		vector<string>vwords;
		vwords = split(s, " ");
		vector<string>::iterator iter = vwords.end();
		while (iter != vwords.begin()) {
			--iter;
			sword += *iter + " ";
		}
		sword = sword.substr(0, sword.length() - 1);
		return sword;
	}
	void RevereWords() {
		_value = RevereWords(_value);
	}

	static string ReplaceWords(string s, string orgword, string newword, bool match = true) {
		vector<string>vwords;
		string nstring = "";
		vwords = split(s, " ");
		for (string& word : vwords) {
			if (match) {
				if (word == orgword) {
					word = newword;
				}
				nstring += word + " ";
			}
			else {
				word[0] = tolower(word[0]);
				if (word == orgword) {
					word = newword;
				}
				nstring += word + " ";
			}
		}
		return nstring;
	}
	string ReplaceWords(string orgword, string newword, bool match = true) {
		return ReplaceWords(_value, orgword, newword, match);
	}

	static string RemovePunctuation(string s) {
		string word = "";
		for (short i = 0; i < s.length(); i++) {

			if (!ispunct(s[i])) {
				word += s[i];
			}
		}
		return word;
	}
	void RemovePunctuation() {
		_value = RemovePunctuation(_value);
	}

	static short StringLength(string s) {
		return s.length();
	}
	short StringLength() {
		return _value.length();
	}

};

