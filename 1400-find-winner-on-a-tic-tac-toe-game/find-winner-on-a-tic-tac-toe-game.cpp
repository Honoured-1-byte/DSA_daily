#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string tictactoe(vector<vector<int>>& m) {
        int r[3] = {0}, c[3] = {0}, d1 = 0, d2 = 0;
        for(int i = 0; i < m.size(); ++i) {
            int v = i % 2 == 0 ? 1 : -1;
            int x = m[i][0], y = m[i][1];
            r[x] += v;
            c[y] += v;
            if(x == y) d1 += v;
            if(x + y == 2) d2 += v;
            if(abs(r[x]) == 3 || abs(c[y]) == 3 || abs(d1) == 3 || abs(d2) == 3)
                return v == 1 ? "A" : "B";
        }
        return m.size() == 9 ? "Draw" : "Pending";
    }
};