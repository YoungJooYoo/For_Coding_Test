class DetectSquares {
private:
    map<pair<int,int>, int>mp; // <pair<x, y> , freq>
    
public:
    DetectSquares() 
    {
    }
    
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
            pair<int, int>it = elem.first; // x, y 좌표를 가져온다.
            if (it.first != x && it.second != y && (abs(it.first - x) == abs(it.second - y))) { // abs 조건은 대각선인 경우
                int f1 = mp[{it.first, it.second}]; // 대각선을 찾으면, 그에 기반한 온전한 사각형을 하나 만든다.
                int f2 = mp[{it.first, y}];
                int f3 = mp[{x, it.second}];
                count += f1 * f2 * f3; // 각 점의 나온 횟수를 곱하면 그게 카운트가 된다. 그리고 카운트를 누적한다.
            }
        }
        
        return count;
    }
};
