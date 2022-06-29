class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) 
    {
        int seen[60] = {0, };
        int count = 0;
        
        // 숫자가 어떻든 나머지 패턴은 같으므로, 배열의 원소들의 나머지만 구한다.
        for (int& ele : time) {
            ele = ele % 60;
        }
        
        for (const int& ele : time) { // 60 = ele  + x   ->  60 - ele = x    => 즉 ele를 알고 있으므로 짝이되는 x를 구하는 것
            int x = 60 - ele;
            count += seen[x % 60]; // 60 - (ele % 60) 나머지 구하고  -> 60 - 나머지  =  
            seen[ele % 60]++;
        }
        
        for (auto ele : seen) {
            cout << ele << " ";
        }
        
        return count;
    }
};

/*

Brute Force로 풀이할 경우 시간 초과가 나온다.
따라서 O(n)에 끝나는 방법으로 진행 해야한다.

*/