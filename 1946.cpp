#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main(){
    
    int T;
    cin>>T;
    
    int n;
    for(int testCase=0;testCase<T;testCase++){
        cin>>n;
        vector<vector<int>> score(n,vector<int>(2,0));
        for(int i=0;i<n;i++){
            scanf("%d %d",&score[i][0],&score[i][1]); //서류,면접 등수
        }
        
        int ans=0;
        sort(score.begin(),score.end());
        
        vector<int> select;
        select.push_back(score[0][1]);
        
        for(int i=1;i<n;i++){
            if(select[ans]>score[i][1]){
                select.push_back(score[i][1]);
                ans++;
            }
        }
        printf("%d\n",ans+1);
    }
    
    return 0;
}