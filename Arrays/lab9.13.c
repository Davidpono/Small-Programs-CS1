#include <stdlib.h>
#include <stdio.h>
typedef struct author_t{
    char name[20];
    int birthyear;
    int publishings;

}author_t;
typedef struct book_t{
char name[20];
int year;
int numauth;
author_t * authors;
}book_t;

int main()
{

int numbooks,i , j;
book_t* bookarr;
scanf("%d", &numbooks);
bookarr = (book_t*)calloc(numbooks, sizeof(book_t));
{
    scanf("%s", bookarr[i].name);
    scanf("%d", &bookarr[i].year);
    scanf("%d", &bookarr[i].numauth);
    bookarr[i].authors = (author_t*)calloc(bookarr[i].numauth, sizeof(author_t));
    for(j=0; j < bookarr[i].numauth; j++)
    {
        scanf("%s", bookarr[i].authors[j].name);
        scanf("%d", &bookarr[i].authors[j].birthyear);
        scanf("%d", &bookarr[i].authors[j].publishings);
    }
    
}
for(i=0;i<numbooks ; i++)
{
free(bookarr[i].authors);
bookarr[i].authors = NULL;

}
free(bookarr);
bookarr = NULL;
}