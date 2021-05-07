# ch10_IPC_and_error
###### tags: `HFC`
[TOC]
## overview
- [x] fileno and dup2
- [x] error and exit
- [x] sys/wait.h and waitpid
- [x] pipe()
    - [ ] named pipe
- [x] kill and sigaction
- [ ] raise and alarm
## concept
- 檔案描述子(file descriptor)
    - 代表data stream的數字
- 描述子表格(descriptor table)
    - 表格內有槽位(slot)
        - 0: stdin
        - 1: stdout
        - 2: stderr
    - 重導向改變的是描述子對應的stream
    - 開啟某個stream會新增slot
- 例子:
    - 用fopen開啟stream，表格可能新增描述子4，參照到fopen的stream
- IPC(interprocess communication)
    - 把輸入輸出重導向
    - 讓行程彼此等待
    - 透過管線
- pipe連接一個行程的輸出，與另一個行程的輸入
- 在命令列上以管線將命令串接在一起時，實際上是將他們以父行程和子行程的方式連接
    - 例子: `|grep`就是！
## redirection
- fileno and dup2
    ```
    FILE *out = fopen(test.txt, "w");
    int fno = fileno(out);
    dup2(fno, 1); // redirection stdout
    ```
    - fileno: 輸入stream的指標，回傳int:檔案描述子
    - dup2(3,4): 把描述子4參照的stream改成描述子3參照的stream
        - 描述子3的stream仍然不變 
## error and exit
- 呼叫exit可以直接讓程式結束
- exit是唯一不會失敗的函式，而且不會回傳值
## waitpid
- 使用waitpid等待行程
    - 在`<sys/wait.h>`
- `waitpid(pid, pid_status, options)`
    - man waitpid
- example:
    ```
    pid_t pid = fork();
    /*
    ...
     */
    int pid_status;
    if (waitpid(pid, &pid_status, 0) == -1) {
    error
    }
    if (WEXITSTATUS(pid_status)) {
    /*
    ...
     */
    }
    ```
- WIFSIGNALED(pid_status)
- WEXITSTATUS(pid_status)
- options in waitpid:
## pipe
- pipe()函式:
    - 打開兩個資料串流
    ```
    int fd[2];
    if (pipe(fd) == -1) {
        error("Can't create the pipe");
    }
    ```
    - `fd[0]`是寫入描述子，`fd[1]`是讀取描述子
- [ ] EOF
- [ ] wget download
## sigaction
- 在`signal.h`
- sigaction_struct
    - 裡面有一個指向函式的指標
    - 這個函式稱為handler(處理器)
        - handler無回傳；input是int
    - 還不知道幹啥用的東西:
    - [ ] sa_mask
    - [ ] sa_flags
- sigaction(signal_no, &new_action, &old_action);
- default key word
    - SIGINT
    - SIGQUIT
    - SIGFPE
    - SIGTRAP
    - SIGSEGV
    - SIGWINCH
    - SIGTERM
    - SIGPIPE
    - SIGALRM
    - SIG_IGN
    - SIG_DFL
## raise and alrm
- `raise(SIGTERM)`