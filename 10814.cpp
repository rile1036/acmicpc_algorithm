#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, string>> vec;

bool cmp(pair<int, string> a, pair<int, string> b){
    if (a.first < b.first)
         return true;
    else if (a.first == b.first)
        return false;
    return false;
}

int main(void){
    cin >> N;

    vec.resize(N);

    for (int i = 0; i < N; i++)
        cin >> vec[i].first >> vec[i].second;
    
    stable_sort(vec.begin(), vec.end(), cmp);
        
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i].first << " " << vec[i].second << "\n";

    return 0;
}