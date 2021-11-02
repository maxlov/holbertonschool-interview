#0x0E. Linear search in skip list
Looking for a specific value in a singly linked list always leads to browse every element of the list. A common way to optimize the time complexity of a search in a singly linked list is to modify the list itself by adding an “express lane” to browse it. A linked list with an express lane is called a skip list.

In this project I write a function that searches for a value using a skip list.

skiplist_t *linear_skip(skiplist_t *list, int value)
Where list is a pointer to the head of the skip list to search in
And value is the value to search for
