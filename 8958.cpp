#include<iostream>
#include<string.h>

using namespace std;

int main(void){
    char check[80];
    int num;
    
    cin >> num;
    for(int i = 0; i < num; i++){
        int score = 1;
        int sum = 0;
        cin >> check;
        for(int j = 0; j < strlen(check); j++){
            if(check[j] == 'O'){
                sum += score;
                score++;
            }
            if(check[j] == 'X') score = 1;
        }
        cout << sum << "\n";
    }
}