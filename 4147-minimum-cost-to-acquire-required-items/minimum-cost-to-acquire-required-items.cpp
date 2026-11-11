class Solution {
public:
    long long minimumCost(int c1, int c2, int cb, int n1, int n2) {
        long long n = min(n1, n2);
        return n * min(c1 + c2, cb) + (n1 - n) * min(c1, cb) +
               (n2 - n) * min(c2, cb);
    }
};