class Solution {
public:
    vector<string> subdomainVisits(const vector<string>& cpdomains) 
    {
        unordered_map<string, int> subdomainCounts;
        vector<string> result;

        for (const string& cpdomainStr : cpdomains) 
        { 
            int count;
            size_t currentDotPos = 0; 
            string fullDomainName;

            istringstream lineStream(cpdomainStr);
            lineStream >> count >> fullDomainName;
            subdomainCounts[fullDomainName] += count; // {fullDomainName, count} : map

            while ((currentDotPos = fullDomainName.find('.', currentDotPos)) != string::npos) 
            {
                const string subdomain = fullDomainName.substr(currentDotPos + 1);
                subdomainCounts[subdomain] += count;
                ++currentDotPos; 
            }
        }

        for (const auto& entry : subdomainCounts) 
        {
            result.push_back(to_string(entry.second) + " " + entry.first);
        }

        return result;
    }
};

/*
https://leetcode.com/problems/subdomain-visit-count/description/

## 811. 서브도메인 방문 횟수

웹사이트 도메인 "discuss.leetcode.com"은 다양한 서브도메인으로 구성됩니다. 최상위 레벨에는 "com"이 있고, 다음 레벨에는 "leetcode.com", 그리고 최하위 레벨에는 "discuss.leetcode.com"이 있습니다. "discuss.leetcode.com"과 같은 도메인을 방문할 때, 상위 도메인인 "leetcode.com"과 "com"도 암시적으로 함께 방문하게 됩니다.

**방문 횟수-쌍 도메인(count-paired domain)**은 "rep d1.d2.d3" 또는 "rep d1.d2" 두 가지 형식 중 하나를 가지는 도메인으로, 여기서 `rep`는 해당 도메인의 방문 횟수를 나타내고 `d1.d2.d3`는 도메인 자체를 나타냅니다.

예를 들어, "9001 discuss.leetcode.com"은 discuss.leetcode.com이 9001번 방문되었음을 나타내는 방문 횟수-쌍 도메인입니다.

방문 횟수-쌍 도메인 배열 `cpdomains`가 주어지면, 입력된 각 도메인의 모든 서브도메인에 대한 방문 횟수-쌍 도메인을 배열로 반환하세요. 반환되는 순서는 상관없습니다.

---

**예제 1:**

**입력:** `cpdomains = ["9001 discuss.leetcode.com"]`
**출력:** `["9001 leetcode.com","9001 discuss.leetcode.com","9001 com"]`
**설명:** 하나의 웹사이트 도메인 "discuss.leetcode.com"만 있습니다. 위에서 설명했듯이, 서브도메인 "leetcode.com"과 "com"도 함께 방문됩니다. 따라서 이들 모두 9001번 방문됩니다.

**예제 2:**

**입력:** `cpdomains = ["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]`
**출력:** `["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]`
**설명:** 우리는 "google.mail.com"을 900번, "yahoo.com"을 50번, "intel.mail.com"을 1번, "wiki.org"를 5번 방문할 것입니다.
서브도메인들의 경우, "mail.com"은 900 + 1 = 901번 방문되고, "com"은 900 + 50 + 1 = 951번 방문되며, "org"는 5번 방문됩니다.

---

**제약 조건:**

*   `1 <= cpdomains.length <= 100`
*   `1 <= cpdomains[i].length <= 100`
*   `cpdomains[i]`는 "repi d1i.d2i.d3i" 형식 또는 "repi d1i.d2i" 형식을 따릅니다.
*   `repi`는 `[1, 10^4]` 범위의 정수입니다.
*   `d1i`, `d2i`, `d3i`는 소문자 영어 알파벳으로 구성됩니다.
*/
