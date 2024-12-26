#include "bits/stdc++.h"
#include "atcoder/dsu.hpp"
using namespace std;
using namespace atcoder;

int main()
{
    int N, A, B;
    cin >> N >> A >> B;
    set<int> mm;

    for (int i = 0; i < N; i++)
    {
        int D;
        cin >> D;
        mm.insert(D % (A + B));
    }

    if (mm.size() == 1) {
        cout << "Yes" << endl;
        return 0;
    }
    
    for (auto it=mm.begin(); it != mm.end(); it++) {
        auto next_it = std::next(it);
        if (next_it != mm.end()) {
            if ((*next_it - *it) % (A + B) > B) {
                cout << "Yes" << endl;
                return 0;
            }
        } else {
            auto r = (*mm.begin() - *it) % (A + B);
            if (r < 0) {
                r += A + B;
            }
            if (r > B) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
    
}