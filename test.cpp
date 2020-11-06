#include <string>
#include <iostream>
#include <map>

using std::string;
using std::cin;
using std::cout;
using std::map;

map<char, int> f = map<char, int>{
	{'+', 2}, {'*', 4}, {'(', 0}, {')', 6}, {'i', 6}, {'#', -1}
};

map<char, int> g = map<char, int>{
	{'+', 2}, {'*', 3}, {'(', 5}, {')', 1}, {'i', 5}, {'#', 0}
};


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


struct stack{
	char st[100010];
	int size = 0;
	
	void pop() {size--;}

	void push(char c){
		st[size++]=c;
		cout << 'I' << c << '\n';
	}

	char& operator [](int idx){
		return st[idx];
	}

	char topterminal() const {
		for (int i = size - 1; ~i; i--) if (st[i] != 'N') return st[i];
	}

	bool operator < (const char &rhs) const {
		if (!g.count(rhs)) E();
		return f[topterminal()] < g[rhs];
	}

	void work(){
		char c = topterminal();
		// cout << "top: " << c << '\n';
		if (c == '+' || c == '*') {
			if (size > 3 && st[size - 1] == 'N' && st[size - 3] == 'N' && st[size - 2] == c) {
				R();
				size -= 2;
			}
			else RE();
		}
		else if (c == ')') {
			if (size > 3 && st[size - 1] == ')' && st[size - 2] == 'N' && st[size - 3] == '(') {
				R();
				size -= 2;
				st[size - 1] = 'N';
			}
		}
		else if (c == 'i') {
			st[size - 1] = 'N';
			R();
			return ;
		}
	}
};

string s;

int main(){
	cin >> s;
	s += '#';
	stack a;
	a[0] = '#'; a.size++;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'i' && (a[a.size - 1] == 'i' || a[a.size - 1] == 'N')) E();
		// cout << s[i] << '\n';
		while (!(a < s[i])) {
			a.work();
		}
		if (a < s[i] && s[i] != '#') {
			a.push(s[i]);
		}
	}
}
