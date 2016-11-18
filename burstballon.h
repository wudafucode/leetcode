#include<algorithm>
#include<functional>
using namespace std;

class Solution {
public:
	
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        vector<int> data;
		data.resize(len+2);
		
		data[0] = 1;
		for(int i=0; i<nums.size();i++)
		{
           data[i+1]=nums[i];
		}
		data[nums.size()+1] = 1;
	    vector<vector<int>> dp(len+2,len+2);

	    for(int k = 2; k<data.size();k++)
			for(int i=0; i<data.size();i++)
		    {
		        int left = i,right = i+k;
				if(right >= data.size())
					break;
				
				for(int m = left +1; m<right; m++)
				{
				   dp[left][right] = max(dp[left][right],
				   	                     data[left]*data[right]*data[m]+ dp[left][m] + dp[m][right]);
				}  
			}
		
        return dp[0][nums.size()+1];
    }
	
   
};



