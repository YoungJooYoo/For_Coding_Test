class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        // Edge cases:
        if (n == 0) return true;
        else if (flowerbed.size() == 0) return false;
        else if (flowerbed.size() == 1) return flowerbed[0] == 0 ? true : false;
        
        // Add empty plots in the beginning and end:
        flowerbed.push_back(0);
        flowerbed.insert(flowerbed.begin(), 0);  // 0  1010101010   0   -->  양끝에 0 추가, 양끝은 꽃을 바로 둘 수 있으므로
        
        // Check if there are three empty plots in a row:
        int flowers = 0;
        int  i = 0;
        while ((i < flowerbed.size() - 2) && (flowers < n)) {
            if ((flowerbed[i] == 0) && (flowerbed[i + 1] == 0) && (flowerbed[i + 2] == 0)) { // i+1기준으로 앞뒤 전부 비어있다면 화꽃을 둔다
                flowers++;
                flowerbed[i + 1] = 1;
            }
            i++;
        }
        
        return flowers == n ? true : false;
    }
};

// https://leetcode.com/problems/can-place-flowers/description/
