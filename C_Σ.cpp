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
    ios_base::sync_with_stdio(false);

    long long N, K; cin >> N >> K;
    int Ai[N]; re(i, N) { cin >> Ai[i];}

    sort(Ai, Ai + N);
    auto ans = (1 + K) * K / 2;
    rep(i, 1, N) {
        if (Ai[i] != Ai[i - 1] and Ai[i] <= K) ans -= Ai[i];
    }
    if (Ai[0] <= K) ans -= Ai[0];
    cout << ans << endl;
}
