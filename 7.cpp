#include <iostream>
#include <vector>

using namespace std;

int main() {
	int c, to, num;
	cin >> c >> to >> num;
	int a[c][c], b[c][c];
	for (int i=0; i<c; i++) for (int j=0; j<c; j++) a[i][j] = 0;
	for (int i=0; i < num; i++) {
		int tmp1, tmp2, val1, val2;
		cin >> tmp1 >> tmp2 >> val1 >> val2;
		a[tmp1-1][tmp2-1] = val1;
		a[tmp2-1][tmp1-1] = val1;
		b[tmp1-1][tmp2-1] = val2;
		b[tmp2-1][tmp1-1] = val2;
	}
	int m, n;
	cin >> m >> n;
	for (int i=0; i<c; i++) {
		for (int j=0; j<c; j++) {
			if (b[i][j] < m+n) a[i][j] = 0;
		}
	}
	for (int k=0; k<c; k++) {
		for (int i=0; i<c; i++) {
			for (int j=0; j<c; j++) {
				if (a[i][k] != 0 && a[k][j] != 0) {
					a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
				}
			}
		}
	}
	if (a[0][to-1] <= 0) cout << -1;
	else cout << a[0][to-1];
	return 0;
}
