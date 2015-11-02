#include "stdafx.h"
#include"picture.h"
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
picture::picture()
{
   pdata = NULL;

}
picture::picture(string buf[],int num)
{
  int len =0;
  pdata = NULL;
  for(int i=0; i<num;i++)
  {
  	 len = max(num,(int)buf[i].size());
  }
  init(len,num);
  for(int i=0; i<num;i++)
  {
     int index =0;
	 for(int j=0;j< buf[i].size();j++)
	 {
         index = len*i+j;
		 pdata[index]= buf[i][j];
	 }
      
  }
  

}
picture::~picture()
{
   if(pdata != NULL)
   {
   	 delete []pdata;
   }

}

void picture::init(int width,int height)
{
   

    m_width  = width;
	m_height = height;
	if(pdata != NULL)
    {
    	delete []pdata;
	}
	pdata = new char[width*height];
	memset(pdata,0,width*height);

	

}
picture::picture(picture& pic1)
{
	pdata = NULL;
    init(pic1.m_width,pic1.m_height);
    memcpy(pdata,pic1.pdata,m_width*m_height);
  
}

picture& picture::operator=(picture& pic1)
{
    if(this == &pic1)
	return   *this;
    init(pic1.m_width,pic1.m_height);
	memcpy(pdata,pic1.pdata,m_width*m_height);
    return *this;
}

ostream& operator<<(ostream& cout,picture& pic)
{
  for(int i=0; i<pic.m_height;i++)
  {
      int index =0;
      for(int j=0; j<pic.m_width;j++)
      {
          index = i*pic.m_width + j;
          cout<<pic.pdata[index];
	  }
	  cout<<endl;

  }




  return cout;
}
picture operator|(picture&pic1,picture&pic2)
{
  int width,height;
  picture pic;
  width = pic1.m_width+pic2.m_width;
  height= pic1.m_height+pic2.m_height;

  pic.init(width,height);
  for(int i=0; i<pic.m_height;i++)
  {
     int index =0;
	 index = i*pic.m_width;
	 if(i<pic1.m_height)
     memcpy(&pic.pdata[index],&pic1.pdata[i*pic1.m_width],pic1.m_width);
        
	
	 if(i<pic2.m_height)
	 memcpy(&pic.pdata[index] + pic1.m_width,&pic2.pdata[i*pic2.m_width],pic2.m_width);


  }
  return pic;
}



