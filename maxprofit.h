
#include <vector>
#include <limits>
using namespace std;
class Solution {
public:
          int minprice;
	
		  vector<int> maxprice; 
    int maxProfit(vector<int> &prices) {
           if(prices.size() == 0)
            return 0;
           int i=0;
           int result =0;
           maxprice.resize(prices.size());
           int tempresult=0;
           minprice =  numeric_limits<int>::max();
		   ComputeMaxPrice(prices);
           for (i=0; i<prices.size()-1;i++)
           {
                tempresult = GetMax(prices, i) - GetMin(prices, i);
                if(tempresult > result)
                    result = tempresult;


           }
           return result;
    } 
	void ComputeMaxPrice(vector<int> &prices)
    {
      int i=0;
	  int len = prices.size();
	  maxprice[len-1] = prices[len-1];
	  for (i=len-2; i>=0; i--)
	  {
          maxprice[i] = max(prices[i],maxprice[i+1]);
	  
	  }
	}
    int GetMin(vector<int> &prices,int index)
    {
       
          if(prices[index] < minprice)
		  	minprice = prices[index];

          return minprice;

    }
     int GetMax(vector<int> &prices,int index)
    {
       
          return maxprice[index];

    }
};
