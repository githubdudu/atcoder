#include "bits/stdc++.h"
#include "atcoder/dsu.hpp"
using namespace std;
using namespace atcoder;
#define llint long long 
#define vv vector<vector<llint>>

int main()
{
    llint L = 0, R = 0;
    cin >> L >> R;
    vv ans;
    while (L < R) {
        llint sl = L, step = 1;
        while ((sl & 1) == 0 and L + step * 2 <= R) { sl /= 2; step *= 2; }
        ans.push_back({L, L + step});
        L += step; step = 1;
    }
    cout << ans.size() << endl;
    for (auto &i : ans) cout << i[0] << " " << i[1] << endl;
}
