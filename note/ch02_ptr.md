# ch02_ptr
###### tags: `HFC`
[TOC]
## overview
- callbyptr
- arrayvsptr
- fgetsvsscanf
## concept
- stack and heap
    - stack, heap, globals, constants, code
- array vs prt
    - sizeof(ptr) vs sizeof(array)
    - &arr vs &ptr
    - arr can't pointer other
        - 陣列並不配置記憶體
            - 這也解釋了&arr vs &ptr
    - char array and string literal
        - string literal存在CONSTANTS
        - bus error
    - const char
- 指標需要型別的理由
    - shift才知道移多少
## note
- personal: 總是使用空格前置
    - `int *a`
- sizeof是運算子
    - sizeof(ptr)回傳位元組(8 in 84)
- fgets and scanf
    - `fgets(ptr, sizeof(ptr), stdin)`
        - sizeof(ptr) include `\0`
    - `scanf`
        - 1: 使用scanf簡單造成區段錯誤
        - 2: scanf寫入string array[80]只能寫79個"字"
## extension
### danger zone