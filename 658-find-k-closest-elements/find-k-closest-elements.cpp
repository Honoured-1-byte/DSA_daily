class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int left = idx - 1, right = idx;
        while (right - left - 1 < k) {
            if (left < 0)
                right++;
            else if (right >= n)
                left--;
            else if (abs(arr[left] - x) <= abs(arr[right] - x))
                left--;
            else
                right++;
        }
        return vector<int>(arr.begin() + left + 1, arr.begin() + right);
    }
};