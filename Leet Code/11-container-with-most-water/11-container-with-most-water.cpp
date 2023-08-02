class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        int max_area = INT_MIN;
        int i = 0;
        int j = height.size() - 1;
        
        while (i < j) {
            int x = j - i; // distance, 밑변
            int y = min(height[i], height[j]); // height, 높이
            int curr_area = x * y;
            max_area = max(max_area, curr_area);

            while (i < j && height[i] <= y) {
                i++;
            }
            while (i < j && height[j] <= y) {
                j--;
            }
        }
        
        return max_area;
    }
};

/*

풀이법 :

밑변 * 높이 = 면적
이 문제에서는 밑변이 길수록 더 면접이 크다.
따라서 밑변을 기준으로, 인덱스를 옮겨가며 넓이를 찾는다.

while문이 돌때마다, x의 갚이 작아지므로
그것을 보완하려면 필연적으로 y 값은 더 큰 값을 취해야한다.
작은 y값은 100프로 더 작은 값이므로 그냥 pass,
더 높은 y값으로 면적 계산 후 취사 선택한다.

*/