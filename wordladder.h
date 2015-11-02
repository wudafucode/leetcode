#include<unordered_set>
#include<stack>
#include<queue>
using namespace std;

class Solution {
public:
	unordered_set<string> data;
	queue<pair<string,int>> result;

    int ladderLength(string start, string end, unordered_set<string> &dict) {

	  pair<string,int> temp;
      temp.second = 1;
	  temp.first  = start;

      InitData(end);
      if(CheckResult(start,end) == true)
	  	return 2;
      GetData(temp,dict);
	  if(result.size() == 0)
	  	return 0;
	
      while(result.size() !=0)
      {
         temp = result.front();
		 if(CheckResult(temp.first, end)== true)
		 {
            return temp.second+1;
		 }
		 result.pop();
		 GetData(temp,dict);
		 	 
	  }


     return 0;
		
        
    }
	void InitData(string end)
	{
         int i=0,j=0;
		string temp;
		
	
        for(i = 0; i < end.size(); i++)
        {
           temp = end;
           for(j=0; j< 26;j++)
           {
             
			 if(end[i] != 'a'+j)
			 {
                temp[i] = 'a'+j;
			    data.insert(temp);
			 }
			
	

		   }

		}
	


	}
	bool GetData(pair<string,int> &start,unordered_set<string> &dict)
	{
	    int i=0,j=0;
		string temp;
		pair<string,int> pattern;
	
        for(i = 0; i < start.first.size(); i++)
        {
           temp = start.first;
           for(j=0; j< 26;j++)
           {
             temp[i] = 'a'+j;
			 if(dict.find(temp) != dict.end())
			 {
			    pattern.first   = temp;
				pattern.second  = start.second + 1;
                result.push(pattern);
				dict.erase(temp);
			 }

		   }

		}
		return true;
        
	}
	
   bool CheckResult(string &temp, string &end)
   {
      if(data.find(temp) != data.end())
	   return true;
	  else
	  	return false;
   }
};