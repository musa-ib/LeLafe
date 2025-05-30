#include<stdio.h>
int main(){
    int arr[100][50];// 2D array to 100, 50 digit numbers
    char c; 
    int sum[55]={0};//to store sum of 50 digit numbers

    FILE *f = fopen("digit150.txt","r");
    int i=0,j=0;
    while((c=fgetc(f))!=EOF && i<100){
        if(c=='\n'){j=0;i++;}
        if(c-'0'>=0 && c-'0'<=9 &&j<50){
            arr[i][j] = c-'0';
            j++;
        }
    }

    fclose(f);


    int k = 54, r=0;
    for(int j=49;j>=0;j--){
        int s = r;
        for(int i=0;i<100;i++){
            s = s+arr[i][j];
            
        }
        if(s>9){
                sum[k]=s%10;
                r = s/10;
            }
        else sum[k] = s;
        k--;
    }
    if(r>9){
        while(r && k>=0){
            sum[k]=r%10;
            r= r/10;
            k--;
        }
    }
    else sum[k]=r;

    
    int indx=0;
    while(sum[indx]==0){
        indx++;
    }
    for(int a =indx;a<10+indx;a++){
        printf("%d",sum[a]);
    }

}