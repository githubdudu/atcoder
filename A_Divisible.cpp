#include "bits/stdc++.h"
#include "atcoder/dsu.hpp"
using namespace std;
using namespace atcoder;

int main()
{
    int N, K;
    cin >> N >> K;
    
    for (int i = 0; i < N; i++)
    {
        int A;
        cin >> A;
        if (A % K == 0) {
            cout << A / K << " ";
        }

    }
}