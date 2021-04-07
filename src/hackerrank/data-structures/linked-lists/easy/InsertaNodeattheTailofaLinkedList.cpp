

// Complete the insertNodeAtTail function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* p = head;
    SinglyLinkedListNode* tail = new SinglyLinkedListNode(data);
    if (p) {
        while (p->next)
            p = p->next;
        p->next = tail;      
    }
    else {
        head = tail;
    }
    return head;
}

