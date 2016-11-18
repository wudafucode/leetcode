


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
		if(nums.size() == 0 || nums.size() == 1)
		return 0;
		if(nums.size() == 2)
		return nums[0];
	    int middle = 0;
		int middlecount = 0;
		int lowbound  = 1;
		int highbound = nums.size()-1;
	 
		while(lowbound < highbound)
		{
           middle      = (lowbound+highbound)/2;
		   middlecount = GetCount(nums,middle);
		   if(middlecount > middle)
		   {
              highbound = middle;
		   }
		   else if(middlecount <= middle)
		   {
              lowbound = middle+1;
		   }
		} 
        return lowbound;
    }
	
	int GetCount(vector<int>& nums,int middle)
	{
      int count = 0;
	  for(int i =0; i<nums.size();i++)
	  {
         if(nums[i] <= middle )
		 	count++;
	  }
	  return count;

	}
};




