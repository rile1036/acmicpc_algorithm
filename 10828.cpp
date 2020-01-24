#include<iostream>
#include<string.h>

using namespace std;

int main(void) {
	int space[100000];
	int num;
	int top = 0;
	int n;
	char line[100];

	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> line;
		if (strcmp(line, "push") == 0) {
			cin >> n;
			space[top] = n;
			top++;
		}
		if (strcmp(line, "pop") == 0) {
			if (top <= 0) cout << "-1\n";
			else {
				cout << space[top - 1] << "\n";
				top--;
			}
		}
		if (strcmp(line, "size") == 0) {
			cout << top << "\n";
		}
		if (strcmp(line, "empty") == 0) {
			if (top <= 0) cout << "1" << "\n";
			else cout << "0" << "\n";
		}
		if (strcmp(line, "top") == 0) {
			if (top <= 0) cout << "-1" << "\n";
			else cout << space[top-1] << "\n";
		}
	}
}