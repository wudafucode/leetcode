#include <vector>
#include <queue>
#include  <string>
using namespace std;


class Solution {
public:
	
	string result;
	int maxpoint;
	int maxlen;
	vector<int> buf;
    string longestPalindrome(string s) {
         if(s.empty())
		  return s;
         string temp;
		 temp = Init(s);
		 buf.resize(temp.size());
		 maxpoint = 0;
		 maxlen =0;
		 int len =0;
		 for(int i=0; i<temp.size(); i++)
		 {

			len = Getlen(temp,i);
            buf[i] = len;
		    if(len >= maxlen)
		    {
               maxlen   = len;
			   maxpoint = i;
			   
			}
		 }
		 for(int i = maxpoint - (maxlen - 1); i<= maxpoint + maxlen -1; i++)
		 {
             if(temp[i] == '#')
			 	continue;
			 result.push_back(temp[i]);
		 }
		 return result;
           
        
    }
	int Getlen(string& pattern,int mid)
	{
	    int left=0, right =0;
		int index =1;
		if(maxpoint + maxlen > mid)
		{
            if(buf[2*maxpoint - mid] + mid - maxpoint > maxlen)
            {
                index = maxlen - (mid - maxpoint);
			}
			else
			{
                index = buf[2*maxpoint - mid];
			}
		}
		while(1)
		{
          if(mid - index<0)
		  	break;
		  if(mid + index>= pattern.size())
		  	break;
		  if(pattern[mid-index] != pattern[mid + index])
		  	break;
		  index++;
		}
		return index;
	}
	string Init(string& s)
    {
        string temp;
		bool flag = false;
        temp.push_back('#');
		for(int i=0; i<s.size(); )
		{
		    if(flag == false)
		    {
				temp.push_back(s[i]);
                flag = true;
				i++;
			}
			else
			{
               temp.push_back('#');
               flag = false;
			}
		}
        if(flag == true)
        {
			temp.push_back('#');
		}

		return temp;
	}
    
  
};
bool test1()
{
	Solution msol;

	string result;
	result = msol.longestPalindrome("abc");


	 
	return true;

}
bool test2()
{
    
	Solution msol;

	string result;
	result = msol.longestPalindrome("abbac");

	EXPECT_EQ("abba",result);



     return true;

}
bool test3()
{
   	Solution msol;

	string result;
	result = msol.longestPalindrome("abcbe");
	
    EXPECT_EQ("bcb",result);
	
   
     return true;

}
bool test4()
{
	Solution msol;

	string result;
	result = msol.longestPalindrome("aaabaaaa");
	EXPECT_EQ("aaabaaa",result);
    return true;

}
bool test5()
{
    Solution msol;

	string result;
	result = msol.longestPalindrome("aaaaaaaaaaaaa");
	EXPECT_EQ("aaaaaaaaaaaaa",result);

  
    return true;

}


