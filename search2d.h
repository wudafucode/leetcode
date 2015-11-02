#include<vector>
#include<map>
using namespace std;
class Solution {
public:
	int rowlen;
    int collen;
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
             rowlen = matrix[0].size();
         
		     int begin =0, end = matrix.size()*matrix[0].size() -1;
			 pair<int,int> index ;
			 while(begin <= end)
			 {
				index = GetIndex(begin,end);
				if(matrix[index.first][index.second] == target)
				 return true;
				if(matrix[index.first][index.second] < target)
				{
				
                     begin = (begin + end)/2 +1;
				}
				else
			    {
                     end = (begin + end)/2 -1;
				}		 
			 }

            return false;	    
    }
	
	pair<int,int> GetIndex(int begin,int end)
	{
	    pair<int,int> temp;
    	int middle  = (begin + end)/2;
		temp.first  = middle / rowlen;
		temp.second = middle % rowlen;
		return temp;
	
	}
};
