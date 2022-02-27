class Solution {
public:
    string originalDigits(string s) 
    {
        vector<int> count(26); // 알파벳 개수 26개
        vector<int> nums(10);
        
        for (const auto& ch: s) {
            count[ch - 'a']++;
        }
        
        // Unique cases 유니크케이스 짝수
        nums[0] = count['z' - 'a'];
        nums[2] = count['w' - 'a'];
        nums[4] = count['u' - 'a'];
        nums[6] = count['x' - 'a'];
        nums[8] = count['g' - 'a'];
        
        // Derived Cases 파생케이스, 홀수
        nums[1] = count['o' - 'a'] - nums[0] -nums[2] - nums[4];
        nums[3] = count['h' - 'a'] - nums[8];
        nums[5] = count['f' - 'a'] - nums[4];
        nums[7] = count['s' - 'a'] - nums[6];
        nums[9] = count['i' - 'a'] - nums[5] - nums[6] - nums[8];
        
        //         Resultant String
        string str;
        for (size_t i = 0; i < 10; i++){
            while (nums[i]--) {
                str += to_string(i);
            }
        }
        
        return str;
    }
};