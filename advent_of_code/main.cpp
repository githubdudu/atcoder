#include "bits/stdc++.h"
using namespace std;

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

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif

/* Use (1<<n)-1 to create a bitwise 1 with length n. 
   Use (1<<i)&binary to check ith bit.
   Use (1<<i)^binary to toggle ith bit.
*/

string input;
vector<int> disk;
int char_to_int(char ch) {
    return ch - '0';
} 
int main()
{
    fast();
    #ifndef ONLINE_JUDGE
        freopen("./input2.txt", "r", stdin);
    #endif
    cin >> input;
    int id_num = 0;    
    for(int i=0; i< input.size(); i+=1) {
        int count = char_to_int(input[i]);
        if (i % 2 == 0) {
            for(int j=0;j < count; j++)
            {
                disk.push_back(id_num);
            }
            id_num++;
        } else {
            for(int j =0;j < count; j++)
            {
                disk.push_back(-1);
            }
        }
    }

    vector<pair<int, int>> data_block, free_space;
    int pos = 0;
    for(int i = 0; i < disk.size(); i++)
    {
        int count = char_to_int(input[i]);
        if(i % 2 == 0) {
            data_block.push_back({pos, count});
        } else {
            free_space.push_back({pos, count});
        }
        pos += count;
    }
    
    // move all files on disk
    // int l = 0, r = disk.size() - 1;

    // while(l != r) {
    //     if(disk[l] != -1) {
    //         l++;
    //     } else if (disk[r] == -1) {
    //         r--;
    //     } else {
    //         disk[l] = disk[r];
    //         disk[r] = -1;    
    //     }
    // }

    for(int i=data_block.size() - 1; i>=0; i--) {
        auto data = data_block[i];
        for (int j = 0; j < free_space.size(); j++ ) {
            if (data.first < free_space[j].first) {
                break;
            }

            if (data.second > free_space[j].second) {
                continue;
            } else {
                int start = free_space[j].first;
                for(int k = 0 ; k < data.second; k++ ) {
                    disk[free_space[j].first + k] = disk[data.first + k];
                    disk[data.first + k] = -1;
                }
                free_space[j].second -= data.second;
                free_space[j].first += data.second;
            }
        }
    }
    // cal checksum
    ll ans = 0;
    for(int i = 0; i < disk.size(); i++) {
        if(disk[i] == -1) {
            break;
        }
        ans += i * disk[i];
        
    }
    for(auto i: disk) cout << i << " ";
    cout << ans;
}

