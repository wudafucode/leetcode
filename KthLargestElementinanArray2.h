#include<vector>

using namespace std;



class Solution{
public:
    int findKthLargest(vector<int>& nums, int k) {
		if(nums.size() == 0)
			return 0;
		int index  = 0;
		int left = 0;
		int right = nums.size()-1;
		while(1){
			index  = mergesort(nums,left,right);
			
			if(k == index+1){
				return nums[index];
			}
			if(k < index+1){
				 right = index-1;
			}else{
				left  = index+1;
			}
        }
		
    }
	int mergesort(vector<int>& nums,int left,int right){
		if(left < 0 ||  right >= nums.size())
			return 0;
		
		int pivot = nums[right];
		int j     = left;
		for(int i = left;i < right;i++){
			
			if(nums[i]>pivot){
				swap(nums[i],nums[j]);
				j++;
			}
		}
		
        swap(nums[j],nums[right]);
		
		return j;
	}
};


