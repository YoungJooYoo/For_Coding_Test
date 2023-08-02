class Solution {
public:
    int findMin(vector<int> &num) 
    {
        int start = 0;
        int mid;
        int end = num.size() - 1;
        
        while (start < end) {
            mid = (start + end) / 2;
            if (num[start] < num[end]) {
                return num[start];
            }
            if (num[mid] >= num[start]) {
                start = mid + 1;
            } 
            else { // num[mid] < num[start]
                end = mid;
            }
        }
        
        return num[start];
    }
};

/*
주어진 배열에최소 값을 찾는 문제
문제가 주어진 배열은   배열 = 우측배열 + 좌측 배열
이렇게 구성이 되어 있다.

시간 복잡도 O(log n) 안에 최솟값을 찾아야하기 때문에 순차적으로 탐색하면서 
가장 낮은 값을 찾는 방식을 사용하면 이진탐색문제이다

두 개의 포인터를 사용해 왼쪽 포인터의 값이 오른쪽 포인터의 값보다 작아지는 순간에 
왼쪽 포인터의 값을 반환하면 간단히 답을 찾을 수 있다.

*/