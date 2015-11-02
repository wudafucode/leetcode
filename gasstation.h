#include <vector>
using namespace std;
class Solution {
public:
	vector<int> leftgas;
	int len;
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        len = gas.size();
		int i=0;
		leftgas.resize(gas.size());
		for (i=0; i<len; i++)
	    {
         	leftgas[i] = gas[i] - cost[i];
		}
		pair<bool,int> temp;
        temp = IndexComplete();
        if(temp.first == true)
		 return temp.second;


		return -1;
    }
	pair<bool,int> IndexComplete()
	{
	  int allgas = 0;
	  int backwardindex = 0;
	  int forwardindex = 0;
	  bool ret;
      while(1)
      {
        allgas +=leftgas[forwardindex++];
		
		if(allgas >= 0)
		{
		 
		   if(forwardindex  == backwardindex || forwardindex  == len)
		   	return pair<bool,int>(true,backwardindex);
		}
		else
		{
            ret = SupplyGas(allgas,backwardindex,forwardindex);
			if(ret == false)
			return pair<bool,int>(false,backwardindex);

		}
		
	  }

	}
	bool  SupplyGas(int &allgas,int& backwardindex,int forwardindex )
	 {
	  	
        while(1)
        {
          if(backwardindex == 0)
          {
             backwardindex = len-1;
		  }
		  else
		  {
             backwardindex--;
		  }
		  
          allgas += leftgas[backwardindex];
		  if(allgas >= 0)
		  {
             return true;
		  }
		  else
		  {
            if(backwardindex <= forwardindex)
			  return false;

		  }
		 
		 
		}

	 }
};
bool test1()
{
   Solution msol;
   vector<int> gas, cost;
   gas.push_back(4);
   cost.push_back(5);
   string result ;
   int ret;
   ret = msol.canCompleteCircuit(gas,cost);
   EXPECT_EQ(ret ,-1);

	return true;

}
bool test2()
{
     
  Solution msol;
   vector<int> gas, cost;
   gas.push_back(6);
   cost.push_back(5);
   string result ;
   int ret;
   ret = msol.canCompleteCircuit(gas,cost);
   EXPECT_EQ(ret ,0);


     return true;

}