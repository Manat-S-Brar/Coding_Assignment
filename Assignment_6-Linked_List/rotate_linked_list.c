/* Rotate linked list
 *
 * Compilation: gcc rotate_linked_list.c
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


struct ListNode* rotateRight(struct ListNode* head, int k){
    
    if(head == NULL || head->next == NULL || k == 0)
    {
        return head;
    }
    
    int size = 1;
    
    struct ListNode *curr = head;
    
    while(curr->next != NULL)
    {
        size++;
        curr = curr->next;
    }
    
    k %= size;
    
    if(k == 0)
    {
        return head;
    }
    
    k = size - k;
    
    curr->next = head; // making list circular
    
    curr = head;
    
    for(int i = 0 ; i < k - 1 ; i++)
    {
        curr = curr->next;
    }
    
    head = curr->next;
    curr->next = NULL;
    
    return head;
    
}