class Solution {
public:
    int minOperations(string s) {
        string t = s;
        sort(t.begin(), t.end());
        if (t == s)
            return 0;
        int n = s.size();
        if (n == 2)
            return -1;
        char mn = *min_element(s.begin(), s.end()),
             mx = *max_element(s.begin(), s.end());
        if (s[0] == mn || s[n - 1] == mx)
            return 1;
        int cmn = count(s.begin(), s.end(), mn),
            cmx = count(s.begin(), s.end(), mx);
        if (cmn == 1 && cmx == 1 && s[0] == mx && s[n - 1] == mn)
            return 3;
        return 2;
    }
};