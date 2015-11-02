#include <vector>
#include <stack>
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
    vector<int> preorderTraversal(TreeNode *root) {
	
		stack<STreeNode> buf;
	
		vector<int> result;
		STreeNode pcurrent;
		pcurrent = root;
		while(pcurrent != NULL)
		{
		   result.push_back(pcurrent->val);
		   if(pcurrent->left != NULL)
		   {
			   buf.push(pcurrent);
			   pcurrent = pcurrent->left;
			   continue;

		   }
		   if(pcurrent->right != NULL)
		   {
			   pcurrent = pcurrent->right;
			   continue ;
		   }
		   pcurrent = NULL;
		   while(buf.size()!=0)
		   {
			   pcurrent = buf.top();
			   buf.pop();
			   if(pcurrent->right != NULL)
			   {
			      pcurrent = pcurrent->right;
               	  break;
			   }
			  
			   pcurrent = NULL;
		   }
		   

		}
		

	
		return result;
    }
	
};

class Solution1 {
public:
	
	typedef TreeNode * STreeNode;
    vector<int> preorderTraversal(TreeNode *root) {
	
		stack<STreeNode> buf;
		nodeiterator temp(root,buf);
		vector<int> result;
		
		for(;temp.NotDone();++temp)
		{
		  result.push_back(temp->val);

		}

	
		return result;
    }
	class nodeiterator
	{
     	public:

		stack<STreeNode>& buf;
		STreeNode pcurrent;
		nodeiterator(TreeNode *root,stack<STreeNode>& data):pcurrent(root),buf(data){}
		void operator++()
		{
		   if(pcurrent->left != NULL)
		   {
			   buf.push(pcurrent);
			   pcurrent = pcurrent->left;
			   return ;

		   }
		   if(pcurrent->right != NULL)
		   {
			   pcurrent = pcurrent->right;
			   return ;
		   }
		   pcurrent = NULL;
		   while(buf.size()!=0)
		   {
			   pcurrent = buf.top();
			   buf.pop();
			   if(pcurrent->right != NULL)
			   {
			      pcurrent = pcurrent->right;
               	  break;
			   }
			  
			   pcurrent = NULL;
		   }
		   
		}
		
		TreeNode* operator->()
		{
         	return pcurrent;
			
		}
		TreeNode& operator*()
		{
         	return *pcurrent;
			
		}
		bool NotDone()
		{
		    if(pcurrent == NULL)
        	return false;
			else
			return true;
		}

	};
};













