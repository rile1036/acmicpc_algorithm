#include <iostream>
#include <algorithm>
 
using namespace std;
 
int arr[500][500];

int Graph(int count){
	for (int i = 0; i < count; i++){
		for (int j = 0; j <= i; j++){
			int tree[2] = { j - 1, j };

			if (i >= 1){
				int left = 0, right = 0;
				if (tree[0] >= 0)	left = arr[i - 1][tree[0]];
				if (tree[1] <= j) right = arr[i - 1][tree[1]];

				arr[i][j] += max(left, right);
			}
		}
	}

	int max = 0;

	for (int i = 0; i < count; i++){
		if (max < arr[count - 1][i]) max = arr[count - 1][i];
	}
	return max;
}

int main() {
	int count;
	cin >> count;
	int num;

	for (int i = 0; i < count; i++){
		for (int j = 0; j <= i; j++){
			cin >> num;
			arr[i][j] = num;
		}
	}
	cout << Graph(count);

	return 0;
}