#include<iostream>
#include<string.h>
#include<vector>
#include<math.h>
using namespace std;

// 最长公共子串动态规划算法
int lgs(string s1,string s2){
    int m=s1.size();int n=s2.size();
    int maxlen=-1;
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            maxlen=max(dp[i][j],maxlen);
        }
    }
    return maxlen;
}

// 计算nextval数组，以检验自己课后作业的正确性
void cnv(string s,vector<int> &nextval){
    int l=s.size();
    nextval[0]=-1;
    int j=-1;
    int n=nextval.size();
    for(int i=0;i<n-1;){
        if(j==-1||s[i]==s[j]){
            i++;j++;
            if(s[i]==s[j]){
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

int main(){
    // string s,t;
    // cin>>s>>t;
    // cout<<lgs(s,t)<<endl;
    string test="adabbadada";
    int n=test.size();
    vector<int>nextval(n,0);
    cnv(test,nextval);
    for(int i=0;i<n;i++){
        cout<<nextval[i]<<" ";
    }
    cout<<endl;
    return 0;
}