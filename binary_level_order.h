

struct TreeNode {
	  int val;
	  TreeNode *left;
	  TreeNode *right;
	  TreeNode(int x =0) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> result;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<TreeNode*> thisleveldata;
		vector<TreeNode*> topleveldata;
		if(root == NULL)
		 return result;
         vector<int> levelresult;
		 levelresult.push_back(root->val);
		 result.push_back(levelresult);
		 //insert_iterator<vector<vector<int>>> iter;
		 int i=0;

		 topleveldata.push_back(root);

		 while(1)
		 {
             levelresult.clear();
			 thisleveldata.clear();
			 if(topleveldata.size() == 0)
			  break ;
			 for(i= 0; i < topleveldata.size() ;i++)
			 {
                
				AddResult(topleveldata[i],levelresult,thisleveldata);
			 }	
			 //AddEnd(topleveldata[topleveldata.size()-1],levelresult,thisleveldata);
			 if(levelresult.size()!=0)
			 result.insert(result.begin(),levelresult);
			 topleveldata.resize(thisleveldata.size());
			 copy(thisleveldata.begin(),thisleveldata.end(),topleveldata.begin());
		 }		
		 return result;
        
    }
	void AddResult(TreeNode* pNode,vector<int>& levelresult,vector<TreeNode*>& thisleveldata)
	{
	
		   TreeNode* pNext; 
		   if(pNode->left != NULL)
		   {
		      pNext = pNode->left;
			  thisleveldata.push_back(pNext);
		      levelresult.push_back(pNext->val);
		   }
		     
		   if(pNode->right != NULL)
		   {
		      pNext = pNode->right;
			  thisleveldata.push_back(pNext);
		      levelresult.push_back(pNext->val);
		   }
	}
	void AddEnd(TreeNode* pNode,vector<int>& levelresult,vector<TreeNode*>& thisleveldata)
	{
    	 if(pNode->right!=NULL)
		 {
              AddResult(pNode,levelresult,thisleveldata);
	     }
		 else
		 {
		    TreeNode* pNext;
            if(pNode->left!=NULL)
            {
                pNext = pNode->left;
				thisleveldata.push_back(pNext);
	            levelresult.push_back(pNext->val);

			}

		}
	}
};



