
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int totalresult = 0;
		for(int i=0; i<nums.size();i++)
			totalresult+=nums[i];
		int tempresult  = 0;
		int len = nums.size();
		tempresult = len*(len+1);
		tempresult = tempresult/2;
		return tempresult - totalresult;

		
        
    }
};





