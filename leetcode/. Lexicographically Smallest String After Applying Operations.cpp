class Solution
{
public:
    string findLexSmallestString(const string& s, const int a, const int b) const
    {
        unordered_set<string> visited;
        visited.reserve(10000);

        search(s, a, b, visited);

        string smallest = s;
        for (const string& str : visited)
        {
            if (str < smallest)
            {
                smallest = str;
            }
        }

        return smallest;
    }

private:
    enum { ZERO = '0' };

    static string rotateRight(const string& s, const int b)
    {
        const int N = static_cast<int>(s.size());
        assert(0 < b && b < N);

        string rotated(N, 0);

        for (int i = 0; i < N; ++i)
        {
            const int newIndex = (i + b) % N;
            rotated[newIndex] = s[i];
        }

        return rotated;
    }

    static string addToOddIndices(const string& s, const int a)
    {
        const int N = static_cast<int>(s.size());
        assert(1 <= a && a <= 9);

        string modified = s;

        for (int i = 1; i < N; i += 2)
        {
            const int digit = modified[i] - ZERO;
            const int newDigit = (digit + a) % 10;
            modified[i] = static_cast<char>(ZERO + newDigit);
        }

        return modified;
    }

    static void search(const string& s, const int a, const int b, unordered_set<string>& visited)
    {
        if (visited.find(s) != visited.end())
        {
            return;
        }

        visited.insert(s);
        search(rotateRight(s, b), a, b, visited);
        search(addToOddIndices(s, a), a, b, visited);
    }


};

// https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/description/

/*
1625. 연산을 적용한 후 사전식으로 가장 작은 문자열
짝수 길이의 숫자 문자열 s(문자 '0'~'9')와 정수 a, b가 주어집니다.

다음 두 연산을 원하는 횟수만큼, 아무 순서로나 s에 적용할 수 있습니다.

s의 홀수 인덱스(0-indexed: 1,3,5,...)에 있는 모든 자리 숫자에 a를 더합니다. 9를 넘으면 0부터 다시 시작합니다(즉, mod 10).
s를 오른쪽으로 b만큼 회전(rotate)합니다.
위 연산들을 적용해서 얻을 수 있는 문자열들 중 사전순(lexicographical order)으로 가장 작은 문자열을 반환하세요.

사전순 비교는 같은 길이의 문자열에서 처음 다른 위치의 문자를 기준으로 더 작은 문자를 가진 문자열이 더 작다고 판단합니다.

예제 1:
Input:

s = "5525", a = 9, b = 2
Output:

"2050"
설명(연산 과정 예시):

"5525" → rotate → "2555" → add → "2454" → add → "2353" → rotate → "5323" → add → "5222" → add → "5121" → rotate → "2151" → add → "2050"
예제 2:
Input:

s = "74", a = 5, b = 1
Output:

"24"
예제 3:
Input:

s = "0011", a = 4, b = 2
Output:

"0011"
제약 조건:

2 <= s.length <= 100, s.length는 짝수
s는 숫자 문자('0'~'9')만 포함
1 <= a <= 9
1 <= b <= s.length - 1





*/
