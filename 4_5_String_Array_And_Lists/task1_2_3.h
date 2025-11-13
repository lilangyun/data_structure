/*
* 必做题1_2_3·头文件
*/
typedef struct {
    char *ch;
    int length;
}HString;  //heapstring

// 创建新HString
HString *creatNewHString();
// 生成一个其值等于ch的T
void strAssign(HString *&s,char* ch);
// 释放HString
void deleteHString(HString *&s);