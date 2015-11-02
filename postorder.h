#include<stack>
using namespace std;
  struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
	typedef TreeNode * STreeNode;
	vector<int> result;
    vector<int> postorderTraversal(TreeNode *root) {
         stack<pair<STreeNode,bool>> buf; 
         if(root == NULL)
		 return result;
		 while(1)
		 {

	        if(root->left == NULL && root->right == NULL)
	        {
	           result.push_back(root->val);
			   root = GetData(buf);
			   if(root == NULL)
			   break;
			}
            else if(root->left != NULL)
			{
			  
			   buf.push(pair<STreeNode,bool>(root,true));
			   if(root->right != NULL)
			   {
			      buf.push(pair<STreeNode,bool>(root->right,false));
			   }
			   root = root->left;  
			}
			else 
			{
              
			   buf.push(pair<STreeNode,bool>(root,true));
			   root = root->right;  
			}
			
		}
     

		 return result;
   
    }
	STreeNode GetData(stack<pair<STreeNode,bool>> &buf)
	{
	    pair<STreeNode,bool> temp;
		if(buf.size() == 0)
		return NULL;
    	
		while(1)
		{
		    temp = buf.top();
		    buf.pop();
			if(temp.second == false)
				break;
            result.push_back((temp.first)->val);
		  
		    if(buf.size() == 0)
		    	break;
		}
        if(temp.second == true)
		return NULL;
		else
		return temp.first;

	}
	
};
bool test1()
{
    int i=0;
	TreeNode buf[3] = {1,2,3};
	TreeNode * root;
	root = &buf[0];
	root->right = &buf[1];
	buf[1].left = &buf[2];
	vector<int> result ;
	Solution msol;
	result = msol.postorderTraversal(root);

	copy(result.begin(),result.end(),ostream_iterator<int>(cout, " "));

	return true;

}
bool test2()
{
     int i=0;
	TreeNode buf[3] = {1,2,3};
	TreeNode * root;
	root = &buf[0];
	root->left  = &buf[1];
	root->right = &buf[2];
	
	vector<int> result ;
	Solution msol;
	result = msol.postorderTraversal(root);

	copy(result.begin(),result.end(),ostream_iterator<int>(cout, " "));

	return true;

     return true;

}