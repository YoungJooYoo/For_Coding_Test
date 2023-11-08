class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) 
    {
        vector<int> nums;
        vector<int> result;
        int k = 0;

        for (const auto& word : words) {
            if (word == "prev") {
                ++k;
                if (k > nums.size()) result.push_back(-1);
                else result.push_back(nums[nums.size() - k]);
            }
            else {
                nums.push_back(stoi(word));
                k = 0;
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/last-visited-integers/description/

/*
주어진 문자열 배열 words에서 "prev" 문자열을 만나면 이전에 방문한 정수를 찾아야 합니다. 
이전에 방문한 정수는 다음과 같이 정의됩니다.

현재 문자열을 포함하여 지금까지 연속으로 나타난 "prev" 문자열의 수를 k라고 합시다.
현재까지 나타난 정수를 저장하는 0-인덱스 배열을 nums라고 하고, nums의 역순 배열을 nums_reverse라고 합시다. 그러면 nums_reverse의 (k-1)번째 인덱스의 정수가 이 "prev"에 대한 마지막으로 방문한 정수가 될 것입니다.
만약 k가 지금까지 방문한 정수의 총 개수보다 크다면, 마지막으로 방문한 정수는 -1이 될 것입니다.
이러한 규칙에 따라 마지막으로 방문한 정수를 찾아서 정수 배열에 저장하고 해당 배열을 반환해야 합니다.

예를 들어, 주어진 입력의 경우:

Input: words = ["1","2","prev","prev","prev"]

"prev"는 다음과 같이 처리됩니다:

인덱스 2에서 "prev"를 만나면, 지금까지 연속으로 나타난 "prev" 문자열의 수는 1이고, nums_reverse 배열의 첫 번째 요소는 2입니다.
인덱스 3에서 "prev"를 만나면, 지금까지 연속으로 나타난 "prev" 문자열의 수는 2이고, nums_reverse 배열의 두 번째 요소는 1입니다.
인덱스 4에서 "prev"를 만나면, 지금까지 연속으로 나타난 "prev" 문자열의 수는 3이지만, 지금까지 방문한 정수의 총 개수는 2입니다.
따라서 반환값은 [2, 1, -1]이 됩니다.

*/
