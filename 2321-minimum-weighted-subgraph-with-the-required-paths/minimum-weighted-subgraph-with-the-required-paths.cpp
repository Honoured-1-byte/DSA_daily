class Solution {
public:
    vector<long long> dijkstra(int src, vector<vector<pair<int,int>>>&adj){
        int n=adj.size();
        vector<long long >dist(n,1e18);
        dist[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        while(!pq.empty()){
            auto [d,node]=pq.top();
            pq.pop();
            if(d>dist[node]) continue;
            for(auto [nei,dis]: adj[node]){
                if(dist[node]+dis<dist[nei]){
                    dist[nei]=dist[node]+dis;
                    pq.push({dist[nei],nei});
                }
            }
        }
        return dist;
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int,int>>>adj(n), rev_adj(n);
        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            rev_adj[e[1]].push_back({e[0],e[2]});
        }
        vector<vector<long long>>opt(3,vector<long long>(n));
        opt[0]=dijkstra(src1,adj);
        opt[1]=dijkstra(src2,adj);
        opt[2]=dijkstra(dest,rev_adj);
        long long ans=LLONG_MAX;
        for(int i=0;i<n;i++) ans=min(ans,(long long)opt[0][i]+opt[1][i]+opt[2][i]);
        return ans>=1e18?-1:ans;
    }
};