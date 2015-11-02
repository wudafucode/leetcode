/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 struct TreeLinkNode {
 	int val;
 	TreeLinkNode *left, *right, *next;
 	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };
class Solution {
public:
    void connect(TreeLinkNode *root) {

       if(root == NULL)
	   	return ;
       root->next = NULL;
	   rconnect(root);

   
    }
	void rconnect(TreeLinkNode *root)
	{
	    if(root->left == NULL && root->right == NULL)
		 return ;
		root->left->next = root->right; 
		rconnect(root->left);
		rconnect(root->right);
		TreeLinkNode temp(0);
		temp.left  = root->left->right;
		temp.right = root->right->left; 
		rconnect(&temp);

	}
};








