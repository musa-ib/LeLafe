

/* program-Find the value of d<1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
 s[rem] where remainder appears.If  remainder repeats  length of  cycle is diff b/w current pos and the pos where this 
 remainder was first seen.If  remainder becomes 0 division terminates and has no cycle
 tc: dl
o/p The value of d  983 */
#include <stdio.h>

//length of the repeating cycle of 1/d
int getCLen(int d) {
    int rem=1;
    int pos=0;
    int s[1000] = {0};  // when each remainder was first seen

    while(rem!=0 && s[rem]==0) {
        s[rem]=pos;
        rem=(rem*10)%d;
        pos++;
    }

    if (rem==0)
        return 0;  // if remainder becomes 0, it terminates means no cycle

    return pos-s[rem];  // cycle length = current pos - first time this rem was seen
}

int main() {
    int maxLen=0;
    int res=0;

    for (int d=2;d<1000;d++) {
        int len=getCLen(d);
        if (len>maxLen) {
            maxLen=len;
            res=d;
        }
    }

    printf("The value of d  %d ", res);

}
