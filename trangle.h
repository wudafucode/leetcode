#include <vector>
#include <limits>
#include <list>
using namespace std;
class Solution {
public:
        vector<int> totalpath;

    int minimumTotal(vector<vector<int> > &triangle) {
         int i=0,j=0;
         totalpath.resize(triangle.size());
         int tempvalue;
         int temp;
         totalpath[0] = triangle[0][0];
         for (i=1; i< triangle.size(); i++)
         {
               tempvalue      = totalpath[0];
               totalpath[0]  += triangle[i][0];
               for (j=1; j< i; j++)
               {
                   if(tempvalue < totalpath[j])
                   {
                        temp          = totalpath[j];
                        totalpath[j] = tempvalue + triangle[i][j];
                        tempvalue   = temp;
                   }
                   else
                  {
                      tempvalue = totalpath[j];
                      totalpath[j] = tempvalue + triangle[i][j];
                  }

               }
               totalpath[j]  = tempvalue  + triangle[i][j];

         }
         temp = totalpath[0];
         for (i=1; i<totalpath.size();i++)
         {
                if(temp > totalpath[i])
                   temp = totalpath[i];
         }
         return temp;
    }

};