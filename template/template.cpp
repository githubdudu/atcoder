#include "bits/stdc++.h"
#include "atcoder/dsu.hpp"
using namespace std;
using namespace atcoder;

#define pos_module(n, mod) (n % mod + mod) % mod
#define re(i,n) for(int i = 0; i < (n); ++i)
#define rep(i, start, end) for(int i = (start); i < (end); i++)
#define repr(i, start, end) for(int i = (end); i >= (start); i--)
#define cinarr(arr, en) for(ll (i) = 0; (i) < en; (i)++){cin >> arr[i];}
#define coutarr(arr, en) for(ll (i) = 0; (i) < en; (i)++){cout << arr[i] << " \n"[i+1 == n];}
#define NO cout << "NO\n"
#define YES cout << "YES\n"
void fast(){ios_base::sync_with_stdio(false);}

int main()
{
    fast();
    int N, M; cin >> N >> M;
    int N; cin >> N;
    int A[N]; re(i, N) cin >> A[i];
    cout << N << endl;
}

void codesnippets() {
    /* bitset */
    long long C = 9999999;
    std::bitset<60> b1(C); // 
    std::bitset<60> b2{b1}; // 
    b1.count(); // get count of 1
    b1[1] = true; // getter and setter, index 0 start from right most
    b1.to_string(); b1.to_ullong(); b1.to_ulong(); //convertion
}