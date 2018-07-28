#include<vector>
using namespace std;

  struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
	vector<vector<int>> result;
    vector<vector<int>> levelOrder(TreeNode* root) {

		pushlevel(root,0);
		return result;
        
    }
	void pushlevel(TreeNode* root,int level){
		if(root == NULL)
			return ;
		if(level < result.size()){
			result[level].push_back(root->val);
		}
		else{
			result.push_back(vector<int>(1,root->val));
		}
        pushlevel(root->left,level+1);
		pushlevel(root->right,level+1);

	}
};

