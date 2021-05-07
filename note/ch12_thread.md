# ch12_thread
###### tags: `HFC`
[TOC]
## overview
- [x] 建立執行緒(pthread_t, pthread_create, pthread_join)
- [x] thread param
- [x] thread unsafe
- [x] mutex(lock)
    - mutually exclusive
    - pthread_mutex_t
    - lock
    - unlock
## concept
- 你要的就是thread
    - process不能輕易共用資料
    - process需要時間建立
    - process就是比較棘手
- 所有執行序跑在同一個行程裡
    - 存取相同的heap
    - 讀寫相同的檔案
    - 在相同的socket交談
    - 改變全域變數，所有人都看得到
## pthread
- pthread_create
- pthread_t
- pthread_join
## mytex
- pthread_mutex_t a_lock = PTHREAD_MYTEX_INITIALIZER;
- pthread_mutex_lock
- pthread_mutex_unlock