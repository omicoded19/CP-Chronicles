// submission link: https://codeforces.com/problemset/submission/1997/355917991

#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;
        s=" "+s;
 
        int open_even=0;
        for(int i=2;i<=n;i+=2){
            if(s[i]=='(') open_even++;
        }
 
        int need_close_odd=open_even;
        long long open_sum=0;
        int balance=0;
 
        for(int i=1;i<=n;i++){
            if(i%2==0){
                if(s[i]=='('){
                    balance++;
                    open_sum+=i;
                }else{
                    balance--;
                }
            }else{
                if(need_close_odd>0&&balance>0){
                    need_close_odd--;
                    balance--;
                }else{
                    balance++;
                    open_sum+=i;
                }
            }
        }
 
        long long total=(long long)n*(n+1)/2;
        cout<<total-2*open_sum<<"\n";
    }
    return 0;
}