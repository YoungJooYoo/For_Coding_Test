class Solution {
public:
    bool wordPattern(string pattern, string s)
    {
        vector<string> v;
        string word; 
        stringstream iss(s); // 문자열 분리하기
        char ch;
        
        while (iss >> word) { // word에 공백 및 스페이스 분리된 문자열을 넣는다.
            v.push_back(word); // 공백이 제거된 각 문자열이 백터에 저장
        }
            
        set<string> S; // 같은 단어가 다른 문자와 매핑되지 않았는지 확인.
        
        if (pattern.size() != v.size()) { // 벡터와 패턴의 크기가 다른 경우 매핑이 불가능.  ex) a = dog,  b = cat  abba(4개 문자)  = dog cat cat dog(문자열 4덩이)  
            return false;
        }
            
        unordered_map<char, string> m; // 정렬하지 않은 맵  문자-문자열 매핑, [a = dog] [b = cat] 매핑을 위해
        
        for (size_t i = 0; i < pattern.size(); i++) {
            ch = pattern[i]; // 패턴의 현재 문자 가져오기.
            if (m.find(ch) != m.end()) { // 현재 캐릭터가 맵에 존재하는 경우,   == m.end 인경우 ch가 없다 의미.
                if (m[ch] != v[i]) {// 해당 문자에 매핑된 문자열이 다른지 여부를 확인합니다.
                    return false;
                }
            }
            else { // 지도에 없는 경우
                // 문자열이 이전에 set에 있는지 확인
                 // set에 있으면 이미 매핑되어 있음을 의미합니다. return false
                if (S.count(v[i]) > 0) {
                    return false;
                }
                m[ch] = v[i]; // 다른 현명한 방법은 지도에 삽입하고 설정합니다.
                S.insert(v[i]);
            }
        }
        
        return true;
    }
};