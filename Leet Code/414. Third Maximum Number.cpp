class Solution
{
public:
    int thirdMax(vector<int>& nums)
    {
        const size_t nums_length = nums.size();
        size_t third_max_index = 1;  // max_index = 3이되면 3번째로 큰수, 중복된 원소 카운트 안하기 위해 사용
       
        /* 길이가 3보다 작은 입력 들어오면, 원소안에 최대 값을 답으로 반환 */
        if (nums_length < 3) {
            return *max_element(nums.begin(), nums.end());
        }
        
        // 내림 차순으로 정렬 후 여기서 3번째로 큰 수 찾기
        sort(nums.begin(), nums.end(), greater<int>());

        // 탐색시 주어진 벡터의 길이를 넘지 않는 조건과 정렬된 원소 값이 같지 않을때 3번째 큰수를 확인하는 변수를 체크
        // 같은 값 원소를 count하지 않기 위해서
        for (int i = 0; i < nums_length; i++) {
            if (i + 1 < nums_length && nums.at(i) != nums.at(i + 1)) {
                third_max_index++;
                if(third_max_index == 3) { // 3번째로 큰수를 발견하면 리턴
                    return nums.at(i + 1);
                }
            }
        }
        
        // 위의 탐색으로도 3번째로 큰수가 나오지 않는다면,
        // 해당 정렬된 원소에서 (맨 앞이 가장 큰 수) 가장 큰 숫자 반환
        if (third_max_index < 3) {
            return nums[0];
        }
        
        return 0;
    }
};
