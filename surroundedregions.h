#include <vector>
#include <unordered_set>
#include <set>
#include <stack>
using namespace std;
bool test1()
{
     Solution msol;
	 vector<vector<char>> board(3,vector<char>(3,'X'));

	 board[1][1] = 'O';
     msol.solve(board);
	 	
	 return true;

}
bool test2()
{
     Solution msol;
	 vector<vector<char>> board(3,vector<char>(3,'X'));

	 board[0][1] = 'O';
     msol.solve(board);
     	
	

     return true;

}
bool test3()
{
      Solution msol;
	 vector<vector<char>> board(3,vector<char>(3,'O'));

	
     msol.solve(board);

     return true;

}
bool test4()
{
    
     Solution msol;
	 vector<vector<char>> board(3,vector<char>(3,'X'));
     board[0][1] = 'O';
	 board[1][1] = 'O';
	 board[2][1] = 'O';
     msol.solve(board);

     return true;

}
bool test5()
{
    Solution msol;
    vector<vector<char>> board(4,vector<char>(6,'X'));
    int i=0;
    for(i=0; i<6;i++)
    {
       if(i%2 == 1)
       {
		   board[0][i] = 'O';

	   }
	}
	for(i=0; i<6;i++)
    {
       if(i%2 == 0)
       {
		   board[1][i] = 'O';

	   }
	}
	copy(board[0].begin(),board[0].end(),board[2].begin());
	copy(board[1].begin(),board[1].end(),board[3].begin());
     msol.solve(board);

     return true;

}
bool test6()
{
	 Solution msol;
	string buf[]={"OXXOX","XOOXO","XOXOX","OXOOO","XXOXO"};
	vector<vector<char>> board(5,vector<char>(5,'X'));
	int i=0,j=0;
	for(i=0; i<5;i++)
	   for(j=0;j<5;j++)
	   {
         board[i][j] = buf[i][j];

	   }
	   msol.solve(board);


    return true;
}

class Solution {
public:
     stack<pair<int,int>> data;
    void solve(vector<vector<char>> &board) {
	
       if(board.size() == 0)
	      return ;
	  GetPoint(board);
	  WriteResult(board);
		
        
    }
	void GetPoint(vector<vector<char>> &board)
	{
       int i =0;
	  	 pair<int,int> temp;
	  	 for (i=0; i<board[0].size();i++)
	  	 {
    	       temp.first  = 0;
    	  	   temp.second = i;
    	  	   ExtendPoint(board,temp);
    	  
    	  	   temp.first  = board.size()-1;
    	  	   temp.second = i;
    	  	   ExtendPoint(board,temp);
	  
	  	 }
	  
	  	 for (i=0; i<board.size();i++)
	  	 {
		       temp.first  = i;
		  	   temp.second = 0;
		  	   ExtendPoint(board,temp);
		  
		  	   temp.first  = i;
		  	   temp.second = board[0].size()-1;
		  	   ExtendPoint(board,temp);
	  
	  	 }
        while(data.size() !=0)
        {
			temp = data.top();
			data.pop();
			ExtendPoint(board,temp);

		}
		 

	}
	void ExtendPoint(vector<vector<char>> &board,pair<int,int> point)
	{
    	if(point.first < 0 || point.first >= board.size())
		  return ;
		if(point.second <0 || point.second >=  board[0].size())
		 return ;
		int x,y;
		pair<int,int> temp;
		x= point.first;
		y= point.second;
		if(board[x][y] == 'X' || board[x][y] == 'A')
		 return ;
		board[x][y] = 'A';

		temp.first  = x-1;
		temp.second = y;
		data.push(temp);

		temp.first  = x+1;
		temp.second = y;
		data.push(temp);

		temp.first  = x;
		temp.second = y-1;
		data.push(temp);

		temp.first  = x;
		temp.second = y+1;
		data.push(temp);

	

	}
	void WriteResult(vector<vector<char>> &board)
	{
	   int i,j;
	 
		for (i=0; i< board.size(); i++)
		    for(j=0; j< board[i].size();j++)
		    {
		       if(board[i][j] == 'A')
		       {
				   board[i][j] = 'O';

			   }
			   else if(board[i][j] == 'O')
			   {
				    board[i][j] = 'X';
			   }

			}


	}
	
	
	
};












