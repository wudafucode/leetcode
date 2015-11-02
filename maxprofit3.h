#include <vector>

using namespace std;
  
class Solution {
public:
	vector<int> forprofit;
	vector<int> backprofit;
	vector<pair<int,int>> maxprice;
    int maxProfit(vector<int> &prices) {
		if(prices.size() == 0)
		 return 0;
        forprofit.resize(prices.size());
		backprofit.resize(prices.size());
		
        ComputeForProfit(prices,prices.size()-1);
        ComputeMaxPrice(prices,prices.size()-1);
		ComputeBackProfit(prices,prices.size()-1);

		int maxresult;
        for (int i=0; i< prices.size()-1; i++)
        {
			if(forprofit[i] + backprofit[i+1] > maxresult)
				maxresult = forprofit[i] + backprofit[i];


		}
		return maxresult;
    
    }
	void ComputeForProfit(vector<int> &prices,int index)
    {
		 if(index <= 0)
		  return ;
		 pair<int,int> result;
	     GetFMaxProfit(prices,index,result);
		
	     for(int i=result.second; i<= index; i++)
	     {
	     	forprofit[i] = result.first;

		 }
	     ComputeForProfit(prices,result.second-1);
	}
	void ComputeBackProfit(vector<int> &prices,int index)
    {
        if(index >= prices.size()-1)
		  return ;
		 pair<int,int> result;
	     GetBMaxProfit(prices,index,result);
		
	     for(int i=result.second; i<= index; i++)
	     {
	     	forprofit[i] = result.first;

		 }
	     ComputeForProfit(prices,result.second-1);

	}
	void GetBMaxProfit(vector<int> &prices,int begin, pair<int,int>& result)
	{
        if(prices.size()-1 == begin)
		return ;
		pair<int,int> tempindex;
		int profit     = 0;
	    int tempresult;
		pair<int,int> temppair;
		GetMin mMin;
        for (int i=begin; i< prices.size();i++)
        {
               temppair= GetMax(i);
               tempresult = temppair.first- mMin(prices, i);
               if(tempresult > result.first)
               {
                 result.first  = tempresult;
				 result.second = temppair.second;


			   }
     
        }


	}
	void GetFMaxProfit(vector<int> &prices,int end, pair<int,int>& result)
    {
        if(0 == end)
		return ;
		pair<int,int> tempindex;
		int profit     = 0;
	    int tempresult;
		pair<int,int> temppair;
		ComputeMaxPrice(prices,end);
		GetMin mMin;
        for (int i=0; i<=end;i++)
        {
               temppair= GetMax(i);
               tempresult = temppair.first- mMin(prices, i);
               if(tempresult > result.first)
               {
                 result.first  = tempresult;
				 result.second = temppair.second;


			   }
     
        }  
	}
	pair<int,int> GetMax(int index)
    {
       
          return maxprice[index];

    }
	class GetMin
    {
       public:
       int minprice;
	   
	   GetMin():minprice(0)
	   {

	   }
	   int operator()(vector<int> &prices,int index)
	   {
           if(prices[index] < minprice)
		  	minprice = prices[index];

          return minprice;
	   }


	};
	

    void ComputeMaxPrice(vector<int> &prices,int end)
    {
      int i=0;
	  int len = prices.size();
	  maxprice[end] = pair<int,int>(prices[end],end);
	  for (i=len-1; i>=0; i--)
	  {
	      if(prices[i] > maxprice[i+1].first)
	      {
           	  maxprice[i] =  pair<int,int>(prices[i],i);
		  }
		  else
		  {
          	  maxprice[i] = maxprice[i+1];
		  }
          
	  }
	}
};