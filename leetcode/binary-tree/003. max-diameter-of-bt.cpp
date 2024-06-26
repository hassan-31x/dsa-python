//? 1. Keep track of height of tree & use a global max variable to store the max diameter & change at any time to keep track of max
//! TC: O(n) SC: O(n)
// https://leetcode.com/problems/diameter-of-binary-tree/submissions/1300159312

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        dfs(root, result);
        return result;
    }

private:
    int dfs(TreeNode* root, int& result) {
        if (root == NULL) {
            return 0;
        }
        
        int left = dfs(root->left, result);
        int right = dfs(root->right, result);
        
        result = max(result, left + right);
        return 1 + max(left, right);
    }
};

//in python using global variable
def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
    res = 0 // or res = [0]

    def dfs(root):
        nonlocal res // or no need

        if not root:
            return 0
        left = dfs(root.left)
        right = dfs(root.right)
        res = max(res, left + right) // or res[0] = max(res[0], left + right)

        return 1 + max(left, right)

    dfs(root)
    return res