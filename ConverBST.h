struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {

      return Convert(nums,0,nums.size());
		
    }
	TreeNode* Convert(vector<int>& nums,int begin,int end)
	{

		int middle = (begin + end)/2;
		if(begin == end)
		return NULL;
        TreeNode* pNode = new TreeNode(nums[middle]);

		pNode->left  = Convert(nums,begin,middle);
		pNode->right = Convert(nums,middle + 1,end);
		 
        return pNode;
	}
	
};