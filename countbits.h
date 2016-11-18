
#include<math.h>
class Solution {
public:
    vector<int> countBits(int num) {
		
	   vector<int> result;
	   vector<int> tmpresult;
	  

	   result.push_back(0);
	    if(num == 0)
	   	return result;
	   result.push_back(1);
	   if(num == 1)
	   	return result;
	   for(int i = 2; pow((float)2,i-1) <= num; i++)
	   {
	       int j = pow((float)2,i-1);
		   int k=0;
	   	   for(; j< pow((float)2,i) && j<=num;j++)
	   	   {
	   	   	  tmpresult.push_back(result[k]+1);
			  k++;
		   }
		   vector<int>::iterator ite; 
		   for(ite = tmpresult.begin(); ite != tmpresult.end(); ite++)
		   	result.push_back(*ite);
           tmpresult.clear();
	   }
	   	

	return result;   
    }
};