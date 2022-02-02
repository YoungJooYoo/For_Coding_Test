class Solution {
public:
    void merge(vector<int>& count, vector<pair<int, int>>& v, int left, int mid, int right) 
	{
        vector<pair<int, int>> tmp(right - left + 1);
        int i = left;
        int j = mid + 1;
        int k = 0;

        while (i <= mid && j <= right) {
            // mind that we're sorting in descending order
            if (v[i].first <= v[j].first) { 
                tmp[k] = v[j];
				k++;
				j++;
            }
            else {
                // only line responsible to update count, related to problem constraint, 
                // remaining part is just regular mergeSort 
                count[v[i].second] += right - j + 1;
                tmp[k] = v[i];
				k++;
				i++;
            }
        }
        while (i <= mid) {
            tmp[k] = v[i];
			k++;
			i++;
        }
        while (j <= right) {
            tmp[k] = v[j];
			k++;
			j++;
        }
        for (int i = left; i <= right; i++) {
			v[i] = tmp[i - left];
		}    
    }        

    void mergeSort(vector<int>& count, vector<pair<int, int>>& v, int left, int right) 
	{
        if (left >= right) {
			return;
		}
            
        int mid = left + (right - left) / 2;

        mergeSort(count, v, left, mid); // 정렬할 배열 분해
        mergeSort(count, v, mid + 1, right); // 정렬할 배열 분해
        merge(count, v, left, mid, right); // 배열 다시 합체
    }

    vector<int> countSmaller(vector<int>& nums) 
	{
        const size_t nums_length = nums.size();
		vector<int> count(nums_length, 0);
        vector<pair<int, int>> v(nums_length);
		
		// init  v
        for (size_t i = 0; i < nums_length; i++) {
			v[i] = make_pair(nums[i], i);
		}
        
        // sorting in descending order
        mergeSort(count, v, 0, nums_length - 1);

        return count;
    }
};
