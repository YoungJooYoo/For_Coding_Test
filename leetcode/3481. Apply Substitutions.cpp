class Solution 
{
public:
    string applySubstitutions(const vector<vector<string>>& replacements, const string& text) 
    {
        assert(MIN_REPLCAEMENTS_LENGTH <= replacements.size() && replacements.size() <= MAX_REPLCAEMENTS_LENGTH);
        assert(text.length() == 4 * replacements.size() -1);

        for (const auto& replacement : replacements)
        {
            const string& key = replacement[0];
            const string& value = replacement[1];
            substitutionMap[key] = value; 
            assert(value.size() <= MAX_VALUE_LENGTH);
        }
        assert(substitutionMap.size() == replacements.size());

        return applySubstitutionsHelperRecursive(text);
    }

private:
    string applySubstitutionsHelperRecursive(const string& text) const
    {
        if (isFullySubstituted(text) == true)
        {
            return text;
        }
        
        const size_t textLength = text.size();
        string result;
        size_t index = 0;
        while (index < textLength)
        {
            if (index + 2 < textLength && text[index] == '%' && isalpha(text[index + 1]) && text[index + 2] == '%')
            {   
                assert('A' <= text[index + 1] && text[index + 1] <= 'Z'); 
                string placeholderKey; // 플레이스홀더에서 키 추출 (예: "%A%" → "A")
                placeholderKey.push_back(text[index + 1]);
                
                const auto& it = substitutionMap.find(placeholderKey); // substitutionMap에서 치환 값 검색
                if (it != substitutionMap.end())
                {
                    result += it->second;
                }
                else
                {
                    result.append(text, index, 3); // 매핑에 없는 경우 원래 패턴 그대로 복사
                }
                
                index += 3; // 플레이스홀더 3문자 건너뛰기
            }
            else
            {
                result.push_back(text[index]);
                ++index;
            }
        }
        
        assert(result.size() >= 1);
        return applySubstitutionsHelperRecursive(result);
    }
    
    bool isFullySubstituted(const string& text) const
    {
        for (size_t i = 0, len = text.size(); i + 2 < len; ++i)
        {
            if (text[i] == '%' && isalpha(text[i + 1]) && text[i + 2] == '%')
            {
                return false;
            }
        }

        return true;
    }

private:
    unordered_map<string, string> substitutionMap;

    enum
    {
        MIN_REPLCAEMENTS_LENGTH = 1,
        MAX_REPLCAEMENTS_LENGTH = 10,
        MAX_VALUE_LENGTH = 8,
    };
};


// https://leetcode.com/problems/apply-substitutions/description/


/*


**3481. Apply Substitutions**

**난이도:** 중간

**문제 설명:**  
replacements 매핑과 텍스트 문자열이 주어집니다. 텍스트 문자열에는 %var% 형식의 플레이스홀더가 포함될 수 있으며, 여기서 각 var는 replacements 매핑의 키에 해당합니다. 각 replacement 값은 하나 이상의 플레이스홀더를 포함할 수 있고, 모든 플레이스홀더는 해당 키와 연결된 값으로 대체됩니다.

플레이스홀더가 전혀 남지 않은, 완전히 치환된 텍스트 문자열을 반환하세요.

---

**예제 1:**

- **입력:**  
  replacements = [["A","abc"],["B","def"]], text = "%A%_%B%"
- **출력:**  
  "abc_def"
- **설명:**  
  매핑은 "A"를 "abc"에, "B"를 "def"에 연결합니다. 텍스트에서 %A%를 "abc"로, %B%를 "def"로 대체하면 최종 텍스트는 "abc_def"가 됩니다.

---

**예제 2:**

- **입력:**  
  replacements = [["A","bce"],["B","ace"],["C","abc%B%"]], text = "%A%_%B%_%C%"
- **출력:**  
  "bce_ace_abcace"
- **설명:**  
  매핑은 "A"를 "bce", "B"를 "ace", "C"를 "abc%B%"에 연결합니다. 텍스트에서 %A%를 "bce", %B%를 "ace"로 대체한 후, %C%의 경우 "abc%B%" 내부에서 %B%를 "ace"로 대체하여 "abcace"를 얻습니다. 최종 텍스트는 "bce_ace_abcace"가 됩니다.

---

**제약 조건:**

- 1 <= replacements.length <= 10  
- replacements의 각 원소는 두 요소 [key, value]로 구성되며,  
  - key는 단일 대문자 영어 알파벳입니다.  
  - value는 최대 8자의 비어있지 않은 문자열이며, 0개 이상의 %<key>% 형식의 플레이스홀더를 포함할 수 있습니다.
- 모든 replacement 키는 고유합니다.
- 텍스트 문자열은 replacements 매핑의 키 플레이스홀더들(형식: %<key>%)을 밑줄(_)로 구분하여 임의로 연결하여 구성됩니다.
- text.length == 4 * replacements.length - 1  
- 텍스트나 각 replacement 값에 있는 모든 플레이스홀더는 replacements 매핑의 키에 해당합니다.
- replacement 키들 간에 순환 종속성은 없습니다.

---

**힌트 1:**  
각 키를 노드로 하는 의존성 그래프를 구성하고, 만약 replacement 값에 플레이스홀더 %X%가 포함되어 있다면, 키 X에서 키 Y로 간선을 추가합니다. 이후, 위상 정렬을 수행하여 유효한 치환 순서를 결정합니다.

**힌트 2:**  
위상 정렬 순서에 따라 각 키를 처리하면서, 각 replacement 값 내의 플레이스홀더를 그 키에 대한 완전히 치환된 값으로 대체합니다. 마지막으로, 이 치환된 값들을 사용하여 텍스트 문자열 내의 플레이스홀더들을 모두 대체합니다.

---

이 번역이 문제의 내용을 명확하게 이해하는 데 도움이 되길 바랍니다.*/
