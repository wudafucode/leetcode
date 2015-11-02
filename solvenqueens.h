#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	vector<int> hor;
	vector<int> ver;
	vector<int> rightline;
	vector<int> leftline;
	int len;
	vector<vector<string>> result;   
    vector<vector<string> > solveNQueens(int n) {

		  if(n<=0)
		  return result;
		  vector<string> temp;
		  Init(n,temp);
		  SolveQueens(temp,n);
		  return result;
		
    }
	void Init(int n,vector<string>&temp)
	{
	      len =n;
          hor.resize(n);
		  ver.resize(n);
		  rightline.resize(2*n);
		
		  leftline.resize(2*n);
		
		  string str(n,'.');
		
		  for(int i=0; i<n;i++)
		  temp.push_back(str);


	}

	void SolveQueens(vector<string>& temp,int num)
	{
	   if(num==0)
	   {
	     result.push_back(temp);
	     return ;
	   }
	   int i=0;
	   i = len-num;
       for(int j=0; j<len;j++)
       {
          if(CheckValid(i,j))
          {
             temp[i][j] = 'Q';
 			SetFlag(i,j);
 			SolveQueens(temp,num-1);
 			ClearFlag(i,j);
 			temp[i][j] = '.';
 			
 		 }
 		
 	  }
	}
	void SetFlag(int i,int j)
	{
       hor[i]    = 1;
	   ver[j]    = 1;
	   int index = GetIndex(i,j) ;
	   rightline[index] = 1;
	   leftline[i+j] = 1;
	}
	void ClearFlag(int i,int j)
	{

       hor[i]    = 0;
	   ver[j]    = 0;
	   int index = GetIndex(i,j);
	   rightline[index] = 0;
	   leftline[i+j]    = 0;
	}
	int GetIndex(int i,int j)
	{
	      int index = 0;
	      if(i>=j)
		   {
	          index = i-j;
		   }
		   else
		   {
	          index = j-i+len;
		   }
		 return index;
	}
	bool CheckValid(int i,int j)
	{
      if(hor[i] == 1|| ver[j] == 1)
	  return false;
	  int index = GetIndex(i,j);
	  if(rightline[index] == 1|| leftline[i+j] == 1)
	  return false;

      return true;
	}
};