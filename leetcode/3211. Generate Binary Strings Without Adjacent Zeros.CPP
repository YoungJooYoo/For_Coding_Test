class Solution 
{
public:
    vector<string> validStrings(const int n) 
    {
        validStringsHelper(n);
        return mResult;
    }

private:
    void validStringsHelper(const int n) 
    {
        if (mCurrent.length() == n) // 재귀함수 종료 조건
        {
            mResult.push_back(mCurrent);
            return;
        }

        if (mCurrent.empty() || mCurrent.back() == '1') 
        {
            mCurrent.push_back('0');
            validStringsHelper(n);
            mCurrent.pop_back();
        }
        mCurrent.push_back('1');
        validStringsHelper(n);
        mCurrent.pop_back();
    }

    vector<string> mResult;
    string mCurrent;
};

// https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros/description/

/*
### 3211. 인접한 0이 없는 이진 문자열 생성

**난이도: 중간**

#### 문제 설명

양의 정수 `n`이 주어집니다.

이진 문자열 `x`는 길이가 2인 모든 부분 문자열에 적어도 하나의 "1"이 포함된 경우 유효합니다.

길이가 `n`인 모든 유효한 문자열을 반환하세요. 반환 순서는 상관없습니다.

#### 예제

**예제 1**:

- 입력: `n = 3`
- 출력: `["010", "011", "101", "110", "111"]`
- 설명:
  - 길이가 3인 유효한 문자열은: `"010"`, `"011"`, `"101"`, `"110"`, `"111"`입니다.

**예제 2**:

- 입력: `n = 1`
- 출력: `["0", "1"]`
- 설명:
  - 길이가 1인 유효한 문자열은: `"0"`, `"1"`입니다.

#### 제약 조건

- `1 <= n <= 18`

---
*/
