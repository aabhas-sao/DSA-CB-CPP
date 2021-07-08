p = revedHead;
    while(temp != NULL) {
        temp = temp->next;
    }
    temp->next = head;
    head->next