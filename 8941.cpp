#include <iostream>
#include <string>
using namespace std;

int main(void)
{
   int num;
   double sum;
   string s;
   string temp;
   char a;
   int x;
   cin >> num;
   for (int i = 0; i < num; i++)
   {
      sum = 0.0;
      cin >> s;
      for (int j = 0; j < s.length(); j++)
      {
         
         if (s[j] == 'C' && s[j+1] >='A' && s[j+1] <='Z' || s[j]=='C' && s[j+1] =='\0')
         {
            sum += 12.010;
         }
         else if (s[j] == 'H' && s[j+1] >='A' && s[j+1] <='Z'|| s[j]=='H' && s[j+1]=='\0')
         {
            sum += 1.008;
         }
         else if (s[j] == 'O' && s[j+1] >='A' && s[j+1] <='Z' || s[j] == 'O' && s[j+1]=='\0')
         {
            sum += 16.000;
         }
         else if (s[j] == 'N' && s[j+1] >='A' && s[j+1]<='Z'|| s[j]=='N' && s[j+1] =='\0')
         {
            sum += 14.010;
         }
         else if (s[j] >= '0' && s[j] <= '9')
         {
            temp.erase();
            a = s[j - 1];
            x = j;
            while (s[x] >= '0' && s[x] <= '9')
            {
               temp += s[x];
               x++;
            }
            if (a == 'C')
            {
               sum += 12.010 * stoi(temp);
            }
            else if (a == 'H')
            {
               sum += 1.008 * stoi(temp);
            }
            else if (a == 'O')
            {
               sum += 16.000 * stoi(temp);
            }
            else if (a == 'N')
            {
               sum += 14.010 * stoi(temp);
            }
         }
      }
      cout << fixed;
      cout.precision(3);
      cout << sum << '\n';
   }
   return 0;
}