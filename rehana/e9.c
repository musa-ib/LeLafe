#include <stdio.h>
int main(){
int x,y ,z;
for(x=1;x<1000;x++){
    for(y=x+1;y<1000;y++){
        z=1000-x-y;
        if(x*x+ y*y ==z*z){
            printf("prod %d ",x*y*z);
        }
       
    }



}
 

} 