/*
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names,
begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, 
multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3+15+12+9+14 = 53,
 is the 938th name in the list. So, COLIN would obtain a score of 938*53=49714.

What is the total of all the name scores in the file?
Time Complexity  = o(N) N is number of characters in txt file
Answer = 871198282
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// compare function for quick sort to compare two strings
int compare(const void *a, const void *b) {  // compare function to compare two strings
    return strcmp(*(const char **)a, *(const char **)b);
}

//Function to calculate worth of a name

int worth(char *n, int len){
    int wrth = 0; // stores worth of a name
    for(int i=0;i<len;i++){
        wrth = wrth + (n[i]-'A')+1;//worth of A=1
    }
    return wrth;
}

int main(){
    FILE *fptr = fopen("names.txt","r");// open the names.txt in reading mode
    char *names[6000]={NULL};//for storing names
    int name_indx=0;// index for names
    char c;//for reading characters in name.txt
    char name[20]; // to store individual names
    int cnt = 0; // for counting " when cnt =2 that means we have read a name
    while((c=fgetc(fptr))!=EOF){
        if(cnt==2){
            names[name_indx]=(char *)malloc(strlen(name)+1); //allocating memory for each name
            
            strcpy(names[name_indx],name); // copy the name from name to names
            name_indx++; // increment name_index for next name
            cnt = 0; // reset counter
            name[0]='\0'; //empty name array after copying
        }
        if(cnt<2 && c!=','){
            if(c=='"')cnt++;
            else {
                int len = strlen(name);
                name[len] = c; // append character c to name 
                name[len+1]='\0';
            }
        }
    }
    // for last name
    names[name_indx]=(char *)malloc(strlen(name)+1);
    strcpy(names[name_indx],name); 
    name_indx++;
    cnt = 0; 
    name[0]='\0';

    fclose(fptr);
    // printf("%d\n",name_indx);
    // printf("%s\n",names[5162]);
    qsort(names,name_indx,sizeof(names[0]),compare);// sort names using quick sort

    int sum_score = 0;// store total of all the name scores
    for(int i=0;i<name_indx;i++){
        sum_score = sum_score + worth(names[i],strlen(names[i]))*(i+1);//calculating score of number(worth*index)
    }
    printf("%d",sum_score);
}