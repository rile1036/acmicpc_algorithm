#include <iostream>
#include <algorithm>
using namespace std;

int Dice[6], min_1, min_2, min_3;

int main() {
	
	long long N, sum = 0;
	cin >> N;
	for (int i = 0; i < 6; i++) cin >> Dice[i];

	if (N == 1) {
		sort(Dice, Dice + 6);
		for (int i = 0; i < 5; i++) sum += Dice[i];
	}
	else {
		Dice[0] = min(Dice[0], Dice[5]);
		Dice[1] = min(Dice[1], Dice[4]);
		Dice[2] = min(Dice[2], Dice[3]);
		sort(Dice, Dice + 3);

		min_1 = Dice[0];
		min_2 = Dice[0] + Dice[1];
		min_3 = Dice[0] + Dice[1] + Dice[2];

		sum += min_1 * ((N - 1) * (N - 2) * 4 + (N - 2) * (N - 2));
		sum += min_2 * ((N - 1) * 4 + (N - 2) * 4);
		sum += min_3 * 4;
	}
	cout << sum << endl;
	return 0;
}