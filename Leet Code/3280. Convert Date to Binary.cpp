class Solution 
{
public:
    string convertDateToBinary(const string& date) 
    {
        const string YEAR = converIntToBinary(date.substr(0, 4));
        const string MONTH = converIntToBinary(date.substr(5, 6));
        const string DAY = converIntToBinary(date.substr(8, 9));

        return (YEAR + "-" + MONTH + "-" + DAY);
    }

private:
    string converIntToBinary(const string& value) 
    {
        int num = stoi(value);
        string binary = "";

        while (num > 0) 
        {
            if (num % 2 == 1) 
            {
                binary = "1" + binary;
            }
            else
            {
                 binary = "0" + binary;
            }
            num >>= 1;
        }

        return binary;
    }
};

// https://leetcode.com/problems/convert-date-to-binary/description/

/*
### 3280. 날짜를 이진수로 변환하기 (Convert Date to Binary)

**난이도: 쉬움**

주어진 날짜 문자열 `date`는 그레고리력(Gregorian calendar)의 날짜를 `yyyy-mm-dd` 형식으로 나타냅니다.

`date`를 연도(year), 월(month), 일(day)을 각각 이진수로 변환한 후, 이진수로 표현된 `연도-월-일` 형식의 결과를 반환하세요. 이때, 이진수 표현에는 앞에 불필요한 0이 포함되지 않으며, 각각의 요소는 이진수로 변환되어야 합니다.

### 반환값:
날짜를 이진수로 변환한 결과 문자열을 반환합니다.

---

### 예제 1:

- **입력**: `date = "2080-02-29"`
- **출력**: `"100000100000-10-11101"`

**설명**:
- `2080`의 이진수는 `100000100000`
- `02`의 이진수는 `10`
- `29`의 이진수는 `11101`
결과적으로 `"100000100000-10-11101"`을 반환합니다.

---

### 예제 2:

- **입력**: `date = "1900-01-01"`
- **출력**: `"11101101100-1-1"`

**설명**:
- `1900`의 이진수는 `11101101100`
- `01`의 이진수는 `1`
- `01`의 이진수는 `1`
결과적으로 `"11101101100-1-1"`을 반환합니다.

---

### 제약 사항:

- `date.length == 10`
- `date[4] == date[7] == '-'`이고, 나머지 `date[i]`는 숫자입니다.
- 주어진 입력은 1900년 1월 1일부터 2100년 12월 31일까지의 유효한 그레고리력 날짜를 나타냅니다.

*/
