#include<stdio.h>
#include<string.h>

int size=0;
char keys[100][100];
int values[100];


int getindex(char key[]){
    for(int i=0;i<size;i++){
        if(strcmp(key,keys[i])==0){
        return i;
        }
    }
    return -1;
}

void insert(char key[],int value){
    int index=getindex(key);
    if(index==-1){
        strcpy(keys[size],key);
        values[size]=value;
        size++;
    }
    else{
        values[index]=value;
    }
}



int get(char key[]){
    int index=getindex(key);
    if(index!=-1){
        return values[index];
    }
    else{
        return -1;
    }
}

void print(){
    for(int i=0;i<size;i++){
        printf("%s - %d \n",keys[i],values[i]);
    }
}



int main(){
    insert("hemanth",69);
    insert("nikhil",56);
    insert("hemanth",78);
   int y= getindex("nikhil");
    printf("\n%d",y);
    int k=get("hemanth");
    printf("\n%d\n",k);
    print();
}