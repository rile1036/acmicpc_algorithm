#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int N;
int testcase;
char Cube[6][3][3];
char Cube_face[3][3];
char color[6] = { 'w', 'y', 'r', 'o', 'g', 'b' };
string Curve;

void Cube_Wise(int face, bool check) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			Cube_face[i][j] = Cube[face][i][j];
	
	if (!check) {
		for (int i = 0; i < 3; i++)
			Cube[face][0][i] = Cube_face[2 - i][0];

		Cube[face][1][0] = Cube_face[2][1];
		Cube[face][1][2] = Cube_face[0][1];

		for (int i = 0; i < 3; i++)
			Cube[face][2][i] = Cube_face[2 - i][2];
	}

	else {
		for (int i = 0; i < 3; i++)
			Cube[face][0][i] = Cube_face[i][2];

		Cube[face][1][0] = Cube_face[0][1];
		Cube[face][1][2] = Cube_face[2][1];

		for (int i = 0; i < 3; i++)
			Cube[face][2][i] = Cube_face[i][0];
	}
}

void Other_face(char face, int num) {
	int other_num; char temp[3];
	if (num == 0) other_num = 2;
	else other_num = 0;

	switch (face) {
	case 'U':
		for (int i = 0; i < 3; i++) temp[i] = Cube[2][num][i];
		for (int i = 0; i < 3; i++) Cube[2][num][i] = Cube[5][num][i];
		for (int i = 0; i < 3; i++) Cube[5][num][i] = Cube[3][num][i];
		for (int i = 0; i < 3; i++) Cube[3][num][i] = Cube[4][num][i];
		for (int i = 0; i < 3; i++) Cube[4][num][i] = temp[i];
		break;
	case 'D':
		for (int i = 0; i < 3; i++) temp[i] = Cube[2][num][i];
		for (int i = 0; i < 3; i++) Cube[2][num][i] = Cube[4][num][i];
		for (int i = 0; i < 3; i++) Cube[4][num][i] = Cube[3][num][i];
		for (int i = 0; i < 3; i++) Cube[3][num][i] = Cube[5][num][i];
		for (int i = 0; i < 3; i++) Cube[5][num][i] = temp[i];
		break;
	case 'F':
		for (int i = 0; i < 3; i++) temp[i] = Cube[0][num][i];
		for (int i = 0; i < 3; i++) Cube[0][num][i] = Cube[4][2 - i][num];
		for (int i = 0; i < 3; i++) Cube[4][i][num] = Cube[1][other_num][i];
		for (int i = 0; i < 3; i++) Cube[1][other_num][i] = Cube[5][2 - i][other_num];
		for (int i = 0; i < 3; i++) Cube[5][i][other_num] = temp[i];
		break;
	case 'B':
		for (int i = 0; i < 3; i++) temp[i] = Cube[0][num][i];
		for (int i = 0; i < 3; i++) Cube[0][num][i] = Cube[5][i][other_num];
		for (int i = 0; i < 3; i++) Cube[5][i][other_num] = Cube[1][other_num][2 - i];
		for (int i = 0; i < 3; i++) Cube[1][other_num][i] = Cube[4][i][num];
		for (int i = 0; i < 3; i++) Cube[4][i][num] = temp[2 - i];
		break;
	case 'L':
		for (int i = 0; i < 3; i++) temp[i] = Cube[0][i][num];
		for (int i = 0; i < 3; i++) Cube[0][i][num] = Cube[3][2 - i][other_num];
		for (int i = 0; i < 3; i++) Cube[3][i][other_num] = Cube[1][2 - i][num];
		for (int i = 0; i < 3; i++) Cube[1][i][num] = Cube[2][i][num];
		for (int i = 0; i < 3; i++) Cube[2][i][num] = temp[i];
		break;
	case 'R':
		for (int i = 0; i < 3; i++) temp[i] = Cube[0][i][num];
		for (int i = 0; i < 3; i++) Cube[0][i][num] = Cube[2][i][num];
		for (int i = 0; i < 3; i++) Cube[2][i][num] = Cube[1][i][num];
		for (int i = 0; i < 3; i++) Cube[1][i][num] = Cube[3][2 - i][other_num];
		for (int i = 0; i < 3; i++) Cube[3][i][other_num] = temp[2 - i];
		break;
	}
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> testcase;

	while (testcase--) {
		cin >> N;

		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++)
					Cube[i][j][k] = color[i];

		for (int i = 0; i < N; i++) {
			cin >> Curve;

			switch (Curve[0]) {	
			case 'U' : // 위
				if (Curve[1] == '+') {
					Cube_Wise(0, false); Other_face('U', 0);
				}
				else {
					Cube_Wise(0, true); Other_face('D', 0);
				}
				break;
			case 'D': // 아래
				if (Curve[1] == '+') {
					Cube_Wise(1, false); Other_face('D', 2);
				}
				else {
					Cube_Wise(1, true); Other_face('U', 2);
				}
				break;
			case 'F': // 앞
				if (Curve[1] == '+') {
					Cube_Wise(2, false); Other_face('F', 2);
				}
				else {
					Cube_Wise(2, true); Other_face('B', 2);
				}
				break;
			case 'B': // 뒤
				if (Curve[1] == '+') {
					Cube_Wise(3, false); Other_face('B', 0);
				}
				else {
					Cube_Wise(3, true); Other_face('F', 0);
				}
				break;
			case 'L': // 왼
				if (Curve[1] == '+') {
					Cube_Wise(4, false); Other_face('L', 0);
				}
				else {
					Cube_Wise(4, true); Other_face('R', 0);
				}
				break;
			case 'R': // 오
				if (Curve[1] == '+') {
					Cube_Wise(5, false); Other_face('R', 2);
				}
				else {
					Cube_Wise(5, true); Other_face('L', 2);
				}
				break;
			}
		}
		
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << Cube[0][i][j];
			}
			cout << "\n";
		}
	}
	return 0;
}