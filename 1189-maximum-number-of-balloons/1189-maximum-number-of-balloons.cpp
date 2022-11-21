class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int a = 0;
        int b = 0;
        int l_2 = 0;
        int o_2 = 0;
        int n = 0;
        
        // a-1 b-1 l-2 o-2 n-1
        for (const auto& ch : text) {
            if (ch == 'b') b++;
            else if (ch == 'a') a++;
            else if (ch== 'l') l_2++;
            else if (ch == 'o') o_2++;
            else if (ch == 'n') n++;
        }
        
        l_2 = l_2 / 2;
        o_2 = o_2 / 2;
        
        return min({a, b, l_2, o_2, n});
    }
};