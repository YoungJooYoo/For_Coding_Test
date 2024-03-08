class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) 
    {
        const size_t ARRAY_LENGTH = words.size();
        vector<string> result;

        result.push_back(words[0]);
        int prev_group = groups[0];
        for (size_t  i = 1; i < ARRAY_LENGTH; ++i) {
            if (prev_group != groups[i]) {
                result.push_back(words[i]);
            }
            prev_group = groups[i];
        }
        
        return result;
    }
};

/*
### 문제 번역

길이가 n인 문자열 배열 `words`와 이진 배열 `groups`가 주어집니다. 여기서 `words[i]`는 `groups[i]`와 연결됩니다.

당신의 임무는 `words`에서 가장 긴 교대 부분 수열을 선택하는 것입니다. `words`의 부분 수열이 교대한다는 것은 수열의 연속된 두 문자열에 대해, 
이진 배열 `groups`에서 해당하는 요소들이 서로 다르다는 것을 의미합니다. 기본적으로, `groups` 배열에서 인접한 요소들이 서로 다른 해당 비트를 가지도록 문자열을 선택해야 합니다.

공식적으로, [0, 1, ..., n - 1]의 인덱스 배열의 가장 긴 부분 수열 [i0, i1, ..., ik-1]을 찾아야 하며, 
각각에 대해 `groups[ij] != groups[ij+1]`이어야 합니다 (각각에 대해 0 <= j < k - 1). 그리고 이 인덱스에 해당하는 단어들을 찾아야 합니다.

선택된 부분 수열을 반환합니다. 여러 답이 가능한 경우, 그 중 하나를 반환하세요.

`words`의 요소는 서로 다릅니다.

### 예시

1. 입력: `words = ["e","a","b"]`, `groups = [0,0,1]`
   출력: `["e","b"]`
   설명: 선택할 수 있는 부분 수열은 `["e","b"]`입니다. 왜냐하면 `groups[0] != groups[2]`이기 때문입니다. 
   또 다른 선택 가능한 부분 수열은 `["a","b"]`이며, `groups[1] != groups[2]`입니다. 조건을 만족하는 가장 긴 인덱스 부분열의 길이가 2임을 증명할 수 있습니다.

2. 입력: `words = ["a","b","c","d"]`, `groups = [1,0,1,1]`
   출력: `["a","b","c"]`
   설명: 선택할 수 있는 부분 수열은 `["a","b","c"]`이며, `groups[0] != groups[1]` 그리고 `groups[1] != groups[2]`입니다. 
   또 다른 선택 가능한 부분 수열은 `["a","b","d"]`이며, `groups[0] != groups[1]` 그리고 `groups[1] != groups[3]`입니다. 조건을 만족하는 가장 긴 인덱스 부분열의 길이가 3임을 알 수 있습니다.

### 요약

주어진 문자열 배열 `words`와 이진 배열 `groups`를 사용하여, `groups` 배열에서 인접한 요소의 값이 다른 문자열들로 구성된 가장 긴 교대 부분 수열을 찾는 문제입니다. 
선택된 부분 수열은 `groups` 배열에서 인접한 요소가 서로 다른 값을 가질 때 해당하는 `words`의 문자열들로 구성됩니다. 가능한 가장 긴 부분 수열을 찾아 반환해야 합니다.

*/
