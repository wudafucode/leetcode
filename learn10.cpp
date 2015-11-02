// learn10.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <unordered_set>
#include <limits>
#include <iterator>
#include <set>
#include "picture.h"
//#include "singlenum.h"
#include  "uniquebinary.h"
using namespace std;
#define  EXPECT_EQ(data0,data1)   do\
{\
    if(data0 != data1)\
       return false;\
}while(0);
bool test1()
{
    Solution temprsult;
	int temp = temprsult.numTrees(3);


	return true;

}
bool test2()
{
    
	

	


	return true;
	

}
bool test3()
{
    int buf[] = {2,2,};
	vector<int> nums;
	nums.resize(2);
	copy(buf,buf + 2,nums.begin());



	Solution msol;
	int result = 0;

	

 
     return true;

}
bool test4()
{
	 Solution msol;
	

    return true;

}
bool test5()
{
    Solution msol;
	


  
    return true;

}
bool test6()
{
	Solution msol;
    int count=0;
 
	 	


    return true;
}
bool test7()
{
	Solution msol;
    int count=0;
 
	 	


    return true;
}



class  AutoTest
{
 public:

   vector<bool (*)(void)> buf;
   void add()
   {

        buf.push_back(test1);
        buf.push_back(test2);
        buf.push_back(test3);
        buf.push_back(test4);
        buf.push_back(test5);
		buf.push_back(test6);
		buf.push_back(test7);


   }
   void run()
   {
     vector<bool (*)(void)>::iterator ite ;
     bool ret ;
     int num=1;
     for(ite = buf.begin(); ite != buf.end(); ite++)
     {
            ret =  (*ite)();
            if(ret == false)
            {
             cout<<num<<":test fail"<<endl;
             system("pause");
            }
            else
           {
             cout<<num<<":test success"<<endl;
           }
            num++;
     }

   }



};






void fun()
{
   shared_ptr<string> sp (new string("code"));
   cout<<*sp<<endl;
   weak_ptr<string> wp = sp;
   cout<<wp.use_count()<<endl;
   cout<<wp.lock()->c_str()<<endl;

   shared_ptr<string> tempsp(wp);
   cout<<wp.use_count()<<endl;
   cout<<*tempsp<<endl;



}

class tclass
{
public:
 tclass():data("")
{
   string temp ="";
   data = temp;

}

string data;
};
void test()
{
	string buf[]= {"paris","in the","spring"};
	string buf2[]={"hello world"};
	picture pic(buf,3);

	picture pic2(buf2,1);
	pic2 = pic | pic2;

	cout<<pic2;



	system("pause");




}
int _tmain(int argc, _TCHAR* argv[])
{
	  // test();
      AutoTest temptest;
      temptest.add();
      temptest.run();
	 system("pause");
       return 0;
}

