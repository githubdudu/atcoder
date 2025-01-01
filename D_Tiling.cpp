#include "bits/stdc++.h"
#include "atcoder/dsu.hpp"
using namespace std;
using namespace atcoder;

#define ll long long
#define pos_module(n, mod) (n % mod + mod) % mod
#define re(i,n) for(int i = 0; i < (n); ++i)
#define rep(i, start, end) for(int i = (start); i < (end); i++)
#define repr(i, start, end) for(int i = (end - 1); i >= (start); i--)
#define cinarr(arr, en) for(ll (i) = 0; (i) < en; (i)++){cin >> arr[i];}
#define coutarr(arr, en) for(ll (i) = 0; (i) < en; (i)++){cout << arr[i] << " \n"[i+1 == n];}
#define NO cout << "No\n"
#define YES cout << "Yes\n"
void fast(){ios_base::sync_with_stdio(false);}
auto Cn2(ll n) {return n * (n - 1) / 2;}

auto fit(int *row, int &cursor, int &height, int &width, int &H, int &W) {
    if (cursor + height > H) return false;
    rep(i, cursor, cursor + height) {
        if (row[i] + width > W) return false;
    }
    return true;
};

auto fill(int *row, int cursor, int &height, int &width, int &H) {
    rep(i, cursor, cursor + height) {
        row[i] += width;
    }
    cursor = (cursor + height) % H;
};

auto full(int *row, int &H, int &W) {
    rep(i, 0, H) {
        if (row[i] != W) return false;
    }
    return true;
};

bool found(pair<int, int> *tiles, int idx, int row[], int N, int H, int W){

    if (full(row, H, W)) return true;
    if (idx >= N) return false;

    int cursor = H - 1;
    repr(i, 0, H) {
        if (row[i] <= row[cursor]) cursor = i;
    }

    int height = tiles[idx].first, width = tiles[idx].second;
    bool f1 = fit(row, cursor, height, width, H, W);
    bool f2 = height == width ? false : fit(row, cursor, width, height, H, W);
    if (!f1 && !f2) return false;

    if (f1) {
        int new_row[H]; copy(row, row + H, new_row);
        fill(new_row, cursor, height, width, H);
        if(found(tiles, idx+1, new_row, N, H, W)) {
            return true;
        }
    }
    if (f2) {
        int new_row[H]; copy(row, row + H, new_row);
        fill(new_row, cursor, width, height, H);
        if(found(tiles, idx+1, new_row, N, H, W)) {
            return true;
        }
    }
    return false;
}
int main()
{
    fast();
    int N,H,W; cin >> N >> H >> W;
    pair<int, int> tiles[N]; re(i, N) cin >> tiles[i].first >> tiles[i].second;

    sort(tiles, tiles + N);
    do
    {
        int row[H]; re(i, H) row[i] = 0;
        if (found(tiles, 0, row, N, H, W)) { YES; return 0;}
    } while (std::next_permutation(tiles, tiles + N));

    NO; return 0;
}