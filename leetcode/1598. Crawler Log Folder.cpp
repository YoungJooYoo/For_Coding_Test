class Solution {
public:
    int minOperations(const vector<string>& logs) 
    {
        const string MOVE_TO_PARENT_FOLDER = "../";
        const string REMAIN_FOLDER = "./";
        int depth = 0;

        for (const auto& log : logs)
        {
            if (log == MOVE_TO_PARENT_FOLDER)
            {
                if (depth > 0) 
                {
                    --depth;
                }
            }
            else if (log == REMAIN_FOLDER)
            {
                continue;
            }
            else // Move to the child folder named x 
            {
                ++depth;
            }
        }

        return depth;
    }
};

// https://leetcode.com/problems/crawler-log-folder/description/?envType=daily-question&envId=2024-07-10
