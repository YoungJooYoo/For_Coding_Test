class Solution {
public:
    int closestValue(TreeNode* root, double target) 
    {
        vector<int> nums; // 트리의 value를 배열에 담는다.
        vector<int> values; // 이 배열은 tree의 노드들과, target과의 값의 차이를 저장하는 배열이다.
        int int_target = target + 0.5; // 0.5 반올림을 해서 근사치 정수로 변환하는 작업
        
        dfs(root, nums); // tree의 값을 탐색해 원소들을 배열에 넣는다
        sort(nums.begin(), nums.end()); // 배열을 정렬한다.
        
        /* 배열에 들어간 원소들은 target 값과 빼서 타겟과 값이 얼마나 차이 나는지 구한다.*/
        for (size_t i = 0; i < nums.size(); i++) {
            values.push_back(abs(nums[i] - int_target));
        }
        
        /* values에서 최소값은 target과 가장 가까운 배열이라는 의미이다.
            따라서 이 배열에서 최소값을 가르키니느 인데스를 알면, 이 인덱스로 nums 배열의 값을 반환하면
            target과 가장 차이가 적은 원소를 찾을 수 있다. */
        int min_index = min_element(values.begin(), values.end()) - values.begin();
        
        return nums[min_index];
    }
    
private:
    void dfs(TreeNode* root, vector<int>& nums)
    {
        if (root == nullptr) {
            return;
        }
        nums.push_back(root->val);
        dfs(root->left, nums);
        dfs(root->right, nums);
    }
};