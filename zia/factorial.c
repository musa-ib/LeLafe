#include <stdio.h>

int main(){
int i;
unsigned fact=1;
for(i=40;i>=1;i--){
fact*=i;
}
printf("%lu\n", fact);

    return 0;
}