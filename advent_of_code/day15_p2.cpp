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
int N1, N2, N3;
char matrix[50][100];

pair<int, int> move_robot(pair<int, int> posi, pair<int, int> v)
{
    auto temp = posi;
    temp.first += v.first, temp.second += v.second;
    while (true)
    {
        if (matrix[temp.first][temp.second] == '[' or matrix[temp.first][temp.second] == ']')
        {
            temp.first += v.first, temp.second += v.second;
            continue;
        }
        else
        {
            if (matrix[temp.first][temp.second] == '#')
            {
                return posi;
            }
            else
            {
                // copy
                while (true)
                {
                    if (matrix[temp.first][temp.second] == '@')
                    {
                        matrix[temp.first][temp.second] = '.';
                        break;
                    }
                    matrix[temp.first][temp.second] = matrix[temp.first - v.first][temp.second - v.second];
                    temp.first -= v.first, temp.second -= v.second;
                }
                return {posi.first + v.first, posi.second + v.second};
            }
        }
    }

    return posi;
}

bool any_fence(set<vector<int>> row, pair<int, int> v)
{
    bool pre = false;
    for (auto ele : row)
    {
        if (matrix[ele[0] + v.first][ele[1] + v.second] == '#')
        {
            return true;
        }
        if (matrix[ele[0]][ele[1]] != '@' and matrix[ele[0]+v.first][ele[1]+v.second+1] == '#') {
            return true;
        }
    }
    return false;
}
set<vector<int>> next_row(set<vector<int>> row, pair<int, int> v)
{
    set<vector<int>> nr;
    for (auto ele : row)
    {
        int x = ele[0] + v.first, y = ele[1] + v.second;
        if (matrix[x][y] == '[')
        {
            nr.insert({x, y});
        }
        else if (matrix[x][y] == ']')
        {
            nr.insert({x, y - 1});
        }
        if (matrix[ele[0]][ele[1]] != '@')
        {
            y += 1;
            if (matrix[x][y] == '[')
            {
                nr.insert({x, y});
            }
            else if (matrix[x][y] == ']')
            {
                nr.insert({x, y - 1});
            }
        }
    }
    return nr;
}
pair<int, int> move_robot_2(pair<int, int> posi, pair<int, int> v)
{
    set<vector<int>> boxes;
    set<vector<int>> one_row;
    one_row.insert({posi.first, posi.second});
    while (true)
    {
        if (any_fence(one_row, v))
        {
            return posi;
        }
        else
        {
            set<vector<int>> nr = next_row(one_row, v);
            if (nr.size())
            {
                for (auto ele : nr)
                    boxes.insert(ele);

                one_row = nr;
            }
            else
            {
                for (auto ele : boxes)
                {
                    matrix[ele[0]][ele[1]] = '.';
                    matrix[ele[0]][ele[1] + 1] = '.';
                }
                for (auto ele : boxes)
                {
                    matrix[ele[0] + v.first][ele[1] + v.second] = '[';
                    matrix[ele[0] + v.first][ele[1] + v.second + 1] = ']';
                }
                matrix[posi.first][posi.second] = '.';
                matrix[posi.first + v.first][posi.second + v.second] = '@';
                return {posi.first + v.first, posi.second + v.second};
            }
        }
    }
}
pair<int, int> get_init_pos()
{
    re(i, N1)
    {
        re(j, N1 * 2)
        {
            if (matrix[i][j] == '@')
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

int main()
{
    fast();
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
#endif

    // init
    ll ans = 0;
    cin >> N1;
    re(i, N1)
    {
        string line;
        cin >> line;
        re(j, N1)
        {
            if (line[j] == '#')
            {
                matrix[i][j * 2] = '#';
                matrix[i][j * 2 + 1] = '#';
            }
            else if (line[j] == '.')
            {
                matrix[i][j * 2] = '.';
                matrix[i][j * 2 + 1] = '.';
            }
            else if (line[j] == 'O')
            {
                matrix[i][j * 2] = '[';
                matrix[i][j * 2 + 1] = ']';
            }
            else
            {
                matrix[i][j * 2] = '@';
                matrix[i][j * 2 + 1] = '.';
            }
        }
    }

    // Similation
    cin >> N2 >> N3;
    auto pos = get_init_pos();
    re(i, N2)
    {
        string oper;
        cin >> oper;
        re(j, N3)
        {
            if (oper[j] == '^')
            {
                // up
                pos = move_robot_2(pos, {-1, 0});
            }
            else if (oper[j] == '>')
            {
                // right
                pos = move_robot(pos, {0, 1});
            }
            else if (oper[j] == 'v')
            {
                // down
                pos = move_robot_2(pos, {1, 0});
            }
            else
            {
                // left
                pos = move_robot(pos, {0, -1});
            }

            // re(i, N1)
            // {
            //     re(j, N1 * 2)
            //     {
            //         cout << matrix[i][j];
            //     }
            //     cout << endl;
            // }
        }
    }

    re(i, N1)
    {
        re(j, N1 * 2)
        {
            if (matrix[i][j] == '[')
                ans += i * 100 + j;
            cout << matrix[i][j];
        }
        cout << endl;
    }
    cout << N1 << " " << N2 << " " << N3 << " " << ans << endl;
}
