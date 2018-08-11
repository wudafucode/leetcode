#include <limits>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	struct MAXNODE{
       int maxnow;
	   int maxhistory;
	   MAXNODE(){maxnow=0;maxhistory=0;}
	};
    int maxPathSum(TreeNode* root) {
        MAXNODE temp;
		if(root==NULL)
			return 0;
		temp = recursive(root);
		return max(temp.maxnow,temp.maxhistory);
    }
	MAXNODE recursive(TreeNode* root){
           MAXNODE ret;
		   MAXNODE left;
		   MAXNODE right;
		   if(root == NULL)
		      return ret;
		   int val = root->val;
		   ret.maxnow     = val;
		   ret.maxhistory = val;
		   if(root->left == NULL && root->right == NULL)
		   	 return ret;
		   if(root->left != NULL && root->right == NULL){
		   	
              left = recursive(root->left);
			  
			  ret.maxnow= max(val,val+left.maxnow);
			  
			  ret.maxhistory = max(ret.maxnow,left.maxhistory);
			  return ret;
		   }
		   if(root->right != NULL && root->left == NULL){
		   	
              right = recursive(root->right);
			  
			  ret.maxnow= max(val,val+right.maxnow);

			  ret.maxhistory = max(ret.maxnow,right.maxhistory);
			  return ret;
		   }
		 
	   	  left = recursive(root->left);
		 
		 
	   	  right = recursive(root->right);

		  ret.maxnow     = max(val,val+left.maxnow);

		  ret.maxnow     = max(ret.maxnow,val+right.maxnow);


		  int temp       = max(ret.maxnow,val+left.maxnow+right.maxnow);
		  

		  ret.maxhistory = max(left.maxhistory,right.maxhistory);

		  ret.maxhistory = max(temp,ret.maxhistory);
		
		  
		  return ret;
	}

};


