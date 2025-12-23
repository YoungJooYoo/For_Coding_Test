class Spreadsheet
{
public:
    Spreadsheet(const int rows)
    : mRows(rows)
    {
        assert(rows >= MIN_ROWS && rows <= MAX_ROWS);
    }

    void setCell(const string& cell, const int value)
    {
        assert(isValidCell(cell));
        assert(value >= MIN_VALUE && value <= MAX_VALUE);
        mCells[cell] = value;
    }

    void resetCell(const string& cell)
    {
        assert(isValidCell(cell));
        mCells[cell] = 0;
    }

    int getValue(const string& formula) const
    {
        assert(formula.size() >= MIN_FORMULA_LENGTH);
        assert(formula[0] == '=');

        const string expression = formula.substr(1);
        const size_t plusPos = expression.find('+');
        assert(plusPos != string::npos);

        const string left = expression.substr(0, plusPos);
        const string right = expression.substr(plusPos + 1);
        const int leftValue = parseToken(left);
        const int rightValue = parseToken(right);

        return leftValue + rightValue;
    }

private:
    int parseToken(const string& token) const
    {
        if (isCellReference(token))
        {
            const auto it = mCells.find(token);
            return (it != mCells.end()) ? it->second : 0;
        }

        return stoi(token);
    }

    bool isCellReference(const string& token) const
    {
        return token.size() >= MIN_CELL_LENGTH &&
               token[0] >= 'A' && token[0] <= 'Z';
    }

    bool isValidCell(const string& cell) const
    {
        if (cell.size() < MIN_CELL_LENGTH)
        {
            return false;
        }

        const char column = cell[0];
        if (column < 'A' || column > 'Z')
        {
            return false;
        }

        const int row = stoi(cell.substr(1));
        return (row >= 1 && row <= mRows) ? true : false;
    }

private:
    enum
    {
        MIN_ROWS = 1,
        MAX_ROWS = 1000,
        MIN_VALUE = 0,
        MAX_VALUE = 100000,
        MIN_CELL_LENGTH = 2,
        MIN_FORMULA_LENGTH = 4  // "=A1+B1" 최소 길이
    };

    int mRows;
    unordered_map<string, int> mCells;
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */

 /*
https://leetcode.com/problems/design-spreadsheet/description/
---

### **3484. 스프레드시트 설계 (Design Spreadsheet)**

스프레드시트는 26개의 열('A'부터 'Z'까지 라벨링됨)과 주어진 수의 행으로 구성된 그리드입니다. 스프레드시트의 각 셀은 0에서 $10^5$ 사이의 정수 값을 저장할 수 있습니다.

`Spreadsheet` 클래스를 구현하십시오:

*   `Spreadsheet(int rows)`: 26개의 열('A'~'Z')과 지정된 수의 행(`rows`)을 가진 스프레드시트를 초기화합니다. 모든 셀은 초기에 0으로 설정됩니다.
*   `void setCell(String cell, int value)`: 지정된 셀의 값을 설정합니다. 셀 참조는 "AX" 형식(예: "A1", "B10")으로 제공되며, 여기서 문자는 열('A'~'Z')을, 숫자는 1부터 시작하는(1-indexed) 행 번호를 나타냅니다.
*   `void resetCell(String cell)`: 지정된 셀의 값을 0으로 초기화합니다.
*   `int getValue(String formula)`: "=X+Y" 형식의 수식을 계산합니다. 여기서 X와 Y는 셀 참조이거나 음이 아닌 정수이며, 계산된 합계를 반환합니다.

**참고:** `getValue`가 `setCell`을 통해 명시적으로 설정되지 않은 셀을 참조하는 경우, 해당 값은 0으로 간주됩니다.

---

### **제약 조건 (Constraints):**

*   $1 \le rows \le 10^3$
*   $0 \le value \le 10^5$
*   수식(`formula`)은 항상 "=X+Y" 형식이며, X와 Y는 유효한 셀 참조이거나 $10^5$ 이하의 음이 아닌 정수입니다.
*   각 셀 참조는 'A'에서 'Z' 사이의 대문자와 1에서 `rows` 사이의 행 번호로 구성됩니다.
*   `setCell`, `resetCell`, `getValue`는 총합 최대 $10^4$번 호출됩니다.
 */
