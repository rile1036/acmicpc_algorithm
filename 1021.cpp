#include<iostream>
#include<deque>
#include<string.h>

using namespace std;

int main(void) {
	int test, num;
	cin >> test >> num;
	deque<int> deq;
	deque<int>::iterator iter;
	for (int i = 1; i <= test; i++) deq.push_back(i);
	int count = 0;
	for (int j = 0; j < num; j++) {
		int check;
		int index = 1;
		cin >> check;
		for (iter = deq.begin(); iter < deq.end(); iter++) {
			if (*iter == check) break;
			index++;
		}
		int left = index - 1;
		int right = deq.size() - (index - 1);
		if (left < right) {
			for (int k = 1; k <= left; k++) {
				deq.push_back(deq.at(0));
				deq.pop_front();
				count++;
			}
			deq.pop_front();
		}
		if (left >= right) {
			for (int k = 1; k <= right; k++) {
				deq.push_front(deq.at(deq.size()-1));
				deq.pop_back();
				count++;
			}
			deq.pop_front();
		}
	}
	cout << count << endl;
}