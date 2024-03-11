/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char* const buf, const int n) 
    {
        int total_size = 0;
        char* buff = buf;

        while (total_size < n) {
            const int SIZE = read4(buff + total_size);
            total_size += SIZE;
            if (SIZE < READ_SIZE)  break;
        }

        return min(n, total_size);
    }

private:
    enum { READ_SIZE = 4 };
};

// https://leetcode.com/problems/read-n-characters-given-read4/

/*

## LeetCode 문제 157. Read N Characters Given Read4 설명

**문제 요약:**

* **문제 유형:** Easy
* **주제:** 문자열, 시뮬레이션
* **관련 기업:** Google, Amazon, Microsoft

**문제 설명:**

`read4`라는 함수가 있고, 이 함수는 파일에서 4개의 문자를 읽어서 `buf4`라는 버퍼에 저장합니다. 우리는 이 함수만 사용해서 파일에서 `n`개의 문자를 읽어서 `buf`라는 버퍼에 저장해야 합니다.

**문제 예시:**

* **입력:** `file = "abc"`, `n = 4`
* **출력:** 3
* **설명:** `read4`를 1번 호출하면 `buf4`에 "abc"가 저장됩니다. 3개의 문자를 읽었으므로 3을 반환합니다.

* **입력:** `file = "abcde"`, `n = 5`
* **출력:** 5
* **설명:** `read4`를 2번 호출하면 `buf4`에 "abcde"가 저장됩니다. 5개의 문자를 읽었으므로 5를 반환합니다.

**문제 풀이:**

1. `read4` 함수를 반복적으로 호출하여 파일에서 4개의 문자씩 읽습니다.
2. 읽은 문자를 `buf` 버퍼에 저장합니다.
3. 읽은 문자의 총 개수가 `n`에 도달하면 멈춥니다.
4. 읽은 문자의 총 개수를 반환합니다.

**주의 사항:**

* `read4` 함수는 항상 4개의 문자를 읽는 것은 아닙니다. 파일 끝에 도달하면 그 이전까지 남아있는 문자만 읽습니다.
* `buf` 버퍼는 충분히 크다고 가정할 수 있습니다.

**문제 풀이 팁:**

* while 루프를 사용하여 `read4` 함수를 반복적으로 호출합니다.
* `read4` 함수의 반환 값을 사용하여 읽은 문자의 개수를 확인합니다.
* for 루프를 사용하여 읽은 문자를 `buf` 버퍼에 저장합니다.

**더 궁금한 점이 있으면 언제든지 물어보세요!**


*/
