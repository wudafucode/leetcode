class Solution {
public:
	enum
    {
       down = 0,
	   up   = 1,
	};
    string convert(string s, int numRows) {
		string result;
        int index = 0;
		int zignum = 0;
		int zigflag = down;

		if(numRows <= 1)
		return s;
		result.resize(s.size());
		for(int i=0; i<numRows;i++)
	    {
	      zignum = 0;
		  zigflag = down;
          for(int j=0; j<s.size();j++)
          {
              if(zignum == i)
              {
                  result[index++] = s[j];
			  }
			 
			  if(zignum == numRows -1)
			  {
                 zigflag= up;
				 zignum--;
			  }
			  else if(zignum == 0)
			  {
                 zigflag= down;
				 zignum++;
			  }
			  else if(zigflag == up)
			  {
                  zignum--;
			  }
			  else
			  {
                  zignum++;
			  }
             
			  
		  }
	    }

		return result;
    }
};