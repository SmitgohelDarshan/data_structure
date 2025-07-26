#include<stdio.h>
void main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("Enter array elements: ");
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){   
            if(a[i]==a[j]){
                count++;
            }
        }
        if(count==1){
            printf("%d,",a[i]);
            count=0;
        }
    }
}