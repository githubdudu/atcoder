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
    int N; cin >> N;
    int A[N]; re(i, N) cin >> A[i];
    re(i, N - 1) cout << A[i] * A[i + 1] << " ";
}