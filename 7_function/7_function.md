# 7_function

## 傳遞程式碼給函式
- 建造函式指標
int (*warp_fn)(int);
warp_fn = go_to_warp_speed;
warp_fn(4);

char** (*names_fn)(char*, int);
names_fn = album_names;
char** results = name_fn("Sacha Distel", 1972)

回傳值型別 (*函式名稱)(函式參數);
範例:
正常定義函數
定義呼叫函數:
void find(int(*match)(char*))
再傳進去match(ADS[i])

## 指標練習
typedef struct {
    int width;
    int height;
} rectangle;

int compare_areas(const void*a, const void*b)
{
    rectangle* ra = (rectangle*)a;
    rectangle* rb = (rectangle*)b;
    int area_a = (ra->width * ra->height);
    int area_b = (rb->width * rb->height);
    return area_a - area_b
}

int compare_names(const void* a, const void* b)
{
    char**sa = (char**)a;
    char**sb = (char**)b;
    return strcmp(*sa, *sb);

## 函式指標陣列
## 可變參數函式