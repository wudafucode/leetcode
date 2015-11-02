#include<string>
#include<vector>
#include<limits>
using namespace std;

class Solution {
public:
	typedef vector<vector<int>> Sdata;
    int minCut(string s) {
       int len = s.length();
	   Sdata buf(len,vector<int>(len));
       dp(s,buf);
       vector<int> result(len);
	   int mindata = numeric_limits<int>::max();
	   if(s.size() == 1)
	   	return 0;
	   
	   result[len-1] = 0;
       for(int i = len-2; i>=0; i--)
	   {
	     
		  if(buf[i][len-1] == 1)
		  {
		    result[i] =0;
			continue;
		  } 
		  mindata = 1+result[i+1];
          for(int j = i + 1; j<=len-1;j++)
          {
              if(buf[i][j] == 1)
              {
                 
                 if(mindata > 1 + result[j+1])
	             {
	                  mindata = 1 + result[j+1];
				 }
	               
			  }
		  }
          result[i] = mindata;
		  
	   }
	   
	   return result[0];
	   
    }
	void dp(const string& s,vector<vector<int>>& buf)
    {
      for(int i=s.length()-1; i>=0;i--)
        for(int j=i; j<s.length();j++)
        {
            if(i == j)
            {
               buf[i][j] =1;
			}
			else
			{
                if(s[i] == s[j])
                {
                   if(i+1 >= j-1 || buf[i+1][j-1] == 1)
                   {
                       buf[i][j] = 1;
				   }
				}

			}

		}
	}
};


bool test1()
{
	Solution msol;
	vector<vector<string>> buf;
	int result;
	string word = "ab";
    result = msol.minCut(word);
	EXPECT_EQ(result,1);

	return true;

}
bool test2()
{
    
	Solution msol;
	vector<vector<string>> buf;
	int result;
	string word = "aab";
    result = msol.minCut(word);
    EXPECT_EQ(result,1);

	return true;
	

}
bool test3()
{
    Solution msol;
	vector<vector<string>> buf;
	int result;
	string word = "aa";
    result = msol.minCut(word);
	EXPECT_EQ(result,0);

 
     return true;

}
bool test4()
{
	 Solution msol;
	vector<vector<string>> buf;
	int result;
	string word = "a";
    result = msol.minCut(word);
	EXPECT_EQ(result,0);

    return true;

}
bool test5()
{
    Solution msol;
	vector<vector<string>> buf;
	int result;
	string word = "abb";
    result = msol.minCut(word);
	EXPECT_EQ(result,1);


  
    return true;

}
bool test6()
{
	Solution msol;
    int count=0;
 
	 	


    return true;
}
bool test7()
{
	Solution msol;
    int count=0;
 
	 	


    return true;
}

