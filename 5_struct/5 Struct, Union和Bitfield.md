# 5 Struct, Union和Bitfield

## 使用struct一次儲存多個變數
struct fish {
    const char *name;
    const char *species;
    int teeth;
    int age;
}
- 不知道struct要定義在哪
  - 放在.c跟void main同一層
- 先做了struct fish的template
之後產生實例
struct fish snappy = {"Snappy", "Piranha", 69, 4}
再複製一個
struct fish gnasher = snappy;
此時：
gnasher和snappy的name指向同一個string
- 可以從struct創建struct
給值的時候要用{{}}

## typedef
定義struct時使用 struct fish
定義變數時又要使用 struct fish snappy
很麻煩，因此改使用typedef
typedef struct{
int cell_no;
const char *wallpaper;
float minutes_of_charge;
}phone;
phone p = {aaa, "s.png", 1.35};

## 傳遞struct的指標
注意(*t).age和*t.age的不同
如果t是指向烏龜的指標變數
則(*t).age就是烏龜的年齡
但*t.age就會有問題，
*t.age會被電腦視為*(t.age)
更改括號的問題，引入->
## ->
(*t).age就是t->age
t所指向之struct的age欄位
- 現在對->只知道這樣，還沒能夠很熟練使用
## 相同類型的事物需要不同類型的資料型別(union)
如下定義
typedef union {
  short count;
  float weight;
  float volume;
} quantity;

初始化方法
1. C89
quantity q = {4}
這個永遠都只有指定第一個
2. designated initializer
quantity q = {.weight=1.5};
這個c++不支援喔
3. 點表示法
quantity q;
q.volume = 3.7;
不論使用何種方式設定union值，都只會有一個資料片段被儲存，union只是提供一種方式，讓你建立支援樹種不同資料型別的變數
## 指定初始化對struct也有用
尤其是在一開始只想要設定struct當中的一些的時候
有兩種兩行的指定法，一種可以一種不行
不行的:
margarita m;
m = {2.0, 1.0, {0.5}};
可以的:
quantity q;
q.volume = 3.7;

- 啥時只是用.啥時要用名稱.沒搞很清楚
例子1.
在定義實例的時候，我已經有一個typedef struct可是裡面有一個變數也是struct
那定義實例的時候按照順序.變數名稱.變數=

## 儲存的union沒有被記錄到底是哪個，因此引入enum(列舉)
- enum的基本使用:
enum colors {RED, GREEN, PUCE};
enum colors favorite = PUCE;
他的值只能是{}裡的東西
- 使用enum追蹤紀錄union
在呼叫的時候先用enum檢查
## 避免short short short short 定在struct裡
- bitfield
定義方式:
typedef struct {
  unsigned int low_pass_vcf:1;
  unsigned int filter_coupler:1,
  unsigned int reverb:1;
  ...
} synth;
這表示每個欄位只佔用一個位元的儲存空間
- 多個bitfile在一個struct就會省空間
- 單一一個還是會被對齊，沒啥用
- 冒號後面的數字可以自己指定多少位元
- 比如unsigned int month_no:4;
## 小錦囊
這個不知道有啥用
- 每個16進位都對應到長度為4的二進位
- C語言不支援二進制實字(就是不能直接0101打)
- 但支援16進位實字(就是0x54之類的)
- 人腦可以簡單支持16進位跟長度4的二進位



