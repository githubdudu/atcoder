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
#define NO cout << "No\n"
#define YES cout << "Yes\n"
void fast(){ios_base::sync_with_stdio(false);}
auto Cn2(ll n) {return n * (n - 1) / 2;}

/* Use (1<<n)-1 to create a bitwise 1 with length n. 
   Use (1<<i)&binary to check ith bit.
   Use (1<<i)^binary to toggle ith bit.
*/
int N, M, L, Q; int A[100], B[100], C[100], X[200000];
bitset<300000001> sum;
int main()
{
    fast();
    cin >> N;
    re(i, N) cin >> A[i];
    cin >> M;
    re(i, M) cin >> B[i];
    cin >> L;
    re(i, L) cin >> C[i];

    cin >> Q;
    re(i, Q) cin >> X[i];

    re(i, N) {
        re(j, M) {
            re(k, L) {
                sum[A[i] + B[j] + C[k]] = true;
            }
        }
    }

    
    re(i, Q) {
        if (sum[X[i]]) YES;
        else NO;
    }

}