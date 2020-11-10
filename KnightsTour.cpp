#include <iostream>
#include <vector>
using namespace std;

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

vector<vector<int>> recurse(vector<vector<int>> m, int x, int y, int num)
{
    if((x > 0 && y > 1) && m[x - 1][y - 2] == -1)
    {
        m[x - 1][y - 2] = num;
        auto loc = recurse(m, x - 1, y - 2, num + 1);
        if(loc[0][0] != -1)
        {
            return loc;
        }
    }
    if((y > 1 && x < m.size() - 1) && m[x + 1][y - 2] == -1)
    {
        m[x + 1][y - 2] = num;
        auto loc = recurse(m, x + 1, y - 2, num + 1);
        if(loc[0][0] != -1)
        {
            return loc;
        }
    }
    if((x > 0 && y < m.size() - 2) && m[x - 1][y + 2] == -1)
    {
        m[x - 1][y + 2] = num;
        auto loc = recurse(m, x - 1, y + 2, num + 1);
        if(loc[0][0] != -1)
        {
            return loc;
        }
    }
    if((x < m.size() - 1 && y < m.size() - 2) && m[x + 1][y + 2] == -1)
    {
        m[x + 1][y + 2] = num;
        auto loc = recurse(m, x + 1, y + 2, num + 1);
        if(loc[0][0] != -1)
        {
            return loc;
        }
    }
    if((x > 1 && y > 2) && m[x - 2][y - 1] == -1)
    {
        m[x - 2][y - 1] = num;
        auto loc = recurse(m, x - 2, y - 1, num + 1);
        if(loc[0][0] != -1)
        {
            return loc;
        }
    }
    if((x < m.size() - 2 && y > 0) && m[x + 2][y - 1] == -1)
    {
        m[x + 2][y - 1] = num;
        auto loc = recurse(m, x + 2, y - 1, num + 1);
        if(loc[0][0] != -1)
        {
            return loc;
        }
    }
    if((x > 1 && y < m.size() - 1) && m[x - 2][y + 1] == -1)
    {
        m[x - 2][y + 1] = num;
        auto loc = recurse(m, x - 2, y + 1, num + 1);
        if(loc[0][0] != -1)
        {
            return loc;
        }
    }
    if((x < m.size() - 2 && y < m.size() - 1) && m[x + 2][y + 1] == -1)
    {
        m[x + 2][y + 1] = num;
        auto loc = recurse(m, x + 2, y + 1, num + 1);
        if(loc[0][0] != -1)
        {
            return loc;
        }
    }
    if(!validityCheck(m))
    {
        m[0][0] = -1;
    }
    return m;
}

vector<vector<int>> getKnightsMoves(int n, int x, int y)
{
    vector<vector<int>> m(n, vector<int>(n, -1));
    m[x][y] = 0;
    m = recurse(m, x, y, 1);
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