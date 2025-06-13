/*
The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe 
that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

We shall consider fractions like,30/50 =3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits
in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
*/

#include<stdio.h>
#include<math.h>

//remove the common digit in numerartor and denominator
double SimpFrac(int a,int b){
    if(a/10==b/10)return (double)(a%10)/(b%10);//if common value is at tens place in both nr and dr
    if(a/10==b%10)return (double)(a%10)/(b/10);//if common value is tens place in nr and ones placein dr
    if(a%10==b/10)return (double)(a/10)/(b%10);//if common value is ones place in nr and tens placein dr
    if(a%10==b%10)return (double)(a/10)/(b/10);//if common value is at ones place in both nr and dr
    return -1;
}



int main(){
    int prod_nr=1;// stores product of nr terms
    int prod_dr=1;// stores product of dr terms
    for(int nr=11;nr<99;nr++){
        if(nr%10==0)continue;// if nr or dr is evenly divisible by 10,
        //then common term we can remove is at tens place, remaining 0 in nr or dr
        for(int dr=nr+1;dr<=99;dr++){
            if(dr%10==0)continue;
            double frac = (double)nr/dr;//value of original fraction
            double simp_frac = SimpFrac(nr,dr);// value of simplified fraction
            if(fabs(frac-simp_frac)<1e-9){
                prod_dr*=dr;
                prod_nr*=nr;
                printf("%d/%d\n",nr,dr);  
            }
        }
    }

    // calculate gcd of nr and dr to simply fraction
    int gcd;
    int i=1;
    while(i<=prod_dr && i<=prod_nr){
        if(prod_dr%i==0 && prod_nr%i==0){
            gcd = i;
        }
        i++;
    }
    printf("%d",prod_dr/gcd);
}