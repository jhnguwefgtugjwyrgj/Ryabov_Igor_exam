#include <iostream>
#include <cmath>

using namespace std;

int a[101][101];

void func(int x, int y, int col, int last_col) {
	if (a[x][y] != last_col) return;
	last_col=a[x][y];
	a[x][y] = col;
	func(x+1, y, col, last_col);
	func(x-1, y, col, last_col);
	func(x, y+1, col, last_col);
	func(x, y-1, col, last_col);
	return;
}

int main() {
	int n, m, x, y, col;
	cin >> n >> m >> y >> x >> col;
	for (int i=0; i< n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	func(x-1, y-1, col, a[x-1][y-1]);
	for (int i=0; i < n; i++) {
		for (int j=0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
