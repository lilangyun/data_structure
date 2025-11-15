/*
* 必做题1_2_3·源代码
*/
#include<iostream>
#include<string.h>
#include "task1_2_3.h"
using namespace std;

// 建立目标串和模式串

HString *creatNewHString(){
    HString *s=new HString;
    s->ch=NULL;
    s->length=0;
    return s;
}

// 生成一个其值等于ch的T
void strAssign(HString *&s,char* ch){
    int i;  //表示字符串ch长度
    char *t=ch;
    if(s->ch!=NULL){
        delete[] s->ch;
        s->ch=NULL;
    }
    for(i=0;*t!='\0';t++){
        i++;
    }
    if(i==0){
        // 如果为空字符串
        s->ch=NULL;
        s->length=0;
    }
    else{
        s->ch=new char[i+1];
        char *p=ch;
        char *q=s->ch;
        for(;*p!='\0';p++){
            *q=*p;
            q++;
        }
        *q='\0';
        s->length=i;
    }
}

void deleteHString(HString *&s){
    if(s!=NULL){
        if(s->ch!=NULL){
            delete[] s->ch;
            s->ch=NULL;
        }
        delete s;
        s=NULL;
    }
}

int easyModeMatch(HString *s,HString *t){
    // 这里约定好s为主串，t为模式串
    int i=0,j=0;
    while(i<s->length&&j<t->length){
        if(s->ch[i]==t->ch[j]){
            i++;j++;
        }
        else{  //这里老想不明白,回退指针
            i=i-j+1;j=0;
        }
    }
    if(j>=t->length){
        return i-t->length;
    }
    return -1;  //否则返回-1表示匹配失败
}

void get_next(int *next,HString *t){
    int i=0,j=-1;
    next[0]=-1;  //-1表示开头字符不等，应移动至下一字符
    while(i<t->length&&j<t->length){
        if(j==-1||t->ch[i]==t->ch[j]){
            i++;j++;next[i]=j;
        }
        else{
            j=next[j];
        }
    }
}

void get_nextval(int *nextval,HString *t){
    int i=0,j=-1;
    nextval[0]=-1;
    while(i<t->length&&j<t->length){
        if(j==-1||t->ch[i]==t->ch[j]){
            i++;j++;
            if(t->ch[i]==t->ch[j]){
                nextval[i]=nextval[j];
            }
            else{
                nextval[i]=j;
            }
        }
        else{
            j=nextval[j];
        }
    }
}

int kmp(HString *s,HString *t){
    int i=0,j=0;
    int len=t->length;
    int *next=new int[len];
    get_nextval(next,t);
    while(i<s->length&&j<t->length){
        if(j==-1||s->ch[i]==t->ch[j]){
            i++;j++;
        }
        else{
            j=next[j];  //i指针不回退
        }
    }
    if(j>=t->length){
        return i-t->length;
    }
    return -1;
}

int main(){
    char a1[100],a2[100];
    cout<<"Please cin your main string:"<<endl;
    cin.getline(a1,100);
    cout<<"Please cin your mode string:"<<endl;
    cin.getline(a2,100);
    HString *s=creatNewHString();
    HString *t=creatNewHString();
    strAssign(s,a1);
    cout<<"Your main string is : "<<s->ch<<endl;
    strAssign(t,a2);
    cout<<"Your mode string is : "<<t->ch<<endl;
    // cout<<"The match result is : "<<easyModeMatch(s,t)<<"  --easyModeMatch"<<endl;
    cout<<"The match result is : "<<kmp(s,t)<<"  --kmp"<<endl;
    deleteHString(s);
    deleteHString(t);
    return 0;
}