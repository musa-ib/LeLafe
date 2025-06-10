 /*Program to find the k-th lexicographic permutation of a given set of digits.   
total no of permutations for n dig is n!.For each position in the final perm,i used factorials to find 
how many permutations every starting digit has.Based on k, i found which unused digit will be at the current position.
write the digit as used and move to the next pos.
TC O(n^2)
output The 1000000th permutation is 2783915460
 **/
 #include <stdio.h>

int facto(int n) {
    int fact=1;
    for (int i=2;i<=n;i++)
        fact*=i;
    return fact;
}

void perm(int dig[], int n, int k) {
    int used[10] = {0}; // to track which digits are used
    k = k - 1; // convert to 0-based index

    for (int i=0;i<n;i++) {
        int fact=facto(n-1-i);//fact 3-1-0 2 =2
        int index=k/fact;//to know which digit's group our 4th perm is  3/2=1
        k=k%fact; //3%2=1

        // unused digit
        int cnt=-1;
        for (int j=0;j<10;j++){
            if (!used[j]){
                cnt++;
            }
            if (cnt==index){
                printf("%d",dig[j]);
                used[j]=1;
                break;
            }
        }
    }
}

int main() {
  int digits[]={0,1,2,3,4,5,6,7,8,9};  
int n=10;
int k=1000000;  


    printf("The %dth permutation is ",k);
    perm(digits,n,k);


}
