class Solution {
public:
    int search(int A[], int n, int target) {

        if(n == 0)
		return 0;
        int middle,end,start;
        start = 0;
		end = n-1;
		middle = (start + end)/2;
		int result;
		while(start <= end)
		{
		   
           if(A[middle] < A[end])
           {
               result = findbinarysearch(A,middle,end,target);
			   if(result !=-1)
			   	return result;
			   end = middle -1;
			   middle = (start+ end)/2;
		   }
           else if(A[middle] > A[end])
           {
               result = findbinarysearch(A,start,middle,target);
			   if(result !=-1)
			   	return result;
			   start  = middle +1 ;
			   middle = (start+ end)/2;

		   }
		   else
		   {
		     if(A[middle] == target)
              return middle;
			 else
			   return -1;
		   }

		}
		return -1;
        
    }
	int findbinarysearch(int A[],int start, int end, int target)
	{
      int middle = (start + end)/2;
	  
	  while(start <= end)
	  {
         if(A[middle] < target)
         {
            start = middle +1;
		    middle = (start + end)/2;
		 }
		 else if(A[middle] > target)
		 {
            end    = middle -1;
		    middle = (start + end)/2;
		 }
		 else
		 {
             return middle;
		 }
		 	

	  }


      return -1;
	}
};