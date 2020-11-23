#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
using namespace std;

int tStart = 0;
bool loopCheck(pair<pii, pii> x)
{
    vector<pii> vPossible = {{1, 2}, {2, 1}, {-1, 2}, {2, -1}, {-1, -2}, {-2, -1}, {1, -2}, {-2, 1}};
    for(auto move : vPossible)
    {
        if(x.first.first - move.first == x.second.first
        && x.first.second - move.second == x.second.second)
        {
            return true;
        }
    }
    return false;
}

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
int getPossi(int x, int y, vector<vector<int>> m, vector<pii> moves)
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

vector<vector<int>> recurse(vector<vector<int>> m, int x, int y, int num, vector<pii> moves)
{
    // Time check
    if(time(0) - tStart == 2)
    {
        return {{0}};
    }

    //Fancy Algorithm
    {
        vector<pii> future(m.size());
        for(int i = 0; i < m.size(); i++)
        {
            future[i] = {getPossi( x - moves[i].first, y - moves[i].second, m, moves), i};
        }
        sort(future.begin(), future.end());
        vector<pii> memoryAbuse(0);
        for(int i = 0; i < m.size(); i++)
        {
            memoryAbuse.push_back(moves[future[i].second]);
        }
        moves = memoryAbuse;
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
    }
    return m;
}

vector<vector<int>> getKnightsMoves(int n, int x, int y)
{
    vector<pii> vPossible = {{1, 2}, {2, 1}, {-1, 2}, {2, -1}, {-1, -2}, {-2, -1}, {1, -2}, {-2, 1}};
    vector<vector<int>> m(n, vector<int>(n, -1));
    m[x][y] = 0;
    m = recurse(m, x, y, 1, vPossible);
    return m;
}

int main()
{
    int n = 0;
    cin >> n;
    vector<pii> timed;
    vector<pair<pii, pii>> paths;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            paths.push_back(pair<pii, pii>(pii(i, j), pii(-1, -1)));
            tStart = time(0);
            vector<vector<int>> m = getKnightsMoves(n, i, j);
            cout << i << "x" << j << ":\n";
            if(m.size() == 1)
            {
                cout << "Time out\n\n";
                timed.push_back(pii(i, j));
                continue;
            }
            for(int x = 0; x < m.size(); x++)
            {
                for(int y = 0; y < m.size(); y++)
                {
                    if(m[x][y] == m.size() * m.size() - 1)
                    {
                        paths[paths.size() - 1].second = {x, y};
                    }
                    cout << m[x][y] << " ";
                }
                cout << "\n";
            }
            cout << "\n";
        }
    }
    cout << "Timed out:\n";
    for(auto x : timed)
    {
        cout << x.first << "x" << x.second << "\n";
    }
    cout << "\n";

    vector<pair<pii, pii>> loops;
    cout << "Paths:\n";
    for(auto x : paths)
    {
        cout << x.first.first << "x" << x.first.second << " --> "
             << x.second.first << "x" << x.second.first << "\n";
        if(loopCheck(x))
        {
            loops.push_back(x);
        }
    }
    cout << "\n";

    cout << "Loops:\n";
    for(auto x : loops)
    {
        cout << x.first.first << "x" << x.first.second << " --> "
             << x.second.first << "x" << x.second.first << "\n";
    }
    cout << "\n";

    vector<vector<int>> loopBoard = getKnightsMoves(n, loops[0].first.first, loops[0].first.second);
    int num = 0;
    cout << "Array formated loop for use elsewhere:\n";
    cout << "{";
    for(int i = 0; i < loopBoard.size(); i++)
    {
        for(int j = 0; j < loopBoard.size(); j++)
        {
            if(loopBoard[i][j] == num)
            {
                num++;
                cout << "{" << i << ", " << j << "}" << ((num == n*n) ? "" : ",") << ((num > 0 && num % n == 0) ? "" : " ");
                i = -1;
                break;
            }
        }
        if(i == -1 && num > n - 1 && num % n == 0 && num != n*n)
        {
            cout << "\n";
        }
    }
    cout << "}\n";
}