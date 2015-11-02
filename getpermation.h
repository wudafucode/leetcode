#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	 vector<int> buf;
    string getPermutation(int n, int k) {
       
		 string result;
		 int index = 0;
		 for(index =1; index <=n; index++)
		 {
         	buf.push_back(index);
		 }
		 GetNextPermutation(0,n,k);
		 
		 result.resize(n);
		 for(index =0; index <n ; index++)
		 {
           result[index] = buf[index] + '0';
		 }
		 return result;
		 
        
    }
	bool GetNextPermutation(int index,int n,int k)
    {
      int num =0;
      int i=0;
	  num = GetMultiResult(n-index - 1);
	  if(index == n)
	  	return true;
	  for(i = 0; i< n - index; i++)
	  {
         if(num*(i+1) >= k)
         {
            AdjustOrder(index,index + i);
            return GetNextPermutation(index + 1,n,k-(num*i));
	     }

	  }
	  return false;
	}
	void AdjustOrder(int startindex,int index )
	{
	  int i=0,temp = buf[index];
	  
	  for(i=index - 1; i>= startindex; i--)
	  {
          buf[i+1] = buf[i];
	  }
	  buf[startindex] = temp;

	}
	int GetMultiResult(int n)
    {
         int result = 1;
		 while(n>1)
		 {
            result = result* n;
			n = n-1;
		 }
       return result;
	}
};
class Solution1 {
public:
    string getPermutation(int n, int k) {
         vector<int> buf;
		 string result;
		 int index = 0;
		 for(index =1; index <=n; index++)
		 {
         	buf.push_back(index);
		 }
		 while(k > 1)
		 {
		   if(next_permutation(buf.begin(),buf.end())==false)
		   	return result;
            k--;
		 }
         result.resize(n);
		 for(index =0; index <n ; index++)
		 {
           result[index] = buf[index];
		 }
		 return result;
        
    }
};
bool test1()
{
	Solution msol;
	string result;
    result = msol.getPermutation(3,1);
	cout<<result<<endl;
    EXPECT_EQ("123",result);



	 
	return true;

}
bool test2()
{
    
	Solution msol;
	string result;
  
	result = msol.getPermutation(3,2);
	cout<<result<<endl;
	EXPECT_EQ("132",result);
	return true;
	

}
bool test3()
{
   	Solution msol;


	string result;
    result = msol.getPermutation(3,5);
	cout<<result<<endl;
	
   
     return true;

}