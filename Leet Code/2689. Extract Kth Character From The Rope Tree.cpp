class Solution {
public:
    void dfs(RopeTreeNode* root) 
    {
        if (root == nullptr) {
            return;
        }

        if (root->val.size() > 0) {
            str += root->val;
        }

        dfs(root->left);
        dfs(root->right);
    }

    char getKthCharacter(RopeTreeNode* root, int k) 
    {
        dfs(root);
        return str[k - 1];
    }

private:
    string str;
};


// https://leetcode.com/problems/extract-kth-character-from-the-rope-tree/

/*

### 2689. 로프 트리에서 K번째 문자 추출하기

#### 문제 설명

이진 트리의 루트와 정수 k가 주어집니다. 각 노드는 왼쪽 및 오른쪽 자식 외에도 두 가지 속성을 가지고 있습니다: 소문자 영어 문자만 포함하는 문자열 `node.val`(빈 문자열일 수 있음)과 음수가 아닌 정수 `node.len`. 이 트리에는 두 종류의 노드가 있습니다:

- **잎(Leaf)**: 이 노드들은 자식이 없으며, `node.len = 0`, `node.val`은 비어 있지 않은 문자열입니다.
- **내부(Internal)**: 이 노드들은 적어도 하나의 자식을 가지고 있으며(최대 두 자식), `node.len > 0`, `node.val`은 빈 문자열입니다.

위에서 설명한 트리를 로프(Rope) 이진 트리라고 합니다. 이제 다음과 같이 재귀적으로 S[node]를 정의합니다:

- 만약 노드가 잎 노드라면, S[node] = node.val,
- 그렇지 않고 노드가 내부 노드라면, S[node] = concat(S[node.left], S[node.right])이고 S[node].length = node.len입니다.

S[root] 문자열의 k번째 문자를 반환하세요.

참고: s와 p가 두 문자열이라면, concat(s, p)는 p를 s에 연결하여 얻은 문자열입니다. 예를 들어, concat("ab", "zz") = "abzz"입니다.

#### 예시

**예시 1:**

- 입력: root = [10,4,"abcpoe","g","rta"], k = 6
- 출력: "b"
- 설명: 아래 그림에서, 내부 노드에는 node.len을 나타내는 정수를, 잎 노드에는 node.val을 나타내는 문자열을 두었습니다. S[root] = concat(concat("g", "rta"), "abcpoe") = "grtaabcpoe"임을 볼 수 있습니다. 따라서 S[root][5], 즉 6번째 문자는 "b"와 같습니다.

**예시 2:**

- 입력: root = [12,6,6,"abc","efg","hij","klm"], k = 3
- 출력: "c"
- 설명: 아래 그림에서, S[root] = concat(concat("abc", "efg"), concat("hij", "klm")) = "abcefghijklm"임을 볼 수 있습니다. 따라서 S[root][2], 즉 3번째 문자는 "c"와 같습니다.

**예시 3:**

- 입력: root = ["ropetree"], k = 8
- 출력: "e"
- 설명: 아래 그림에서, S[root] = "ropetree"임을 볼 수 있습니다. 따라서 S[root][7], 즉 8번째 문자는 "e"와 같습니다.

#### 제약 조건

- 트리의 노드 수는 [1, 10^3] 범위에 있습니다.
- `node.val`은 소문자 영어 문자만 포함합니다.
- 0 <= `node.val.length` <= 50
- 0 <= `node.len` <= 10^4
- 잎 노드의 경우, `node.len = 0`이고 `node.val`은 비어 있지 않습니다.
- 내부 노드의 경우, `node.len > 0`이고 `node.val`은 비어 있습니다.
- 1 <= k <= S[root].length

*/
