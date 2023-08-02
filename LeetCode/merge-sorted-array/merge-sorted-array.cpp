class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int temp_arr[1000];
        size_t p1 = 0;
        size_t p2 = 0;
        size_t index_temp = 0;

        while (p1 < m && p2 <n) {
            if (nums1[p1] < nums2[p2]) {
                temp_arr[index_temp] = nums1[p1]; // 작은값을 대입
                index_temp++;
                p1++;
                if (p1 == m) {
                    break;
                }
            }
            else{
                temp_arr[index_temp] = nums2[p2];
                index_temp++;
                p2++;
                if (p2 == n) {
                    break;
                 }
            }
        }

        // 위의 while 탈출하면서 p1 = m or p2 = n 이된다.
        // 남은배열 전부 넣기 
        while (true) {
            if (p1 < m) {
                temp_arr[index_temp] = nums1[p1];
                index_temp++;
                p1++;
                if (p1 == m) {
                    break;
                }
            }
            else if (p2 < n){
                temp_arr[index_temp] = nums2[p2];
                index_temp++;
                p2++;
                if (p2 == n) {
                    break;
                }
            }
        }

        // 마지막 완성된 배열을 nums1 으로 복사
        for (size_t i = 0; i < m + n; i++) {
            nums1[i] = temp_arr[i];
        }
    }
};