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
#define NO cout << "NO\n"
#define YES cout << "YES\n"
void fast(){ios_base::sync_with_stdio(false);}

int main()
{
    fast();
    ll N; string S; cin >> N >> S;
    ll Ci[N]; re(i, N) cin >> Ci[i];

    ll cost0[N], cost1[N];
    // the sum of cost left to index i
    if (S[0] == '0') {
        cost0[0] = 0; cost1[0] = Ci[0]; 
    } else {
        cost0[0] = Ci[0]; cost1[0] = 0;
    }

    rep(i, 1, N) {
        if (S[i] == '0') {
            cost0[i] = cost1[i - 1];
            cost1[i] = cost0[i - 1] + Ci[i];
        } else {
            cost0[i] = cost1[i - 1] + Ci[i];
            cost1[i] = cost0[i - 1];
        }
    }

    ll ans = 0; for (auto& num : Ci) ans += num;

    rep(i, 1, N) {
        // 00
        ll cost;
        if ((N - 1 - i) % 2 == 0) {
            cost = cost0[i - 1] + cost0[N - 1] - cost1[i - 1];
        } else {
            cost = cost0[i - 1] + cost1[N - 1] - cost1[i - 1];
        }
        ans = min(ans, cost);
        // 11
        if ((N - 1 - i) % 2 == 0) {
            cost = cost1[i - 1] + cost1[N - 1] - cost0[i - 1];
        } else {
            cost = cost1[i - 1] + cost0[N - 1] - cost0[i - 1];
        }
        ans = min(ans, cost);
    }
    cout << ans << endl;
    

}