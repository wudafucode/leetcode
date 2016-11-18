
typedef struct node
{
int data;
node *next;
}node;
node* reverse(node* head)
{
 node*phead,*pmid,*pnext;
 if(head == NULL)
 return head;
 if(head->next == NULL)
 return head;

 phead = head;pmid= head->next;head->next = NULL;pnext= pmid->next;
 while(pnext!=NULL)
 {
  pmid->next = phead;
  phead = pmid;
  pmid = pnext;
  pnext= pmid->next;
 
 }
 pmid->next = phead;
 return pmid;

}
class Solution {
public:
    int bulbSwitch(int n) {
          return (int)(n >0)?(sqrt((float)n)):(0);
		
        
    }
};

