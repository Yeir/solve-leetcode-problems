/********************************************************************************** 
*
*问题：给出一棵二叉树，问树的深度。
*方法一：作一个广搜，将每一层的子节点放到队列里，记录每一层的子节点数，
*	再将子节点出队列，判断是否存在左右子节点，存在就入队列。直到队列为空，就求出深度。
*
*
**********************************************************************************/

//方法一
//15MS
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
		if(root == NULL) return 0;
        int depth = 0;
		int level = 0;
		queue<TreeNode*> q;
		q.push(root);
		level = 1;
		while(!q.empty())
		{
			int levelcopy = level;
			level = 0;
			for( ; levelcopy>0; levelcopy--)
			{
				TreeNode* temp = q.front();
				q.pop();
				if(temp->left != NULL)
				{
					q.push(temp->left);
					level++;
				}
				if(temp->right != NULL)
				{
					q.push(temp->right);
					level++;
				}
			}
			depth++;
		}
		return depth;
    }
};