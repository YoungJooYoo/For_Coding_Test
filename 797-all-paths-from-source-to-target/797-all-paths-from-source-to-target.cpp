class Solution {
public:
    void dfs(vector<vector<int>>& graph, int currNode) 
    {
        tmp.push_back(currNode);
        
        if (currNode == destination) { // 재귀 종료조건, 마지막 노드에 도착하면
            res.push_back(tmp);
            tmp.pop_back();
            return;
        }
        for (const int& node: graph[currNode]) {
            dfs(graph, node);
        }
        tmp.pop_back(); // backtracking with tmp
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        destination = graph.size() - 1; // 주어진 2차원 배열의 마지막 행이 도책해야할 지점이다.
        dfs(graph, 0);
        return res;
    }
    
private:
    int destination;  // setting a few class variables, so that we do not have to pass them down all the time in the recursive dfs calls
    vector<vector<int>> res;
    vector<int> tmp;
};