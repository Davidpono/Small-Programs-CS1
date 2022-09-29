#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
int main(){
int n;
int i;
char *info[100];
printf("how many inputs?");   
scanf("%d", &n);
for(i=0; i<n; i++)
{
char *dowhat;


scanf("%c", dowhat);

if(strcmp(dowhat, "u ") == 0)
{
   printf("write a name with a symptom"); 

printf("Enter a string: ");
scanf("%9s", info);
}

else if(strcmp(dowhat, "q ") == 0){
printf("what symptom would you like to look for");
char *symptom = malloc(10);
printf("Enter a string: ");
scanf("%9s", symptom);
if (strstr(info, symptom) != NULL) {
    
    
    char splitStrings[10][10]; //can store 10 word
    int j,cnt;

    j=0; cnt=0;
    for(i=0;i<=(strlen(info));i++)
    {
       
        if(info[i]==' '||info[i]=='\0')
        {
            splitStrings[cnt][j]='\0';
            cnt++; 
            j=0;   
        }
        else
        {
            splitStrings[cnt][j]=info[i];
            j++;
        }
    }
}


    }

}
return 0;

}