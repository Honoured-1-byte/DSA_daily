class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        long long oddGapSum = 0, evenGapSum = 0;
        int lastOdd = -1;
        bool isOddGap = true; 
        for (int i = 0; i <= n; ++i) {
            if (i == n || (arr[i] & 1)) {
                int gap = i - lastOdd;
                if (isOddGap) {
                    oddGapSum += gap;
                } else {
                    evenGapSum += gap;
                }
                isOddGap = !isOddGap;
                lastOdd = i;
            }
        }

        return ((oddGapSum % MOD) * (evenGapSum % MOD)) % MOD;
    }
};