#include "bits/stdc++.h"
#include "atcoder/dsu.hpp"
using namespace std;
using namespace atcoder;


long long int dist(int p1[2], int p2[2]) {
    return (p1[0] - p2[0]) *(p1[0] - p2[0]) + (p1[1] - p2[1]) *(p1[1] - p2[1]);
}
int main()
{
    int N;
    cin >> N;
    int arr[N][2];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }
    for(int i = 0; i < N; i++) {
        int m = 0;
        int ans = 0;
        for (int j = 0; j < N; j++) {
            auto d = dist(arr[i], arr[j]);
            if (d > m) {
                m = d;
                ans = j;
            }
        }
        cout << ans + 1 << endl;
    }
}