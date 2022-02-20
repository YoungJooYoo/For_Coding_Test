class Solution {
public:
    int countPoints(string rings) 
    {
        bool rgb_check[10][3] = {0, }; // init false;  기둥 - RGB로 매핑;
        int ans = 0;
        
        // rings에서 i = 1, 3, 5, 7 홀수로 나가야지 기둥을 선택할 수 있다.
        // i - 1은,  기둥 인덱스 1, 3, 5, 7 이전의 값인 0, 2, 4, 6인덱스에 RGB값이 있다.
        for (size_t i = 1; i < rings.size(); i += 2) {
            if (rings[i - 1] == 'R') {
                rgb_check[rings[i] - '0'][0] = true;
            }
            if (rings[i - 1] == 'G') {
                rgb_check[rings[i] - '0'][1] = true;
            }
            if (rings[i - 1] == 'B') {
                rgb_check[rings[i] - '0'][2] = true;
            }
            cout << "i : " << i << endl;
        }
        
        for (size_t i = 0; i < 10; i++) {
            ans += rgb_check[i][0] && rgb_check[i][1] && rgb_check[i][2];
        }
        
        return ans;
    }
};