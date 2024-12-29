#include "bits/stdc++.h"
#include "atcoder/dsu.hpp"
using namespace std;
using namespace atcoder;

#define pos_module(n, mod) (n % mod + mod) % mod
#define rep(i, start, end) for(int i = start; i < (end); i++)
#define repr(i, start, end) for(int i = end; i >= (start); i--)

int popc(double num) {
    return std::bitset<64>(num).count();
}

int main()
{
    int a, b;
    long long C;
    cin >> a >> b >> C;
    
    std::bitset<60> b1(C), n1(C), n2(C);

    if (a + b < b1.count()) {
        cout << -1 << endl;
        return 0;
    }
    int same = a + b - b1.count();
    if (same % 2 != 0 or same / 2 > 60 - b1.count()) {
        cout << -1 << endl;
        return 0;
    }
    int ac = a - same / 2 ;
    int bc = b - same / 2 ;
    same = same / 2;
    if (ac < 0 or bc < 0) {
        cout << -1 << endl;
        return 0;
    }
    rep(i, 0, 60) {
        if (b1[i]) {
            if (bc > 0) {
                n2[i] = true; n1[i] = false; bc--;

            } else if (ac > 0) {
                n1[i] = true; n2[i] = false; ac--;
            }
        }
    }
    rep(i, 0, 60) {
        if (!b1[i]) {
            if (same > 0) {
                n1[i] = true; n2[i] = true; same--;
            }
        }
    }

    // cout << n1  << " " << n2 << endl;
    
    cout << n1.to_ullong() << " " << n2.to_ullong() << endl;

}