#include<string>
#include<vector>

using namespace std;
class Solution {
public:
   vector<string> result;
    vector<string> letterCombinations(string digits) {
	 string buf[] = {
	    "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz",
	    };
	  
      if(digits.empty())
      {
        result.push_back("");
        return result;
	  }
      
      string combin;
	  combin.resize(digits.size());
	  GetCombinations(buf,digits,combin);
	  return result;
    }
    void GetCombinations(string buf[],string digits,string& combin)
    {
      if(digits.empty())
      {
         result.push_back(combin);
         return ;
	  }
	  if(digits[0]<'2'||digits[0]>'9')
	  	return ;
	  int index = digits[0] - '2';
	  int len = digits.size();
	  len = combin.size()-len;
	  for(int i=0;i<buf[index].size(); i++)
	  {
         combin[len]=buf[index][i];
		 GetCombinations(buf,digits.substr(1,-1),combin);
	  }


	}

	
};