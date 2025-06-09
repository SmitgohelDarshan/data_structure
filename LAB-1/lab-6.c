#include <stdio.h>
void main(){
    int hour,second,minute,total_seconds;
    printf("Enter the total number of second: ");
    scanf("%d", &total_seconds);
    hour = total_seconds / 3600;
    minute = (total_seconds % 3600) / 60;
    second = total_seconds % 60;
    printf("%d:%d:%d",hour,minute,second);  
}