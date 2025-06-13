#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>


bool isPrime(int n){
    if(n<2)return false;// if number is negative or 0 or 1 return not prime
    if(n==2)return true;// 2 is prime number
    if(n%2==0)return false;// all even numbers except 2 are not prime
    int sq = sqrt(n);
    for(int i=3;i<=sq;i++){
        if(n%i==0){         // check all other numbers by dividing them from 3 to square root
            return false;
        }
    }
    return true;
}
// Function rotate rotates a number
int rotate(int n){
    char str[10];
    itoa(n,str,10);
    int l = strlen(str);
    char c = str[l-1];
    for(int i=l-1;i>0;i--){
        str[i] = str[i-1];
    }
    str[0] = c;
    return atoi(str);

}

bool rotatePrimes(int n){
    int a = n;
    do
    {
        a = rotate(a);
        if(!isPrime(a))return false;
    } while (a!=n);

    return true;
}

int main(){
    int c = 1;
    for(int i=3;i<1000000;i=i+2){
        if(rotatePrimes(i)){
            // printf("%d\t",i);
            c++;
        }
    }    

    printf("%d",c);

    // printf("%d",rotatePrimes(107));
}