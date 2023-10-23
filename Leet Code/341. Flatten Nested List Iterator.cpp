/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(const vector<NestedInteger>& nestedList) 
    {
        const size_t LEN = nestedList.size();

        for (int i = LEN - 1; i >= 0; --i) {
            stack.push(nestedList[i]);
        }
    }
    
    int next() 
    {
        const int result  =  stack.top().getInteger();
        stack.pop();
        return result; 
    }
    
    bool hasNext() 
    {
        while (stack.empty() == false) {
            const auto top = stack.top();
            if (top.isInteger() == true) {
                return true;
            }
            stack.pop();
            const auto& nestedList = top.getList();
            for (int i = nestedList.size() - 1; i >= 0; --i) {
                stack.push(nestedList[i]);
            }
        }

        return false;
    }

private:
    stack<NestedInteger> stack;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

// https://leetcode.com/problems/flatten-nested-list-iterator/description/
