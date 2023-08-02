class Solution {
public:
	bool find_path(TreeNode* root, int target, vector<char>& path) // finds the path from root to 'target' node
	{
		if (root == nullptr) {
			return false;
		}
		if (root->val == target) {
			return true;
		}
		
        // 백트랙킹 시작,
        // go left, 트리의 왼쪽부터 탐색
		path.push_back('L');
		if (find_path(root->left, target, path)) {
			return true; // 오른쪽에서 발견되면 path 배열에 그대로 경로 냅두고 return (경로를 유지)
		}
		path.pop_back(); //backtracking!, 왼쪽 탐색하다 답이 안나오면 뒤도 돌아가서

		path.push_back('R'); // 뒤로 돌아온 후 오른쪽으로 이어서 탐색을 진행한다.
		if (find_path(root->right, target, path)) {
			return true; // 오른쪽에서 발견되면 path 배열에 그대로 경로 냅두고 return (경로를 유지)
		}
		path.pop_back(); // backtracking

		return false;
	}

	string getDirections(TreeNode* root, int startValue, int destValue)
	{
		vector<char> src; // path from root to source,
		vector<char> dest; // path from root to destination
		vector<char> final_path; // will contain the final path from source to destination

		find_path(root, startValue, src); // see above function, startValue 루트를 찾기
		find_path(root, destValue, dest); // see above function, destValue 루트를 찾기

		size_t i = 0;
		size_t j = 0;

        // Trim the same prefix of both the path (i.e. the path upto LCA is not needed)
		while (i < src.size() && j < dest.size() && src[i] == dest[j]) { // 왼쪽에나 오른쪽에만 몰린 경우라면 중복을 제거 해야 하므로 중복제거 part
			i++;
			j++;
            cout << i << endl;
		}
        
        // you will go up from source to LCA (unless source is the ancestor of destination in which case i == src.size())
		while (i < src.size()) {
			final_path.push_back('U');  // since we go up, everthing will be 'U'
			i++;
		}
		while (j < dest.size()) { // path from LCA down to destination
			final_path.push_back(dest[j]); // remains same 
			j++;
		}
        
		return string(final_path.begin(), final_path.end());
	} 
};

/*

풀이법 :
백트랙킹 기법으로 startValue, destValue가 나올때까지 탐색한다.
탐색 경로가 잘못되면 저장된 배열에서 경로를 빼고 뒤로 돌아가 가시 탐색하며
결국 올바른 방향을 탐색한다.
각각 두 배열로 나누어 startValue, destValue 경로를 찾는다.

*/