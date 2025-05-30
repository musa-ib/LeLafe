#include<stdio.h>
#include<math.h>
int main(){
    int n = 1000;
    int arr[310]={0};
    arr[309]=1;
    int r=0;
    for(int j=1;j<=n;j++){
        int i=309,p;
        while(i>=0){
            p = arr[i]*2+r;
            if(p>9){
                arr[i] = p%10;
                r = p/10;
            }
            else{
                arr[i] = p;
                r=0;
            }
            i--;
        }
        
    }

    int sum = 0;
    for(int k=0;k<310;k++){
            sum+=arr[k];
            printf("%d",arr[k]);
        }

    printf("\n%d",sum);
    
}