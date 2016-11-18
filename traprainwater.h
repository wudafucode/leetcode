class Solution {
public:
    int trap(vector<int>& height) {
	   if(height.size() <=2)
	   return 0;
       return RWater(height,0,height.size()-1);
   
    }
	int RWater(vector<int>&height,int left,int right)
    {
       int index  = 0;
	   int result = 0;
	   index =  findHigh(height,left,right);
	   if(index == 0)
	   {
          return calcwater(height,left,right);
	   }
	   else
	   {
            result = RWater(height,left,index);
			result += RWater(height,index,right);
			return result;
	   }
	}
	int calcwater(vector<int>&height,int left, int right)
	{

      int totalmansion = 0;
	  int minheight =0;
	  if(left+1 == right)
	  return 0;
	  minheight = (height[left] > height[right])?(height[right]):(height[left]);
	  totalmansion = minheight*(right - left -1);
	  int tmansion = 0;
	  for(int i=left+1; i<right; i++)
	  {
		  	tmansion +=height[i];
	  }
      return totalmansion - tmansion;
	}
	int findHigh(vector<int>&height,int left, int right)
	{
	    int maxindex = 0;
		int maxheight = 0;
		for(int i = left + 1 ; i<height.size()&&i<right; i++)
		{
        	if(height[i] > maxheight)
        	{
                maxindex  = i;
				maxheight = height[i];
			}
		}
		if(maxheight >= height[left] || maxheight >= height[right])
		return maxindex;
		else
		return 0;

	}
};