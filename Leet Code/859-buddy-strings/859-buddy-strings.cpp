class Solution {
public:
    bool buddyStrings(string A, string B) 
    {
        if (A == B) return (set<char>(A.begin(), A.end()).size() < A.size());  // ex) aabc aabc -> fasle ,    abc acb  -> true
        
        int n = A.length();
        int l = 0;
        int r = n - 1;
        
        // 일치하지 않는 부분을 찾고 거기서부터 swap 
        while (l < n && A[l] == B[l]) l++; // ex) ab ba
        while (r >= 0 && A[r] == B[r]) r--;
        if (l < r) swap(A[l], A[r]);
        
        return (A == B) ? true : false; 
    }
};