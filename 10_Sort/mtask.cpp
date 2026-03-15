/*
* 必做任务·源代码
*/
#include<iostream>
using namespace std;

#define ELEMTYPE int

typedef struct {
    ELEMTYPE *data;
    int length;
}SeqList;  // 顺序表

// 创建顺序表
void Create(SeqList &L, int n){  // 这里使用&传递才能修改值
    L.data = new ELEMTYPE[n+1];
    L.length = 0;
    cout<<"Please input the elements:"<<endl;
    for(int i = 1; i <= n; i++){
        int key;
        cin>>key;
        *(L.data+i) = key;  // 这里注意--指针必须初始化
        L.length++;
    }
}

// 打印信息
void Print(SeqList L){
    for(int i = 1; i <= L.length; i++){
        cout<<L.data[i]<<" ";
    }
}


// 直接插入排序
void InsertSort(SeqList L){
    int len = L.length;
    for(int i = 2; i <= len; i++){
        L.data[0] = L.data[i];
        for(int j = i - 1; j >= 0; j--){
            if(L.data[j] > L.data[0]){
                L.data[j+1] = L.data[j];  // 后移
            }
            else{
                L.data[j+1] = L.data[0];
                break;
            }
        }
    }
}

// 折半插入排序
void BInsertSort(SeqList L){
    int len = L.length;
    for(int i = 2; i <=len; i++){
        L.data[0] = L.data[i];
        int low = 1, high = i - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(L.data[mid] <= L.data[i]){
                low = mid + 1;  // data [1, low - 1] <= data[i]
            }
            else{
                high = mid - 1;  // data[high + 1, len] > data[i]
            }
        }
        for(int j = i - 1; j >= low; j--){
            L.data[j + 1] = L.data[j];
        }
        L.data[low] = L.data[0];
    }
}

// 划分
int Partition(SeqList L, int low, int high){
    int pivot = L.data[low];  // 枢轴量
    while(low < high){
        for( ; (low < high) && (L.data[high] <= pivot); high--);
        L.data[low] = L.data[high];
        for( ; (low < high) && (L.data[low] >= pivot); low++);
        L.data[high] = L.data[low];
    }
    L.data[low] = pivot;
    Print(L);  printf("    Pivot's position: %d\n", low);
    return low;  // 返回pivot所在位置
}

// 递归
void QSort(SeqList L, int low, int high){
    if(low < high){
        int mid = Partition(L, low, high);
        QSort(L, low, mid - 1);
        QSort(L, mid + 1, high);
    }
}

// 快速排序
void QuickSort(SeqList L){
    int len = L.length;
    QSort(L, 1, len);
}

int main(){
    SeqList L;
    int n, key, tmp;
    cout<<"Please input how many elements?"<<endl;
    cin>>n;
    Create(L, n);
    // printf("InsertSort:\n");
    // InsertSort(L);
    // Print(L);
    // printf("BInsertSort:\n");
    // BInsertSort(L);
    // Print(L);
    printf("QuickSort:\n");
    QuickSort(L);
    Print(L);
    return 0;
}