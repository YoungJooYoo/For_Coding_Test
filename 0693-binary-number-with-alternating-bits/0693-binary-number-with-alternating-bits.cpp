class Solution {
public:
    bool hasAlternatingBits(int num) {
        int flag=num%2;
        num=num/2;
        while(num)
        {
            if(flag==num%2)
                return false;
            else
                flag=num%2;
            num/=2;
            
        }
        return true;
    }
};