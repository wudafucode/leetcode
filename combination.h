#include<vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> result;
	vector<int> temp;
    vector<vector<int> > combine(int n, int k) {
 
		temp.resize(k);
		GetCombine(n,k);
		return result;
		

    }
    void GetCombine(int n, int k)
    {
        if(k==0)
        {
          result.push_back(temp);
		  return ;
		}
        for(int i=n; i>=k;i--)
        {
           temp[k-1]=i;
           GetCombine(i-1,k-1);	
		}

	}
	
};