// Delete N nodes after M nodes of a linked list

class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        //Add code here 
        if(head == nullptr){
            return;
        }
        int ctr = 0; 
        while(head != nullptr and head->next){
            ctr++;
            if(ctr == M){
                // you have to delete here N nodes
                Node* curr = head;
                int loop = N;
                while(loop--){
                    if(curr->next)
                        curr = curr->next;
                }
                head->next = curr->next;
                ctr = 0;
            }
            head = head->next;
        }
    }
};