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
const int N = 55; // 55, 8
string trails[N];

int char_to_int(char ch) {
    return ch - '0';
}
bool valid(pair<int, int>& p) {
    int x = p.first, y = p.second;
    return (x >= 0 and x < N and y >= 0 and y < N);
}

int dfs(char ch, pair<int, int> pos) {
    if (ch == '9') return 1;

    char next_ch = ch + 1;
    int ans = 0;
    pair<int, int> up_n = {pos.first - 1, pos.second};
    if(valid(up_n) and trails[up_n.first][up_n.second] == next_ch) {
        ans += dfs(next_ch, up_n);
    }
    pair<int, int> down_n = {pos.first + 1, pos.second};
    if(valid(down_n) and trails[down_n.first][down_n.second] == next_ch) {
        ans += dfs(next_ch, down_n);
    }
    pair<int, int> left_n = {pos.first, pos.second - 1};
    if(valid(left_n) and trails[left_n.first][left_n.second] == next_ch) {
        ans += dfs(next_ch, left_n);
    }
    pair<int, int> right_n = {pos.first, pos.second + 1};
    if(valid(right_n) and trails[right_n.first][right_n.second] == next_ch) {
        ans += dfs(next_ch, right_n);
    }
    return ans;
}

int main()
{
    fast();
    #ifndef ONLINE_JUDGE
        freopen("./input.txt", "r", stdin);
    #endif
    re(i, N) cin >> trails[i];
    int ans = 0;
   
    re(i, N) {
        re (j, N) {
            if(trails[i][j] == '0') {
                ans += dfs('0', {i, j});
            }
        }
    }
    re(i, N) cout << trails[i] << endl;
    cout << ans;
}

