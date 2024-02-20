class RLEIterator {
public:
    RLEIterator(vector<int>& encoded) : encoding(encoded) {}

    int next(int n) 
    {
        const int LEN = encoding.size();

        while (index < LEN) {
            if (remaining + n <= encoding[index]) { // 현재 값으로 n을 충족할 수 있는 경우
                remaining += n;
                return encoding[index + 1];
            } 
            else { // 현재 값으로 n을 충족시키지 못하는 경우
                n -= (encoding[index] - remaining); // 남은 n을 계산
                remaining = 0; // 현재 값의 남은 반복 횟수를 리셋
                index += 2; // 다음 값으로 이동
            }
        }
        return -1; // 더 이상 소모할 원소가 없는 경우
    }

private:
    vector<int> encoding;
    int index = 0; // 현재 처리 중인 encoding 배열의 인덱스
    int remaining = 0; // 현재 값의 남은 반복 횟수
};

// https://leetcode.com/problems/rle-iterator/description/

/*
RLE 이터레이터
난이도: 중간
정수의 시퀀스는 RLE(런길이 인코딩, Run-Length Encoding)를 사용하여 인코딩할 수 있습니다. 짝수 길이의 RLE 인코딩 배열에서, 모든 짝수 i에 대해, encoding[i]는 시퀀스에서 음수가 아닌 정수 값 encoding[i + 1]이 반복되는 횟수를 알려줍니다.

예를 들어, 시퀀스 arr = [8,8,8,5,5]는 encoding = [3,8,2,5]로 인코딩될 수 있습니다. encoding = [3,8,0,9,2,5]와 encoding = [2,8,1,8,2,5]도 arr의 유효한 RLE 인코딩입니다.

런길이 인코딩 배열이 주어졌을 때, 이를 순회하는 이터레이터를 설계하십시오.

RLEIterator 클래스를 구현하십시오:

RLEIterator(int[] encoded): 인코딩된 배열 encoded로 객체를 초기화합니다.
int next(int n): 다음 n개의 원소를 소진하고 이 방식으로 마지막으로 소진된 원소를 반환합니다. 소진할 원소가 없으면 대신 -1을 반환합니다.
*/

/*

시간 복잡도: next 함수는 최악의 경우 O(k) 시간이 걸립니다. 여기서 k는 encoding 배열의 길이입니다. 하지만 각 호출은 최소 하나의 원소를 소모하기 때문에, next 함수의 총 호출 횟수에 대한 평균 시간 복잡도는 O(1)에 가깝습니다.
공간 복잡도: O(k) 여기서 k는 입력으로 주어진 encoding 배열의 길이입니다. 이터레이터는 인코딩된 배열을 저장하기 위해 추가 공간을 사용합니다.
주의 사항
이 구현에서는 index와 remaining 변수를 사용하여 현재 처리 중인 인코딩된 값과 그 값의 남은 반복 횟수를 추적합니다.
next 함수는 요청된 n 개의 원소를 소모하려고 시도하며, 가능할 때마다 마지막으로 소모된 원소를 반환합니다. 만약 더 이상 소모할 원소가 없으면 -1을 반환합니다.
 
 */
