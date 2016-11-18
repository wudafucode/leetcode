
/**
 * Definition for a binary tree node.*/
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
	int index;
	int result;
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL)
		return 0;
		index  = 0;
		result = 0;
	    RSmall(root,k);
		return result;
    }
	int RSmall(TreeNode* root,const int k)
	{
	   int flag = false;
       if(root->left != NULL)
       {
           flag = RSmall(root->left,k);
		   if(flag == true)
		   	return true;
		   
	   }
	   index++;
	   if(index == k)
	   {
          result = root->val;
		  return true;
	   }
	   
	   if(root->right != NULL)
	   {
		  return RSmall(root->right,k);
	   }
	   return false;
	}

};




