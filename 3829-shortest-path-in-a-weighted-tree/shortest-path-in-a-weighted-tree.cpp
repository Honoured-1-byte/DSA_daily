struct FenwickTree {
    int size;
    vector<long long> tree;
    FenwickTree(int n) : size(n + 2), tree(n + 3, 0) {}
    void add(int i, long long delta) {
        for (; i <= size; i += i & -i) {
            tree[i] += delta;
        }
    }
    long long query(int i) {
        long long sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += tree[i];
        }
        return sum;
    }
};

class Solution {
private:
    int timer = 0;

    void dfs(int u, int p, int d, long long cur_dist,
             const vector<vector<pair<int, int>>>& adj,
             vector<int>& in, vector<int>& out, 
             vector<int>& depth, vector<long long>& ini_dist, 
             vector<int>& cur_weight) {
        
        in[u] = ++timer;
        depth[u] = d;
        ini_dist[u] = cur_dist;

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (v != p) {
                cur_weight[v] = w; 
                dfs(v, u, d + 1, cur_dist + w, adj, in, out, depth, ini_dist, cur_weight);
            }
        }

        out[u] = timer;
    }

public:
    vector<int> treeQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        timer = 0;
        vector<int> in(n + 1), out(n + 1), depth(n + 1), cur_weight(n + 1);
        vector<long long> ini_dist(n + 1);
        dfs(1, 0, 0, 0, adj, in, out, depth, ini_dist, cur_weight);

        FenwickTree bit(n);
        vector<int> answer;

        for (const auto& q : queries) {
            if (q[0] == 1) {
                int u = q[1], v = q[2], w_new = q[3];
                int child = (depth[u] > depth[v]) ? u : v;

                long long delta = w_new - cur_weight[child];
                cur_weight[child] = w_new;
                bit.add(in[child], delta);
                bit.add(out[child] + 1, -delta);
            } else {
                int x = q[1];
                long long total_dist = ini_dist[x] + bit.query(in[x]);
                answer.push_back((int)total_dist);
            }
        }

        return answer;
    }
};