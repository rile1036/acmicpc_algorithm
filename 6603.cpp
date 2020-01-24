#include <iostream>
#include <vector>
using namespace std;
 
int n;
vector<int> arr;
vector<int> visited;
 
void dfs(int step,int cnt){
    
    if(cnt==6){
        for(int i=0;i<n;i++)
            if(visited[i])
                printf("%d ",arr[i]);
        
        printf("\n");
        return;
    }
    
    //남은 원소 모두 선택해도 6개 안될 때
    if(n-step<6-cnt)
        return;
    
    visited[step]++;
    dfs(step+1,cnt+1);
    
    visited[step]--;
    dfs(step+1,cnt);
    
}
int main(){
    
    
    while(true){
        scanf("%d",&n);
        if(n==0)
            break;
        
        arr=vector<int> (n,0);
        visited=vector<int> (n,0);
        
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        
        
        dfs(0,0);
        printf("\n");
    }
    return 0;
}