class Solution {
public:
    double get_distance(vector<int>& p1, vector<int>& p2) // 두 점의 거리를 구하기
    {
        const int distance_x = p2[0] - p1[0];
        const int distance_y = p2[1] - p1[1];
        return sqrt((distance_x * distance_x) + (distance_y * distance_y));
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) 
    {
        vector<vector<int>> points = {p1, p2, p3, p4}; // 주어진 배열을, 인덱스 접근이 가능한 반복문에 사용하기 위해 2차원 배열에 넣는다.
        set<double> lengths;
        
        for (size_t i = 0; i < 4 - 1; i++) { // 각 점의 서로 모든 거리를 다 구한다.
            for (size_t j = i + 1; j < 4; j++) {
                double distance = get_distance(points[i], points[j]);
                if (distance != 0) {
                    lengths.insert(distance);
                }
                else { // if distance is zero - we got a duplicated point
                    return false;
                }
            }
        }
        // We are supposed to end with only two different lengths: the sides and the diagonals
        return lengths.size() == 2 ? true : false;
    }
};