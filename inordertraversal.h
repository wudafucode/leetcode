

  struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 #include<stack>
class Solution {
public:
	class InorderIte
	{
	public:
       stack<TreeNode*> buf;
	   InorderIte()
	   {
	      
	   }
	   void Init(TreeNode* root)
	   {
         while(root != NULL)
         {
            buf.push(root);
			root = root->left;
		 }

	   }
	   TreeNode* next()
	   {
	       if(buf.size() == 0)
		   	return NULL;
           TreeNode* temp = buf.top();
		   buf.pop();
		   Init(temp->right);
		   return temp;
	   }
	   

	};
    vector<int> inorderTraversal(TreeNode* root) {
          InorderIte tempite;
		  TreeNode* pdata = NULL;
		  vector<int> result;
		  tempite.Init(root);
		  
		  pdata = tempite.next();
		  for(;pdata != NULL; pdata = tempite.next())
		  {
             result.push_back(pdata->val);
		  }
		  return result;
    
    }

};