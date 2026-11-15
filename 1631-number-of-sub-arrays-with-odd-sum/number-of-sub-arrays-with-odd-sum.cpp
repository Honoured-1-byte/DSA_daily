class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        int prefixParity = 0, evenCount = 1, oddCount = 0;
        for (int num : arr) {
            prefixParity ^= (num & 1);
            if (prefixParity == 1) {
                ans = (ans + evenCount) % MOD;
                oddCount++;
            } else {
                ans = (ans + oddCount) % MOD;
                evenCount++;
            }
        }
        return ans;
    }
};