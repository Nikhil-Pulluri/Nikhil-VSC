#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// That's okay : ). DO it later.
struct Student{
    char n[20];
    char g[10];
    float c; 
};

int main(){
    int n;
    scanf("%d",&n);
    struct Student s[n];

    for(int i=0;i<n;i++){
        scanf("%s",s[i].n);
        scanf("%s",s[i].g);
        scanf("%f",&s[i].c);
    }

    for(int i=0;i<n;i++){
        if(s[i].c>195){
            printf("Course alloted to %s is ECE",s[i].n);
        }
      else  if(s[i].c>190){
            printf("Course alloted to %s is MECH");
        }
      else  if(s[i].c>185){
            printf("Course alloted to %s is EEE");
        }
      else  if(s[i].c>180){
            printf("Course alloted to %s is CIVIL");
        }
     else  if(s[i].c>0){
            printf("Course alloted to %s is CSE/IT");
        }
        printf("/n");
    }
    return 0;
}