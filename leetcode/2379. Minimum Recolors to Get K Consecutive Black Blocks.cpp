class Solution 
{
public:
    int minimumRecolors(const string& blocks, int k) 
    {
        int min_operations = INT_MAX;
        int current_white_blocks = 0;
        
        // 첫 번째 윈도우의 흰색 블록 수 계산
        for (size_t i = 0; i < k; ++i) 
        {
            if (blocks[i] == 'W') 
            {
                ++current_white_blocks;
            }
        }
        
        min_operations = current_white_blocks;
        
        // 슬라이딩 윈도우 이동
        for (size_t i = k; i < blocks.size(); ++i) 
        {
            if (blocks[i] == 'W') 
            {
                ++current_white_blocks;
            }
            if (blocks[i - k] == 'W') {
                --current_white_blocks;
            }
            
            min_operations = min(min_operations, current_white_blocks);
        }
        
        return min_operations;
    }
};
// https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/

/*

### 2379. K개의 연속된 검은 블록을 얻기 위한 최소 재색칠 횟수

**난이도: 쉬움**

#### 문제 설명
길이 n인 0-인덱스 문자열 `blocks`가 주어집니다. 여기서 `blocks[i]`는 i번째 블록의 색을 나타내며, 'W' 또는 'B' 중 하나입니다. 문자 'W'와 'B'는 각각 흰색과 검은색을 나타냅니다.

또한, k라는 정수가 주어지며, 이는 원하는 연속된 검은 블록의 수를 나타냅니다.

한 번의 작업에서 흰색 블록을 검은색 블록으로 재색칠할 수 있습니다.

k개의 연속된 검은 블록이 적어도 한 번 나타나도록 하는 데 필요한 최소 작업 수를 반환하세요.

#### 예제

**예제 1**:

- 입력: `blocks = "WBBWWBBWBW"`, `k = 7`
- 출력: `3`
- 설명:
  - 7개의 연속된 검은 블록을 얻기 위한 한 가지 방법은 0번째, 3번째, 4번째 블록을 재색칠하여 `blocks = "BBBBBBBWBW"`로 만드는 것입니다.
  - 7개의 연속된 검은 블록을 얻기 위해 3번 미만으로 작업을 수행하는 방법은 없으므로, 3을 반환합니다.

**예제 2**:

- 입력: `blocks = "WBWBBBW"`, `k = 2`
- 출력: `0`
- 설명:
  - 이미 2개의 연속된 검은 블록이 있으므로, 변경할 필요가 없습니다.
  - 따라서 0을 반환합니다.

#### 제약 조건

- `n == blocks.length`
- `1 <= n <= 100`
- `blocks[i]는 'W' 또는 'B'입니다.`
- `1 <= k <= n`
*/
