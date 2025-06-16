/*How many circular primes are there below one million like 197,719,?
o/p total circular primes 55*/

#include <stdio.h>
#include <stdbool.h>

#define N 1000000

// if a no. is prime
bool isPrime(int n){
    if(n<2) 
    {return false;}
    for(int i=2;i*i<=n;i++)
        if(n%i==0) 
        {return false;}
    return true;
}

//to count no. of digits
int digCnt(int n){
    int count=0;
    while(n>0) {
        count++;
        n/=10;//197/3 will run 3 times until it becomes 0
    }
    return count;//3
}

// get power of 10
int tenPow(int n){//n=2
    int result=1;
    while(n-->0) 
    {result *= 10;}//2=10,1=100,0 exit 
    return result;//100
}

//to check if all rotations of a number are prime
bool isCP(int n){//197
    int digs=digCnt(n);//count no. of digits in no. digits=3
    int powTen=tenPow(digs-1); //calculate power of ten of no. which will be used to get new circular prime nos
//tenPower(2) =100

    for (int i=0;i<digs;i++){//0 to 2
        if (!isPrime(n)) 
        {return false;} //197 is prime so dont run this if //719 //971

        // rotate number
        int l=n%10; //get last digit to take it to first position l=197%10=7 ,9,1
        n=(n/10)+(l*powTen);//got new circular prime no n=197/10+7*100=19+700=719, 71+9*100=971,97+1*100=197
    }

    return true;
}

int main(){
    int cnt=0;
    for(int i=2;i<N;i++){
        if (isCP(i)){ //if no is circular prime or not CP(197)
            cnt++; //then count that no. which is cp 
        }
    }
    printf("total circular primes %d ",cnt);
    
}
