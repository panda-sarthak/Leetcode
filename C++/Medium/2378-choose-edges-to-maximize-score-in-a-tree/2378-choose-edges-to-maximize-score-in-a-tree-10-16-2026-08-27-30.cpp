typedef long long ll;

class Solution {
public:
    ll t[100002][2];

    long long maxScore(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<vector<pair<int,int>>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[i].push_back({edges[i][0], edges[i][1]});
            adj[edges[i][0]].push_back({i, edges[i][1]});
        }

        // 1. Generate a traversal order starting from the root.
        vector<int> par(n, -1), order;
        order.reserve(n);
        order.push_back(0);

        for (int k = 0; k < (int)order.size(); k++) {
            int u = order[k];

            for (auto& [v, w] : adj[u]) {
                if (v == par[u]) continue;

                par[v] = u;
                order.push_back(v);
            }
        }

        // 2. Process children before parents.
        memset(t, 0, sizeof(t));

        for (int k = n - 1; k >= 0; k--) {
            int i = order[k];

            ll res = 0;
            ll best_cand_comp = 0;

            for (auto& [j, w] : adj[i]) {
                if (j == par[i]) continue;

                ll r1 = t[j][0];       // Parent edge not selected
                ll r2 = t[j][1] + w;   // Parent edge selected

                res += max(r1, 0LL);

                ll curr_gain = r2 - max(r1, 0LL);
                best_cand_comp = max(best_cand_comp, curr_gain);
            }

            // Parent edge selected: cannot select any child edge.
            t[i][1] = res;

            // Parent edge not selected: select at most one child edge.
            t[i][0] = res + best_cand_comp;
        }

        return t[0][0];
    }
};