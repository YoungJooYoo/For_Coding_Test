class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int low=0;
        int high=nums.size()-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            cout << "mid : " <<mid << endl;
            
            if(nums[mid]<nums[high]){
                high=mid;
                cout << "high : " <<high << endl;
            }
            else if(nums[mid]>nums[high]){
                low=mid + 1;
                cout << "low : " << low << endl;
            }
            else{
                high--;
                cout << "high-- : " << high << endl;
            }
        }
        return nums[low];
    }
};