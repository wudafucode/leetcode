
#include <vector>
using namespace std;
class Solution {
public:
	vector<pair<int,int>> nothingprofit;
	vector<pair<int,int>> hastockprofit;
	
	enum
    {
       nothing  =0,
	   hasstock =1,
	};
    int maxProfit(vector<int> &prices) {

        int result =0;
        nothingprofit.resize(prices.size());
		hastockprofit.resize(prices.size());
        result = BuyandSell(prices,0,pair<int,int>(0,0));
		return result;
        
    }
	int BuyandSell(vector<int> &prices,int index,pair<int,int> status)
    {
      int i=0;
	
	  pair<int,int> profit,temp;
	  int maxprofit;
      if(index == prices.size())
	  	return 0;
	  if(nothingprofit[index].first == 1 && status.first == nothing )
	  {
    
	     return nothingprofit[index].second;

	  }
	  if(hastockprofit[index].first == 1 &&status.first == hasstock)
	  {
		    if(status.second >= hastockprofit[index].second)
			return 0;
	  }
	
	  if(status.first == nothing)
	  {
	  
		  profit.first	= BuyandSell(prices,index +1,status);

		  status.first  = hasstock;
		  status.second = prices[index]; 
		  profit.second += BuyandSell(prices,index+1,status);
		  nothingprofit[index].first  =1;
		  maxprofit =max(profit.first,profit.second);
	      nothingprofit[index].second = maxprofit;

	  }
	  else
	  {
	  
          profit.first	= BuyandSell(prices,index +1,status);

          if(prices[index] > status.second)
          {
           	status.first  = nothing;
			
		    profit.second  = prices[index] - status.second ; 
			status.second  = 0;
		    profit.second += BuyandSell(prices,index+1,status);	
		  }
		  maxprofit =max(profit.first,profit.second);
	     
		  if(maxprofit == 0)
		  {
			  hastockprofit[index].first  =1;
			   hastockprofit[index].second = status.second;

		  }
		 
		 
	
	  }

	 // allprofit[index].first  =1;
	 // allprofit[index].second = maxprofit;
	  return maxprofit;


	}
	pair<int,int> FindHighPrice(vector<int> &prices,int index)
    {
       pair<int,int> temp;
	   temp.first = prices[index];
      for(int i=index+1; i< prices.size(); i++)
      {
        if(prices[i]>temp.first)
        {
           temp.first  = prices[i];
		   temp.second = i;
		}

	  }
      return temp;
	}
};

