#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream Fin;
    Fin.open("input.txt");
	string s, abc = "ABCDEFJHIGKLMNOPQRSTUVWXYZ";
	char lmax='1';
	Fin >> s;
	int max=-1, fl=0;
	for (int i=0; i < s.size(); i++) {
		char let = s[i];
		for (int j=0; j < s.size(); j++) {
			if (i != j && s[j] == let) {
				int t=abs((i-j))-1;
				if (max <= t) {
					if (abc.find(lmax) >= abc.find(let) || lmax == '1'){
						lmax = let;
						max = t;
						fl = 1;
					}
				}
			}
		}
	}
	if (fl == 1) cout << lmax << " " << max;
	else cout << 0;
	Fin.close();
	return 0;
}
