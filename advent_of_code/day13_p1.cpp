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
bool valid(pair<int, int> &p)
{
    int x = p.first, y = p.second;
    return (x >= 0 and x < N and y >= 0 and y < N);
}


int main()
{
    fast();
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
#endif

    // init
    ll ans = 0;
    cin >> N;
    re(i, N) {
        pair<int, int> A, B, target;
        cin >> A.first >> A.second;
        cin >> B.first >> B.second;
        cin >> target.first >> target.second;

        cout << A.first << " " <<  A.second << B.first << " " << B.second << target.first << target.second << endl;

        // try every machine
        for(int k = 0; k < 101; k++) {
            double temp_x = target.first - B.first * k;
            double temp_y = target.second - B.second * k;
            double count_x = temp_x / A.first;
            double count_y = temp_y / A.second;

            if (count_x == count_y and (int)count_x == count_x) {
                ans += (int)count_x * 3 + k;
                break;
            }
            
        }
    }

    cout << ans; 
}
