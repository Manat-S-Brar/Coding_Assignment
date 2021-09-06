/* Remove nth node from end
 *
 * Compilation: gcc remove_nth_node.c
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


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    
    if(head->next == NULL)
    {
        head = NULL;
        return head;
    }
    
    struct ListNode *temp = head;
    int size = 0;
    
    //Calculating size of linked list
    while(temp != NULL)
    {
        size++;
        temp = temp->next;
    }
    
    //If n == size that means we have to remove the first node
    if(n == size)
    {
        head = head->next;
        return head;
    }
    
    temp = head;
    
    for(int i = 0 ; i < (size - n - 1) ; i++)
    {
        temp = temp->next;
    }
    
    //Removing nth node
    temp->next = temp->next->next;
    
    return head;
}