class UnionFind {
public:
    vector<int> parent;
    int count;

    UnionFind(const int n) : count(n) 
    {
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    
    int find(const int x) 
    {
        if (x != parent[x]) {
            parent[x] = find(parent[x]); // Path compression
        }

        return parent[x];
    }
    
    void unite(const int x, const int y) 
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
            --count;
        }
    }
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, const int n) 
    {
        UnionFind uf(n);

        sort(logs.begin(), logs.end()); // 시간 기준으로 로그 정렬
        
        for (const auto& log : logs) {
            const int timestamp = log[0];
            const int start = log[1];
            const int end = log[2];
            uf.unite(start, end);
            if (uf.count == 1) { // 모든 사람이 연결되었는지 확인
                return timestamp; // 모든 사람이 연결된 시점의 timestamp 반환
            }
        }
        
        return -1; // 모든 사람이 연결되지 않았다면 -1 반환
    }
};

/*
이 문제는 사회적 그룹 내에서 모든 사람이 서로 친구가 되는 가장 빠른 시점을 찾는 문제입니다. 
주어진 로그 배열을 통해 특정 시간에 두 사람이 친구가 되는 이벤트를 추적하고, 
이 정보를 사용하여 모든 사람이 서로 알게 되는 가장 빠른 시간을 계산해야 합니다.

문제 요약
n명의 사람들이 있고, 각 사람은 0부터 n-1까지의 라벨로 구분됩니다.
logs[i] = [timestampi, xi, yi] 배열은 xi와 yi가 timestampi 시간에 친구가 된다는 것을 나타냅니다.
친구 관계는 대칭적이며, 간접적인 친구 관계도 인정됩니다.
모든 사람이 서로 친구가 되는 가장 빠른 시간을 반환합니다. 그런 시간이 없다면 -1을 반환합니다.
문제 풀이 방향
이 문제는 Union-Find 알고리즘을 사용하여 효율적으로 해결할 수 있습니다. Union-Find 알고리즘은 집합의 합집합 연산과 찾기 연산을 효율적으로 처리할 수 있게 해주며, 주로 네트워크 연결성 문제나 최소 신장 트리 문제에서 사용됩니다.

초기화: n개의 사람 각각을 독립적인 집합으로 초기화합니다. 이 때, 각 사람은 자신의 집합의 대표(루트)입니다.

로그 정렬: logs 배열을 시간 timestamp 기준으로 오름차순 정렬합니다. 이렇게 하면 사건들을 시간 순서대로 처리할 수 있습니다.

Union 연산: 각 로그를 순회하면서 두 사람을 하나의 집합으로 합칩니다. 두 사람이 이미 같은 집합에 속해 있다면, 이는 이미 친구 관계에 있다는 것을 의미하므로 넘어갑니다. 두 사람이 다른 집합에 속해 있다면, 이 두 집합을 합치고 사람 수를 하나 줄입니다.

모든 사람이 연결되었는지 확인: 모든 사람이 하나의 큰 집합에 속하게 되는 순간, 즉 모든 사람이 서로 친구가 되는 순간을 찾습니다. 이 때의 timestamp를 반환합니다.

결과 반환: 모든 사람이 서로 연결되어 있으면 해당 시간을, 그렇지 않으면 -1을 반환합니다.
*/

// https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/description/
