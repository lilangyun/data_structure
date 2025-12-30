/*
* 必做任务·源代码
*/
#include<iostream>
using namespace std;

#define ELEMTYPE int

typedef struct {
    ELEMTYPE *elem;
    int length;
}SSTable;  // 静态查找表

// 创建查找表
void Create(SSTable &ST, int n){  // 这里使用&传递才能修改值
    ST.elem = new ELEMTYPE[n+1];
    ST.length = 0;
    cout<<"Please input the elements:"<<endl;
    for(int i = 1; i <= n; i++){
        int key;
        cin>>key;
        *(ST.elem+i) = key;  // 这里注意--指针必须初始化
        ST.length++;
    }
}

// 打印信息
void Print(SSTable ST){
    for(int i = 1; i <= ST.length; i++){
        cout<<ST.elem[i]<<" ";
    }
    cout<<endl;
}

// 顺序查找
int Search_Seq(SSTable ST, ELEMTYPE key){
    ST.elem[0] = key;  // 设置哨兵值
    int i;
    for(i = ST.length; ST.elem[i] != key ;i--);
    return i;
    // 如果返回0说明没找到
    // 返回>0说明找到元素
}

// 折半查找
int Search_bin(SSTable ST, ELEMTYPE key, int *cnt){
    int low, high;
    low = 1;
    high = ST.length;
    *cnt = 0;  // 比较关键字次数
    while(low <= high){
        int mid = low + (high - low)/2;
        if(ST.elem[mid] > key){
            high = mid - 1;
        }
        else if(ST.elem[mid] < key){
            low = mid + 1;
        }
        else{
            return mid;
        }
        (*cnt)++;
    }
    return 0;
}

int main(){
    SSTable ST;
    int n, key, tmp;
    cout<<"Please input how many elements?"<<endl;
    cin>>n;
    Create(ST, n);
    cout<<"Please input the element you want to find:"<<endl;
    cin>>key;
    if((tmp = Search_Seq(ST, key)) > 0){
        printf("The element %d is located in %d.   (Search_Seq)\n", key, tmp);
    }
    else{
        printf("I can't find the element %d.   (Search_Seq)\n", key);
    }
    int *cnt = new int;
    *cnt = 0;  // 比较关键字次数
    if((tmp = Search_bin(ST, key, cnt)) > 0){
        printf("The element %d is located in %d.   (Search_bin)\n", key, tmp);
        printf("The number of comparisons is %d.   (Search_bin)\n", *cnt);
    }
    else{
        printf("I can't find the element %d.   (Search_bin)\n", key);
    }
    return 0;
}
