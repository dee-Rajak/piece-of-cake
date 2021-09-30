# Memory Allocation in C
- Static Memory Allocation
- Dynamic Memory Allocation
## Static Memory Allocation
- Memory allocated during compile time is `Static Memory Allocation`
- The memory allocatd is fixed & cannot be increased or decreased during run-time.
```C
  int main(){
    int arr[5] = {1, 2, 3, 4, 5};   //Memory allocated at compile time and is dixed
  }
```
### Problems with Static Memory Allocation
- If you are allocating memory for an array during compile time then you have to fix the size at the time of declaration. Size is fixed and user cannot increase or decrease the size of the array at run-time.
- If the value stored by the user in the array at run-time is `less` than the size specified then there will be `wastage of memory`
- If the value stored by the user in the array at run-time is `more` than the size specified then `the program my crash or misbehave`

## Dynamic Memory Allocation
- The process of allocating memory at the time of execution is `Dynamic Memory Allocation`
- getting inside `memory layout`
  - `HEAP` is the segment of memory where dynamic memory allocation takes place.
  - Unlike `STACK` where memory is allocated/deallocated in a defined order, `HEAP` is an area of memory where memory is allocated/deallocated without any order or randomly.
- There are certain built-in functions that can help in allocating/deallocating some memory space at run-time.
  - `malloc()`
  - `calloc()`
  - `realloc()`
  - `free()`

> *`Pointers` play an important role in dynamic memory allocation.*
> *Allocated memory can only be accessed through Pointers.*

### Ungerstanding `malloc()`
- It is a built-in function declared in header file `<stdlib.h>`
- malloc short-for **"Memory Allocation"**, used to dynamically allocate `a single large block of contiguous memory` aaccording to the size specified.
- `Syntax :`
  ```C
  (void*)malloc(size_t size);
  ```
- `size_t` is defined in <stdlib.h> as `unsigned int`
- It allocates memory in the heap and on success it returns `a pointer` pointing to the first byte of the allocated memory else returns `NULL`
####  Why voiid pointer ?
- malloc dosen't have any idea of whaat it si pointing to.
- it allocates memory requested by the user without knowing the type of data to be stored inside the memory.
- `void pointer` can be typecasted to an appropriate type.
```C
  int *ptr = (int *)malloc(4);
```
- malloc allocates 4 bytes of memory in the `heap` and the address of the first byte is stored in the pointer `ptr`
```C
    #include <stdio.h>
    #include <stdlib.h>

    int main(){
        int n;
        printf("Enter the number of the integer : ");
        scanf("%d", &n);
        int *ptr = (int*)malloc(n*sizeof(int));

        if(ptr == NULL){
            printf("Memory not available.\n");
            exit(1);
        }
        for(int i = 0; i < n; i++){
            printf("Enter an integer : ");
            scanf("%d", ptr + i);
        }
        for(int i = 0; i < n; i++)
            printf("%d ", *(ptr + i));

        return 0;
    }
```

### Understanding `calloc()`
- `calloc()` is used to dynamically allocate multiple blocks of memory.
- calloc stands-for `Clear Allocation`
- It is different from malloc in two ways :
  - calloc() needs two arguments instead of just one
    - `SYNTAX:`
    ```C
      void *calloc(size_t n, size_t size);
      // n    = Number of blocks
      // size = Size of each block

      //EXAMPLE

      int *ptr = (int *)calloc(10, sizeof(int));
      int *ptr = (int *)malloc(10*sizeof(int));
      //both works the same
    ```
  - Memory allocated by `calloc` is initialized to 0 (zero)
    - It is not the case with `malloc`, memory allocated by malloc is initialized with some `garbage value`

### Understanding `realloc()`
- It is used to change the size of the memory block without losing the old data.
- `SYNTAX :`
  ```C
    void *realloc(void *ptr, size_t newSize);   // *ptr = pointer to the previous allocated memory
    //lets see
    int *ptr = (int *)malloc(sizeof(int));
    ptr = (int *)realloc(ptr, 2*sizeof(int));
  ```
  - This will allocate memory space of 2*sizeof(int)
  - This func. also moves the contents of the old block to a new block and the data of the old block is not lost.
  - We might lose the data when the new size is smaller than the old size.
  - Newly allocatd bytes are uninitialized.

### Understanding `free()`
- It is used to release the dynamically allocaated memory in heap.
- `Syntax :   void free(ptr)`
- Memory allocated in heap will not be released automatically after using the memory. The space remain there and cannot be used.
```C
  int main(){
    int *ptr = (int *)malloc(5*sizeof(int));
    ...
  free(ptr);
  }
```

> *Ahh it is exhausting to write notes this way*
> *I hope you have understood memory allocation in C now*






