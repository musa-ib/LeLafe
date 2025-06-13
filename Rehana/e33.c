/*49/98=4/8,30/50=3/5(is trivial).There are exactly four non-trivial examples of this type of fraction, 
less than one in value, and containing two digits in the numerator and denominator.
If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
o/p Ans 100
*/
#include <stdio.h>
//to simplify fraction
int gcd(int a,int b){
    while(b!=0){
        int x=b;
        b=a%b;
        a=x;
    }
    return a;
}

int main(){
    int numProd=1;
    int denProd=1;
//all 2 digit fractions less than 1 
// num=49 den 98
    for(int num=10;num<100;num++){
        for(int den=num+1;den<100;den++){
            int n1=num/10;     // tens of num 4
            int n2=num% 10;     // ones of num 9
            int d1=den/ 10;   // tens of den 9
            int d2=den%10;   // ones of den 8
            if(n2==0&&d2==0)
                continue;//skip fractions like 30/50
            if(n2==d1 && d2!=0 && num*d2==den*n1){//n2=9,d1=9 equal.d2=8 is not=0.49*8=392 .98*4=392
                numProd*=n1;//4
                denProd*=d2;//8
            }
            if(n1==d2 && d1!=0 && num*d1==den*n2) {//4!=8 
                numProd*=n2;
                denProd*=d1;
            }
        }//loop continues for 4 non trivial fractions
    }
    int finalGCD=gcd(numProd,denProd);
    int simpleDen=denProd/finalGCD;
    printf("Ans %d ",simpleDen);
}
