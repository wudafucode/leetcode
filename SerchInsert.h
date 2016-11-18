class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
          if(nums.size() == 0)
		  	return 0;
          return binarysearch(nums,target);
    }
	int binarysearch(vector<int>& nums, int target)
	{
      int leftindex = 0, rightindex = nums.size()-1;
	  int middle = (leftindex + rightindex)/2;
	  while(leftindex <= rightindex)
	  {
	    middle = (leftindex + rightindex)/2;
        if(nums[middle] > target)
        {
        	rightindex = middle-1;
		}
		else if(nums[middle] < target)
		{
            leftindex = middle + 1;
		}
		else
		{
            return middle;
		}
	  }
      if(nums[middle]>target)
	  	return middle;
	  else
	  	return middle+1;

	}
};