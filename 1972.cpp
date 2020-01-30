bool check;
string temp;
vector <string> vec;

void Solve() {
	for (int i = 1; i < temp.length(); i++) {
		vec.clear();
		for (int j = 0; j < temp.length(); j++) {
			if (i + j >= temp.length()) break;
			
			string s;

			s += temp[j]; s += temp[i + j];
			//cout << s;
			vec.push_back(s);
		}
		for (int j = 0; j < vec.size(); j++) 
			for (int k = j + 1; k < vec.size(); k++) 
				if (vec[j] == vec[k]) {
					check = true;
					return;
				}
	}
}

void Print() {
	cout << temp;
	if (!check) cout << " is surprising." << endl;
	else cout << " is NOT surprising." << endl;
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
}

int main() {
	init();
	
	while (1) {
		cin >> temp;

		if (temp == "*") return 0;
		check = false;
		
		Solve();
		Print();
	}
}