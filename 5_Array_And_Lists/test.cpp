#include<iostream>
#include<string>
using namespace std;

typedef enum{
    ATOM,LIST
}ElemTag;

int main(){
    char s[]={'a','b','c'};
    cout<<ATOM<<endl;
    string s1="abcdefg";
    int start=4;
    int count=3;
    cout<<s1.substr(start,count);  //这里start指得是s1中的起始位置(以0为字符串第一个位置)
    // char s[6]="Hello!";  //注意:这里等式右侧的字符串其实是7个字符，因为其包括'\0'结束符
    char s[]="Hello!";
    char t[]={'h','e','l','l','o','!'};
    return 0;
}