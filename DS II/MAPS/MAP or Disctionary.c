#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char keys[100][100];  // Use const char* keys[100] instead

// const char* keys[100]
int values[100];
int size=0;

int getindex(char key[])
{
    for(int i=0;i<size;i++)
    {
        if(strcmp(keys[i],key)==0)
        return i;
    }

    return -1;
}

void insert(char key[],int value)
{
    int index=getindex(key);
    if(index==-1)
    {
        strcpy(keys[size],key);
        values[size]=value;     // Creating a new pair 
        size++;
    }
    else
    {
        values[index]=value; // Updating the pair 
    }
}

int get(char key[])
{
     int index=getindex(key);
     if(index==-1)
     return -1;
     else
     {
        return values[index];
     }
}


void print()
{
    for(int i=0;i<size;i++)
    printf("\n%s--%d",keys[i],values[i]);
}

int main()
{
    insert("hi",69);
    insert("hello",78);
    insert("hi",34);
    int y=getindex("hi");
    printf("\n%d",y);

    int k=get("hello");
    printf("\n%d",k);
    print();
}