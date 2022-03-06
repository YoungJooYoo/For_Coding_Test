class SparseVector {
public:
    SparseVector(vector<int>& nums) 
    {
        array = nums;
    }
    
    int dotProduct(SparseVector& vec) 
    {
        for (size_t i = 0; i < array.size(); i++) {
            sum = sum + array[i] * vec.array[i];
        }
        
        return sum;
    }
    
private:
    vector<int> array;
    int sum = 0;
    
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);