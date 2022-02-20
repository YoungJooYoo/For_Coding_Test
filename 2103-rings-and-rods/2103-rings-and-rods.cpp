class Solution {
public:
    int countPoints(string rings) 
    {
        bool rgb_check[10][3] = {0, }; // init false;
        int ans = 0;
        
        for (size_t i = 1; i < rings.size(); i += 2){
            if (rings[i - 1]=='R') {
                rgb_check[rings[i] - '0'][0] = true;
            }
            if (rings[i-1] == 'G') {
                rgb_check[rings[i] - '0'][1] = true;
            }
            if (rings[i-1] == 'B') {
                rgb_check[rings[i]-'0'][2] = true;
            }
        }
        for (size_t i = 0; i < 10; i++) {
            ans += rgb_check[i][0] && rgb_check[i][1] && rgb_check[i][2];
        }
        
        return ans;
    }
};