#include <vector>
#include <limits>
using namespace std;
//想想用foreach怎么写
bool test1()
{
     vector<int> data;
	 int i=1;
     for(; i<=10;i++)
        data.push_back(i);
     Solution msol;
     i = msol.maxProfit(data);
    EXPECT_EQ(9,i);
       return true;

}
bool test2()
{
     vector<int> data;
     data.push_back(1);
     Solution msol;
     int i=0;
     i=msol.maxProfit(data);
     EXPECT_EQ(0,i);

     return true;

}
bool test3()
{
     vector<int> data;
     data.push_back(2);
     data.push_back(1);
     Solution msol;
     int i=0;
     i=msol.maxProfit(data);
     EXPECT_EQ(0,i);

     return true;

}
bool test4()
{
     vector<int> data;
     data.push_back(2);
     data.push_back(4);
     data.push_back(1);
     Solution msol;
     int i=0;
     i=msol.maxProfit(data);
     EXPECT_EQ(2,i);

     return true;

}
bool test5()
{
     vector<int> data;
     data.push_back(7);
     data.push_back(2);
     data.push_back(4);
     data.push_back(1);
     Solution msol;
     int i=0;
     i=msol.maxProfit(data);
     EXPECT_EQ(2,i);

     return true;

}

class Solution {
public:
       
	
		  vector<int> fprofit;
		  vector<int> bprofit;
		  class fprofit;
		  class bprofit;
    int maxProfit(vector<int> &prices) {
           if(prices.size() == 0)
            return 0;
         
           int result =0;
		   fprofit.resize(prices.size());
		   bprofit.resize(prices.size());
           int i=0;
		   cfprofit tempfprofit(prices);
		   for(i=0; i<prices.size(); i++)
		   {
			   tempfprofit(i,fprofit);
		   }
		   cbprofit tempbprofit(prices);
		   for(i=prices.size()-1; i>=0; i--)
		   {
			   tempbprofit(i,bprofit);
		   }
		   for(i=0; i<prices.size(); i++)
		   {
			   if(fprofit[i] + bprofit[i] > result)
			   	 result = fprofit[i] + bprofit[i];
		   }
           return result;
    } 
	class cfprofit
    {
        public:
         vector<int> &prices;
		 int minprice;
         cfprofit(vector<int> &data):prices(data),minprice(0)
         	{}
		 void operator()(int index,vector<int>&fprofit)
		 {
			 if(index == prices.size())
					 return ;
			 if(index == 0)
			 {
				fprofit[0]	= 0;
				minprice = prices[0];
				return;
			 }
			 int profit = fprofit[index-1];
			 if(prices[index] - minprice > profit)
			 profit = prices[index] - minprice;

			 if(prices[index] < minprice)
			 	minprice = prices[index];
			 fprofit[index]= profit;

		 }


	};
	class cbprofit
    {
        public:
         vector<int> &prices;
		 int maxprice;
         cbprofit(vector<int> &data):prices(data),maxprice(0)
         	{}
		 void operator()(int index,vector<int>&bprofit)
		 {
			 
		    if(index == prices.size())
			 return ;
			if(index == prices.size() -1)
		    {
		        bprofit[0]  = 0;
				maxprice    = prices[prices.size() -1];
		    	return;
			}
			int profit = bprofit[index+1];
			if (maxprice - prices[index] > profit)
				profit = maxprice - prices[index];
			if(prices[index] > maxprice)
			   maxprice = prices[index];
			bprofit[index]= profit;
		 }


	};
	
};






