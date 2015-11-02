
class Solution {
public:
    double pow(double x, int n) {
           double result =1;
		   int    index = abs(n);
			   
		  for(int i=0; i<32;i++)
		  {
				  if(0x01<<i & index)
				  {
					 result *=ppow(x,i);
				  }
		  }
		  if(n <0)
		  	result = 1/result;
		   
		   
           return result;

		
        
     }
     double ppow(double x,int n)
     {
	    double result =x;
		while(n > 0)
		{
			n =n-1;
			result = result * result;

		}
        return result;
     }
    
};






