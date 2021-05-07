# ch08_static_and_shared
###### tags: `HFC`
[TOC]
## 目標
- 建立你自己的程式庫(靜態)
    - 重複利用程式碼
- 動態程式庫
    - 執行期間共用程式碼
## note:
- include`<>`和`""`
    - 通常標準標頭在:
        - `/usr/local/include/`
        - `/usr/include`
- note:
    - 通常會共用的檔案
        - 標頭(.h)
        - 目的檔(.o)
## 共用標頭檔
- 1. 把標頭複製到`/usr/local/include/`
    - 就直接用`<>`
- 2. 把標頭複製到特定路徑
    - `include "PATH/xxx.h"`
- 3. 使用`-I`
    - `-I`用來找標頭
## static library(.a)
- 用來放一堆目的檔(.a)： 靜態程式庫
- 使用`nm`查看`.a`的內容
- 使用`ar`(.o2.a)
    - `ar -rcs libhfsecurity.a encrypt.o checksum.o`
        - r表示如果收藏檔存在則更新
        - c表示隱藏回饋訊息
        - s建立索引？
        - `ar -t`可以列出有什麼內容
        - `ar -x` : 取出單一`.o`檔案
- 靜態程式庫名稱要叫libxxx.a
- 使用`-l<lib名稱>`
- 使用`-L<lib路徑>`
## shared library(.so)
- 在執行時期才連結
- 建造目的檔
    - `gcc -I/includes -fPIC -c hfcal.c`
    - `-fPIC`:
        - position-independent
    - `-fPIC`->.o
    - `-shared`->.so
        - `gcc -shared xxx.o -o libxxx.so`
- LD_LIBRARY_PATH
    - `export LD_LIBRARY_PATH=$LIBRARY_PATH:/libs`