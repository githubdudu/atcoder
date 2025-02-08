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
bool valid(pair<int, int>& p, vector<pair<int,int>>& stack) {
    int x = p.first, y = p.second;
    if (!(x >= 0 and x < N and y >= 0 and y < N)) {
        return false;
    }

    return find(stack.begin(), stack.end(), p) == stack.end();
}
int count_score(int x, int y) {
    vector<pair<int,int>> stack;
    stack.push_back({x,y});
    for(int i='1'; i != '9'+1; i++) {
        if(stack.size() == 0) return 0;

        vector<pair<int,int>> new_stack;
        for(auto pos: stack) {
            pair<int, int> up_n = {pos.first - 1, pos.second};
            if(valid(up_n, new_stack) and trails[up_n.first][up_n.second] == i) {
                new_stack.push_back(up_n);
            }
            pair<int, int> down_n = {pos.first + 1, pos.second};
            if(valid(down_n, new_stack) and trails[down_n.first][down_n.second] == i) {
                new_stack.push_back(down_n);
            }
            pair<int, int> left_n = {pos.first, pos.second - 1};
            if(valid(left_n, new_stack) and trails[left_n.first][left_n.second] == i) {
                new_stack.push_back(left_n);
            }
            pair<int, int> right_n = {pos.first, pos.second + 1};
            if(valid(right_n, new_stack) and trails[right_n.first][right_n.second] == i) {
                new_stack.push_back(right_n);
            }
        }
        stack = new_stack;

    }
    return stack.size();
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
                ans += count_score(i, j);
            }
        }
    }
    re(i, N) cout << trails[i] << endl;
    cout << ans;
}

