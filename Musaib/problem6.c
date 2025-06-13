#include<stdio.h>

// Method 1
// int main(){
//     int s=0;
//     for(int i = 1;i<100;i++){
//         for(int j=i+1;j<=100;j++){
//             s = s + i*j;
//         }
//     }
//     printf("%d",2*s);
// }

// Method 1
// int main(){
//     int sum = 0,sqsum=0;
//     for(int i=1;i<=100;i++){
//         sum = sum + i;
//         sqsum = sqsum + i*i;
//     }
    
//     printf("%d",sum*sum - sqsum);
// }

// Method 3

int main(){
    int n = 100;
    int sum = (n*(n+1))/2;
    int sqsum = (sum*(2*n+1))/3;
    printf("%d",sum*sum-sqsum);
}