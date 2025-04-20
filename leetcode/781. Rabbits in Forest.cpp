class Solution 
{
public:
    int numRabbits(const vector<int>& answers) const 
    {
        assert(answers.size() >= MIN_SIZE && answers.size() <= MAX_SIZE);
        
        unordered_map<int,int> freq;
        int result = 0;

        for (const int x : answers) 
        {
            assert(x >= MIN_ANSWER && x < MAX_ANSWER);
            ++freq[x];
        }
                
        for (const auto& [x, count] : freq) 
        {
            const int groupSize = x + 1;            
            const int groups = (count + groupSize - 1) / groupSize; // 필요한 그룹 수 = ceil(count / groupSize)
            result += groups * groupSize;
        }
        
        return result;
    }

private:
    enum {
        MIN_SIZE     = 1,
        MAX_SIZE     = 1000,
        MIN_ANSWER   = 0,
        MAX_ANSWER   = 1000
    };
};

// https://leetcode.com/problems/rabbits-in-forest/description/?envType=daily-question&envId=2025-04-20

/*
**781. 숲속의 토끼**

**난이도:** 중간

**문제 설명:**  
숲속에는 토끼들이 여러 마리 살고 있으며, 전체 마릿수는 알 수 없습니다.  
n마리의 토끼에게 “당신과 같은 색깔인 토끼가 총 몇 마리인가요?”라고 물었고, 각 토끼의 답변을 정수 배열 **answers**에 모았습니다. 여기서 **answers[i]**는 i번째 토끼의 답변입니다.

배열 **answers**가 주어질 때, 숲속에 있을 수 있는 토끼의 **최소** 마릿수를 구하여 반환하세요.

---

**예제 1:**

- **입력:** answers = [1,1,2]  
- **출력:** 5  
- **설명:**  
  - “1”이라고 답한 두 토끼는 같은 색(예: 빨간색)일 수 있습니다.  
  - “2”라고 답한 토끼는 빨간색일 수 없으므로, 예: 파란색이라고 합시다.  
  - 파란색 토끼는 이 토끼 이외에 답하지 않은 다른 2마리가 더 있어야 하므로,  
    - 답한 토끼 3마리 + 답하지 않은 파란색 토끼 2마리 = 최소 5마리입니다.

---

**예제 2:**

- **입력:** answers = [10,10,10]  
- **출력:** 11  
- **설명:**  
  “10”이라고 답한 3마리는 같은 색으로 묶어서,  
  해당 색의 토끼는 총 11마리가 있어야 합니다.

---

**제약 조건:**

- 1 ≤ answers.length ≤ 1000  
- 0 ≤ answers[i] < 1000
*/
