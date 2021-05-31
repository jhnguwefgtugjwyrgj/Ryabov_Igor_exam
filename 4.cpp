#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s="AFIN";
vector <string> a;

void func(int n, int m, string cur="") {
	if (n == 0) {
		if (m <= 0) {
			a.push_back(cur);
		}
		return;
	}
	for (int i=0; i < s.size(); i++) {
		if (s[i] == 'A' || s[i] == 'I') func(n-1, m-1, cur+s[i]);
		else func(n-1, m, cur+s[i]);
	}
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	func(n, m);
	if (k <= a.size()) cout << a.size() << " " << a[k-1];
	else cout << "ERROR";
	return 0;
}
