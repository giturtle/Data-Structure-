 ListNode *detectCycle(ListNode *head) {
 
      /*
       //方法一
       if(!head){
            return NULL;
       }
       ListNode*p,*q;
       p = q = head;
       int flag = 0,c = 0;
       while(p && p->next){
            p = p->next->next;
            q = q->next;
            c++;
            if(p == q){
                flag = 1;
                break;
            }
        }
        if(!flag){
            return NULL;
        }
        p = q = head;
        while(c--)
            p = p->next;
        while(p != q){
            p = p->next;
            q = q->next;
        }
        return p; 
    
    */
    
    //方法二
     if (head == NULL) {
	    	return NULL;
	    }

    	struct ListNode *fast = head;
    	struct ListNode *slow = head;

	    while (1) {
	    	fast = fast->next;
	    	if (fast == NULL) {
		    	return NULL;
	    	}
		    fast = fast->next;
		    if (fast == NULL) {
		    	return NULL;
		    }
		    slow = slow->next;
		    if (fast == slow) {
		    	break;
		    }
    	}

	    struct ListNode *n1 = head;
	    struct ListNode *n2 = slow;

	    while (n1 != n2) {
	    	n1 = n1->next;
	    	n2 = n2->next;
    	}

	    return n1;
    }
