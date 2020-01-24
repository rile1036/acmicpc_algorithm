#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;

string text;
string Check_text = "";

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> text; //93996

	int check = text.size() / 2;
	string Left = text.substr(0, check);
	string Right = text.substr((text.size() + text.size() % 2) / 2, check);
	string Mid = text.substr(check, text.size() % 2);
	reverse(Left.begin(), Left.end());

	bool flag = false;
	if (Left.size() % 2 == 1) flag = true;

	if (text.size() > 1) {
		int Left_num = atoi(Left.c_str());
		int Right_num = atoi(Right.c_str());
		int Mid_num = atoi(Mid.c_str());
		if (Left > Right) {
			reverse(Left.begin(), Left.end());
			Check_text += Left;
			if (Mid.size() != 0)
				Check_text += Mid;
			reverse(Left.begin(), Left.end());
			Check_text += Left;
		}
		else {
			reverse(Left.begin(), Left.end());
			if (Mid.size() == 0 || Mid == "9") {
				//Left_num = atoi(Left.c_str());
				//Left_num += 1;
				
				for (int i = Left.size() - 1; i >= 0; i--) {
					Left[i] += 1;
					if (Left[i] == ':')
						Left[i] = '0';
					else break;
					if (Left[0] == '0')
						Left = "1" + Left;
				}
				//Left = to_string(Left_num);
			}

			Check_text += Left;
			if (Mid.size() != 0) {
				if (Mid == "9")
					Check_text += "0";
				else {
					Mid_num += 1;
					Check_text += to_string(Mid_num);
				}
			}
			reverse(Left.begin(), Left.end());
			if ((Left.size() % 2 == 0 && flag) || (Left.size() % 2 == 1) && !flag)
				Check_text = Check_text.substr(0, Check_text.size() - 1);
			Check_text += Left;
		}

		cout << Check_text;
		return 0;
	}
	else {
		if (text == "9")
			cout << 11;
		else cout << atoi(text.c_str()) + 1;
	}

	return 0;
}