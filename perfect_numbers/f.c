#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int sum = 0;
int factor(int test,int i){
    if(i >= test) return 0;
    if(test%i==0) sum += i;
    factor(test, i+1);
    return 0;
}
int isperfect(int test){
    int i=1;
    factor(test, 1);
    printf("%d bruh", sum);
    if(sum==test){
        sum=0;
        return 1;
    }
    else{
        sum=0;
        return 0;
    }
}
int readperfects(int myperfects[7]){
    int x=1,count=0,i=0;
    while(count<7){
        printf("enter number:");
        scanf("%d",&x);
        if(x == 0) break;
        if(isperfect(x)){
            myperfects[i]=x;
            i++;
        }
        count++;
    }
    return i;
}
int main(){
    int myperfects[7];
    int len= readperfects(myperfects);
    printf("perfect numbers:\n");
    for(int j=0;j<len;j++){
        printf("%d ",myperfects[j]);
    }
}