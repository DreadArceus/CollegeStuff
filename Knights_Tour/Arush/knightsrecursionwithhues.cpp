#include <math.h>
#include <iostream>
#include <cstdlib>
using namespace std;
int vert[] = {2, 1, -1, -2, -2, -1, 1, 2};   //these are the 8 definite moves a knight can make on a chess board
int hori[] = {1, 2, 2, 1, -1, -2, -2, -1}; //ri stands for along right of chessboard


     int safetynet(int x ,int y,int board[8][8])//to check if a move is possible here
    {    if(x>=0&&x<8&&y>=0&&y<8&&board[x][y]==0)
           {return 1;}
      return 0;}
 
    int possibilty(int x ,int y,int board[8][8])//to check number of possibilities of next move
    {int i;
     int cnt=0;
     for(i=0;i<8;i++)
     {if(safetynet(x+vert[i],y+hori[i],board))
         {
             cnt++;
         }     
     }
return cnt;
    }
    int* prefmove(int x ,int y,int board[8][8])// creates the order of preference of next move
    {   int i,j,temp;
int order[8],counts[8];
for(i=0;i<8;i++)
{counts[i]=possibilty(x+vert[i],y+hori[i],board);
order[i]=i;}

for(i = 0; i<8; i++)//sorting
 {
   for(j = i+1; j<8; j++)
   {
      if(counts[j] < counts[i]) {
         temp = counts[i];
         counts[i] = counts[j];
         counts[j] = temp;
          temp = order[i];
         order[i] =order[j];
         order[j] = temp;

      }
   }

}

  return order;  }

int knightrecursor(int x, int y,int m,int board[8][8])
{
int new_x,new_y,i;
   if(m==64)
   {//cout<<"64";
   return 1;}
   else{int* order =prefmove(x,y,board);
     for(i = 0 ; i++ ; i < 8)
       {new_x=x+vert[*(order + i)];
       new_y=y+hori[*(order + i)];

       if(safetynet(new_x,new_y,board))
       {
       board[new_x][new_y]=m+1;
       
     
       
           if(knightrecursor(new_x,new_y,m+1,board)==1)//keep recursing till it finds soln if not it will unfold and try again
           {  
                return 1;}
           board[new_x][new_y]=0;
         
      }
      
   }
   //cout<<"unfolding"<<endl;
   }  
   return 0;
 
}
   int main()
   { int m=1;int x,y;
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
    

