#include <stdio.h>

int main() {
  int a;
  int b;
  int c;
  for(a=1;a<=1000;a++){
for(b=2;b<=1000;b++){
for(c=3;c<=1000;c++){
if(a+b+c==1000 && c*c==a*a+b*b){
printf("values of a b and c are %d %d %d\n", a, b, c);
 printf("product is %d\n", a*b*c);

}
  }
  }
  }
    return 0;
}
