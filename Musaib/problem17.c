/*
    If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
    
    Time Complexity = O(n)
    Answer = 21124
*/


#include<stdio.h>
#include<string.h>
#include <time.h>


//Function that counts number of words in a number n
int countWord(int n){

    int num_Count = 0;  //stores word count in a number n

    char *one[]={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve",
                "Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};// words from 1 to 19

    char *twen[]={"","Twenty","Thirty","forty","fifty","Sixty","seventy","Eighty","Ninety"};
    char *other[]={"","hundred","thousand"};

    if(n%100<20){
        num_Count+= strlen(one[n%100]); // for first 19 numbers
    }
    else {
        num_Count=num_Count+strlen(one[n%10])+strlen(twen[((n/10)%10)-1]); //for numbers from 20 -99
    }
    if(n>100 && n%100!=0){
        num_Count += 3;  //Adds 3 for AND
    }

    if((n%1000)/100){
        num_Count =  num_Count + strlen(one[n%1000/100]) + strlen(other[1]); //for numbers greater than 99 and less than 1000
    }
    if(n/1000){
        num_Count =  num_Count + strlen(one[n/1000]) + strlen(other[2]);// numbers greaterthan thousand
    }

    
    return num_Count;
}

int main(){
    int sum = 0;// for storing sum of word count from 1 to 1000

    for(int i=1;i<=1000;i++){
        sum = sum + countWord(i);//counts words in number i and adds it to previous sum
    }

    printf("%d",sum);
}