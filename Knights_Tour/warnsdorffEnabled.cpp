#include <iostream>
#include <vector>
#include <algorithm>
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

int getPossi(int x, int y, vector<vector<int>> m, vector<pair<int, int>> moves)
{
    int cnt = 0;
    for(int i = 0; i < moves.size(); i++)
    {
        if((x < m.size() + moves[i].first && y < m.size() + moves[i].second) && (x > moves[i].first - 1 && y > moves[i].second - 1)
            && m[x - moves[i].first][y - moves[i].second] == -1)
        {
            cnt++;
        }
    }
    return cnt;
}

vector<vector<int>> recurse(vector<vector<int>> m, int x, int y, int num, vector<pair<int, int>> moves)
{
    //Fancy Algorithm
    {
        vector<pair<int, int>> future(m.size());
        for(int i = 0; i < m.size(); i++)
        {
            future[i] = {getPossi( x - moves[i].first, y - moves[i].second, m, moves), i};
        }
        sort(future.begin(), future.end());
        vector<pair<int, int>> memoryAbuse(0);
        for(int i = 0; i < m.size(); i++)
        {
            memoryAbuse.push_back(moves[future[i].second]);
        }
        moves = memoryAbuse;
    /*  Testing
        bool dump;
        cin >> dump;
        for(int i = 0; i < m.size(); i++)
        {
            cout << future[i].first << ":" << future[i].second << " ";
        }
        cout << "\n";
        for(int i = 0; i < m.size(); i++)
        {
            cout << moves[i].first << "," << moves[i].second << " ";
        }
        cout << endl; */
    }
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
        system("clear");
        for(vector<int> v : m)
        {
            for(int i : v)
            {
                cout << i << " ";
            }
            cout << "\n";
        }
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