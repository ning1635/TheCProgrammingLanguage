/*
 * binsearch: find x in v[0] <= v[1] <= --- <= v[n - 1]
 */
#include <stdio.h>

int binsearch(int,int *,int);

int main(){
        int x = 2;
        int v[] = {1,2,3,4,5,6,7,8,9,10};         
        int n = 10;
        printf("%d",binsearch(x,v,n));
        return 1;
}

int binsearch(int x,int *v,int n){
        int lower = 0;
        while(x != v[n - 1]){
                if(x > v[n / 2]){
                        lower = n / 2;
                }
                else{
                        n = n / 2;
                }
        }
        return v[n-1];
}
