//
// Definition for singly-linked list:
// typedef struct list_##name {
//   type value;
//   struct list_##name *next;
// } list_##name;
//
// list_##name *alloc_list_##name(type v) {
//   list_##name *l = calloc(1, sizeof(list_##name));
//   l->value = v;
//   return l;
// }
//
list_integer * reverseNodesInKGroups(list_integer * l, int k) {
    list_integer *next;
    list_integer *prev = NULL;
    list_integer *curr = l;
    list_integer *tmp;
    int counter = 0;
    
    while(counter != k && curr != NULL){
        ++counter;
        
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    if(next != NULL){
        tmp = next;
        counter = 0;
        
        while(counter != k && tmp != NULL){
            tmp = tmp->next;
            counter++;
            //printf(" %d %d ", counter, k);
        }
        
        if(counter == k)
            l->next = reverseNodesInKGroups(next, k);
        else
            l->next = reverseNodesInKGroups(next, 1);
    }
    
    return prev;
}
