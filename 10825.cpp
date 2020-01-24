#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

struct S_Score{
	int K_score;
	int E_score;
	int M_score;
	string name;
};

bool compare(const S_Score &a, const S_Score &b){
	if (a.K_score > b.K_score)	return true;
	else if (a.K_score == b.K_score){
		if (a.E_score < b.E_score)	return true;
		else if (a.E_score == b.E_score){
			if (a.M_score > b.M_score)	return true;
			else if (a.M_score == b.M_score){
				if (a.name < b.name)	return true;	
			}
		}
	}
	return false;
}

int main()
{
	int Case;
	cin >> Case;
	vector<S_Score> v(Case);
	for (int i = 0; i < Case; i++){
		cin >> v[i].name >> v[i].K_score >> v[i].E_score >> v[i].M_score;
	}
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < Case; i++){
		cout << v[i].name << "\n";
	}

	return 0;
}