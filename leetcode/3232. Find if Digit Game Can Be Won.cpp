class Solution 
{
public:
    bool canAliceWin(const vector<int>& nums) 
    {
        int singleDigitSum = 0;
        int doubleDigitSum = 0;
        int totalSum = 0;

        // 1자리 숫자와 2자리 숫자의 합을 각각 계산
        for (const int& num : nums) 
        {
            if (num < 10) singleDigitSum += num;
            else doubleDigitSum += num;
            totalSum += num;
        }

        // 1 자리수만 or 2자리수만 있는 경우 -> 앨리스가 무조건 이긴다.
        if (singleDigitSum == 0 or doubleDigitSum == 0)
        {
            return true;
        }

        // 1자리 숫자와 2자리 숫자의 합을 비교하여 Alice가 이길 수 있는지 판단
        const int bobSingleDigitSum = totalSum - singleDigitSum; // 앨리스가 한자리 숫자만 선택 후 밥의 값
        const int bobDoubleDigitSum = totalSum - doubleDigitSum; // 앨리스가 두자리수 선택후 남은 밥의 값

        if (singleDigitSum > bobSingleDigitSum) // 앨리스가 크면
        {
            return true;
        }
        else if(doubleDigitSum > bobDoubleDigitSum) // 앨리스가 크면
        {
            return true;
        }
        else // 밥이 큰경우
        {
            return false;
        }
    }
};

/*
### 3232. 숫자 게임을 이길 수 있는지 확인

**난이도: 쉬움**

#### 문제 설명
양의 정수 배열 `nums`가 주어집니다.

앨리스와 밥은 게임을 하고 있습니다. 게임에서 앨리스는 `nums`에서 한 자리 숫자 또는 두 자리 숫자 중 하나를 선택할 수 있으며, 나머지 숫자는 밥에게 주어집니다. 앨리스가 자신의 숫자의 합이 밥의 숫자의 합보다 엄격하게 큰 경우에 이깁니다.

앨리스가 이길 수 있으면 `true`를 반환하고, 그렇지 않으면 `false`를 반환하세요.

#### 예제

**예제 1**:

- 입력: `nums = [1,2,3,4,10]`
- 출력: `false`
- 설명:
  - 앨리스는 한 자리 숫자 또는 두 자리 숫자를 선택할 수 있지만, 어느 쪽을 선택해도 밥의 숫자의 합보다 크게 만들 수 없습니다.

**예제 2**:

- 입력: `nums = [1,2,3,4,5,14]`
- 출력: `true`
- 설명:
  - 앨리스는 한 자리 숫자를 선택하여 합이 15가 되도록 만들 수 있습니다.

**예제 3**:

- 입력: `nums = [5,5,5,25]`
- 출력: `true`
- 설명:
  - 앨리스는 두 자리 숫자를 선택하여 합이 25가 되도록 만들 수 있습니다.

#### 제약 조건

- `1 <= nums.length <= 100`
- `1 <= nums[i] <= 99`



input이 나올 수 있는 경우의 수

1. 1자리 숫자만 있는 경우
예제:

nums = [1, 2, 3, 4]
앨리스가 1자리 숫자만 선택할 수 있습니다.
밥은 숫자를 받을 수 없습니다.

앨리스의 합: 10
밥의 합: 0
앨리스는 항상 이길 수 있습니다.

2. 1자리 숫자와 2자리 숫자가 섞여 있는 경우
예제:

nums = [1, 2, 3, 14, 15]
앨리스는 1자리 숫자 또는 2자리 숫자를 선택할 수 있습니다.

앨리스가 1자리 숫자를 선택할 경우:
앨리스의 합: 6
밥의 합: 29 (14 + 15)
앨리스가 2자리 숫자를 선택할 경우:
앨리스의 합: 29
밥의 합: 6 (1 + 2 + 3)
이 경우, 앨리스가 2자리 숫자를 선택하면 이길 수 있습니다.

3. 2자리 숫자만 있는 경우
예제:

nums = [14, 15, 20]
앨리스가 2자리 숫자만 선택할 수 있습니다.
밥은 숫자를 받을 수 없습니다.

앨리스의 합: 49
밥의 합: 0
앨리스는 항상 이길 수 있습니다.


*/

// https://leetcode.com/problems/find-if-digit-game-can-be-won/description/
