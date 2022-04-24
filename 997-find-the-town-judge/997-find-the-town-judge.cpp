class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        int outDeg[n + 1];
        int inDeg[n + 1];
        int m = trust.size();
        
        memset(outDeg, 0, sizeof(outDeg));
        memset(inDeg, 0, sizeof(inDeg));
        
        for (size_t i = 0; i < m; i++) {
            outDeg[trust[i][0]]++;
            inDeg[trust[i][1]]++;
        }
        
        for (size_t i = 1; i <= n; i++) {
            if (outDeg[i] == 0 && inDeg[i] == n - 1) {
                return i;
            }
        }
        
        return -1;
    }
};

/*
Indegree and Outdegree based approach.
Indegree of a node is the number of edges coming 'in' to that node.
Similary outdegree is defined as the number of nodes going 'out' of that node.

Please note that Indegree and Outdegree is defined for Directed Graphs.
The two conditions in the description in terms of Indegree and Outdegree are as follows:

Outdegree of the Judge node will be 0.
InDegree of the Judge node will be n-1.

Indegree 및 Outdegree 기반 접근 방식.
노드의 차수는 해당 노드에 '들어오는' 간선의 수입니다.
유사 외도는 해당 노드에서 '나가는' 노드의 수로 정의됩니다.

Indegree 및 Outdegree는 방향 그래프에 대해 정의됩니다.
Indegree와 Outdegree에 대한 설명의 두 가지 조건은 다음과 같습니다.

Judge 노드의 외도는 0이 됩니다.
Judge 노드의 InDegree는 n-1이 됩니다.

*/