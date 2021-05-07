# ch09_system_and_process
###### tags: `HFC`
[TOC]
## overview
- [x] system
- [x] exec
- [x] errno and strerror
- [x] for and pid
## concept
- os kernel:
    - 主要負責三件事:
    - 行程
        - 核心把行程載入記憶體
    - 記憶體
        - 增加虛擬記憶體尺寸
    - 硬體
        - 使用裝置驅動程式
## system函式
- 使用system()執行命令
    - ex: system("echo xxx >> reports.log")
- 缺點
    - 由於是依靠string執行，把string改成指令變成可以任意輸入指令
    - 如果輸入內容包含單引號會破壞命令
    - 改用exec
## exec
- exec在`unistd.h`
### 由exec()替換當前行程
- 行程就是在記憶體裡執行的程式
- linux命令: `ps -ef`
    - report a snapshot of the current processes.
- 作業系統使用PID追蹤每個行程
- 在exec指名行程並替換當前行程(擁有相同PID)
### exec的種類
- execl: (list)
    - execl, execlp, execle
- execv: (vector)
    - evecv, execvp, execve
- p: path, e: environment
#### 參數
- 程式
    - 第一個參數告訴exec要執行什麼程式
- 命令列引數
    - 因為第一個命令列引數總是程式名稱，所以給exec的前兩個引數總是同名
- NULL
    - 最後的引數需要是NULL
- 環境變數(option)
    - 名稱以e結尾的exec，可以傳遞環境變數構成的陣列
### 環境變數
- linux command: set
- linux command: env
    - run a program in a modified environment
- c語言可以使用getenv()系統呼叫讀取環境變數
## errorno and strerror
- `errno` in `<errno.h>`
- `strerror` in `string.h`
- example: `strerror(errno)`
- 如果exec成功，後面的程式碼就不會執行，所以可以用來處理失敗
- 失敗處理行為
    - 盡可能清理乾淨
    - 為errno變數設定錯誤值
        - 定義在errno.h
    - 回傳-1
## fork
- example:
    ```
    pid_t pid = fork();
    ```
- pid
    - -1: err
    - 0: child
    - 1: father