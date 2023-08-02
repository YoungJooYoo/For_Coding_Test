class Solution 
{
public:
    int largestVariance(string s) 
    {
        int result = 0;
        
        // 알파벳 빈도수를 찾는다. 최대빈도 최소빈도를 이용해 구한다.
        for (char highFreqChar = 'a'; highFreqChar <= 'z'; ++highFreqChar) {
            for (char lowFreqChar = 'a'; lowFreqChar <= 'z'; ++lowFreqChar) {
                if (highFreqChar == lowFreqChar) continue;
                int highFreq = 0;
                int lowFreq = 0;
                bool lowFreqAbandoned = false;

                for (const char& ch : s) {
                    if (ch == highFreqChar) ++highFreq; // 최빈출 알파벳 체크
                    if (ch == lowFreqChar) ++lowFreq;
                    
                    if (lowFreq > 0) { // 한개문자 몰빵 케이스 걸러내기
                        result = max(result, highFreq - lowFreq);
                    } 
                    else if (lowFreq == 0) { // lowFreq == 0;
                        if (lowFreqAbandoned == true) { 
                            result = max(result, highFreq - 1); 
                        }
                    }
    
                    if (lowFreq > highFreq) {
                        lowFreq = 0; // 값 초기화
                        highFreq = 0;
                        lowFreqAbandoned = true; // low 빈도수 버리기
                    }
                }
            }
        }
        
        return result;
    }
};