#include <vector>
using namespace std;
struct TreeLinkNode {
 	int val;
 	TreeLinkNode *left, *right, *next;
 	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };


class Solution {
public:
	typedef TreeLinkNode * Snode;

    void connect(TreeLinkNode *root) {

       if(root == NULL)
	   	return ;
       root->next = NULL;
	   if(root->left != NULL && root->right != NULL)
	   	 root->left->next = root->right;
	   TreeLinkNode parent(0);
	   parent.left = root;
	   rconnect(root,&parent);

   
    }
	void rconnect(TreeLinkNode *root,TreeLinkNode *parentroot)
	{
	    connecthlevel(root,parentroot);

	    pair<Snode,Snode> temp;
		temp=getfirst(parentroot);
	    if(temp.first == NULL)
		 return ;
        	
       rconnect(temp.first,temp.second);
		
	}
	pair<Snode,Snode> getfirst(TreeLinkNode *parentroot)
    {
       TreeLinkNode *ptemp = NULL;
       while(parentroot != NULL)
       {
        
        if(parentroot->left != NULL)
        {
           ptemp = parentroot->left;
		   if(ptemp->left != NULL)
		   {
        	  return pair<Snode,Snode>(ptemp->left,ptemp);
		   }
    	   if(ptemp->right != NULL)
    	   {
              return pair<Snode,Snode>(ptemp->right,ptemp);
			 	
    	   }	
 
		}
	    if(parentroot->right != NULL)
	    {
			ptemp = parentroot->right;
			if(ptemp->left != NULL)
		    {
			   return pair<Snode,Snode>(ptemp->left,ptemp);
		    }
		    if(ptemp->right != NULL)
		    {
			  return pair<Snode,Snode>(ptemp->right,ptemp);
		    }    
			
		}
		parentroot = parentroot->next;
	   }
	   ptemp = NULL;
	   return pair<Snode,Snode>(ptemp,ptemp);

	

	}
	void connecthlevel(TreeLinkNode *root,TreeLinkNode *parentroot)
	{
        if(parentroot == NULL)
		  return ;
		TreeLinkNode *ptemp,*pconnect;
		ptemp = parentroot->next;
		pconnect = root;
		if(parentroot->right != NULL && root != parentroot->right)
        {
             pconnect->next = parentroot->right;
			 pconnect = parentroot->right;
		}
		while(ptemp != NULL)
		{
		  if(ptemp->left != NULL)
          {
             pconnect->next = ptemp->left;
			 pconnect = ptemp->left;
		  }
          if(ptemp->right != NULL)
          {
             pconnect->next = ptemp->right;
			 pconnect = ptemp->right;
		  }
          ptemp = ptemp->next;
		}
			



	}
	
};


