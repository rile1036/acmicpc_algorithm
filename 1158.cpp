#include<iostream>
#include<queue>
#include<string.h>

using namespace std;

int main(void) {
	int n, count;
	queue<int> jos;
	cin >> n >> count;
	for (int i = 1; i <= n; i++) jos.push(i);
	cout << "<";
	while (jos.size()) {
		if (jos.size() == 1) {
			cout << jos.front();
			jos.pop();
			break;
		}
		for (int j = 1; j < count; j++) {
			jos.push(jos.front());
			jos.pop();
		}
		cout << jos.front() << ", ";
		jos.pop();
	}

	cout << ">" << endl;
}