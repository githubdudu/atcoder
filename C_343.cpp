#include "bits/stdc++.h"
#include "atcoder/dsu.hpp"
using namespace std;
using namespace atcoder;

#define ll long long
#define pos_module(n, mod) (n % mod + mod) % mod
#define re(i,n) for(int i = 0; i < (n); ++i)
#define rep(i, start, end) for(int i = (start); i < (end); i++)
#define repr(i, start, end) for(int i = (end); i >= (start); i--)
#define cinarr(arr, en) for(ll (_i) = 0; (_i) < en; (_i)++){cin >> arr[_i];}
#define coutarr(arr, en) for(ll (_i) = 0; (_i) < en; (_i)++){cout << arr[_i] << " \n"[_i+1 == en];}
#define NO cout << "No\n"
#define YES cout << "Yes\n"
void fast(){ios_base::sync_with_stdio(false);}
auto Cn2(ll n) {return n * (n - 1) / 2;}

/* Use (1<<n)-1 to create a bitwise 1 with length n. 
   Use (1<<i)&binary to check ith bit.
   Use (1<<i)^binary to toggle ith bit.
*/
ll N;

bool pali(ll num) {
    string str = to_string(num);
    int l = 0, r = str.length() - 1;
    while (l < r) {
        if (str[l] == str[r]) {l++; r--;}
        else return false;
    }
    return true;
}
int main()
{
    fast();
    cin >> N;
    int ans = pow(N, 1.0/3) + 1;
    while (true)
    {
        ll pow3 = pow(ans, 3);
        if (pow3 <= N and pali(pow3)) {
            cout << pow3 << endl;
            return 0;
        } else {
            ans--;
        }
    }
}