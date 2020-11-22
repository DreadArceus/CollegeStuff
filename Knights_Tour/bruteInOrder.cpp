#include <iostream>
#include <vector>
using namespace std;

bool bad = false;
bool validityCheck(vector<vector<int>> m)
{
    for(auto x : m)
    {
        for(auto y : x)
        {
            if(y == -1)
            {
                return false;
            }
        }
    }
    return true;
}

vector<vector<int>> recurse(vector<vector<int>> m, int x, int y, int num, vector<pair<int, int>> moves)
{
    for(int i = 0; i < moves.size(); i++)
    {
        if((x < m.size() + moves[i].first && y < m.size() + moves[i].second) && (x > moves[i].first - 1 && y > moves[i].second - 1)
            && m[x - moves[i].first][y - moves[i].second] == -1)
        {
            m[x - moves[i].first][y - moves[i].second] = num;
            m = recurse(m, x - moves[i].first, y - moves[i].second, num + 1, moves);
            if(!bad)
            {
                return m;
            }
            m[x - moves[i].first][y - moves[i].second] = -1;
            bad = false;
        }
    }
    if(!validityCheck(m))
    {
        bad = true;
    /*  Testing
        system("clear");
        for(vector<int> v : m)
        {
            for(int i : v)
            {
                cout << i << " ";
            }
            cout << "\n";
        } */
    }
    return m;
}

vector<vector<int>> getKnightsMoves(int n, int x, int y)
{
    vector<pair<int, int>> vPossible = {{1, 2}, {2, 1}, {-1, 2}, {2, -1}, {-1, -2}, {-2, -1}, {1, -2}, {-2, 1}};
    vector<vector<int>> m(n, vector<int>(n, -1));
    m[x][y] = 0;
    m = recurse(m, x, y, 1, vPossible);
    return m;
}

int main()
{
    int n = 0, x = 0, y = 0;
    cin >> n >> x >> y;
    vector<vector<int>> m = getKnightsMoves(n, x, y);
    
    for(vector<int> v : m)
    {
        for(int i : v)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}