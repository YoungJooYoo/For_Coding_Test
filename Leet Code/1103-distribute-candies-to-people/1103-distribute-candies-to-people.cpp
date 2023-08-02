class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) 
    {
        vector<int> result(num_people, 0);
        int candy = 1;
        int i = 0;

        while (candies > 0) {
            int give = min(candy++, candies);
            result[i] += give;
            candies -= give;
            i = (i + 1) % num_people;
        }
        
        return result;
    }
};