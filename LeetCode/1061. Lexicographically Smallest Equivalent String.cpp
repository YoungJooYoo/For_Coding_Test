class Solution 
{
public:
    string smallestEquivalentString(const string& s1, const string& s2, const string& baseStr) const
    {
        assert(s1.size() == s2.size());
        assert(MIN_LENGTH <= s1.size() && s1.size() <= MAX_LENGTH);
        assert(MIN_LENGTH <= s2.size() && s2.size() <= MAX_LENGTH);
        assert(MIN_LENGTH <= baseStr.size() && baseStr.size() <= MAX_LENGTH);

        vector<int> parent(ALPHABET_LENGTH);
        string result = baseStr;

        for (int i = 0; i < ALPHABET_LENGTH; ++i)
        {
            parent[i] = i;
        }

        for (size_t i = 0; i < s1.size(); ++i) // s1[i] 와 s2[i] 를 같은 집합으로 합치기
        {
            const int a = s1[i] - 'a';
            const int b = s2[i] - 'a';
            unionNodes(parent, a, b);
        }

        for (char& c : result) // baseStr 의 각 문자를 해당 그룹의 최소 문자(대표)로 변환
        {
            const int idx = c - 'a';
            const int root = findParent(parent, idx);
            c = static_cast<char>('a' + root);
        }

        return result;
    }

private:
    static int findParent(vector<int>& parent, const int x) // 경로 압축을 적용한 find
    {
        if (parent[x] != x)
        {
            parent[x] = findParent(parent, parent[x]);
        }

        return parent[x];
    }

   
    static void unionNodes(vector<int>& parent, const int x, const int y)  // 대표를 더 작은 알파벳 순(숫자)으로 설정하며 합치기
    {
        const int rx = findParent(parent, x);
        const int ry = findParent(parent, y);

        if (rx == ry)
        { 
            return;
        }

        if (rx < ry)
        {
            parent[ry] = rx;
        }
        else
        {
            parent[rx] = ry;
        }
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 1000,
        ALPHABET_LENGTH = 26,
    };
};

// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/description/?envType=daily-question&envId=2025-06-05
