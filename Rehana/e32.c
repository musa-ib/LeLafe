/*Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 
 through pandigital
 o/p 
4*1738=6952 is pandigital
4*1963=7852 is pandigital
12*483=5796 is pandigital
18*297=5346 is pandigital
28*157=4396 is pandigital
39*186=7254 is pandigital
48*159=7632 is pandigital
sum 45228
*/
 #include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isPandig(int a,int b,int c){
    char dig[20];
    sprintf(dig,"%d%d%d",a,b,c);//convrts int to strings and concats them

    // musst be exactly 9 digits
    if(strlen(dig)!=9)  //combines a,b, c into a single string of digits="391867254"
       {return 0;}
    // check for digits 1 to 9 exactly once ,if a digit was already used
    int used[10]={0};  

    for(int i=0;i<9;i++) {//loop over eah digit from 1 to 9
        int d=dig[i]-'0'; //converted char into int
        if(d==0||used[d]) 
        {return 0;}  // skip 0 and repeated digits
        used[d]=1;//mark it used
    }

    return 1;
}

int main() {
    int sum=0; //total of valid products
    int fnd[10000]={0}; //  avoid duplicate products-which products we have already added

    for(int a=1;a<100;a++){ // multiplicand 39 e.g
        for(int b=100;b<10000;b++){ // multiplier 186
            int c=a*b; // product 7254

            if(c>9999) 
            {break;} // since product must be 4-digit max

            if (isPandig(a,b,c)&&!fnd[c]){
                printf("%d*%d=%d is pandigital\n",a,b,c);
                sum+=c;//added valid products 
                fnd[c]=1;//to avoid duplicate products later on 
            }
        }
    }

    printf("sum %d ",sum);
    
}
