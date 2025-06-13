#include <stdio.h>
#include <math.h>

int div(int no){
    int cnt =0;
    
    
    for(int i=1;i*i<=no;i++){
        if (no %i ==0) {
            if (i==no/i)
                cnt++; 
            else
                cnt+= 2; 
        }
    }

    return cnt;
}

int main(){
    int tri= 0;
    int i = 1;

    while(1){
        tri+=i;
        int divs=div(tri);

        if(divs>500) {
            printf("ist triangle number %d",tri);
            break;
        }

        i++;
    }

}
