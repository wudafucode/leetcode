struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         ListNode* tempA = headA;ListNode* tempB = headB;
         int countA=0,countB=0;
		 
		 if(headA == NULL || headB == NULL)
		   return NULL;
		 while(tempA->next != NULL)
		 {
		     countA++;
			 tempA = tempA->next;
		 }
		 while(tempB->next != NULL)
		 {
		     countB++;
			 tempB = tempB->next;
		 }
		 if(tempA != tempB)
		 	return NULL;
		 if(countA > countB)
		 {
		 
		   	int count = countA- countB;
			while(count>0)
		    {
              headA = headA->next;
			  count--;
		    }

		 }
		 
		 else
		 {
            int count = countB - countA;
			while(count>0)
		    {
              headB = headB->next;
			  count--;
		    }

		 }
		 while(headA != headB)
		 {
              headA = headA->next;
			  headB = headB->next;
		 }
		 return headA;
		  
        
    }
   
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
          ListNode * endA;
		  if(headA == NULL || headB == NULL)
		  return NULL;
		  endA = headA;
		  while(endA->next != NULL)
          {
            endA = endA->next;
	      }
		  endA->next = headA;

		  ListNode * pmeetpoint = headB;
		 // ListNode * pslow = headB;
		  headA = headB;
		  while(1)
		  {
		
			  if(pmeetpoint->next ==NULL)
			  	return NULL;
			  pmeetpoint = pmeetpoint->next;
			  if(pmeetpoint->next ==NULL)
			  	return NULL;
			  pmeetpoint = pmeetpoint->next;
			  headA = headA->next;

			  if(headA == pmeetpoint)
			  {
	            break;
			  }
			  
		  }
		
		while(headB != pmeetpoint)
        {
             headB = headB->next;
		     pmeetpoint = pmeetpoint->next;
	    }
   
		endA->next = NULL;
		return pmeetpoint;
		  
        
    }
 
};














