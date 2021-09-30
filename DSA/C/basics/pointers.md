# POINTERS

## 1. Void Pointer
> - Pointer which has no associated datatype with it.
> - It can point to any data of any datatype and can be typecasted to any type.

```C
    int main(){
        int n = 10;
        void *ptr = &n;
        
        printf("%d", *(int*)ptr);   // we cannot dereference a void pointer
        return 0;
    }
```
- ### Use of Void pointer
> malloc & calloc function returns a void pointer,
> due to this they can allocate memory to any type of data.

## 2. Null Pointer
> - It is a pointer which does not point to any menory location.
> - When a NULL value is assigned to a pointer, then the pointer is considered as NULL Pointer.
```C
    int main(){
        int ptr* = NULL;    //this is null pointer
        return 0;
    }
```
- ### Use of NULL Pointer
> - It is used to initialize a pointer when that pointer isn't assigned any valid memory address yet.
> - Useful for handeling errors when using **`malloc`** function
```C
    int main(){
        int *ptr;
        ptr = (int*)malloc(2*sizeof(int));
        if(ptr == NULL)
            printf("Memory could not be allocated");
        else
            printf("Memory is allocated successfully");
    }
```
 - ### Some facts on NULL pointer
 >  - The value of NULL is 0. We can either use NULL or 0 but this 0 is written in context
 >  of pointers and is not equivalent to the integer 0.
 >  ```C
 >      int main(){
 >          int *ptr = NULL;
 >          printf("%d", *ptr);
 >          return 0;
 >      }
 >  ```
 >  - Size of the NULL pointer depends upon the platform and is similar to the size of the
 >  normal pointer.
 >  - **`It is a good practice to initialize a pointer as NULL.`**
