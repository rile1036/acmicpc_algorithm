#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;

int main() {
	int count, num;
	int temp;
	scanf("%d %d", &count, &num);
	
	vector<int> arr;
	for (int i = 0; i < count; i++) {
		scanf("%d", &temp);
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	printf("%d\n", arr[num - 1]);
	return 0;
}