#include "bits/stdc++.h"
#include "atcoder/dsu.hpp"
using namespace std;
using namespace atcoder;

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        if ((i + 1) % 3 == 0) cout << 'x';
        else cout << 'o';
    }
}