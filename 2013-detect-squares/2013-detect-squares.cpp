class DetectSquares {
private:
    map<pair<int,int>, int>mp; // <pair<x, y> , freq>
    
public:
    DetectSquares() {}
    
    void add(vector<int> point) 
    {
        mp[{point[0],point[1]}]++; // x, y 좌표의 빈도수 체크
    }
    
    int count(vector<int> point) 
    {
        int count = 0;
        int x = point[0];
        int y = point[1];
        
        for (const auto& elem : mp) {
            pair<int, int>it = elem.first;
            if (it.first != x && it.second != y && (abs(it.first - x) == abs(it.second - y))) {
                int f1 = mp[{it.first, it.second}];
                int f2 = mp[{it.first, y}];
                int f3 = mp[{x, it.second}];
                count += f1 * f2 * f3;
            }
        }
        
        return count;
    }
};
