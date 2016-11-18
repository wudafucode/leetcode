class Solution {
public:
    int row;
	int col;
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        if(matrix.size() == 0)
		return 0;
		row = matrix.size();col = matrix[0].size();
		vector<vector<int>> dataup(row,vector<int>(col));
	
        vector<vector<int>> datadown(row,vector<int>(col));
	    for(int i= 0; i<row; i++)
			for(int j=0; j<col;j++)
			{
               GetUpPath(i,j,dataup,matrix);
			   GetDownPath(i,j,datadown,matrix);
			}
		int maxstep = 0;
		for(int i= 0; i<row; i++)
			for(int j=0; j<col;j++)
			{
                maxstep = max(maxstep,dataup[i][j] + datadown[i][j]);
			}
	 return maxstep-1;
        
    }
	int GetUpPath(int i, int j,vector<vector<int>>& dataup,vector<vector<int>>& matrix)
	{
	   int upstep  = 0,downstep = 0,rightstep= 0 ,leftstep = 0,maxstep = 0;
       if(i<0 ||j <0)
	   	return 0;
	   if(i>= row || j >= col)
	   	return 0;
	   if(dataup[i][j] != 0)
	   	return dataup[i][j];
 
	   if(i>=1)
	   {
       	  if(matrix[i][j] < matrix[i-1][j])
		  	upstep=1+GetUpPath(i-1,j,dataup,matrix);
	   }
	   if(i <row-1)
	   {
          if(matrix[i][j] < matrix[i+1][j])
		  	downstep = 1+GetUpPath(i+1,j,dataup,matrix);
	   }
	   if(j>=1)
	   {
          if(matrix[i][j] < matrix[i][j-1])
          {
             leftstep = 1+ GetUpPath(i,j-1,dataup,matrix);
		  }
	   }
	   if(j < col-1)
	   {
          if(matrix[i][j] < matrix[i][j+1])
          {
             rightstep = 1+ GetUpPath(i,j+1,dataup,matrix);
		  }
	   }
       maxstep = max(upstep,downstep);
	   maxstep = max(maxstep,max(leftstep,rightstep));
	   if(maxstep == 0)
	   	 maxstep = 1;
	   dataup[i][j] = maxstep;
	   return maxstep;
	}
	int GetDownPath(int i, int j,vector<vector<int>>& datadown,vector<vector<int>>& matrix)
	{
	   int upstep  = 0,downstep = 0,rightstep= 0 ,leftstep = 0,maxstep = 0;
       if(i<0 ||j <0)
	   	return 0;
	   if(i>= row || j >= col)
	   	return 0;
	   if(datadown[i][j] != 0)
	   	return datadown[i][j];
  
	   if(i>=1)
	   {
       	  if(matrix[i][j] > matrix[i-1][j])
		  	upstep=1+GetDownPath(i-1,j,datadown,matrix);
	   }
	   if(i <row-1)
	   {
          if(matrix[i][j] > matrix[i+1][j])
		  	downstep = 1+ GetDownPath(i+1,j,datadown,matrix);
	   }
	   if(j>=1)
	   {
          if(matrix[i][j] > matrix[i][j-1])
          {
             leftstep = 1+ GetDownPath(i,j-1,datadown,matrix);
		  }
	   }
	   if(j < col-1)
	   {
          if(matrix[i][j] > matrix[i][j+1])
          {
             rightstep = 1+ GetDownPath(i,j+1,datadown,matrix);
		  }
	   }
       maxstep = max(upstep,downstep);
	   maxstep = max(maxstep,max(leftstep,rightstep));
	   if(maxstep == 0)
	   	 maxstep = 1;
	   datadown[i][j] = maxstep;
	   return maxstep;
	}
};