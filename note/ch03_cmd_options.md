# ch3_command_line_option
###### tags: `HFC`
[TOC]
# outline
- [x] redirection
- [x] pipline
- [x] `FILE *in = fopen(...)`
- [x] argc and argv
- [x] getopt optind optarg unistd.h
## scanf
- 記得scanf要的是指標(所以string才是直接放)
## 檔案重導向
- 其實`printf`是呼叫`fprintf`
    - `fprintf(stderr, "msg")`
    - 還有`fscanf`
    - 用`<`更改標準輸入
    - 用`>`更改標準輸出
        - `2>`改成標準錯誤
    - 使用pipline`|`
    - 讀寫檔案
        - `FILE *in_file = fopen("filename.txt", r)`
        - `fclose(in_file)`
    - 檔案的安全檢查
        - 如果fopen有問題會回傳0
        ```
        FILE *in;
        if (!(in = fopen("dont_exit.txt", "r"))) {
          fprintf(stderr, "can't open the file.\n");
          return 1;
        }
        ```
## command_line_option
- `argc`和`*argv[]`
- argc包含了argv有多長
- argv的第一個元素是檔案名稱，所以長度會+1
- unistd.h, getopt, optind, optarg