#include "bits/stdc++.h"
#include "atcoder/dsu.hpp"
using namespace std;
using namespace atcoder;
#define vi vector<int>
#define vvi vector<vector<int>>

vi findS(vector<string> &mat)
{
    for (int i = 0; i < (int)mat.size(); i++)
    {
        for (int j = 0; j < (int)mat[i].size(); j++)
        {
            if (mat[i][j] == 'S')
                return {i, j};
        }
    }
    return {0, 0};
}
int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> mat;
    for (int i = 0; i < H; i++)
    {
        string line;
        cin >> line;
        mat.push_back(line);
    }
    vi start = findS(mat);

    int N;
    cin >> N;
    std::map<vi, int> medicine;
    for (int i = 0; i < N; i++)
    {
        int r, c, e;
        cin >> r >> c >> e;
        medicine.insert({{r - 1, c - 1}, e});
    }

    //  terminate
    if (not medicine.contains(start)) {
        cout << "No" << endl;
        return 0;
    }

    vvi f1 = {start};
    set<vi> visited;

    while (f1.size() > 0) {
        vi front = f1.back();
        f1.pop_back();
        int energy = medicine.at(front);
        visited.insert(front);

        vvi f2 = {front};
        set<vi> visited2{front};
        while (energy > 0) {
            vvi new_f2;
            for (vi front2 : f2){
                int x = front2[0], y = front2[1];
                vvi directions = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
                for (auto dire : directions) {
                    int xi = x + dire[0], yi = y + dire[1];
                    if (xi >= 0 and xi < H and yi >= 0 and yi < W) {
                        if (mat[xi][yi] != '#' and not visited2.contains({xi, yi})) {
                            // check target
                            if (mat[xi][yi] == 'T') {
                                cout << "Yes" << endl;
                                return 0;
                            }
                            // check another medicine
                            if (medicine.contains({xi, yi})  and not visited.contains({xi, yi})) {
                                if (medicine.at({xi, yi}) > energy) {
                                    f1.push_back({xi, yi});
                                } else {
                                    visited.insert({xi, yi});
                                }
                            }
                            // push into new_f2
                            new_f2.push_back({xi, yi});
                            visited2.insert({xi, yi});
                        }
                    }
                }

            }
            f2 = new_f2;
            energy--;
        }


    }
    cout << "No" << endl;
    return 0;
}