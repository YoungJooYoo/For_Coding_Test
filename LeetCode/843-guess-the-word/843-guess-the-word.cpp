class Solution {
public:
    int match(string w1, string w2, int res = 0) // 알파벳들이 얼마나 매치되는지 반환하는 함수
    {
        for (size_t i = 0; i < w1.size(); ++i) {
            if (w1[i] == w2[i]) {
                ++res;
            }
        }
        
        return res;
    }
        
    string bestCandidate(list<string>& words, vector<vector<int>> &probs, int m_scr = 0, string best = "") 
    {
        for (const auto& word : words) {
            int score = 1;
            for (size_t i = 0; i < 6; ++i) {
                score *= probs[i][word[i] - 'a'];
            }
            if (score > m_scr) {
                m_scr = score;
                best = word;
            }
        }
        
        return best;
    }
        
    void findSecretWord(vector<string>& wordlist, Master& master, int res = 0) 
    {
        vector<vector<int>> probs(6, vector<int>(26)); // 6 * 26(알파벳갯수) 배열을 만든다. 
        list<string> remWords; // 연결리스트로 단어를 저장한다.
        
        for (const auto& word: wordlist) {
            remWords.push_back(word); // 리스트에 단어들을 연결한다.
            for (size_t i = 0; i < 6; ++i) {
                probs[i][word[i] - 'a'] += 1; // 알파벳 빈도수를 체크한다. 즉 6개의 문자열, 문자열의 길이는 6
            }
        }
        
        while (res < 6) {
            string candidate = bestCandidate(remWords, probs);
            res = master.guess(candidate);
            for (auto it = remWords.begin(); it != remWords.end();) {
                if (match(*it, candidate) != res) {
                    for (size_t i = 0; i < 6; ++i) {
                        probs[i][(*it)[i] - 'a'] -= 1;
                    }
                    it = remWords.erase(it);
                }
                else ++it;
            }
         }
    }
};

/*
풀이법 :

문제는 주어진 문자열을 저장한 배열에
secret 문자가 무엇인지 알아 맞추는 것이다.

이 문자열이 master.guess()를 호출하고
전혀 char 전혀 매칭되는게없으면 -1
일부 맞으면 맞은갯수 만큼 반환해서

6 자리로 이루어진 scret 문자열이 무엇인지 찾는 것이다.

즉, 6개의 word가 주어지고, 각 word는 6자리로 구성되어있다.

이 단어마다, 알파벳 빈도수를 체크한다.
*/