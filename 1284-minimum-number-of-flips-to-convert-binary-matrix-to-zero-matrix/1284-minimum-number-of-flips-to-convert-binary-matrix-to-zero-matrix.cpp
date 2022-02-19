class Solution {
public:
    int row;
    int col;
    
    int minFlips(vector<vector<int>>& mat) {
        row = mat.size();
        col = mat[0].size();
        unordered_set<string> s;
        queue<pair<vector<vector<int>>,int>> q; // mat, age
        q.push({mat,0});

        while(!q.empty()){
            auto pair = q.front();q.pop();
            vector<vector<int>> v = pair.first;
            int age = pair.second;
            string matStr = toString(v);

            if(s.find(matStr) != s.end()) continue;
            s.insert(matStr);
         
            if(isZeroMatrix(v)) return age;
            
            for(int i = 0 ; i < row ; i++){
                for(int j = 0 ; j < col ; j++){
                    vector<vector<int>> fliped = getFliped(v, i,j);
                    q.push({fliped, age+1});
                }
            }
            
        }
        return -1;
        
    }
    vector<vector<int>> getFliped(vector<vector<int>> mat,int i, int j){
        
        mat[i][j] = 1^mat[i][j];
        if(i-1>=0){
            mat[i-1][j] = 1^mat[i-1][j];
        }
        if (i+1 < row){
            mat[i+1][j] = 1^mat[i+1][j];
        }
        if(j-1>=0){
            mat[i][j-1] = 1^mat[i][j-1];
        }
        if (j+1 < col){
            mat[i][j+1] = 1^mat[i][j+1];
        }
   
        return mat;
    }
    bool isZeroMatrix(vector<vector<int>>& mat){
        for(int i = 0 ; i < row; i++){
            for(int j = 0 ; j < col ; j++){
                if(mat[i][j] == 1){
                    return false;
                }
            }
        }
        return true;
    }
    string toString(vector<vector<int>> & mat){
        string result = "";
        for(int i = 0 ; i < row; i++){
            for(int j = 0 ; j < col ; j++){
                result+=to_string(mat[i][j]) + " ";
            }
        }
        return result;
    }
};