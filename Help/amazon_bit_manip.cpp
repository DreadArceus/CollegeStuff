#include <iostream>
using namespace std;
int solve(int n)
{
    int ans = 0;
    int len = 1, temp_n = n;
    while(temp_n > 1)
    {
        temp_n /= 2;
        len++;
    }
    for(int i = 0; i < len; i++)
    {
        ans += (__builtin_powf(2, i)) * ( (n + 1) / int(__builtin_powf(2, i + 1)) );
        int extra = (n + 1) % int(__builtin_powf(2, i + 1)) - __builtin_powf(2, i);
        if(extra > 0)
        {
            ans += extra;
        }
    }
    return ans;
}
int main()
{
    int n = 0;
    cin >> n;
    int ans = solve(n);
    cout << ans;
}