class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int>state(101,0);
        for(int b:bulbs) state[b]^=1;
        vector<int>ans;
        for(int i=1;i<101;i++) if(state[i]) ans.push_back(i);
        return ans;
    }
};