class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) 
    {
        /* unin find 그래프 풀이 방식을 쓰기 위한 초기화 단계 */
        parent.resize(n);
        fill(parent.begin(), parent.end(), -1);
        count = n;
        
        // 주어진 edges 배열에서, 관게가 있는지 찾는다
        for (const auto edge : edges) {
            if (union_set(edge[0], edge[1]) == false) { 
                return false; //cycle is present
            }
        }
        
        // 트리에서 홀로 떨어진 원소가 있다면 1이 나오지 않는다.
        return count == 1 ? true : false;     // some disconnected component in tree if count != 1
    }
    
private:
    vector<int> parent; // 배열로 그래프를 표현
    int count;  // int n을 받는다.
    
    int find(int v)
    {
        /* 노트가 아무것도 연결성이 없다면 그냥 정점을 반환 */
        if (parent[v] == -1) {
            return v;
        }
        // 노드가 이어진 것이 있다면 재귀적으로 이어진 쭉 찾아서 리턴    
        return parent[v] = find(parent[v]); // return값을 배열에 대입하므로, 트리의 깊이를 낮춘다.
    }
    
    bool union_set(int a, int b)
    {
        int pa = find(a);
        int pb = find(b);
        
        if(pa == pb) {  // for cycle present
            return false;
        } 
        
        parent[pb] = pa; // 연관된 v끼리 연결한다.
        count--;  
        
        //decrease no of parents
        return true;
    }
};


/*
풀이밥 :
그래프 문제의 전형적인 패턴인
find, union 기법을 사용한다.

*/