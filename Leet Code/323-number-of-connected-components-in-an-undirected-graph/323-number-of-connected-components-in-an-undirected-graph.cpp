class Solution // 솔직히 이해 못하겠ㄷ ㅏㅠㅠ 다시 풀기
{
public:
    void dfs (int i) 
    {
        if (visit.count(i)) {
            return;
        }

        visit.insert(i);

        if (adj[i].empty()) {
            return;
        }

        for (auto node : adj[i]) {
            if (visit.count(node)) {
                continue;
                }
            dfs (node);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) 
    {
        if (edges.empty()) {
            return n;
        }

        adj.resize(n);

        for (const auto& edge : edges) { // Create adjacent matrix
            // Since values of each nodes are not in ascending order, we need to store relationship in pair of two nodes
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int part = 0;
        for (int i = 0; i < n; i++) {
            if (!visit.count(i)) {
                dfs(i);
                ++part;
            }
        }

        return part;
    }

private:
    unordered_set<int> visit; // Check whether nodes have been visited before
    vector<vector<int>> adj; // 인접행렬
};