#include "bits/stdc++.h"
#include "atcoder/dsu.hpp"
using namespace std;
using namespace atcoder;

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

/* Use (1<<n)-1 to create a bitwise 1 with length n. 
   Use (1<<i)&binary to check ith bit.
   Use (1<<i)^binary to toggle ith bit.
*/
int D[10]; ll N,K; vector<int> R;
int convert(vector<int> &v) {
    int num = 0;
    re(i, v.size()) {
        num += R[v[i]] * pow(10, i);
    }
    return num;
}

int main()
{
    fast();
    cin>>N>>K;
    re(i, K) cin>>D[i];
    re(i, 10) {
        if (find(D, D + K, i) == D+K) R.push_back(i);
    }
    
    vector<int> ans = {0};

    while (true) {
        int num = convert(ans);
        if (num >= N) {
            cout << num;
            return 0;
        }
        else {
            int idx = 0;
            while(true) {
                if(idx > ans.size() - 1) {
                    ans.push_back(0);
                    break;
                }

                if (ans[idx] != R.size() - 1) {
                    ans[idx]++;
                    break;
                } else {
                    ans[idx] = 0;
                    idx += 1;
                }
            }
        }
    }
}

