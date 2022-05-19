class Solution {
public:
    vector<int> minOperations(string boxes) 
	{
	    int sum = 0;
		int ballSeen = 0;
        const size_t BOXES_LENGTH = boxes.size();
		vector<int> result(BOXES_LENGTH, 0);
                
        for (size_t i = 1; i < BOXES_LENGTH; ++i) {
		    if (boxes[i-1] == '1') { 
			    ballSeen++;
			}
			sum += ballSeen;
			result[i] += sum;
		 }

		 sum = 0;
		 ballSeen = 0;
        
		 for (int i = BOXES_LENGTH - 2; i >= 0; --i) {
			 if (boxes[i + 1] == '1') { 
				 ballSeen++;
			 }
			 sum += ballSeen;
			 result[i] += sum;
		 }
		 
		return result;
    }
};