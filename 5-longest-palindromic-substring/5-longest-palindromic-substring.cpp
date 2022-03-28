class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0) return "";
        int n = s.size();
        int table[n][n];
        memset(table,-1,sizeof(table)); //Initializing table with -1
        for (int i = 0; i < n; ++i) 
            table[i][i] = 1;  //Filling up the table
        int maxLen = 1;
        int start = 0; 
        for (int i = 0; i < n - 1; ++i) { //checking for substring of length 2.
            if (s[i] == s[i + 1]) { 
                table[i][i + 1] = 1; 
                start = i;  //Updating the start
                maxLen = 2; 
            } 
        }
        for(int k=3;k<=n;k++){ //Checking for length greater than 2 and k is length of substring 
            for(int i=0;i<n - k + 1;i++){
                int j = i + k - 1; //Initializing the end Index i.e j = i + k - 1
                if(table[i+1][j-1] == 1 && s[i] == s[j]){ //Checking for the conditions i.e checking for sub-string from ith index to jth index.
                    table[i][j] = 1;
                    if (k > maxLen) { //Updating the maxLen
                        start = i;  //Updating the start
                        maxLen = k; 
                    } 
                }
            }
        }
        return s.substr(start, maxLen);
    }
};

/*

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) { // if size is 0 or 1 
			return s;  // return string directly
		}

        int max =1; // the max length of palindrome in string
        int f = 0;  // the first index of this max palindrome
        
        for(int i = 0; i< s.size(); i++) { //for every element in string
            for (int j= s.size()-1; j>=i; j--) { // check if we have the same element
                if (s[i] == s[j]){  // if two element are same
                    int a = i;      // check if between them is palindrome
                    int b = j;
                    int flag = 1;

                    while(a<=b){    // from the start index i to the end index j
                        if (s[a] == s[b]){ // if the elements between are same
                            a++; b--;           
                        }
                        else{
                            flag = 0; 
                            break;
                        }
                    }

                    if (flag ==1 && max <(j-i+1)){  // if it is palindrome and longer than max
                        max = j-i+1;  // set it to max
                        f = i;
                    }    
                }
			}
		}

        return s.substr(f,max);
    }
};
*/