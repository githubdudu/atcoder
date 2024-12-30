#include "bits/stdc++.h"
#include "atcoder/dsu.hpp"
using namespace std;
using namespace atcoder;

#define pos_module(n, mod) (n % mod + mod) % mod
#define re(i,n) for(int i = 0; i < (n); ++i)
#define rep(i, start, end) for(int i = (start); i < (end); i++)
#define repr(i, start, end) for(int i = (end); i >= (start); i--)
int main()
{
    long long N, K; cin >> N >> K;
    set<int> Ai; re(i, N) {int a; cin >> a; Ai.insert(a);}

    auto ans = (1 + K) * K / 2;
    for(auto a: Ai) {
        if (a >= 1 and a <= K) ans -= a;
    }
    cout << ans << endl;
}
