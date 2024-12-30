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
    int N, M; cin >> N >> M;
    string p = "wbwbwwbwbwbw";
    set<pair<int, int>> occr;

    occr.insert({0, 0});
    rep(i, 0, p.size()) {
        int cw = 0, cb = 0;
        rep(j, i, i + p.size()) {

            if (p[j % p.size()] == 'w') cw++;
            else cb++;
            occr.insert({cw, cb});
        }
    }
    
    while (N >= 7 and M >= 5) {
        N -= 7; M -= 5;
    }

    if (occr.contains({N, M})) cout << "Yes" << endl;
    else cout << "No" << endl;

}
