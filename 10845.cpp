#include <iostream>
#include <queue>
#include <string>
using namespace std;


int main(){
	int size;
	cin >> size;

	queue<int> qu;
    string s;
	for (int i = 0; i < size; i++){
		cin >> s;
		if (s == "push"){
			int n;
			cin >> n;
			qu.push(n);
		}
		else if (s == "pop"){
			if (!qu.empty()){
				cout << qu.front() << endl;
				qu.pop();
			}
			else{
				cout << -1 << endl;
			}			
		}
		else if (s == "size"){
			cout << qu.size() << endl;
		}
		else if (s == "empty"){
			if (qu.empty()){
				cout << 1 << endl;
			}
			else{
				cout << 0 << endl;
			}
		}
		else if(s == "front"){
			if (!qu.empty()){
				cout << qu.front() << endl;
			}
			else{
				cout << -1 << endl;
			}
		}
		else{
			if (!qu.empty()){
				cout << qu.back() << endl;
			}
			else{
				cout << -1 << endl;
			}
		}
	}
	return 0;
}


