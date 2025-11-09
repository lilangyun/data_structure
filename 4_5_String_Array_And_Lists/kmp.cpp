#include<iostream>
#include<string.h>
using namespace std;

void printnext(int next[],int len){
    int i=0;
    for(;i<len;i++){
        cout<<next[i]<<" ";
    }
    cout<<endl;
}

void get_next(string t,int next[]){
    int fast=0,slow=-1,len=t.length();
    next[0]=-1;  //最开始的字符串是没有前后缀的
    while(fast<len-1){
        if(slow==-1||t[slow]==t[fast]){
            fast++;slow++;
            next[fast]=slow;
        }
        else{
            slow=next[slow];
        }
    }
}

void get_nextval(string t,int next[]){
    int fast=0,slow=-1,len=t.length();
    next[0]=-1;  //最开始的字符串是没有前后缀的
    while(fast<len-1){
        if(slow==-1||t[slow]==t[fast]){
            fast++;slow++;
            if(t[fast]==t[slow]){
                // 省去了很多步骤
                next[fast]=next[slow];
            }
            else{
                next[fast]=slow;
            }
        }
        else{
            slow=next[slow];
        }
    }
}

int index_kmp(string s,string t){
    int i=0,j=0;
    int next[64]={0};
    get_nextval(t,next);
    int len_s=s.length();
    int len_t=t.length();
    // 这里很隐蔽的一个地方是：length()函数的返回值是无符号数，这个错误太难排查
    printnext(next,len_t);
    while(i<len_s&&j<len_t){
        if(j==-1||s[i]==t[j]){
            i++;j++;
        }
        else{
            j=next[j];
        }
    }
    if(j>=len_t){
        return i-len_t;
    }
    return -1;
}


int main(){
    string s,t;
    cin>>s>>t;
    cout<<index_kmp(s,t)<<endl;
    return 0;
}