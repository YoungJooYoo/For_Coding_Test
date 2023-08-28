class Solution {
public:
    int houseCount(Street* street, int k) 
    {
        int ans = 0;
        
        for(int i = 0; i < k; i++) { // open all door -> 1 1 1 1
            street->openDoor();
            street->moveRight();
        }
    
        for(int i = 0; i < k; i++) { // close all door -> 0 0 0 0
            if(street->isDoorOpen()) {
                street->closeDoor();
                ++ans;
            } else break; // done
            street->moveRight();
        }

        return ans;
    }
};

// https://leetcode.com/problems/count-houses-in-a-circular-street/
