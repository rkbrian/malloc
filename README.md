# 0x00. C - malloc
Project to implement malloc and related functions in C.

## General
 - What is a program break
 - How to play with a program break in order to allocate memory dynamically
 - How the glibc malloc and free functions work
 - What is ASLR
 - What is memory alignment
 - What is a memory page
 - How to encapsulate the memory management in order to hide it from the user

### 0. Naive malloc
Build the naive malloc that is presented in the concept page (can not be linkd here).
 - Prototype: void *naive_malloc(size_t size);
 - Where size is the size needed to be allocated for the user
 - Your function must return a pointer to the allocated memory that is suitably aligned for any kind of variable
 - You naive malloc should be able to:
 - - Allocate enough memory to store
 - - - A size_t as the chunk header
 - - - The size requested as parameter
 - - Allocate memory pages only

### 1. malloc
Write you own malloc function that allocates space in the heap
 - Prototype: void *_malloc(size_t size);
 - Where size is the size needed to be allocated for the user
 - Your function must return a pointer to the allocated memory that is suitably aligned for any kind of variable

### 2. free
Write you own free function that frees a memory space
 - Prototype: void _free(void *ptr);
 - Where ptr is a pointer to the memory space to be freed
