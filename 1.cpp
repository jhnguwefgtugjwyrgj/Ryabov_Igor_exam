#include <iostream>
#include <cmath>

using namespace std;

int func(int c) {
	while (c / 100 > 0) {
		c /= 10;
	}
	return c;
}

int main() {
	int a, b, max=0, count=0;
	cin >> a >> b;
	for (int i=a; i <= b; i++) {
		if (abs(i) > 99 && abs(i % 100) != func(abs(i))) {
			if (i % (func(abs(i)) - (abs(i % 100))) == 0) {
				count++;
				if (i > max || max == 0) max = i;
			}
		}
	}
	cout << count << " " << max;
	return 0;
}
