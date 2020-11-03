#include <string>
#include <iostream>
#include <map>
#include <stack>

using std::string;
using std::cin;
using std::cout;
using std::map;
using std::stack;

string s;
int cnt;

map<char, int> f = map<char, int>{
	{'+', 2}, {'*', 4}, {'(', 0}, {')', 6}, {'i', 6}, {'#', 0}
};

map<char, int> g = map<char, int>{
	{'+', 1}, {'*', 3}, {'(', 5}, {')', 0}, {'i', 5}, {'#', 0}
};

bool compare(const char & lhs, const char & rhs) {
	return f[lhs]<g[rhs];
}

bool isoperator(char c){
	return c == '+' || c == '*';
}

bool issym(char c){
	return c == '+' || c == '*' || c == '(' || c == ')' || c == '#';
}

void push(stack<char> &s, char c){
	if (c == '#') return ;
	if (isoperator(c)) cnt++;
	if (isoperator(c) || c == '(' || c == 'i') s.push(c);
	cout << "I" << c << '\n';
}

void RE(){
	cout << "RE" << '\n';
	exit(0);
}

void R(){
	cout << "R" << '\n';
}

void E(){
	cout << "E" << '\n';
	exit(0);
}

void printstk(const stack<char> s){
	// cout << "top" << s.top() << '\n';
}

int main() {
	cin >> s;
	s += '#';
	stack<char> a, b;
	b.push('#');
	int n = s.length();

	for (int i = 0; i < n; i++) {
		printstk(b);
		if (issym(s[i])) {
			if (compare(b.top(), s[i])) {
				push(b, s[i]);
			}
			else {
				while (!compare(b.top(), s[i])) {
					// printf ("cmp : %c %c\n",b.top(), s[i]);
					if (f[b.top()] == g[s[i]]){
						b.pop();
						break;
					}
					if (isoperator(b.top())) {
						if (a.size() < 2){
							RE();
						}
						a.pop();
						cnt--;
					}
					else {
						if (a.size() < 1) {
							RE();
						}
						a.pop();
					}
					b.pop();
					R();
				}
				push(b, s[i]);
			}
		}
		else if (s[i] == 'i') {
			if (a.size() > cnt) E();
			push(a, s[i]);
			if(issym(s[i + 1])) R();
		}
		else E();
	}
	// cout << a.size() << " " << b.size() << '\n';
	if(!(b.size() == 0 && a.size() == 1)) RE();
}
