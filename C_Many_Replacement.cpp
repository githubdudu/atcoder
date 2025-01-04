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

int main()
{
    fast();
    int N, Q; string S;
    cin >> N >> S >> Q;
    int root[26]; re(i, 26) root[i] = i;
    int INDEX_M = (int)'a';

    re(i, Q) {
        char c, d;
        cin >> c >> d;
        if (c == d) continue;
        else {
            int c_id = (int) c - INDEX_M, d_id = (int) d - INDEX_M;
            re(i, 26) if (root[i] == c_id) root[i] = d_id;
        }
    }

    re(i, S.size()) {
        cout << (char) (root[(int)S[i] - INDEX_M] + INDEX_M);
    }

    
}
