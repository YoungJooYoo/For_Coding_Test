class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
        sort(products.begin(),products.end());
        
        for (size_t i = 0; i< searchWord.size(); i++) {
            if (i == 0) {
                space = products;
            }
            else { // i != 0
                space = filtered;
            }
            
            temp.clear();
            filtered.clear();
            int count = 0;
            
            for (const string& s : space) {
                if (i < s.size() and s[i] == searchWord[i]) {
                    if (count < 3) {
                        temp.push_back(s);
                    }
                    filtered.push_back(s);
                    count++;
                }
            }
            output.push_back(temp);
        }
        
        return output;
    }
    
private:
        vector<vector<string>> output;
        vector<string> temp;
        vector<string> space;
        vector<string> filtered;
};