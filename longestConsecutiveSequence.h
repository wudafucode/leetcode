class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash_buf(nums.begin(),nums.end());
		int value;
		int rightvalue,leftvalue,result = 0;
		while(!hash_buf.empty())
		{
	         unordered_set<int>::iterator ite;
			 ite = hash_buf.begin();
			 rightvalue = *ite;
			 leftvalue = *ite -1;
			 while(hash_buf.find(rightvalue) != hash_buf.end())
			 {
			    hash_buf.erase(rightvalue);
				rightvalue++;
			 }
			 while(hash_buf.find(leftvalue) != hash_buf.end())
			 {
			    hash_buf.erase(leftvalue);
				leftvalue--;
			 }
			 if(rightvalue - leftvalue > result)
			 {
                result = rightvalue - leftvalue - 1;
			 }

		}
		return result;
		



		
    }
};