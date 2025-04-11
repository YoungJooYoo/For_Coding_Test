class Solution 
{
public:
    string findContestMatch(const int n)
    {
        assert(n % 2 == 0);
        assert((1 << MIN_RANGE) <= n && n <= (1 << MAX_RANGE));
        
        vector<string> teams;

        for (int i = 1; i <= n; ++i)
        {
            teams.push_back(to_string(i));
        }
        
        return buildContestMatch(teams);
    }
    
private:
    string buildContestMatch(const vector<string>& teams) const 
    {
        if (teams.size() == 1)
        {
            assert(teams[0].size() > 0);
            return teams[0];
        }
        
        vector<string> nextRound;     
        const int size = teams.size();
      
        for (int i = 0; i < size / 2; ++i) 
        {
            const string match = "(" + teams[i] + "," + teams[size - 1 - i] + ")";
            nextRound.push_back(match);
        }

        return buildContestMatch(nextRound);
    }
    
    enum 
    {
        MIN_RANGE = 1,
        MAX_RANGE = 12,
    };
};

// https://leetcode.com/problems/output-contest-matches/description/

/*

---

**544. 대회 경기 결과 출력**

**난이도:** 중간

**문제 설명:**  
NBA 플레이오프에서는 보통 강팀과 약팀을 맞붙게 하여 경기를 더 흥미롭게 만드는 전략을 사용합니다. 예를 들어, 1위(가장 강한 팀)와 n위(가장 약한 팀)를 맞붙게 하는 방식입니다.

n개의 팀이 주어지면, 이 팀들의 최종 경기 대진표를 문자열 형식으로 반환하세요.

- 팀들은 1부터 n까지 번호가 매겨져 있으며, 이 번호는 초기 순위를 나타냅니다 (즉, 1위는 가장 강한 팀, n위는 가장 약한 팀입니다).
- 대진표는 괄호 '(', ')'와 쉼표 ','를 사용하여 표현합니다.
  - 괄호는 팀들의 짝을 묶기 위해 사용하고, 쉼표는 구분(분할)을 위해 사용합니다.
- 각 라운드에서 팀들을 짝지을 때, 항상 강팀과 약팀이 서로 맞붙도록 합니다.

---

**예제 1:**

- **입력:** n = 4  
- **출력:** "((1,4),(2,3))"  
- **설명:**  
  첫 번째 라운드에서는 1번 팀과 4번 팀, 2번 팀과 3번 팀을 짝지어 대진표를 만듭니다.  
  두 번째 라운드에서는 두 경기의 승자가 다시 맞붙게 되므로, 전체 대진표는 "((1,4),(2,3))"이 됩니다.

---

**예제 2:**

- **입력:** n = 8  
- **출력:** "(((1,8),(4,5)),((2,7),(3,6)))"  
- **설명:**  
  첫 번째 라운드: (1,8), (2,7), (3,6), (4,5)  
  두 번째 라운드: ((1,8),(4,5)), ((2,7),(3,6))  
  세 번째 라운드: (((1,8),(4,5)),((2,7),(3,6)))  
  최종 대진표는 "(((1,8),(4,5)),((2,7),(3,6)))"가 됩니다.

---

**제약 조건:**

- 1 <= n <= 2 * 10⁴

---
*/
