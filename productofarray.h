class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
             vector<int> resultarray;
			 resultarray.resize(nums.size());
			 int result = 1;
			 int zerocount = 0;
             if(nums[0] == 0)
			 	zerocount++;
			 for(int i=1; i< nums.size(); i++)
			 {
			     if(nums[i] == 0)
				 	zerocount++;
				 if(zerocount == 2)
				 return resultarray;
                 result = result*nums[i];
			 }
			 if(zerocount == 1)
			 {
			   int j=0;
			   result = 1;
               for(int i=0; i<nums.size(); i++)
               {
                   if(nums[i] == 0)
				   	 j = i;
				    else
				     result = result*nums[i];
			   }
			   resultarray[j]= result;
			   return resultarray;

			 }
			 resultarray[0] = result; 
			 for(int i=1; i<nums.size();i++)
			 {
			    
                resultarray[i] = (result /nums[i])*nums[i-1];
				result = resultarray[i];
			 }

             return resultarray;
        
    }
};