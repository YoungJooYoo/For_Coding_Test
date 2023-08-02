/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) 
    {
        return dfs(nestedList, 1);
    }

    int dfs(vector<NestedInteger>& list, int depth) {
        int total = 0;
        for (NestedInteger& nested : list) { // 주어진 리스트를 원소단위로 훓는다.
            if (nested.isInteger()) { // 훓어진 원소가 하나짜리인지, 또 다른리스트인지 판별한다.
                total += nested.getInteger() * depth; // 현재 리스트에서 depth 가중치를 더해 누적
            } else { // 다른 리스트가 속에 있다면 더 깊이 탐색하면서 들어간다.
                total += dfs(nested.getList(), depth + 1); // 탐색하며 깊이는 1씩 깊어진다.
            }
        }
        return total;
    }
};


/*
풀이법 :
내포된 리스트를 찾는 것이 관건
즉, 리스트의 깊이가 깊어지면 가중치를 곱해서 누적 값을 반환한다.
[전체리스트] + [부분리스트] =[전체[부분리스트]리스트]
이런 식으로 리스트의 깊이가 깊어지는 것이 문제를 해석하는 방향이다.
따라서 리스트를 탐색하면서 깊이를 아는 것이 관건이다.
*/