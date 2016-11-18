
#include<map>
#include<vector>

class Solution {
public:
	vector<int> flag;
	enum
	{
	  idle_state  = 0,
	  false_state = 1,
	  true_state  = 2,
	};
	map<int,int> stonemap;
	map<int,set<int>> calresult;
    bool canCross(vector<int>& stones) {
		
         flag.resize(stones.size());
		 if(stones.size() == 0)
		 	return true;
		 
	    if(stones[1] != 1)
			return false;
		initmap(stones);
         
		if(true_state == depthfirst(stones,1,1))
			return true;

		return false;
        
    }
	void initmap(vector<int>& stones)
	{
	    set<int> tmp;
        for(int i=0; i<stones.size(); i++)
        {
        	stonemap[stones[i]] = i;
		}
		for(int i=0; i<stones.size(); i++)
		{
            calresult[i] = tmp;
		}
		
	}
	int depthfirst(vector<int>& stones,int laststep,int stoneindex)
	{
	    int steplength  = 0;
		int totallength = 0;
        int stepflag = 0;
		map<int,int>::iterator ite;
        map<int,set<int>>::iterator  itecal;
		
		if(stoneindex == stones.size() -1)
			return true_state;
		if(laststep == 0)
			return false_state;
		
		itecal = calresult.find(stoneindex);

		if(itecal->second.find(laststep) != itecal->second.end())
			return false_state;
			
	    totallength = stones[stoneindex] + laststep-1;
			
		ite = stonemap.find(totallength);
		if(ite != stonemap.end())
		{
			stepflag = depthfirst(stones,laststep - 1,ite->second);
			if(stepflag == true_state)
				return true_state;
		}

		totallength = stones[stoneindex] + laststep;
		
		ite = stonemap.find(totallength);
        if(ite != stonemap.end())
        {
            stepflag = depthfirst(stones,laststep,ite->second);
			if(stepflag == true_state)
				return true_state;
		}

		
		totallength = stones[stoneindex] + laststep + 1;
				
		ite = stonemap.find(totallength);
		if(ite != stonemap.end())
		{
			stepflag = depthfirst(stones,laststep + 1,ite->second);
			if(stepflag == true_state)
				return true_state;
		}
		
		itecal->second.insert(laststep);
		return false_state;

	}
};






