class Solution 
{
public:
    string reorganizeString(string s) 
    {
        unordered_map<char, int> char_freq;
        priority_queue<pair<int, char>> pq;
        const size_t STR_SIZE = s.size();
        string result;
        
        if (STR_SIZE == 0) {
            return result;
        }

        // 해시테이블로 갯수 카운트
        for (const char& ch : s) {
            char_freq[ch]++;
        }
        // 우선순위 큐에 데이터 넣기
        for (const auto& elem : char_freq) {
            pq.push({elem.second, elem.first}); // push {freq, char} !!
        }
        
        // a, b 동시에 2개씩 빼야하므로 size는 항상 1보다 커야한다.
        while (pq.size() > 1) {
            auto a = pq.top(); pq.pop(); // 자주 등장하는 순위 2개를 뽑아온다.
            auto b = pq.top(); pq.pop();
            a.first--; // 문자를 사용했으니, 사용 빈도를낮춘다.
            b.first--;
            
            result += a.second;
            result += b.second;
            
            // 알파벳이(first) 아직 남았다면, 다시 우선순위 큐에 넣는다.
            if (a.first > 0) {
                pq.push(a);
            }
            if (b.first > 0) {
                pq.push(b);
            } 
        }
        
        // while 문에서 pq.size가 1이 남았을 경우부터 시작
        if (pq.size() > 0) {
            if (pq.top().first > 1) { // 문제의 조건을 만족 못하므로 빈 문자열 반환
                return "";
            } 
            else { // 마지막 남은 원소를 붙여서 반환 
                result += pq.top().second;
            }
        }
        
        return result;
    } 
};