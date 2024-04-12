class DataStream {
public:
    DataStream(const int value, const int k) : mValue(value), mK(k), consec_count(0) {}
    
    bool consec(const int num) 
    {
        if (num != mValue) consec_count = 0;
        else ++consec_count;

        return (consec_count >= mK) ? true : false;
    }

private:
    const int mValue;             // 연속된 수의 목표 값 ==  valuse
    const int mK;                     // 연속된 수의 길이 == k
    int consec_count;                   // 현재 연속된 수의 개수
};

// https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/description/

 /*
 이 문제는 정수 스트림에서 마지막 k개의 정수가 특정 값과 동일한지 확인하는 데이터 구조를 구현하는 문제입니다.

다음과 같은 DataStream 클래스를 구현해야 합니다:

- DataStream(int value, int k): 빈 정수 스트림과 두 개의 정수 value와 k로 객체를 초기화합니다.
- boolean consec(int num): num을 정수 스트림에 추가합니다. 마지막 k개의 정수가 value와 동일하면 true를 반환하고, 그렇지 않으면 false를 반환합니다. 정수가 k개 미만인 경우 조건이 충족되지 않으므로 false를 반환합니다.

예를 들어, 다음과 같은 입력이 주어졌을 때:

```
["DataStream", "consec", "consec", "consec", "consec"]
[[4, 3], [4], [4], [4], [3]]
```

다음과 같은 출력을 반환해야 합니다:

```
[null, false, false, true, false]
```

설명:
- DataStream dataStream = new DataStream(4, 3); // value = 4, k = 3
- dataStream.consec(4); // 정수가 1개만 파싱되었으므로 false를 반환합니다.
- dataStream.consec(4); // 정수가 2개만 파싱되었습니다. k보다 적기 때문에 false를 반환합니다.
- dataStream.consec(4); // 파싱된 3개의 정수가 모두 값과 같으므로 true를 반환합니다.
- dataStream.consec(3); // 스트림에서 마지막 k개의 정수는 [4,4,3]입니다. 값과 같지 않기 때문에 false를 반환합니다.
 */
