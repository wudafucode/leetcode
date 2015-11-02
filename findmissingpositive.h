#include <vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {

         if(n==0)
            return 1;
         int i=0;
         for(i=0; i<n;i++)
         {
             if(A[i]>0)
                FindandReplace(A ,  n, A[i]);
         }
         int expect;
         if(A[0]==0)
             expect=0;
         else
             expect=1;
         for(i=0; i<n;i++)
         {
            if(A[i]<0 || A[i] != expect)
                return expect;

                expect++;
         }

         return expect;

    }
    void FindandReplace(int A[], int n,int index)
    {
           int tempdata;
           if(index-1 < n)
            {
                tempdata = A[index-1];
                A[index-1] = index;
               if(tempdata == index)
                  return ;
                if(tempdata> 0)
                 FindandReplace(A,n,tempdata);

            }

    }
};
bool  test1(void)
 {
      int buf[] ={2};
      Solution  msol;
      int result ;
      result = msol.firstMissingPositive(buf,sizeof(buf)/sizeof(int));
      EXPECT_EQ(result, 1);
 }
bool  test2(void)
 {
      int buf[] ={2,1};
      Solution  msol;
      int result ;
      result = msol.firstMissingPositive(buf,sizeof(buf)/sizeof(int));
      EXPECT_EQ(result, 3);
 }
bool  test3(void)
 {
      int buf[] ={1};
      Solution  msol;
      int result ;
      result = msol.firstMissingPositive(buf,sizeof(buf)/sizeof(int));
      EXPECT_EQ(result, 2);
 }
bool  test4(void)
 {
      int buf[] ={-1,1};
      Solution  msol;
      int result ;
      result = msol.firstMissingPositive(buf,sizeof(buf)/sizeof(int));
      EXPECT_EQ(result, 2);
 }