# ch07_func_ptr
###### tags: `HFC`
[TOC]

## overview
- func_ptr example
- qsort example
- array of function pointer
- variadic function
## concept
- function name is a pointer
    - type: `returntype (* functionname) (param)`
## qsort func
- qsort:
    ```
    qsort(void *array,
          size_t length,
          size_t item_size,
          int (*compar)(const void *, const void *));
    ```
    - default increasing
    - compar:
        - param:
        - `(void *a, void *b)`
        - return:
        - positive: `a>b`
        - negative: `a<b`
        - 0: `a=b`
## array of function pointer
- `returntype (* varname[])(param)`
- working together with enum
## variadic func
- stdarg.h
    ```
    void funcname (int args, ...) {
      va_list ap;
      va_start(ap, args);
      /*
       *codehere
       */
      va_end(ap);
    }
    ```
- variadic function is macro
- va_start, va_end, and ==va_arg(ap, type)==
## extension
- implement:
    - [ ] inserition
    - [ ] bubble
    - [ ] selection
    - [ ] quick
    - [ ] heap
    - [ ] merge