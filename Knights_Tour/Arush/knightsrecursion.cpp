#include <math.h>
#include <iostream>
#include <cstdlib>
using namespace std;
int vert[] = {2, 1, -1, -2, -2, -1, 1, 2};   //these are the 8 definite moves a knight can make on a chess board
int hori[] = {1, 2, 2, 1, -1, -2, -2, -1}; //ri stands for along right of chessboard

int x, y,m=1;
int safetynet(int x ,int y,int board[8][8])
{if(x>=0&&x<8&&y>=0&&y<8&&board[x][y]==0)
{return 1;}
 return 0;}

int knightrecursor(int x, int y,int m,int board[8][8])
{
int new_x,new_y,i;
   if(m==64)
   {//cout<<"64";
   return 1;}
   else{
   for(i=0;i<8;i++)
   {int l,n;
       new_x=x+vert[i];
       new_y=y+hori[i];
       //cout<<m<<endl;

       if(safetynet(new_x,new_y,board))
       {m++;
       board[new_x][new_y]=m;
       
     /*  for (l = 0; l < 8; l++)
      {  for (n = 0; n < 8; n++)
        {
            cout << board[l][n] << "  ";
        }
        cout << endl;
       }*/
       
           if(knightrecursor(new_x,new_y,m,board)==1)//keep recursing till it finds soln if not it will unfold and try again
           {   return 1;}
           board[new_x][new_y]=0;//backtracking
           m--;
      }
      
   }
//cout<<"unfolding"<<endl;
   }
   return 0;
}
int main()
{
int board[8][8];
    for (x = 0; x < 8; x++) //for loop cleans board and fills it with zeros
    {
        for (y = 0; y < 8; y++)
        {
            board[x][y] = 0;
        }
    }

  

    char ch;

    cout << "Enter initial position";
    cin >> x >> y;
   board[x][y]=1;
    knightrecursor(x, y,m,board);

    for (x = 0; x < 8; x++) //printing the final chessboard with tracked movement of knight
    {
        for (y = 0; y < 8; y++)
        {
            cout << board[x][y] << "  ";
        }
        cout << endl;
    }

    cin >> ch;
    return 0;
}
