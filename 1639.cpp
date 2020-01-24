#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

#define MAX 101

string Ticket;
int Start, End, Mid;
int arr[MAX];


void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> Ticket;

	for (int i = 0; i < Ticket.size(); i++)
		arr[i] = Ticket[i] - 48;
	
	End = (Ticket.size() % 2 == 0 ? Ticket.size() : Ticket.size() - 1) + 2;
	
	while (End > 2) {
		Start = 0; End -= 2;
		int Start_Temp = Start; int End_Temp = End;
		while (End_Temp <= Ticket.size()) {
			Mid = (Start_Temp + End_Temp) / 2;
			int Left_Value = 0; int Right_Value = 0;

			for (int i = Start_Temp; i < Mid; i++)
				Left_Value += arr[i];
			for (int i = Mid; i < End_Temp; i++)
				Right_Value += arr[i];

			if (Left_Value == Right_Value) {
				cout << End; return 0;
			}

			Start_Temp++; End_Temp++;
		}
	}
	cout << "0";
	return 0;
}