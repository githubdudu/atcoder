#include "bits/stdc++.h"
#include "atcoder/dsu.hpp"
using namespace std;
using namespace atcoder;

int main()
{
    int N;
    cin >> N;
    map<int, int> deli;
    for (int i = 0; i < N; i++)
    {
        int a, c;
        cin >> a >> c;
        if (deli.find(c) == deli.end()) {deli.insert({c, a});} 
        else {
            int v = min(deli.at(c), a);
            deli[c] = v;
        }
    }
    int maxValue = 0;
    for (auto& pair: deli) {
        if (pair.second > maxValue) maxValue = pair.second;
    }
    cout << maxValue << endl;
}