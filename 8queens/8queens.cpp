#include <iostream>
#include <vector>
using namespace std;

vector<int> finalColumns(8, -1);

void printSolution(vector<int> fc)
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            cout << ((fc[i] == j) ? "Q" : ".") << " ";
        }
        cout << "\n";
    }
}

vector<int> diagL(15, 0);
vector<int> diagR(15, 0);
vector<int> column(8, 0);

vector<int> findSolution(int i)
{
    for(int j = 0; j < 8; j++)
    {
        if(column[j]) continue;
        if(!diagL[i-j+7] && !diagR[i + j + (i > j) * 7])
        {
            diagL[i-j+7] = 1;
            diagR[i + j + (i > j) * 7] = 1;
            column[j] = 1;
            finalColumns[i] = j;

            vector<int> temp = findSolution(i+1);
            if(temp.size() == 8) break;

            diagL[i-j+7] = 0;
            diagR[i + j + (i > j) * 7] = 0;
            column[j] = 0;
            finalColumns[i] = -1;
        }
    }
    if(finalColumns[i] == -1)
    {
        return {-1};
    }
    return finalColumns;
}

int main()
{
    findSolution(0);
    printSolution(finalColumns);
}