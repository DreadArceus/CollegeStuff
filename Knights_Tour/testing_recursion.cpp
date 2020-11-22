#include <iostream>
using namespace std;
int recurse(int x, int y)
{
    if(y < 3)
    {
        cout << x << y << " ";
        return recurse(x, ++y);
    }
    else if(x < 3)
    {
        cout << x << y << "\n";
        int loc = recurse(++x, 1);
        if(loc == 1)
        {
            return recurse(x, 4);
        }
    }
    else
    {
        cout << x << y << "\n";
        return 1;
    }
    
}
int main()
{
    int x = 1, y = 1;
    recurse(x, y);
}
//Pointers (array, vector): change
//Local variables: destroy