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
int H,W,N; string T; string S[500];
bool search(int i, int j) {
    for(auto ch: T) {

        if (ch == 'U') {i -= 1;} 
        else if (ch == 'D') i += 1;
        else if (ch == 'L') j -= 1;
        else j += 1;

        if (i < 0 or i >= H or j < 0 or j >= W) return false;
        if (S[i][j] != '.') return false;
    }
    return true;
}

int main()
{
    fast();
     cin >>H>>W>>N;
     cin >>T;
    
    re(i, H) cin>>S[i];

    int ans = 0;
    re(i, H) {
        re(j, W){
            if(S[i][j] =='.') {
                bool p = search(i, j);
                ans += p ? 1 : 0;
            }
        }
    }
    cout << ans  << endl;
}
