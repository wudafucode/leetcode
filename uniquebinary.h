class Solution {
public:
	int result;
	vector<int> tempresult;
    int numTrees(int n) {
       tempresult.resize(n+1);
	   return recurnum(n);
    }
   int recurnum(int n)
   {
        int leftnum;
		int leftmulti  = 1;
		int rightmulti = 1;
		int result = 0,totalnum = n-1;
		if(n == 0 || n==1)
		return 1;
		if(tempresult[n] != 0)
		return tempresult[n];
		for(leftnum=0; leftnum<= totalnum;leftnum++)
		{
            leftmulti  = recurnum(leftnum);
			rightmulti = recurnum(totalnum-leftnum);
			result = result + leftmulti*rightmulti;
		}
	    tempresult[n] = result;
		return result;

   }
};