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

int main()
{
    fast();
    int N, M; cin >> N >> M;
    int N; cin >> N;
    int A[N]; re(i, N) cin >> A[i];
    cout << N << endl;
}

map<char, ll> iter_to_map(string& S) {
    map<char, ll> m; for (auto ele: S) m[ele]++;
    return m;
}

set<char> iter_to_set(string& S) {
    return std::set<char> (S.begin(), S.end());
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