
#include <stack>

class Solution {
public:
    string simplifyPath(string path) {
		   string slicepath;
           stack<string> pathstack;
		   int index = 1;
           while(1)
           {
           		slicepath = GetSlice(path,index);
               
				
				if(slicepath == "..")
				{
                	if(pathstack.size() != 0)
						pathstack.pop();
				}
				else if(slicepath == "." || slicepath.size() == 0)
				{

				}
				else 
				{
			    	pathstack.push(slicepath);
				}
			   if(index >= path.size())
					break;
		   }
           return getresult(pathstack);
    }
	string getresult(stack<string> pathstack)
	{
	   string result;
	   string tmpstr;

	   if(pathstack.empty())
	   {
           return "/";
	   }
	  
	   while(!pathstack.empty())
	   {
	        tmpstr = pathstack.top();
	
            result = "/" + tmpstr + result;
       		pathstack.pop();
	   }
	  
	   return result;
	}
	string GetSlice(string& path, int& index)
	{
	    string slicepath;
		if(index >= path.size())
		return slicepath;
        int i = index;
		for(; path[i] != '/';)
	    {
	        	i++;
        	if(i >=path.size())
				break;
		}
		
        slicepath = path.substr(index,i-index);
		index = i+1;
		return slicepath;
	}
	
};

