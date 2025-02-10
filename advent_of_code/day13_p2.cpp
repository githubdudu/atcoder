#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define pos_module(n, mod) (n % mod + mod) % mod
#define re(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, start, end) for (int i = (start); i < (end); i++)
#define repr(i, start, end) for (int i = (end); i >= (start); i--)
#define cinarr(arr, en)                 \
    for (ll(_i) = 0; (_i) < en; (_i)++) \
    {                                   \
        cin >> arr[_i];                 \
    }
#define coutarr(arr, en)                        \
    for (ll(_i) = 0; (_i) < en; (_i)++)         \
    {                                           \
        cout << arr[_i] << " \n"[_i + 1 == en]; \
    }
#define NO cout << "No\n"
#define YES cout << "Yes\n"
void fast() { ios_base::sync_with_stdio(false); }
auto Cn2(ll n) { return n * (n - 1) / 2; }

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif

/* Use (1<<n)-1 to create a bitwise 1 with length n.
   Use (1<<i)&binary to check ith bit.
   Use (1<<i)^binary to toggle ith bit.
*/
int N; //
int main()
{
    fast();
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
#endif

    // init
    ll ans = 0;
    cin >> N;
    re(i, N)
    {
        pair<double, double> A, B, target;
        cin >> A.first >> A.second;
        cin >> B.first >> B.second;
        cin >> target.first >> target.second;

        cout << A.first << " " << A.second << B.first << " " << B.second << target.first << target.second << endl;

        target.first += 1e13;
        target.second += 1e13;
        // try every machine
        double x = (target.first * B.second - target.second * B.first) / (A.first * B.second - A.second * B.first);
        double y = (target.first * A.second - target.second * A.first) / (B.first * A.second - B.second * A.first);
        if (x == (ll)x and y == (ll)y) {
            ans += x * 3 + y;
        }
    }

    cout << ans;
}
