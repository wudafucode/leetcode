#include <string>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
      string   pattern ;
	  string   word;
    int minDistance(string word1, string word2) {
       vector<vector<int>> buf(word2.size()+1);
	   int step = 0 ,i = 0, j = 0;
	   pattern = word1;
	   word    = word2;
       if(word1.size() ==0)
	   	return word2.size();
	   if(word2.size() ==0)
	   	return word1.size();
	   
	   for(i=0; i<word2.size()+1; i++)
	   {
          buf[i].resize(word1.size()+1);
	   }
	   for(i=0; i<word2.size()+1; i++)
	   {
        	buf[i][0] = i;
	   }
	   for(i=0; i<word1.size()+1; i++)
	   {
        	buf[0][i] = i;
	   }
      for(i=1; i<=word2.size(); i++)
	  	for(j=1; j<= word1.size(); j++)
	  	{
        	step = GetMin(i,j,buf);
			buf[i][j] = step;
		}
		return buf[i-1][j-1];
    }
   int GetMin(int i,int j,vector<vector<int>>& buf)
   {
      int step = 0;
	  if(i == 0)
		return j;
	  if(j == 0)
		return i;
	  if(word[i-1] == pattern[j-1])
	  	return GetMin(i-1,j-1,buf);
	  step = min(buf[i-1][j],buf[i][j-1]);
	  step = min(step,buf[i-1][j-1]);
	  step +=1;

	  return step;
   }
};
bool test1()
{
	Solution msol;
	string result;
	string word1 = "ab";
	string word2 = "cd";
	int step =0;
    step = msol.minDistance(word1,word2);
	EXPECT_EQ(2,step);



	 
	return true;

}
bool test2()
{
    
	Solution msol;
	string result;
	string word1 = "sea";
	string word2 = "ate";
	int step =0;
    step = msol.minDistance(word1,word2);
	cout<<step<<endl;
  
	
	return true;
	

}
bool test3()
{
    
	Solution msol;
	string result;
	string word1 = "horse";
	string word2 = "ros";
	int step =0;
    step = msol.minDistance(word1,word2);
	cout<<step<<endl;
  
	
	return true;
    
	
   
     return true;

}

