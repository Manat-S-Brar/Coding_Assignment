/* Linked List Cycle
 *
 * Compilation: gcc linked_list_cycle.c
 * Execution: ./a.out
 *
 * Assignment: 6
 * Date: 30/08/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    
    if(head == NULL || head->next == NULL)
    {
        return NULL;
    }
    
    struct ListNode *sptr = head;
    struct ListNode *fptr = head;
    
    int has_cycle = 0;
    
    /*sptr moves 1 step and fptr moves 2 steps
    If fptr and sptr collides at a point that means there is a cycle*/
    while(fptr->next != NULL && fptr->next->next != NULL )
    {
        sptr = sptr->next;
        fptr = fptr->next->next;
        
        if(sptr == fptr)
        {
            has_cycle = 1;
            break;
        }
    }
    
    if(!has_cycle)
    {
        return NULL;
    }
    
    sptr = head;
    
    while(sptr != fptr)
    {
        sptr = sptr->next;
        fptr = fptr->next;
    }
    
    return sptr;
}