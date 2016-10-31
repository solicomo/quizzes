#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

bool create_tree(TreeNode* &root, vector<int> &nums)
{
	queue<TreeNode**> nodes;
	nodes.push(&root);

	for (auto n : nums)
	{
		if (nodes.empty())
			break;

		auto node = nodes.front();
		nodes.pop();

		if (n == INT_MAX)
		{
			*node = NULL;
			continue;
		}

		*node = new TreeNode(n);
		nodes.push(&((*node)->left));
		nodes.push(&((*node)->right));
	}

	return nodes.empty();
}

void destroy_tree(TreeNode* root)
{
	queue<TreeNode*> nodes;
	nodes.push(root);

	while(!nodes.empty())
	{
		auto node = nodes.front();
		nodes.pop();

		if (node->left != NULL)
			nodes.push(node->left);

		if (node->right != NULL)
			nodes.push(node->right);

		delete root;
	}
}


bool tree2dot(TreeNode* root, const char* file)
{
	int n = 0;
	queue<TreeNode**> nodes;
	nodes.push(&root);

	FILE* fp = fopen(file, "w");

	if (fp == NULL)
		return false;

	fprintf(fp, "digraph BinTree {\n");

	while(!nodes.empty())
	{
		auto node = nodes.front();
		nodes.pop();

		if (*node == NULL)
		{
			fprintf(fp, "\tn%p [shape=box,label=\"NULL\"];\n", node);
			continue;
		}

		fprintf(fp, "\tn%p [label=\"%d\"];\n", node, (*node)->val);
		fprintf(fp, "\tn%p -> n%p;\n", node, &((*node)->left));
		fprintf(fp, "\tn%p -> n%p;\n", node, &((*node)->right));

		nodes.push(&((*node)->left));
		nodes.push(&((*node)->right));
	}

	fprintf(fp, "}\n");
	fclose(fp);

	return true;
}

