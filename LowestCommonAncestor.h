
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		  if(root == NULL || p == NULL || q == NULL)
		  	return NULL;
		  return  lowestR(root,p,q);
    }
	TreeNode* lowestR(TreeNode* root, TreeNode* p, TreeNode* q){
		if(p == root || q == root){
			return root;
		}
		
		TreeNode* left = NULL;
		TreeNode* right = NULL;
		if(root->left != NULL){
			 left = lowestR(root->left,p,q);
		}
		
		if(root->right != NULL){
			 right = lowestR(root->right,p,q);
		}
		if(left == NULL && right == NULL)
			return NULL;
		if(left != NULL && right != NULL)
			return root;
		
		return (left != NULL)?left:right;
	}
	
};