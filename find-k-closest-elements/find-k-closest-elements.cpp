class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        int start = 0;
        int mid;
        int end = arr.size() - k;
        
        while (start < end) {
            mid = (start + end) / 2;
            if (x - arr[mid] > arr[mid + k] - x) {
                start = mid + 1;
            }
            else { // x - arr[mid] <= arr[mid + k] - x
                end = mid;
            }
        }
        
        return vector<int>(arr.begin() + start, arr.begin() + start + k);
    }
};

/*

풀이 해설 :
배열에서 x와 가장 가까운 k개의 숫자를 찾아 반환하는 것이 문제이다.
즉 k길이만큼 숫자를 넣으면 되므로, 해당 범위를 찾아가면서 탐색을 진행한다.

*/