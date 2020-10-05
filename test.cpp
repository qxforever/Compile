#include <bits/stdc++.h>

using std::string;
using std::vector;
using std::map;
using std::cin;
using std::cout;

string s;

map<string, string> table;

bool isEqu(char x){
	return x == '=';
}

bool isColon(char x){
	return x == ':';
}

bool isPlus(char x){
	return x == '+';
}

bool isStar(char x){
	return x == '*';
}

bool isComma(char x){
	return x == ',';
}

bool isLParenthesis(char x){
	return x == '(';
}

bool isRParenthesis(char x){
	return x == ')';
}

void init(){
	table = map<string, string> {
		{"BEGIN", "Begin"},
		{"END", "End"},
		{"FOR", "For"},
		{"IF", "If"},
		{"THEN", "Then"},
		{"ELSE", "Else"},
		{":", "Colon"},
		{"+", "Plus"},
		{"*", "Star"},
		{",", "Comma"},
		{"(", "LParenthesis"},
		{")", "RParenthesis"},
		{":=", "Assign"}
	};
}

int main(){
	// freopen("1.in","r",stdin);
	cout << "????" << endl;
	init();
	while(!cin.eof()){
		string ss;
		getline(cin, ss);
		s += ss + '\n';
	}

	int len = s.length();

	for (int i = 0; i < len; i++) {
		if (isspace(s[i])) continue;
		string tmp = "";
		int j = i;

		if (isalpha(s[i])) {

			while (isalpha(s[j]) || isdigit(s[j])) {
				tmp += s[j];
				j++;
			}

			if (table.count(tmp)) {
				cout << table[tmp] << '\n';
			}
			else {
				cout << "Ident(" << tmp << ')' << '\n';
			}
			i = j - 1;
		}
		else if (isdigit(s[i])) {
			while (isdigit(s[j])) {
				tmp += s[j];
				j++;
			}
			int res = stoi(tmp);
			cout << "Int(" << res << ')' << '\n';
			i = j - 1;
		}
		else if (isColon(s[i])) {
			if (isEqu(s[i + 1])) {
				cout << table[":="] << '\n';
				i = i + 1;
			}
			else {
				cout << table[":"] << '\n';
			}
		}
		else if (isPlus(s[i])) 
			cout << table["+"] << '\n';
		else if (isStar(s[i])) 
			cout << table["*"] << '\n';
		else if (isComma(s[i])) 
			cout << table[","] << '\n';
		else if (isLParenthesis(s[i])) 
			cout << table["("] << '\n';
		else if (isRParenthesis(s[i])) 
			cout << table[")"] << '\n';
		else {
			cout << "Unknown" << '\n';
			fprintf(stderr, "Unknown\n");
		}
	}

}#include <bits/stdc++.h>

using std::string;
using std::vector;
using std::map;
using std::cin;
using std::cout;

string s;

map<string, string> table;

bool isEqu(char x){
	return x == '=';
}

bool isColon(char x){
	return x == ':';
}

bool isPlus(char x){
	return x == '+';
}

bool isStar(char x){
	return x == '*';
}

bool isComma(char x){
	return x == ',';
}

bool isLParenthesis(char x){
	return x == '(';
}

bool isRParenthesis(char x){
	return x == ')';
}

void init(){
	table = map<string, string> {
		{"BEGIN", "Begin"},
		{"END", "End"},
		{"FOR", "For"},
		{"IF", "If"},
		{"THEN", "Then"},
		{"ELSE", "Else"},
		{":", "Colon"},
		{"+", "Plus"},
		{"*", "Star"},
		{",", "Comma"},
		{"(", "LParenthesis"},
		{")", "RParenthesis"},
		{":=", "Assign"}
	};
}

int main(){
	cout << "????" << endl;
	init();
	while(!cin.eof()){
		string ss;
		getline(cin, ss);
		s += ss + '\n';
	}

	int len = s.length();

	for (int i = 0; i < len; i++) {
		if (isspace(s[i])) continue;
		string tmp = "";
		int j = i;

		if (isalpha(s[i])) {

			while (isalpha(s[j]) || isdigit(s[j])) {
				tmp += s[j];
				j++;
			}

			if (table.count(tmp)) {
				cout << table[tmp] << '\n';
			}
			else {
				cout << "Ident(" << tmp << ')' << '\n';
			}
			i = j - 1;
		}
		else if (isdigit(s[i])) {
			while (isdigit(s[j])) {
				tmp += s[j];
				j++;
			}
			int res = stoi(tmp);
			cout << "Int(" << res << ')' << '\n';
			i = j - 1;
		}
		else if (isColon(s[i])) {
			if (isEqu(s[i + 1])) {
				cout << table[":="] << '\n';
				i = i + 1;
			}
			else {
				cout << table[":"] << '\n';
			}
		}
		else if (isPlus(s[i])) 
			cout << table["+"] << '\n';
		else if (isStar(s[i])) 
			cout << table["*"] << '\n';
		else if (isComma(s[i])) 
			cout << table[","] << '\n';
		else if (isLParenthesis(s[i])) 
			cout << table["("] << '\n';
		else if (isRParenthesis(s[i])) 
			cout << table[")"] << '\n';
		else {
			cout << "Unknown" << '\n';
			fprintf(stderr, "Unknown\n");
		}
	}

}
