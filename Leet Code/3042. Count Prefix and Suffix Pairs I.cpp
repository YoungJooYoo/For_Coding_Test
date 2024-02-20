class Solution {
public:
    bool isPrefixAndSuffix (const string& str1, const string& str2)
    {   
        const size_t STR1_LEN = str1.size();
        const size_t STR2_LEN = str2.size();

        int i = 0;
        int j = 0;
        while (i < STR1_LEN && j < STR2_LEN && str1[i] == str2[j]) {
            ++i;
            ++j;
        }
        if (i != STR1_LEN) {
            return false;
        }

        i = STR1_LEN - 1;
        j = STR2_LEN - 1;
        while (i >= 0 && j >= 0 && str1[i] == str2[j]) {
            --i;
            --j;
        }

        return i == -1 ? true : false;
    } // str1이 str2만큼 길이를 순회했는지, 순회했다면 마지막 인덱스의 위치는 정해져있으니 이걸로 판별

    int countPrefixSuffixPairs(const vector<string>& words) 
    {
        const size_t LEN = words.size();
        int count = 0;

        for (size_t i = 0; i < LEN; ++i) {
            const string& str1 = words[i];
            for (size_t j = i + 1; j < LEN; ++j) {
                const string& str2 = words[j];
                if (isPrefixAndSuffix(str1, str2) == true) {
                    ++count;
                }
            }
        }

        return count;
    }
};

// https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/

/*

### 시간 복잡도

1. **`isPrefixAndSuffix` 함수**: 이 함수는 두 문자열 `str1`과 `str2`를 비교합니다. 최악의 경우, `str1`의 길이를 `n`이라 하고, `str2`의 길이를 `m`이라 할 때, 접두사 검사와 접미사 검사 모두 `O(n)` 시간이 걸립니다. 여기서 `n`은 `str1`의 길이이며, `m >= n`입니다. 따라서, 이 함수의 시간 복잡도는 `O(n)`입니다.

2. **`countPrefixSuffixPairs` 함수**: 이 함수는 `words` 배열의 모든 가능한 쌍에 대해 `isPrefixAndSuffix` 함수를 호출합니다. `words` 배열의 길이를 `L`이라 할 때, 가능한 모든 쌍의 수는 `L*(L-1)/2`입니다. 각 쌍에 대해 `isPrefixAndSuffix` 함수를 호출하므로, 최악의 경우 각 문자열 쌍의 비교에 `O(n)` 시간이 소요됩니다. 여기서 `n`은 최대 문자열 길이입니다. 따라서, 전체 시간 복잡도는 `O(L^2 * n)`입니다.

### 공간 복잡도

1. **`isPrefixAndSuffix` 함수**: 이 함수는 추가적인 공간을 사용하지 않으며, 입력 문자열에 대한 인덱스 변수만 사용합니다. 따라서, 공간 복잡도는 `O(1)`입니다.

2. **`countPrefixSuffixPairs` 함수**: 이 함수 역시 입력 배열 `words`를 제외하고는 추가적인 공간을 사용하지 않습니다. `isPrefixAndSuffix` 함수 호출 시에도 추가적인 메모리 할당이 발생하지 않으므로, 전체 공간 복잡도는 `O(1)`입니다.

### 결론

- **시간 복잡도**: `O(L^2 * n)` 여기서 `L`은 `words` 배열의 길이이고, `n`은 배열 내 문자열의 최대 길이입니다.
- **공간 복잡도**: `O(1)`, 추가적인 공간을 사용하지 않습니다.

이러한 복잡도 분석은 알고리즘의 효율성을 이해하는 데 중요합니다. 특히, 큰 입력 사이즈나 문자열 길이에 대해 성능 저하가 발생할 수 있음을 알 수 있습니다.
*/
