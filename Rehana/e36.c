/*Find the sum of all numbers, less than one million, which are palindromic in base 10
 and base 2
 o/p sum of double base palindromes 872187
.*/
#include <stdio.h>
#include <string.h>

//if string is a palindrome
int isPal(char str[]){
    int len=strlen(str);//,,,,,//3
    for (int i=0;i<len/2;i++) {//0<1/2 f  ,,,, 0,1 since 0<3/2 ,1<3/2
        if (str[i]!=str[len-1-i])//str[0]=1=str[3-1-0]=1 true
            return 0;
    }
    return 1;//5 is pal,,,101 is pal
}

//convert no to binary string
void toBin(int n,char bin[]){//5
    int i=0;
    while(n>0){
        bin[i++]=(n%2)+'0';  // convert remainder to 0 or 1 but char 5%2=1,2%2=0,1%2=1  0+'0'=48 1+'0'=49
        n=n/2;// 5/2=2, 2/2=1,1/2=0   end
    }
    bin[i]='\0';

    // reverse the string to get crrct binary no
    int len = strlen(bin); //101
    for (int j=0;j<len/2;j++) {
        char x=bin[j];
        bin[j]=bin[len-1-j];
        bin[len-1-j]=x; //101
    }
}

int main(){
    int sum=0;
    char dec[20],bin[40];//to store decimal str and binary string resp

    for (int i=1;i<1000000;i++) {//i=5
        sprintf(dec,"%d",i);       //to decimal string

        if (isPal(dec)){     //if decimal string is palindrome

            toBin(i,bin);        //convert to binary string 5,bin

            if (isPal(bin)){ //check if binary string is palindrome //101
                sum+=i;            // if both satisfy, add to sum
            }
        }
    }

    printf("sum of double base palindromes %d",sum);
    
}
