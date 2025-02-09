#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define pos_module(n, mod) (n % mod + mod) % mod
#define re(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, start, end) for (int i = (start); i < (end); i++)
#define repr(i, start, end) for (int i = (end); i >= (start); i--)
#define cinarr(arr, en)                 \
    for (ll(_i) = 0; (_i) < en; (_i)++) \
    {                                   \
        cin >> arr[_i];                 \
    }
#define coutarr(arr, en)                        \
    for (ll(_i) = 0; (_i) < en; (_i)++)         \
    {                                           \
        cout << arr[_i] << " \n"[_i + 1 == en]; \
    }
#define NO cout << "No\n"
#define YES cout << "Yes\n"
void fast() { ios_base::sync_with_stdio(false); }
auto Cn2(ll n) { return n * (n - 1) / 2; }

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

bool valid(pair<int, int> &p)
{
    int x = p.first, y = p.second;
    return (x >= 0 and x < N and y >= 0 and y < N);
}

int count_sides(map<int, vector<int>> borders_verti)
{
    int sides = 0;
    set<int> b;
    for(auto& [key, values]: borders_verti) {
        for(auto v : values) {
            if(!b.contains(v)) sides += 1;
        }

        // a new b
        b.clear();
        for(int v: values) b.insert(v);
    }
    return sides * 2;
}
ll bfs(int x, int y)
{
    char symbol = garden[x][y];
    list<pair<int, int>> frontier;
    frontier.push_back({x, y});
    int area = 1;

    visited[x][y] = true;

    map<int, vector<int>> borders_verti;
    while (frontier.size())
    {
        auto parent = frontier.front();
        frontier.pop_front();
        auto [_x, _y] = parent;
        // left
        if (_x == 0 or garden[_x - 1][_y] != symbol)
        {
            borders_verti[_y].push_back(_x);
        }
        else if (garden[_x - 1][_y] == symbol)
        {
            if (!visited[_x - 1][_y])
            {
                area += 1;
                frontier.push_back({_x - 1, _y});
                visited[_x - 1][_y] = true;
            }
        }

        if (_x == N - 1 or garden[_x + 1][_y] != symbol)
        {
            borders_verti[_y].push_back(-_x - 1);
        }
        else if (garden[_x + 1][_y] == symbol)
        {
            if (!visited[_x + 1][_y])
            {
                area += 1;
                frontier.push_back({_x + 1, _y});
                visited[_x + 1][_y] = true;
            }
        }

        if (_y == 0 or garden[_x][_y - 1] != symbol)
        {
            
        }
        else if (garden[_x][_y - 1] == symbol)
        {
            if (!visited[_x][_y - 1])
            {
                area += 1;
                frontier.push_back({_x, _y - 1});
                visited[_x][_y - 1] = true;
            }
        }

        if (_y == N - 1 or garden[_x][_y + 1] != symbol)
        {
            
        }
        else if (garden[_x][_y + 1] == symbol)
        {
            if (!visited[_x][_y + 1])
            {
                area += 1;
                frontier.push_back({_x, _y + 1});
                visited[_x][_y + 1] = true;
            }
        }
    }
    int peri = count_sides(borders_verti);

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
    re(i, N)
    {
        re(j, N)
        {
            visited[i][j] = false;
        }
    }

    // loop each region
    ll ans = 0;
    re(i, N)
    {
        re(j, N)
        {
            if (!visited[i][j])
            {
                ll price = bfs(i, j);
                ans += price;
                // cout << garden[i][j] << price << endl;
            }
        }
    }

    cout << ans;
}
