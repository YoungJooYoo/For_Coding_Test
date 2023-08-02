class UnionFind {
public:
    UnionFind(int size) : root(size), rank(size), count(size) 
    {
        for (size_t i = 0; i < size; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (x == root[x]) {
            return x;
        }
  
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y) 
    {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
            count--;
        }
    }

    int getCount() 
    {
        return count;
    }

private:
    vector<int> root;
    vector<int> rank;
    int count;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        if (isConnected.size() == 0) {
            return 0;
        }
        
        int n = isConnected.size();
        UnionFind uf(n);
        
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    uf.unionSet(i, j);
                }
            }
        }
        
        return uf.getCount();
    }
};

/*
그래프의 대표적인 풀이 방법이다.
배열을 트리화시켜 인덱스 - 값을 서로 연동한다
즉
배열  1 2 3 4 5 6
값    2 3 4 5 6 7
1번배열을 2번을, 2번배열은 3번을 리턴하는 재귀로
노드끼리 연결 되었다면 서로 계속 탐색이 가능하다.
즉 연결리스트 처럼 직선으로 연결되는 방식이다.
*/