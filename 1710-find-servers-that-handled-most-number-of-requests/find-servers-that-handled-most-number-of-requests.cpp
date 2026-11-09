class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<int,vector<int>,greater<int>>free;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>taken;
        vector<int>req(k,0);
        for(int i=0;i<k;i++) free.push(i);
        int n=load.size();
        for(int i=0;i<n;i++){
            int t=arrival[i];
            while(!taken.empty() && taken.top().first<=t){
                int x=taken.top().second;
                taken.pop();
                free.push(i+(k-(i%k)+(x%k))%k);
            }
            if(free.empty()) continue;
            int s=free.top();
            free.pop();
            taken.push({arrival[i]+load[i],s});
            req[s%k]++;
        }
        int maxi=INT_MIN;
        vector<int>ans;
        for(int i=0;i<k;i++){
            if(req[i]<maxi) continue;
            if(req[i]>maxi){
                maxi=req[i];
                ans={};
            }
            ans.push_back(i);
        }
        return ans;
    }
};