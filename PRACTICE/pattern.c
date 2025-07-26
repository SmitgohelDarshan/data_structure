#include<stdio.h>
void main(){
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2*i-1;j++){
            if(i==j){
                printf("%d",i);
            }
            else if(j==1 || j==2*i-1){
                printf("1");
            }
            else{
                printf("*");
            }
        }
        printf("\n");
    }
}