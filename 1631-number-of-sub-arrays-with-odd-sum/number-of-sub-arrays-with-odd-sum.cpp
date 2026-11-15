class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        int odd = 0, even = 0;

        for (int num : arr) {
            if (num & 1) {
                int prevOdd = odd;
                odd = even + 1;
                even = prevOdd;
            } else {
                even = even + 1;
            }
            ans = (ans + odd) % MOD;
        }
        return ans;
    }
};