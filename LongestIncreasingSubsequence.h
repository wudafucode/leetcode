#include<vector>

using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
			return 0;
		vector<int> data(nums.size(),1);
		int maxvalue = 1;
		for(int i=nums.size()-1; i>=0; i--){
			int temp = data[i];
			for(int j=i+1; j<nums.size();j++){
				
				if(nums[j] > nums[i]){
					data[i] = max(data[i],temp+data[j]);
				}	
				
			}
			if(maxvalue < data[i])
				maxvalue = data[i];

		}
		return maxvalue;


		
        
    }
};

