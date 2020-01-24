#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int num = 0, result;
    int RGB[1000][3];
    int res[1000][3];
    cin >> num;
    for(int i = 0; i < num; i++){
        int red, green, blue;
        cin >> red >> green >> blue;
        RGB[i][0] = red;
        RGB[i][1] = green;
        RGB[i][2] = blue;
    }
    res[0][0] = RGB[0][0];
    res[0][1] = RGB[0][1];
    res[0][2] = RGB[0][2];
    
    for (int i = 1; i < num; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 0) {
                res[i][j] = RGB[i][j] + min(res[i - 1][1], res[i - 1][2]);
            }
            else if (j == 1) { 
                res[i][j] = RGB[i][j] + min(res[i - 1][0], res[i - 1][2]);
            }
            else if (j == 2) {
                res[i][j] = RGB[i][j] + min(res[i - 1][0], res[i - 1][1]);
            }
        }
    }
    
    result = res[num-1][0] < res[num-1][1] ? min(res[num-1][0], res[num-1][2]):min(res[num-1][1], res[num-1][2]);
    printf("%d\n", result);
    return 0;
}