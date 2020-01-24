#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;

int main() {
	int Test, x1, y1, r1, x2, y2, r2;
	
	cin >> Test;
	for (int i = 0; i < Test; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		double length = sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));

		if (x1 == x2 && y1 == y2) {
			if (r1 == r2) cout << -1 << endl;
			else cout << 0 << endl;
		}
		else {
			if ((r1 + r2) > length && abs(r1 - r2) < length) cout << 2 << endl;
			else if ((r1 + r2) == length || abs(r1 - r2) == length) cout << 1 << endl;
			else cout << 0 << endl;
		}
	}
	return 0;
}