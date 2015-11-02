
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
         stack<int> mstack;
		 char cbefore;
         int count = 0;
		 if(s.empty())
		  return 0;
		 
		 for(int i=0; i<s.size(); i++)
		 {
            
		     bool ret;
			
			 CountTotal(mstack,count);
			 if(mstack.empty())
			 {
			    if(count!=0)
			    {
					mstack.push(count);
					mstack.push('a');
					count =0;

				}
			    
				mstack.push(s[i]);
				
				continue;
			 }
           
             ret = CheckValidParentheses(mstack.top(),s[i]);
			 if(ret == false)
			 {  
				if(count!=0)
			    {
					mstack.push(count);
					mstack.push('a');
					count =0;

				}
                  mstack.push(s[i]);	  
			 }
			 else
			 {
			     mstack.pop();
			     count++;
				 mstack.push(count);
				 mstack.push('a');
				 count =0;
				 
			

			 }
			 
		 }
	    CountTotal(mstack,count);
	  int maxcount = count;
	  count =0;
	  while(!mstack.empty())
	  {
          if(mstack.top() != 'a')
		  {
             mstack.pop();
			 if(count > maxcount)
			 	maxcount = count;
			 count =0;
			 continue;

		  };
		  
		  mstack.pop();
		  count+=mstack.top();
		  mstack.pop();
	  }
      if(count > maxcount)
		maxcount = count;
	   return maxcount*2;
		     
    }
	bool CheckValidParentheses(char a,char b)
	{
        if(a == '(' && b == ')')
		 return true;
		return false;

	}
	void CountTotal(stack<int>& mstack,int& count)
	{
	  
		while(1)
		{    
		  if(mstack.empty())
		  	return;
		  if(mstack.top() != 'a')
		  	return;
		  
		  mstack.pop();
		  count+=mstack.top();
		  mstack.pop();
		}

	}
};







