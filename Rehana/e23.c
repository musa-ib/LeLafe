
/**
 program is to sum all +ve integers that cant Be written as sum of Two Abundant nos
upper limit 28123 
 sumDiv
calculates the sum of proper divisors of n 
 
 Variables:
 is_abundant[LIMIT + 1] array where is_abundant[i] is true if i is abundant
.can_be_written[LIMIT + 1]  array where can_be_written[i] is true if i can be expressed as the sum of two abundant numbers.
total stores the final sum of numbers that cannot be written as such sums
 
 i found all abundant numbers up to LIMIT.then i marked all nos that can be expressed as the sum of two abundant numbers.then i summed up all nos up to LIMIT that are not marked
  
Output 4179871
Time complexity O(n²)  */
#include <stdio.h>
#include <stdbool.h>

#define LIMIT 28123  

int sumDiv(int n) {
    int sum=1;
    for (int i=2;i*i<=n;i++) {
        if (n%i==0){
            sum+=i;
            if (i!=n/i) {
                sum+=n/i;
            }
        }
    }
    return sum;
}

int main() {
    bool is_abundant[LIMIT + 1] ={false};
    int i,j;

    // find all abundant ns
    for (i=1; i<=LIMIT;i++) {
        if (sumDiv(i)>i) {
            is_abundant[i]=true;
        }
    }

    //numbers that can be written as sum of two abundant nos
    bool can_be_written[LIMIT + 1]={false};
    for (i=1;i<=LIMIT;i++) {
        if(is_abundant[i]) {
            for (j=i;j<=LIMIT;j++) {
                if(is_abundant[j]) {
                    int sum=i+j;
                    if (sum<=LIMIT) {
                        can_be_written[sum]=true;
                    }
                }
            }
        }
    }

    //  sum numbers that cant be written as sum of two abundant nos
    int total=0;
    for (i=1;i<=LIMIT;i++) {
        if (!can_be_written[i]) {
            total+=i;
        }
    }

    printf("Ans %d ",total);
    
}
