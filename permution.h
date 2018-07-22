
#include<vector>

using namespace std;


class Solution {
public:
		vector<vector<int>>  all;
    vector<vector<int>> permute(vector<int>& nums) {

		permute_index(nums,0);
		return all;
    }
	void  permute_index(vector<int> nums,int index){
		
		if(index == nums.size()){
			all.push_back(nums);
			return;
		}
        for(int i=index; i<nums.size();i++){
			swap(nums[index],nums[i]);
			permute_index(nums,index+1);
		}
	}
};



