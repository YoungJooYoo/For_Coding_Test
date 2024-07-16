class Solution {
public:
    int calPoints(const vector<string>& operations) 
    {
        stack<int> st;

        for (const string& operation : operations)
        {
            if (operation == "C")
            {
                st.pop();
            }
            else if (operation == "D")
            {
                const int num1 = st.top();
                st.push(2 * num1);
            }
            else if (operation == "+")
            {
                const int num1 = st.top(); st.pop();
                const int num2 = st.top();
                st.push(num1);
                st.push(num1 + num2);
            }
            else
            {
                st.push(stoi(operation));
            }
        }

        int result = 0;
        while (!st.empty())
        {
            const int num = st.top(); st.pop();
            result += num;
        }
        
        return result;
    }
};

// https://leetcode.com/problems/baseball-game/description/
