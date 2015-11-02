#include<vector>
using namespace std;


class Solution {
public:
	vector<int> range;
    vector<int> searchRange(int A[], int n, int target) {
          range.push_back(-1);
		  range.push_back(-1);
		  if(n == 0)
		  return range;
          int max,min,middle;
		  max = n-1;
		  min =0;
		  middle = (max + min)/2;
		  while(min <= max)
		  {
             if(A[middle] > target)
             {
                 max    = middle -1;
				 middle =  (min + max)/2;
			 }
			 else if(A[middle] < target)
			 {
                 min    = middle + 1;
				 middle =  (min + max)/2;

			 }
			 else 
			 {
                break;
			 }

		  }
          if(A[middle] != target)
		  	return range;
		  min = middle;
		  while(1)
		  {
             if(min - 1 >=0)
             {
                if(A[min-1] != target)
                {
                  break;
				}
				min = min-1;
			 }
			 else
			 {
                 break;
			 }
		  }
		  max = middle;
		  while(1)
		  {
             if(max + 1 <n)
             {
                if(A[max + 1 ] != target)
                {
                  break;
				}
				max = max + 1;
			 }
			 else
			 {
                 break;
			 }
		  }
		  range.clear();
		  range.push_back(min);
		  range.push_back(max);
		  return range;
		
        
    }
  

	
};