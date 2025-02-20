class Solution 
{
public:
    string findDifferentBinaryString(const vector<string> &nums)
    {
        assert(nums.size() >= MIN_NUMS_SIZE && nums.size() <= MAX_NUMS_SIZE);

        const size_t totalStrings = nums.size();

        for (const string &binaryStr : nums)
        {
            assert(binaryStr.size() == totalStrings);
            mExistingStrings.insert(binaryStr);
        }
        
        string currentCandidate;
        generateCandidateRecursive(currentCandidate, totalStrings);
        
        return mResultString;
    }

private:
    void generateCandidateRecursive(string &currentCandidate, const size_t targetLength)
    {
        if (!mResultString.empty())
        {
            return;
        }
        else if (currentCandidate.size() == targetLength)
        {
            if (mExistingStrings.find(currentCandidate) == mExistingStrings.end())
            {
                mResultString = currentCandidate;
            }
            return;
        }
        
        for (int i = 0; i < 2; i++)
        {
            const char nextChar = '0' + i;
            currentCandidate.push_back(nextChar);
            generateCandidateRecursive(currentCandidate, targetLength);
            currentCandidate.pop_back();
        }
    }

private:
    unordered_set<string> mExistingStrings;
    string mResultString;
    
    enum
    {
        MIN_NUMS_SIZE = 1,
        MAX_NUMS_SIZE = 16
    };
};

// https://leetcode.com/problems/find-unique-binary-string/description/?envType=daily-question&envId=2025-02-20

/*
다음은 문제 원문을 그대로 한국어로 번역한 내용입니다.

---

**1980. 고유한 이진 문자열 찾기**  
*Medium*  
*Topics*  
*Companies*  
*Hint*

길이가 n인 고유한 이진 문자열 n개를 포함하는 문자열 배열 **nums**가 주어집니다.  
**nums**에 나타나지 않는 길이 n의 이진 문자열을 반환하세요.  
만약 정답이 여러 개라면 그 중 아무 것이나 반환하면 됩니다.

---

**예제 1:**

입력: nums = ["01", "10"]  
출력: "11"  
설명: "11"은 **nums**에 나타나지 않습니다. "00"도 올바른 답입니다.

---

**예제 2:**

입력: nums = ["00", "01"]  
출력: "11"  
설명: "11"은 **nums**에 나타나지 않습니다. "10"도 올바른 답입니다.

---

**예제 3:**

입력: nums = ["111", "011", "001"]  
출력: "101"  
설명: "101"은 **nums**에 나타나지 않습니다. "000", "010", "100", "110"도 올바른 답입니다.

---

**제약 조건:**

- n == nums.length  
- 1 <= n <= 16  
- nums[i].length == n  
- nums[i]는 '0' 또는 '1'로만 구성되어 있습니다.  
- nums의 모든 문자열은 고유합니다.
*/
