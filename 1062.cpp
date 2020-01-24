#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int n, k, result_value;
bool visit[26];
vector<string> vec;
void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}
void brute_force()
{
    int value = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        bool check = false;
        for (int j = 0; j < vec[i].size(); j++)
        {
            if (!visit[vec[i][j] - 97])
            {
                check = true;
                break;
            }
        }
        if (!check)value++;
    }
    result_value = max(value, result_value);
}
void check_string(int alpha_num, int count)
{
    if (count == k)
    {
        brute_force();
        return;
    }
    else
    {
        for (int i = alpha_num; i < 26; i++)
        {
            if (!visit[i]) {
                visit[i] = true;
                check_string(i, count + 1);
                visit[i] = false;
            }
        }
    }
}
void precheck()
{
    visit['a' - 97] = true;
    visit['c' - 97] = true;
    visit['i' - 97] = true;
    visit['n' - 97] = true;
    visit['t' - 97] = true;
    k -= 5;
}
int main(void)
{
    init();
    string str;
    cin >> n >> k;
    precheck();
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        str.erase(str.begin(), str.begin() + 4);
        str.erase(str.end() - 4, str.end());
        vec.push_back(str);
    }
    check_string(0, 0);
    cout << result_value;
    return 0;
}