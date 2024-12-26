#include "bits/stdc++.h"
#include "atcoder/dsu.hpp"
using namespace std;
using namespace atcoder;

int main()
{
    string S;
    cin >> S;
    set<string> sub;

    for (int i = 0; i < int(S.size()); i++)
    {
        for (int j = i + 1; j <= int(S.size()); j++)
        {
            string n_s = S.substr(i, j - i);
            sub.insert(n_s);
        }
        
    }
    cout << sub.size() << endl;
    
}