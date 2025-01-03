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
ll N, T;

int main()
{
    fast();
    cin >> N >> T;
    
    ll count[N + 1]; re(i, N+1) count[i]=0;
    unordered_map<ll, int> ans_map; ans_map[0] = N;
    vector<vector<int>> c(T, vector<int>(2));
    re(i, T) cin >> c[i][0] >> c[i][1]; 
    re(i, T) {
        ll prev = count[c[i][0]];
        count[c[i][0]] += c[i][1];
        ll curr = count[c[i][0]];

        ans_map[prev]--;
        ans_map[curr]++;
        if(ans_map[prev] == 0){
            ans_map.erase(prev);
        }
        cout << ans_map.size() << endl;
    }
}