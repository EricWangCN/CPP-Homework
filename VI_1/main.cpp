#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cstdio>
#include <string>
#include <vector>
#include <math.h>
#include <time.h>
#include <utility>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
const int dx[]={-1,1,0,0,-1,1,-1,1},dy[]={0,0,-1,1,1,-1,-1,1};
char c[300][300];
int used[300][300];
int n,m,t,ans,i,j,cnt,i1,j11,i2,j2,num1,num2;
bool flag;
bool check(int a,int b){
    int ok=0;
    for(int i=0;i<8;i++){
        int x=a+dx[i];
        int y=b+dy[i];
        if(c[x][y]=='1'){
            ok++;
            if(x==a||y==b||ok>2)return false;
        }
    }
    if(ok<=1)return false;
    return true;
}
void make1(int a,int b){
    i1=a;
    j11=b;
    i2=a;
    j2=b;
    for(;;){
        if(!check(i1,j11)||!check(i2,j2))return;
        used[i1][j11]=1;
        used[i2][j2]=1;
        if(c[i1+1][j11+1]=='1'&&c[i2+1][j2-1]=='1'){
            i1++;
            j11++;
            i2++;
            j2--;
        }else if(c[i1+1][j11-1]=='1'&&c[i2+1][j2+1]=='1'){
            i1++;
            j11--;
            i2++;
            j2++;
        }else return;
        if(j11==j2){
            used[i1][j11]=1;
            if(!check(i1,j11))return;
            flag=true;
            return;
        }
    }
}
void make(int a,int b){
    used[a][b]=1;
    i=a,j=b+1,cnt=0;
    if(c[a-1][b-1]=='1'||c[a-1][b]=='1'||c[a][b-1]=='1')return;
    while(j<=m){
        used[i][j]=1;
        if(c[i][j]!='1')return;
        cnt++;
        if(c[i-1][j]=='1')return;
        if(c[i+1][j]=='1'){
            if(c[i][j+1]=='1')return;
            break;
        }else if(c[i][j+1]=='1'){
            j++;
        }else return;
    }
    if(i+cnt>n)return;
    if(c[i-1][j+1]=='1')return;
    for(int x=1;x<cnt;x++){
        used[i+x][j]=1;
        if(c[i+x][j]!='1')return;
        if(c[i+x][j-1]=='1'||c[i+x][j+1]=='1')return;
    }
    i+=cnt;
    used[i][j]=1;
    if(c[i][j+1]=='1'||c[i][j-1]!='1'||c[i+1][j]=='1'||c[i+1][j+1]=='1')return;
    for(int x=1;x<cnt;x++){
        used[i][j-x]=1;
        if(c[i][j-x]!='1')return;
        if(c[i+1][j-x]=='1'||c[i-1][j-x]=='1')return;
    }
    j-=cnt;
    used[i][j]=1;
    if(c[i+1][j-1]=='1')return;
    if(c[i+1][j]=='1'||c[i-1][j]!='1'||c[i][j-1]=='1')return;
    for(int x=1;x<cnt;x++){
        used[i-x][j]=1;
        if(c[i-x][j]!='1')return;
        if(c[i-x][j-1]=='1'||c[i-x][j+1]=='1')return;
    }
    flag=true;
}
void launch(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>c[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            flag=false;
            if(c[i][j]=='1'&&!used[i][j]){
                make(i,j);
                make1(i,j);
            }
            if(flag)ans++;
        }
    }
    cout<<ans<<endl;
}
int main() {
    bool a[1000];
    for (int i = 0; i < 10; ++i) cout << a[i] << " ";
    /*cin >> t;
    for (int i = 1; i <= t; i++) {
        memset(used, 0, sizeof(used));
        memset(c, '0', sizeof(c));
        ans = 0;
        launch();
    }*/
    return 0;
}