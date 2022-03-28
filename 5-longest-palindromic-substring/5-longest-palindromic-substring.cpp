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
    string longestPalindrome(string s) 
	{
		const size_t str_len = s.size();
		int max_len = 1; // the max length of palindrome in string
        int max_index = 0;  // the first index of this max palindrome

        if (str_len <= 1) {
            return s;
		}
        
        for (int i = 0; i < str_len; i++) { // for every element in string
            for (int j = str_len - 1; j >= i; j--) { // check if we have the same element
                if (s[i] == s[j]) {  // if two element are same
                    int index_i = i;      // check if between them is palindrome
                    int index_j = j;
                    bool flag = true; // palindrome 확인 flag 일단체크, 아래 반복문에서 제대로 체크
                    while (index_i <= index_j) {    // from the start index i to the end index j
                        if (s[index_i] == s[index_j]){ // if the elements between are same
                            index_i++; 
							index_j--;           
                        }
                        else { // palindrome이 아니다.
                            flag = false; 
                            break;
                        }
                    }
                    if (flag == true && max_len < (j - i + 1)) {  // if it is palindrome and longer than max , j - i + 1 = 길이이다.
                        max_len = j - i + 1;  // set it to max, max 길이 갱신
                        max_index = i; // max 길이의 시작점 갱신
                    }    
        		}
			}
		}

        return s.substr(max_index, max_len);
    }
};

/*

 풀이법 :
 뒤에서부터 배열을 읽어가며, 읽는 중 앞 인덱스와, 뒤 인덱스 문자가 같은지 확인한다.
 일단 확인되면, 반복문을 돌려 그 사이의 문자들으 서로 같은지 확인을한다.
 같은 문자끼리 가장 긴 길이를 갱신하면서 계속 탐색한다.

*/
