//Q.Find the Pythagorean triplet (a, b, c), such that a + b + c = 1000 and a² + b² = c². Return the product abc.

#include <stdio.h>
//driver 
int main() {
    int a, b, c;
    for (a=0;a<300;a++){
        for(b=a+1;b<500;b++){
        c=1000-a-b;// generates value and hen it computes c using the formula
        if(a*a+b*b == c*c){
         printf("Trile is a = %d, b = %d, c = %d\n", a, b, c);
                printf("Prod: %d\n", a * b * c);
                return 0;
    }

}
        }

    return 1;
}
