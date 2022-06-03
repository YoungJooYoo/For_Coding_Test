class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, const string& searchWord) 
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
            int size = 0;
            
            for (const string& s : space) {
                if (i < s.size() and s[i] == searchWord[i]) {
                    if (size < MAX_SIZE) {
                        temp.push_back(s);
                    }
                    filtered.push_back(s);
                    size++;
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
        const int MAX_SIZE = 3;
};