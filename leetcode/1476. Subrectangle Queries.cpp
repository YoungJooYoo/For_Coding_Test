class SubrectangleQueries 
{
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) 
        : mRectangle(rectangle) 
    {
        
    }
    
    void updateSubrectangle(const int row1, const int col1, const int row2, const int col2, const int newValue) 
    {
        for (int i = row1; i <= row2; ++i) 
        {
            for (int j = col1; j <= col2; ++j) 
            {
                mRectangle[i][j] = newValue;
            }
        }
    }
    
    int getValue(const int row, const int col) const 
    {
        return mRectangle[row][col];
    }

private:
    vector<vector<int>>& mRectangle;
};

// https://leetcode.com/problems/subrectangle-queries/

 /*
 
 ### 1476. 서브직사각형 쿼리(Subrectangle Queries)

**난이도: 중간**

#### 문제 설명

`SubrectangleQueries` 클래스를 구현하세요. 이 클래스는 rows x cols 크기의 직사각형을 정수 매트릭스로 받으며, 다음 두 가지 메서드를 지원합니다:

1. `updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)`
   - `(row1, col1)` 좌표에서 `(row2, col2)` 좌표까지의 서브직사각형 내의 모든 값을 `newValue`로 업데이트합니다.

2. `getValue(int row, int col)`
   - 직사각형에서 `(row, col)` 좌표의 현재 값을 반환합니다.

#### 예제 1:

**입력:**
```
["SubrectangleQueries","getValue","updateSubrectangle","getValue","getValue","updateSubrectangle","getValue","getValue"]
[[[[1,2,1],[4,3,4],[3,2,1],[1,1,1]]],[0,2],[0,0,3,2,5],[0,2],[3,1],[3,0,3,2,10],[3,1],[0,2]]
```

**출력:**
```
[null,1,null,5,5,null,10,5]
```

**설명:**
```
SubrectangleQueries subrectangleQueries = new SubrectangleQueries([[1,2,1],[4,3,4],[3,2,1],[1,1,1]]);
// 초기 직사각형 (4x3)은 다음과 같습니다:
// 1 2 1
// 4 3 4
// 3 2 1
// 1 1 1
subrectangleQueries.getValue(0, 2); // 1 반환
subrectangleQueries.updateSubrectangle(0, 0, 3, 2, 5);
// 업데이트 후 직사각형은 다음과 같습니다:
// 5 5 5
// 5 5 5
// 5 5 5
// 5 5 5
subrectangleQueries.getValue(0, 2); // 5 반환
subrectangleQueries.getValue(3, 1); // 5 반환
subrectangleQueries.updateSubrectangle(3, 0, 3, 2, 10);
// 업데이트 후 직사각형은 다음과 같습니다:
// 5   5   5
// 5   5   5
// 5   5   5
// 10  10  10
subrectangleQueries.getValue(3, 1); // 10 반환
subrectangleQueries.getValue(0, 2); // 5 반환
```

#### 예제 2:

**입력:**
```
["SubrectangleQueries","getValue","updateSubrectangle","getValue","getValue","updateSubrectangle","getValue"]
[[[[1,1,1],[2,2,2],[3,3,3]]],[0,0],[0,0,2,2,100],[0,0],[2,2],[1,1,2,2,20],[2,2]]
```

**출력:**
```
[null,1,null,100,100,null,20]
```

**설명:**
```
SubrectangleQueries subrectangleQueries = new SubrectangleQueries([[1,1,1],[2,2,2],[3,3,3]]);
subrectangleQueries.getValue(0, 0); // 1 반환
subrectangleQueries.updateSubrectangle(0, 0, 2, 2, 100);
subrectangleQueries.getValue(0, 0); // 100 반환
subrectangleQueries.getValue(2, 2); // 100 반환
subrectangleQueries.updateSubrectangle(1, 1, 2, 2, 20);
subrectangleQueries.getValue(2, 2); // 20 반환
```

#### 제약 조건:

- `1 <= rows, cols <= 100`
- `0 <= row1 <= row2 < rows`
- `0 <= col1 <= col2 < cols`
- `1 <= newValue, getValue(row, col) <= 10^9`
- `getValue`와 `updateSubrectangle` 메서드는 각 메서드 호출이 최대 1000번까지 발생할 수 있습니다.
 
 */
