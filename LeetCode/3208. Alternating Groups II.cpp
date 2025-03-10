class Solution 
{
public:
    int numberOfAlternatingGroups(const vector<int>& colors, const int k) 
    {
        const size_t n = colors.size();
        
        vector<bool> diff(n);

        for (size_t i = 0; i < n; ++i)
        {
            const size_t next = (i + 1) % n;
            diff[i] = (colors[i] != colors[next]) ? true : false;
        }
        
        vector<bool> doubledDiff(diff); // diff 배열을 두 배로 확장하여 원형 효과를 쉽게 처리
        for (size_t i = 0; i < n; ++i)
        {
            doubledDiff.push_back(diff[i]);
        }
        
        vector<int> prefix(2 * n + 1, 0); // doubledDiff의 prefix sum 계산
        for (size_t i = 0; i < 2 * n; ++i)
        {
            prefix[i + 1] = prefix[i] + doubledDiff[i];
        }
        
        int alternatingGroupCount = 0;
        for (size_t start = 0; start < n; ++start)
        {
            const int groupSum = prefix[start + k - 1] - prefix[start];
            if (groupSum == k - 1)
            {
                ++alternatingGroupCount;
            }
        }
        
        return alternatingGroupCount;
    }
};

// https://leetcode.com/problems/alternating-groups-ii/description/?envType=daily-question&envId=2025-03-09


/*

아래는 문제의 국문 번역입니다.

---

**3208. Alternating Groups II**

**난이도:** 중간

**문제 설명:**  
빨간색과 파란색 타일이 원형으로 배열되어 있습니다. 정수 배열 **colors**와 정수 **k**가 주어지며, 타일 i의 색상은 **colors[i]**로 나타냅니다.

- **colors[i] == 0** → 타일 i는 빨간색입니다.  
- **colors[i] == 1** → 타일 i는 파란색입니다.

**교대 그룹(alternating group)**이란 원형에서 연속된 **k**개의 타일로 이루어진 그룹으로, 그룹 내에서 타일들의 색상이 번갈아 나타나야 합니다.  
(즉, 그룹의 첫 번째와 마지막 타일을 제외한 각 타일은 양 옆의 타일과 다른 색이어야 합니다.)

**문제:**  
모든 교대 그룹의 개수를 반환하세요.  
※ 주의: **colors** 배열이 원형을 나타내므로, 첫 번째 타일과 마지막 타일은 서로 인접한 것으로 간주합니다.

---

**예제 1:**

- **입력:** colors = [0,1,0,1,0], k = 3  
- **출력:** 3  
- **설명:**  
  교대 그룹의 예시들이 주어집니다.

---

**예제 2:**

- **입력:** colors = [0,1,0,0,1,0,1], k = 6  
- **출력:** 2  
- **설명:**  
  교대 그룹의 예시들이 주어집니다.

---

**예제 3:**

- **입력:** colors = [1,1,0,1], k = 4  
- **출력:** 0  
- **설명:**  
  교대 그룹이 형성되지 않는 예시입니다.

---

**제약 조건:**

- 3 <= colors.length <= 10^5  
- 0 <= colors[i] <= 1  
- 3 <= k <= colors.length

---

**힌트:**

1. 인접한 다음 타일과 같은 색을 가지는 타일이 있는지 확인해보세요.
2. 그러한 타일을 시작점으로 하여 하나의 for 루프 내에서 최대한 큰 교대 그룹을 찾아보세요.
*/
