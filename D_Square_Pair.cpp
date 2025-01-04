#include "bits/stdc++.h"
#include "atcoder/dsu.hpp"
using namespace std;
using namespace atcoder;

#define ll long long
#define pos_module(n, mod) (n % mod + mod) % mod
#define re(i,n) for(int i = 0; i < (n); ++i)
#define rep(i, start, end) for(int i = (start); i < (end); i++)
#define repr(i, start, end) for(int i = (end); i >= (start); i--)
#define cinarr(arr, en) for(ll (_i) = 0; (_i) < en; (_i)++){cin >> arr[_i];}
#define coutarr(arr, en) for(ll (_i) = 0; (_i) < en; (_i)++){cout << arr[_i] << " \n"[_i+1 == en];}
#define NO cout << "No\n"
#define YES cout << "Yes\n"
void fast(){ios_base::sync_with_stdio(false);}
auto Cn2(ll n) {return n * (n - 1) / 2;}

/* Use (1<<n)-1 to create a bitwise 1 with length n. 
   Use (1<<i)&binary to check ith bit.
   Use (1<<i)^binary to toggle ith bit.
*/
const int MAX_N = 200000;
int N;
unordered_set<ll> sqr_set;
int nums[MAX_N];

int main()
{
    re(i, MAX_N) {
        ll sqr_num = pow(i + 1, 2);
        if (sqr_num > MAX_N) break;
        sqr_set.insert(sqr_num);
    }

    ll ans = 0;
    cin >> N; re(i, N) cin >> nums[i];
    sort(nums, nums + N);
    unordered_map<ll, ll> count;

    int max_sqr;

    rep(i, 0, N) {
        int v = nums[i];
        // number 0
        if (v == 0) {ans += N - 1 - i; continue;}

        if (i > 0 and v == nums[i - 1]) {
            count[v/max_sqr]++;
            continue;
        }

        max_sqr = 1;
        // non square number
        rep(j, 1, pow(v, 0.5) + 1) {
            float div = (float) v / j;
            if ((int) div == div and sqr_set.contains(div) and div > max_sqr) {
                max_sqr = div;
            }
            if ((int) div == div and sqr_set.contains(j) and j > max_sqr) {
                max_sqr = j;
            }
        }
        count[v/max_sqr]++;
    }
    for(auto it: count) {
        ans+= it.second * (it.second - 1) / 2;
    }
    cout << ans << endl;

}