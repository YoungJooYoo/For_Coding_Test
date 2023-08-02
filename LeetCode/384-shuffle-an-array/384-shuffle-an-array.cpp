class Solution {
public:
	Solution(vector<int>& nums) 
	{
		original = nums;
		array_size = original.size();
	}
	
	vector<int> reset() 
	{
		return original;
	}
	
	vector<int> shuffle() 
	{
		vector<int> shuffled = original; // make a copy of the original
		int leftSize = array_size;

		for (int i = array_size - 1; i >= 0; i--) {
			int j = rand() % leftSize; // draw from the bag
			swap(shuffled[i], shuffled[j]); //put this element at current position and put the original element in the bag
			leftSize--;
		}

		return shuffled;
	}

private:
	vector<int> original;
	size_t array_size;
};