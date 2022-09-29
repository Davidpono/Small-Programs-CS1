

#include <stdio.h>
#include <stdlib.h>
#define SUCCESS 1
#define FAILURE 0
#define TRUE (1==1)
#define FALSE (!TRUE)
#define DEFAULT_CAP 5
typedef struct ArrayList
{
   int size;
   int cap;
   int * values;
} ArrayList;
int expand(ArrayList *);
int add(ArrayList *, int);
int expand(ArrayList * al)
{
   int newCap = al->cap + 1;
   int * newValues = (int *) realloc(al->values, newCap * sizeof(int));
   // Check if allocation failed
   if (newValues == NULL)
   {
      return FAILURE;
   }
   // Update the array list
   al->cap = newCap;
   al->values = newValues;
   // Return a success!
   return SUCCESS;
}
int add(ArrayList * al, int value)
{
   // Check if array list is full
   if (al->cap == al->size)
   {
      // Try to expand the array list
      if (expand(al) == FAILURE)
      {
         return FAILURE;
      }
   }
   // Store the new value
   al->values[al->size] = value;
   al->size++;
   // Return a success
   return SUCCESS;







}
ArrayList * newArrayList()
{
   ArrayList * ret = (ArrayList *)calloc(1, sizeof(ArrayList));
   if (ret != NULL)
   {
      ret->values = (int *) calloc(DEFAULT_CAP, sizeof(int));
      ret->cap = DEFAULT_CAP;
      ret->size = 0;
      if (ret->values == NULL)
      {
         free(ret);
         ret = NULL;
      }
   }
   return ret;
}
int main()
{
   ArrayList * al;
   al = newArrayList();
   if (al == NULL)
      return 1;
   while (TRUE)
   {
      int val;
      scanf("%d", &val);
      if (val == -1)
         break;
      add(al, val);
   }
   return 0;
}





