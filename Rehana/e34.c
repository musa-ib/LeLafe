/*Find the sum of all numbers which are equal to the sum of the factorial of their digits.
TC O(n) n is nos to check whether they are curious
o/p
found 145
found 40585
sum: 40730


*/


#include <stdio.h>

// factorial of digits from 0 to 9
int facto(int n){
    int fact=1;
    for (int i=2;i<=n;i++){
        fact*=i;
    }
    return fact;
}

int main(){
    int sum=0;
    int fact[10];
    // calculate in advance factorials of 0 to 9
    for (int i=0;i<10;i++){
        fact[i]=facto(i);
    }
    for (int i=10;i<=2903040;i++){
        int x=i;
        int digSum=0;

        while(x>0){//while individual digit is not zero
            int dig=x % 10;//get digit by digit value from right to left
            digSum+=fact[dig];//find factorial of that very digit
            x/=10;//to move to extreme left digit till no digit is left
        }

        if (digSum==i){//if sum of fact of individual digits is equal to no. itself,its a curious no
            printf("found %d\n",i);
            sum+=i;//add curious digits
        }
    }

    printf("sum %d\n",sum);

}
