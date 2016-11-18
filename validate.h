



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
    bool isValidBST(TreeNode* root) {
		int  minvalue = 0,maxvalue = 0;
	   	bool flag = false;
         if(NULL == root)
		 	return true;

		 
		
		 if(root->left != NULL)
		 {
             flag = depthfirst(root->left,minvalue,maxvalue);
			 if(flag == false || root->val <= maxvalue)
			 	return false;
			 
			 
		 }
	
		 
         if(root->right != NULL)
         {
         	flag = depthfirst(root->right,minvalue,maxvalue);
			if(flag == false || root->val >= minvalue)
				return false;
			
		 }

		 
         return true;
        
    }
	
	bool depthfirst(TreeNode* root,int& minvalue,int& maxvalue)
	{
		int  tminvalue = 0,tmaxvalue = 0;
	   	bool flag = false;
        if(NULL == root)
		 	return true;

		 
		 minvalue   = root->val;
		 maxvalue   = root->val;
		 if(root->left != NULL)
		 {
             flag =  depthfirst(root->left,tminvalue,tmaxvalue);
			 if(flag == false || root->val <= tmaxvalue)
			 	return false;
			 minvalue  = tminvalue;
			 
		 }
	
		 
         if(root->right != NULL)
         {
         	flag =  depthfirst(root->right,tminvalue,tmaxvalue);
			if(flag == false || root->val >= tminvalue)
				return false;
			 maxvalue = tmaxvalue;
		 }

		 
         return true;

	}
	
};



