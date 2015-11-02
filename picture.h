
#include<string>

using namespace std;
class picture
{
 public:
	   picture();
 	   picture(string buf[],int num);
	   picture& operator=(picture&); 
	   picture(picture&);
	   void init(int width,int height);
       ~picture();
	  
	   char *pdata;
	   int m_width;
	   int m_height;


};
 ostream& operator<<(ostream& cout,picture& pic);
 picture operator|(picture&,picture&);

