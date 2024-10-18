class Solution 
{
public:
    vector<int> pancakeSort(vector<int>& arr) 
    {
        vector<int> result;
        const int n = arr.size();
        
        for (int size = n; size > 1; --size)
        {
            int maxIdx = 0;
            for (int i = 1; i < size; ++i) 
            {
                if (arr[i] > arr[maxIdx]) // 현재 정렬되지 않은 부분에서 가장 큰 요소 찾기
                {
                    maxIdx = i;
                }
            }
            
            if (maxIdx == size - 1) // 가장 큰 요소가 이미 최종 위치에 있다면 건너뛰기
            {
                continue;
            }
            
            if (maxIdx != 0) // 가장 큰 요소를 맨 앞으로 이동
            {
                flip(arr, maxIdx +1);
                result.push_back(maxIdx + 1);
            }
            
            flip(arr, size); // 가장 큰 요소를 최종 위치로 이동
            result.push_back(size);
        }
        
        return result;
    }
    
private:
    void flip(vector<int>& arr, const int k) // 배열의 처음부터 k까지를 뒤집는 함수
    {
        reverse(arr.begin(), arr.begin() + k);
    }
};

// https://leetcode.com/problems/pancake-sorting/description/

/*

969. 팬케이크 정렬 (Pancake Sorting)
중간 난이도

주제

기업

📄 문제 설명
정수 배열 arr이 주어집니다. 이 배열을 일련의 팬케이크 뒤집기(pancake flip)를 수행하여 정렬하세요.

팬케이크 뒤집기란 다음 단계를 수행하는 것입니다:

정수 k를 선택합니다. 여기서 1 <= k <= arr.length를 만족해야 합니다.

배열의 부분 배열 arr[0...k-1]을 뒤집습니다. (0-인덱스 기준)

예를 들어, arr = [3,2,1,4]이고 k = 3을 선택하여 팬케이크 뒤집기를 수행하면, arr[0...2] = [3,2,1]이 뒤집혀 arr = [1,2,3,4]가 됩니다.

배열을 정렬하기 위해 수행한 팬케이크 뒤집기 k 값들의 시퀀스를 반환하세요. 배열을 10 * arr.length 번의 뒤집기로 정렬할 수 있는 유효한 답안은 정답으로 인정됩니다.

💡 예제 1:
less
코드 복사
입력: arr = [3,2,4,1]
출력: [4,2,4,3]
설명: 팬케이크 뒤집기를 4번 수행하며, k 값은 순서대로 4, 2, 4, 3입니다.

1번째 뒤집기 (k = 4): arr = [3,2,4,1] → arr = [1,4,2,3]
2번째 뒤집기 (k = 2): arr = [1,4,2,3] → arr = [4,1,2,3]
3번째 뒤집기 (k = 4): arr = [4,1,2,3] → arr = [3,2,1,4]
4번째 뒤집기 (k = 3): arr = [3,2,1,4] → arr = [1,2,3,4] (정렬 완료)
따라서, [4,2,4,3]이 올바른 출력입니다.

💡 예제 2:
less
코드 복사
입력: arr = [1,2,3]
출력: []
설명: 입력 배열이 이미 정렬되어 있으므로, 팬케이크 뒤집기를 수행할 필요가 없습니다. 따라서 빈 배열 []을 반환합니다.

참고: 다른 답안, 예를 들어 [3, 3]도 정답으로 인정됩니다.

📌 제약 사항:
1 <= arr.length <= 100
1 <= arr[i] <= arr.length
모든 정수 arr[i]는 서로 다릅니다. (즉, arr은 1부터 arr.length까지의 정수의 순열입니다.)
*/
