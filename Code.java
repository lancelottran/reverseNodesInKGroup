// Definition for singly-linked list:
// class ListNode<T> {
//   ListNode(T x) {
//     value = x;
//   }
//   T value;
//   ListNode<T> next;
// }
//
ListNode<Integer> reverseNodesInKGroups(ListNode<Integer> l, int k) {  
    
    return reverse(l,k);
}

ListNode reverse(ListNode<Integer> l, int counter)
{
    ListNode<Integer> curr = l, next = null, prev = null;
    int count = counter;
    ListNode<Integer> pointer = null;

    while(count > 0 && curr != null)
    {
        next = curr.next;
        curr.next = prev;
        prev = curr;
        curr = next;
        
        count--;
    }
    
    if(next != null)
    {
        pointer = next;
        while(pointer != null && count != counter)
        {
            pointer = pointer.next;
            count++;
        }
        
        if(count == counter)
        {
            l.next = reverse(next, counter);
        }
        else
            l.next = reverse(next, 1);
    }
    
    return prev;
}
