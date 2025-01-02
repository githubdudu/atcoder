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
string T;
int N, A;
vector<string> S[100];
map<pair<int, int>, int> cache;

int solve(int idx_a, int idx_t) {
    if (idx_t == (int) T.size()) return 0;
    if (idx_a >= N) return 101;
    if (cache.contains({idx_a, idx_t})) return cache[{idx_a, idx_t}];
    
    int ans = 101;
    re(i, S[idx_a].size()) {
        string sub_str = S[idx_a][i];
        int new_len = sub_str.size() + idx_t;
        if (new_len <= (int) T.size()) {
            if (T.substr(idx_t, sub_str.size()) == sub_str) {
                int ans2 = 1 + solve(idx_a + 1, new_len);

                if (ans2 < ans) ans = ans2;
            }
        }
    }
    auto ans2 = solve(idx_a + 1, idx_t);
    if (ans2 < ans) ans = ans2;
    cache[{idx_a, idx_t}] = ans;
    return ans;
}

int main()
{
    fast();
    cin >> T; cin >> N;
    
    re(i, N) {
        cin >> A;
        re(j, A) {
            string sub_str; cin >> sub_str;
            S[i].push_back(sub_str);
        }
    }
    int ans = solve(0, 0);
    if (ans >= 101) cout << -1 << endl;
    else cout << ans << endl;
}