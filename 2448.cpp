#include<iostream>
using namespace std;
char arr[3073][6145];
int Tri(int i, int j)
{
       int p;
       arr[i][j] = arr[i][j + 1] = arr[i][j + 3] = arr[i][j + 4] = ' ';
       arr[i][j + 2] = '*';
       arr[i + 1][j] = arr[i + 1][j + 2] = arr[i + 1][j + 4] = ' ';
       arr[i + 1][j + 1] = arr[i + 1][j + 3] = '*';
       arr[i + 2][j] = arr[i + 2][j + 1] = arr[i + 2][j + 2] = arr[i + 2][j + 3] = arr[i + 2][j + 4] = '*'; 
   return 0;
}
int Tri2(int i, int j, int w, int h, int p, int q)
{
   int x, y;
   for (x = 0; x < h; x++)
   {
     for (y = 0; y < w; y++)
     {
       arr[p + x][q + y] = arr[i + x][j + y];
     }
   }
   return 0;
}
int main()
{
     int n;
     cin >> n;
     int i, j;
     int w, h, p, q;
     int x, y;
     p = n - 3;
     x = 0; 
     y = p;
     int k;
     for (i = 0; i < 3; i++)
     {
         for (j = 0; j < p; j++)
         {
             arr[i][j] = ' ';
         }
     }
     Tri(0, j);
     j += 5;
     for (i = 0; i < 3; i++)
     {    
         for (q = 0; q < p; q++)
         {
             arr[i][j + q] = ' ';
         }
     }
     w = 5; h = 3;
     for (i = 3; i < n;)
     {
          p = n - i * 2;
          for (k = 0; k < h; k++)for (j = 0; j < p; j++)arr[i + k][j] = ' ';
          Tri2(x, y, w, h, i, j); j += w;
          for (k = 0; k < h; k++)arr[i + k][j] = ' '; j += 1;
          Tri2(x, y, w, h, i, j); j += w;
 
          for (k = 0; k < h; k++)for (q = 0; q < p; q++)arr[i + k][j + q] = ' ';
          y = p;
          i += h;
          w = w * 2 + 1; h *= 2;
     }
     for (i = 0; i < n; i++)puts(arr[i]);
}