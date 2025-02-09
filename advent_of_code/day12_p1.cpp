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
int N; // 10, 140
string garden[140];
bool visited[140][140];

bool valid(pair<int, int>& p) {
    int x = p.first, y = p.second;
    return (x >= 0 and x < N and y >= 0 and y < N);
}

int revise(int x, int y, char& symbol) {
    vector<pair<int, int>> v = {{0,1}, {0,-1}, {1,0}, {-1, 0}};
    int diminish = 0;
    for(auto vv: v) {
        int _x = vv.first + x;
        int _y = vv.second + y;
        if(_x >= 0 and _y >= 0 and _x < N and _y < N and garden[_x][_y] == symbol) {
            if(visited[_x][_y]) {
                diminish += 2;
            }
        }
    }
    return diminish;
}
ll bfs(int x, int y) {
    char symbol = garden[x][y];
    list<pair<int,int>> frontier; frontier.push_back({x,y});
    int area = 1;
    int peri = 4;
    visited[x][y] = true;

    while(frontier.size()) {
        auto parent = frontier.front(); frontier.pop_front();

        vector<pair<int,int>> v = {{0,1}, {0,-1}, {1,0}, {-1, 0}};
        for(auto vv: v) {
            int _x = vv.first + parent.first;
            int _y = vv.second + parent.second;
            if (_x >= 0 and _y >= 0 and _x < N and _y < N and garden[_x][_y] == symbol) {
                if(!visited[_x][_y]) {
                    peri += 4; area += 1;
                    frontier.push_back({_x, _y});
                    visited[_x][_y] = true;
                    peri -= revise(_x, _y, symbol);
                }
            }
        }
    } 
    cout << "area" << area << "peri" << peri << endl;
    return area * peri;
}
int main()
{
    fast();
    #ifndef ONLINE_JUDGE
        freopen("./input.txt", "r", stdin);
    #endif
    
    // init
    cin >> N;
    re(i, N) cin >> garden[i];
    re(i, N) {
        re(j, N) {
            visited[i][j] = false;
        }
    }

    // loop each region
    ll ans = 0;
    re(i, N) {
        re(j, N) {
            if(!visited[i][j]) {
                ll price = bfs(i, j);
                ans += price;
                // cout << garden[i][j] << price << endl;
            }
        }
    }
    
    cout << ans;
}

