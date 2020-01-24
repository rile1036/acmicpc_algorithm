#include <iostream>
using namespace std;

int temp[3];
int arr[2187][2187];

void paper(int x, int y, int num) {
	int start = arr[x][y];
	bool check = true;

	for (int i = x; i < x + num; i++) {
		for (int j = y; j < y + num; j++) {
			if (arr[i][j] != start) {
				check = false;
				break;
			}
		}
	}
	if (check)	temp[start + 1]++;
	else for (int i = x; i < x + num; i += num / 3) for (int j = y; j < y + num; j += num/3) paper(i, j, num / 3);		
}

int main() {
	int num;
	cin >> num;

	for (int i = 0; i < num; i++) for (int j = 0; j < num; j++) cin >> arr[i][j];

	paper(0, 0, num);

	for (int i = 0; i < 3; i++) {
		cout << temp[i] << endl;
	}

	return 0;
}