class Solution {
public:
    vector<vector<int>> generate(int numRows) 
	{
		vector<vector<int>> triangle;

		// 행을 하나 만들고, 계산하면, 그 다음 2차월 배열에 넣는다. 
        for (size_t i = 0; i < numRows; i++) {
			vector<int> row(i + 1, 1);
			for (size_t j = 1; j < i; j++) { // i + 1은 이미 1로 세팅 되었으니, i번까지만 계산
				row[j] = triangle[i - 1][j] + triangle[i - 1][j - 1];
			}
			triangle.push_back(row);
		}

		return triangle;
    }
};