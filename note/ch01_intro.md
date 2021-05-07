# ch01_intro
###### tags: `HFC`
[TOC]
## overview
- [x] basic gcc
- [x] basic type
- [x] basic operator
- [x] basic key word
- [x] io
- [x] coding style note
## basic gcc
- gcc
    - `gcc xxx.c -o xxx`
    - GNU compiler Collection
    - c standard
        - ANSI C
        - C99
        - C11
    - `-std=c99`
- return value
    - `echo $?`
## basic type
- array
    - s = "" include `\0`
    - `''` and `""` are different
- atio function
## basic operator
- `++i` and `i++`
- `&&`, `||` and `!`
    - left first
- `&` and `|`
    - also can do on bitwise operation
    - example:
        - `6&4` will return 4
- chaining assignments
    - `x = 4` will return 4
        - therefore y = x = 4;
## basic key word
- do while
    ```
    do {
    } while (cond);
    ```
- switch
    ```
    switch (var) {
      case 'K':
      case 'Q':
        dosomething;
        break;
      default:
        dosomething;
    }
    ```
- `continue` and `break`
    - continue: 回到迴圈的開始
    - break: 跳出迴圈
## io
- fgets
- puts
    `puts("message")`
- printf
    ```
    int i = 0;
    printf("%i", i)
    ```
    - `%s`: string
        - `%2s`
    - `%i`: int
    - `%d`: ??
- scanf
    ```
    int decks;
    scanf("%i", &decks);
    ```
    - 因為scanf要寫入變數，所以總是傳指標
## coding style note
- function
    - `int main() {`小括號和函數名稱沒有空格，和大括號空一格
    - 函數宣告/定義太長對參數分行，後面按照參數對齊
    - 連第一個參數都放不下，4格空格縮排，函式主體2格空格縮排
    - 右大括號和左大括號總是有1個空格
- if
    ```
    if (cond) {
    } else {
    }
    ```
- switch
    - case2格縮排
    - 語句4格縮排
    - 可以兩個case並在一起
