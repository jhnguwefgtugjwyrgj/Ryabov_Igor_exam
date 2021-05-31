#include <iostream>
#include <cmath>

using namespace std;

int is_p(int num) {
	int fl=0;
	for (int i=2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			fl=i;
			break;
		}
	}
	return fl;
}

int main() {
	int a, b, count=0, max=0, max_dif = 0;
	cin >> a >> b;
	if (a  < 0) a = 0;
	for (int i=a; i <= b; i++) {
		int t1, t2, t3;
		t1 = is_p(a);
		t2 = is_p(a/t1);
		t3 = (a / t1) / t2;
		if (t1 != 0 && t2 != 0 && t3 != 0) {
			if (is_p(t3) == 0) {
				if (t1 % 10 == t2 % 10 && t2 % 10 == t3 % 10) {
					count++;
					if (t3 - t1 > max_dif) {
						max = i;
						max_dif = t3-t1;
					}
				}
			}
		}
	}
	cout << count << " " << max;
	return 0;
}
