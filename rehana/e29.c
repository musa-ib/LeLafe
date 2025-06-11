/*prog to find distint nos for a^b where a ranges and b both ranges from 2 to 100
i used 2 loops to include these ranges and caculates power for all combinations for a and b ,if power is unique
i will use set flag var i.e isUnq to 1 i.e true then i will check in res[] array which stores these power values 
whether this power came before,if so then i will set isUnq var to 0 i.e no its not unique .If isUnq is true then 
I will increment the count var which tracks no of distinct terms of these power and then i will consider other 
combinations of a and b as well
TC O(n^2) for a,b comb *O(n*2) for search =O(n^4)
o/p no of distinct terms 9183*/

#include <stdio.h>
#include <math.h>

int main(){
double res[10000];//store power values
int cnt=0;//store distinct values of power

for(int a=2;a<=100;a++){
for(int b=2;b<=100;b++){
double power=pow(a,b);

int isUnq=1;//yes power has not appeared before
for(int j=0;j<cnt;j++){
if(res[j]==power){
isUnq=0;//power  appeared before
break;
}
}

if(isUnq){
        res[cnt]=power;//store power value
        cnt++;//to include unique value of power
             }
         }
}

printf("no of distinct terms %d ",cnt);
   
}
