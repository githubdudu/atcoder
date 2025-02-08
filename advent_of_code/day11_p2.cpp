#include "bits/stdc++.h"
using namespace std;

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

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif

/* Use (1<<n)-1 to create a bitwise 1 with length n. 
   Use (1<<i)&binary to check ith bit.
   Use (1<<i)^binary to toggle ith bit.
*/
const int N = 8; // 2, 8
unordered_map<ll, ll > stones;

bool valid(pair<int, int>& p) {
    int x = p.first, y = p.second;
    return (x >= 0 and x < N and y >= 0 and y < N);
}

int main()
{
    fast();
    #ifndef ONLINE_JUDGE
        freopen("./input.txt", "r", stdin);
    #endif
    re(i, N) {
        ll num;
        cin >> num; stones[num]++;
    }

    const int BLINK = 75;
    re(i, BLINK) {
        const int M = stones.size();
        unordered_map<ll, ll> next_stones;

        for(const auto& [num, value]: stones) {

            string num_str = to_string(num);
            if(num == 0) {
                next_stones[1] += stones[0];
            } else if(num_str.length() % 2 == 0) {
                string sub1 = num_str.substr(0, num_str.length()/ 2);
                string sub2 = num_str.substr(num_str.length()/2, num_str.length()/2);
                next_stones[stoll(sub1)] += stones[num];
                next_stones[stoll(sub2)] += stones[num];
            } else {
                next_stones[num * 2024] += stones[num];
            }
        }

        stones = next_stones;
    }
    
    ll ans = 0;
    for(const auto& [num, value]: stones) {
        ans += value;
    }
    cout << stones.size() << endl;
    cout << ans;
}

