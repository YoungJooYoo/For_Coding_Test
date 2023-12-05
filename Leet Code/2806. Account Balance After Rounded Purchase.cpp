class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) 
    {
        return BALANCE - ((purchaseAmount + 5) / 10) * 10;
    }
private :
    enum { BALANCE = 100 };
};

// https://leetcode.com/problems/account-balance-after-rounded-purchase/description/
