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
	{'+', 2}, {'*', 4}, {'(', 0}, {')', 6}, {'i', 6}, {'#', 0}, {'N', -1}
};

map<char, int> g = map<char, int>{
	{'+', 2}, {'*', 3}, {'(', 5}, {')', 0}, {'i', 5}, {'#', 0}
};

bool compare(const char &lhs, const char &rhs) {
	return f[lhs]<g[rhs];
}

bool canComp(const char &lhs, const char &rhs) {
	return !(lhs == rhs);
}

bool issym(char c){
	return c == '+' || c == '*' || c == '(' || c == ')' || c == '#' || c == 'i';
}

void push(stack<char> &s, char c){
	if (c == '#') return ;
	s.push(c);
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

void work(stack<char> &s){
	if (s.top() == ')'){
		if (s.size() < 4) RE();
		char ch[3];
		for (int i = 0; i < 3; i++){
			ch[i] = s.top();
			s.pop(); 
		}
		if (!(ch[0] == ')') && ch[1] == 'N' && ch[2] == '(') RE();
		s.push('N');
		R();
		return ;
	}
	if (s.top() != 'N' && s.top() != 'i') RE();
	if (s.top() == 'i'){
		s.pop();
		s.push('N');
		R();
		return ;
	}
	else {
		if (s.size() < 4) RE();
		char ch[3];
		for (int i = 0; i < 3; i++){
			ch[i] = s.top();
			s.pop(); 
		}
		if (!(ch[0] == 'N') && (ch[1] == '+' || ch[1] == '*') && ch[2] == 'N') RE();
		R();
		s.push('N');
		return ;
	}
}

int main() {
	cin >> s;
	s += '#';
	stack<char> a;
	a.push('#');
	for (size_t i = 0; i < s.length(); i++) {
		if(!issym(s[i]) || !canComp(a.top(), s[i])) E();

		while(!compare(a.top(), s[i])){
			// printf("%c %c %d\n", a.top(), s[i], compare(a.top(), s[i]));
			work(a);
		}
		
		if (compare(a.top(), s[i])) {
			push(a, s[i]);
		}
	}
	while (a.size() > 2) work(a);
}
