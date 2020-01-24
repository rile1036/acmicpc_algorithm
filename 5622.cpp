#include<iostream>
#include<string>

using namespace std;

int test(char alp){
    int num;
    switch(alp){
            case 'A':
        case 'B':
        case 'C':
            num = 2;
            break;
        case 'D':
        case 'E':
        case 'F':
            num = 3;
            break;
        case 'G':
        case 'H':
        case 'I':
            num = 4;
            break;
            
        case 'J':
        case 'K':
        case 'L':
            num = 5;
            break;
            
        case 'M':
        case 'N':
        case 'O':
            num = 6;
            break;
            
        case 'P':
        case 'Q':
        case 'R':
        case 'S':
            num = 7;
            break;
            
        case 'T':
        case 'U':
        case 'V':
            num = 8;
            break;
            
        case 'W':
        case 'X':
        case 'Y':
        case 'Z':
            num = 9;
            break;
            
        default:
            break;
    }
    return num;
}

int main(void){
    int sum = 0;
    string line;
    cin >> line;
    for(int i = 0; i < line.length(); i++){
        if(line[i] == 0) sum += 0;
        else if(line[i] == 1) sum += 1;
        else sum += test(line[i]);
    }
    sum += (int)line.length();
    cout << sum;
}