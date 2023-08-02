class Solution 
{
public:
    int compress(vector<char>& chars) 
    {
        int i = 0;              
        int index = 0;
        int ARR_SIZE = chars.size();
        
        // 주어진 배열에서 순차적으로 읽는다.
        while (i < ARR_SIZE) {
            char current = chars[i];
            int count = 1;
            
            // 인덱스를 증가시키면서(다음 원소로 접근) 이전 원소와 현재 원소가 같은지 확인한다.
            while (++i < ARR_SIZE && chars[i] == current) {
                count++; // 이전 원소와 현재 원소가 같으면 count를 증가한다.
            }
            
            chars[index++] = current;
            
            if (count > 1) { 
                for (char& ch : to_string(count)) {
                    chars[index++] = ch;
                }
            }
        }
        
        return index;
    }
};