/*Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
NOTE: 
2,3,5 and 7 are not considered to be truncatable primes.
o/p 23 is a truncatable prime
37 is a truncatable prime
53 is a truncatable prime
73 is a truncatable prime
313 is a truncatable prime
317 is a truncatable prime
373 is a truncatable prime
797 is a truncatable prime
3137 is a truncatable prime
3797 is a truncatable prime
739397 is a truncatable prime
sum of all 11 truncatable primes 748317 

*/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// if a no is prime
bool isPrime(int n){
    if(n<2) 
    {return false;}


    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) 
        {return false;}
    }

    return true;
}

//if a no. is right truncatable prime
bool isRightT(int n){
    while(n>0){
        if(!isPrime(n)) //3797 
        {return false;}
        n/=10;  // remove last digit ,,379,37,3,0 end loop
    }
    return true;
}

// count digits in a no.
int cntDig(int n){
    int count=0;
    while(n>0){
        count++;
        n/=10;
    }
    return count;
}

//power of 10 
int power10(int k){
    int res=1;
    for(int i=0;i<k;i++)
        res*=10;
    return res;
}

// if a no is left truncatable prime
bool isLeftT(int n) {
    int dig=cntDig(n);//3797 4 dig

    while(dig>0){
        if(!isPrime(n)) //true not false,797 prime,97 prime
        {return false;}
        int pow10=power10(dig-1); //10^3=1000...10^2=100,10^1
        n=n%pow10;  // remove ist digit...3797%1000=797,797%100=97,7
        dig--;//dig=2,dig=1,0 loop ends
    }

    return true;
}

int main() {
    int cnt=0;
    int sum=0;
    int num=11;  // as 2, 3, 5, 7 are not allowed

    while(cnt<11){
        if (isLeftT(num)&&isRightT(num)){//num 3797 true
            printf("%d is a truncatable prime\n",num);
            sum+=num;
            cnt++;
        }
        num++;
    }

    printf("sum of all 11 truncatable primes %d ",sum);
    
}
