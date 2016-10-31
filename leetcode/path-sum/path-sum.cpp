// https://leetcode.com/problems/path-sum/
//
// 112. Path Sum
//
// Given a binary tree and a sum, determine if the tree has a root-to-leaf path 
// such that adding up all the values along the path equals the given sum.
//
// For example:
//
// Given the below binary tree and sum = 22,
//
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \      \
//         7    2      1
// 
// return true, as there exist a root-to-leaf path `5->4->11->2` which sum is 22.
//
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
	bool hasPathSum(TreeNode* root, int sum)
	{
		if (root == NULL)
			return false;

		TreeNode* child = NULL;
		stack<TreeNode*> s;
		s.push(root);

		while(!s.empty())
		{
			root = s.top();

			if (root->left == NULL && root->right == NULL)
			{
				if (root->val == sum)
					return true;

				s.pop();
				child = root;
			}
			else if (child != NULL && (root->left == child || root->right == child))
			{
				s.pop();
				child = root;
			}
			else
			{
				if (root->left != NULL)
				{
					root->left->val += root->val;
					s.push(root->left);
				}

				if (root->right != NULL)
				{
					root->right->val += root->val;
					s.push(root->right);
				}
			}
		}

		return false;
	}
};

