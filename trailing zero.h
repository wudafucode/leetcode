class Solution{
public:
    int trailingZeroes(int n) {
       int num= 0;
       while(n>0)
       {
         num += n/5;
		 n=n/5;

	   }
	   return num;
    }
	
	
};
class Solution1 {
public:
    int trailingZeroes(int n) {
       int num= 0;
	   while(n%5 !=0)
	   {
          n--;
		  if(n<=0)
		  return 0;
	   }
       while(n>0)
       {
         num += GetFiveNum(n);
		 n-=5;

	   }
	   return num;
    }
	int GetFiveNum(int n)
    {
      int num = 0;
	  while(n%5 == 0)
	  {
          num++;
	      n=n/5;
	  }
      return num;
	}
	
};