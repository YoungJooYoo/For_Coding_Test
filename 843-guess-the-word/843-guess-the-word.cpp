class Solution {
public:
    int match(string w1, string w2, int res = 0) 
    {
        for (size_t i = 0; i < w1.size(); ++i) {
            if (w1[i] == w2[i]) {
                ++res;
            }
        }
        return res;
    }
        
    string bestCandidate(list<string>& words, vector<vector<int>> &probs, int m_scr = 0, string best = "") {
      for (const auto& w : words) {
        int score = 1;
        for (auto i = 0; i < 6; ++i) {
            score *= probs[i][w[i] - 'a'];
        }
        if (score > m_scr) {
            m_scr = score;
            best = w;
        }
      }
      return best;
    }
        
    void findSecretWord(vector<string>& wordlist, Master& master, int res = 0) 
    {
        vector<vector<int>> probs(6, vector<int>(26));
        list<string> remWords;
        for (const auto& w : wordlist) {
            remWords.push_back(w);
            for (size_t i = 0; i < 6; ++i) {
                probs[i][w[i] - 'a'] += 1;
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