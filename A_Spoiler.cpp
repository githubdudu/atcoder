#include "bits/stdc++.h"
#include "atcoder/dsu.hpp"
using namespace std;
using namespace atcoder;

#define ll long long
#define pos_module(n, mod) (n % mod + mod) % mod
#define re(i,n) for(int i = 0; i < (n); ++i)
#define rep(i, start, end) for(int i = (start); i < (end); i++)
#define repr(i, start, end) for(int i = (end); i >= (start); i--)
#define cinarr(arr, en) for(ll (i) = 0; (i) < en; (i)++){cin >> arr[i];}
#define coutarr(arr, en) for(ll (i) = 0; (i) < en; (i)++){cout << arr[i] << " \n"[i+1 == n];}
#define NO cout << "No\n"
#define YES cout << "Yes\n"
void fast(){ios_base::sync_with_stdio(false);}
auto Cn2(ll n) {return n * (n - 1) / 2;}

/* Use (1<<n)-1 to create a bitwise 1 with length n. 
   Use (1<<i)&binary to check ith bit.
   Use (1<<i)^binary to toggle ith bit.
*/

int main()
{
    fast();
    string S; cin >> S;
    bool first_syb = false, second_syb = false;
    string ans = "";
    for(auto ch: S) {
        if (!first_syb && !second_syb) {
            if (ch == '|') {
                first_syb = true;
            } else {
                ans += ch;
            }
        } else if (first_syb && !second_syb) {
            if (ch == '|') {
                second_syb = true;
            }
        } else if (first_syb && second_syb) {
            ans += ch;
        }
    }
    cout << ans << endl;
}