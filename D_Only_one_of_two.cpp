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
ll N,M, K;
void disp(ll num){
    ll n1 = num / N * N;
    ll n2 = num / M * M;
    if (n1 != n2) cout << max(n1, n2);
    else cout << max(n1 - N, n2 - M);
}
ll gcd(ll a, ll b) {
    if (a < b) return gcd(b, a);
    if (a % b==0) return b;
    else return gcd(b, a % b);
}
int main()
{
    fast();
     cin >>N>>M>>K;
    ll left = 1, right = 1e18;
    while (left < right) {
        ll mid = (left + right) / 2;
        ll ith = mid / N + mid / M - 2 * (mid / (N*M / gcd(N, M)));
        if (ith == K) {
            disp(mid);
            return 0;
        } else if (ith > K) {
            right = mid;
        } else {
            left = mid;
        }
    }
}
