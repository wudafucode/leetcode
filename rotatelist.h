
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
typedef ListNode * SNode;
class Solution {
public:
	typedef ListNode * SNode;
    ListNode *rotateRight(ListNode *head, int k) {
		SNode pcurrent , pnext,ptemp;
		if(k<=0 || head == NULL || head->next == NULL)
		return head;
		pnext    = head;
		pcurrent = head; 
		int count = 0;
		while(count <k)
		{
           
		   if(pnext->next != NULL)
		   {
			  pnext = pnext->next;
		   }
		   else
		   {
              pnext = head;
		   }
		   count++;
		}
		if(pcurrent == pnext)
		return head;
        while(pnext->next != NULL)
        {
            pcurrent = pcurrent->next;
			pnext    = pnext->next;

		}
		ptemp = pcurrent->next;
		pcurrent->next = NULL;
		pcurrent = ptemp;
		pnext->next = head;
		return pcurrent;
        
    }
};
bool test1()
{
     Solution msol;
     ListNode  buf[5] = {1,2,3,4,5};
	 for(int i=0; i<4;i++)
	 {
        buf[i].next = &buf[i+1];
	 }
	  SNode ptemp;
	 ptemp = msol.rotateRight(&buf[0],2);
	 int  result[5] = {4,5,1,2,3};
	 int i=0;
	 while(ptemp != NULL)
	 {
	   EXPECT_EQ(result[i++],ptemp->val);		
	   ptemp = ptemp->next;

	 }
	 	
	 return true;

}
bool test2()
{
     Solution msol;
     ListNode  buf[2] = {1,2};
	 SNode ptemp;
	 buf[0].next = &buf[1];
	 ptemp = msol.rotateRight(&buf[0],1);
	
     int  result[5] = {2,1};
	 int i=0;
	 while(ptemp != NULL)
	 {
	   EXPECT_EQ(result[i++],ptemp->val);		
	   ptemp = ptemp->next;

	 }		
	

     return true;

}
bool test3()
{
     Solution msol;
     ListNode  buf[1] = {1};
	 SNode ptemp;
	 ptemp = msol.rotateRight(&buf[0],1);
	
     EXPECT_EQ(1,ptemp->val);	

     return true;

}















