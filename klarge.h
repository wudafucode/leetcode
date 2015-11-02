#include<vector>
using namespace std;

//´ý»áÔÚÐ´holeindex
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

       int index=0;
	   int backindex = nums.size()-1, forindex = 0;
       while(1)
       {
          index = sort(nums,forindex,backindex);
		  if(index == k-1)
		  break;
		  if(index > k-1)
		  {
             backindex = index -1;
		  }
		  else
		  {
             forindex = index + 1;
		  }
   
	   }
	   return nums[k-1];      
    }
	void AdjustBack(vector<int>& nums,int& holeindex,int &backindex)
	{
          while(nums[backindex] <= nums[holeindex] && backindex> holeindex)
	      {
              backindex--;
		  }
		  if(backindex ==holeindex)
		  	return;
		  
		   swap(nums[holeindex],nums[backindex]);
		   holeindex = backindex;
		  
	}
	void AdjustFor(vector<int>& nums,int& holeindex,int &forindex)
	{
          while(nums[forindex] >= nums[holeindex] && forindex < holeindex)
	      {
              forindex++;
		  }
		  if(forindex == holeindex)
		  	return;
		  
		   swap(nums[holeindex],nums[forindex]);
		   holeindex = forindex;
		  
	}
	int sort(vector<int>& nums,int forindex,int backindex)
    {
      int flag=0;
	  int holeindex = forindex;
	  while(forindex < backindex)
	  {
	      if(flag ==0)
	      {

             AdjustBack(nums,holeindex,backindex);
          	 flag =1;
		  }
		  else
		  {

            AdjustFor(nums,holeindex,forindex);
			flag = 0;
		  }
	  }
	  return holeindex;
	
	}
};





