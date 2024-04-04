class Solution {
public:
    int largestInteger(const int num) 
    {
        string number = to_string(num);
        priority_queue<char> even_nums;
        priority_queue<char> odd_nums;

        for (const auto ch : number) {
            const int temp = ch - '0';
            if (temp % 2 == 0) { // even
                even_nums.push(ch);
            }
            else {  // odd
                odd_nums.push(ch);
            }
        }

        for (auto& ch : number) {
            const int temp = ch - '0';
            if (temp % 2 == 0) { // even
                ch = even_nums.top();
                even_nums.pop();
            }
            else {  // odd
                ch = odd_nums.top();
                odd_nums.pop();
            }
        }

        return stoi(number);
    }
};

/*

주어진 양의 정수 `num`이 있습니다. `num`의 숫자 중에서 서로 같은 패리티(짝수이거나 홀수인)를 가진 두 숫자를 교환할 수 있습니다. 어떤 수의 교환 횟수에 상관없이 `num`의 가능한 최대값을 반환하세요.

**예시:**

입력: num = 1234  
출력: 3412  
설명: 숫자 3을 숫자 1과 교환하면 3214가 됩니다. 그 다음 숫자 2를 숫자 4와 교환하면 3412가 됩니다. 다른 순서의 교환도 있을 수 있지만, 3412가 가능한 최대값임을 보일 수 있습니다. 또한, 숫자 4와 숫자 1을 서로 다른 패리티를 가지고 있기 때문에 숫자 4와 숫자 1을 교환할 수 없습니다.

입력: num = 65875  
출력: 87655  
설명: 숫자 8을 숫자 6과 교환하면 85675가 됩니다. 그 다음 첫 번째 숫자 5를 숫자 7과 교환하면 87655가 됩니다. 다른 순서의 교환도 있을 수 있지만, 87655가 가능한 최대값임을 보일 수 있습니다.

*/

// https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/description/
