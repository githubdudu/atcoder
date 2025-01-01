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

auto Cn2(ll n) {return n * (n - 1) / 2;}

int main()
{
    fast();
    string S; cin >> S;
    
    map<char, int> abc;
    for (auto ch: S) abc[ch]++;
    
    ll ans = Cn2(S.size());
    if (abc.size() < S.size()) {
        ans++;
        for(const auto& p: abc) ans -= Cn2(p.second);
        cout << ans << endl;
    } else {
        cout << ans << endl;
    }
}
