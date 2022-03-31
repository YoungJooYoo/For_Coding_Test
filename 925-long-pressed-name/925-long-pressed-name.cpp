class Solution {
public:
   bool isLongPressedName(string name, string typed)
   {
       size_t i = 0;
       size_t j = 0;
       
        while (j < typed.size()) {
            if (i < name.size() && name[i] == typed[j]) { // 두 문자열을 비교, 같다면 인덱스 증가
                ++i; 
                ++j;
            }        
            else if (i > 0 && name[i - 1] == typed[j]) { // 같지 않다면, 중복 문자 발견하면 j인덱스만 올린다.
                ++j;
            }
            else {
                return false;
            }
        }
       
        // 리턴하는 i의 인덱스가 name size와 같으면, 모든 문자열을 포함했다는 의미이므로
        return i == name.size() ? true : false;
    }
};