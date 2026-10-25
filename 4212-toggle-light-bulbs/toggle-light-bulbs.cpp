class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        unordered_set<int> seen;
        for (int b : bulbs) {
            if (seen.count(b)) seen.erase(b);
            else seen.insert(b);
        }
        vector<int> ans(seen.begin(), seen.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};