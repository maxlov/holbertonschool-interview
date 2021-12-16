# #0x14. Heap Extraction
## Removes and returns root node of binary tree

* int heap_extract(heap_t **root)
* root is a double pointer to the root node of the heap
* Returns the value stored in the root node
* The root node is freed and replaced with the last level-order node of the heap
* Once replaced, the heap is rebuilt if necessary
* On failure returns 0
