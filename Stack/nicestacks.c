#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

node *top;

void initialize()
{
    top = NULL;
}

void push(int value)
{
    node *tmp;
    tmp = malloc(sizeof(node));
    tmp -> data = value;
    tmp -> next = top;
    top = tmp;
   
}

int pop()
{
    node *tmp;
    int n;
    tmp = top;
    n = tmp->data;
    top = top->next;
    free(tmp);
    return n;
}

int Top()
{
    return top->data;
}

int isempty()
{
    return top==NULL;
}


int main()
{
    int choice=1, data=0, counter=0, counter2=0, brokenlinks=0,notbroken=0, counter1=0, fulllinks=0;
    initialize();
    node* max;
//printf("Enter data to push into stack: ");
    
    while(data>=0)
    {
        
    scanf("%d", &data);
    if(data==-1)
    {
        //printf("stackbroke\n");
        break;
    }

 
    if(isempty())
    {
        push(data);
        max=top;
        counter1++;
        counter++;
    } 
   
    else 
    {
        push(data);
        
        max->data=max->data-1;
        counter1++;
        counter++;
    } 
    if(max->data==-2){
        max=top;


    }
    if(max->data>top->data)
    {
        max=top;
       // printf("the new max is %d \n", top->data);
    }
  
//printf("the max %d \n", max->data);
    if(max->data==-1)
     {
    while(top!=max){
        pop();
        counter2++;
        fulllinks++;
    
        if(top->data-counter2==-1){
                 brokenlinks++;
           // printf("link fully broke\n");
        }
         if(top==max){
             brokenlinks++;
             fulllinks++;
              //printf("your stack size should be %d \n", counter1);
             // printf("youve poped %d \n",counter2+1);
            printf("Chain broke at link %d. New height is %d \n",counter, (counter1)-(counter2+1));
            counter1=(counter1)-(counter2+1);
            counter2=0;
           // printf("%d\n", counter1);
            break;
        }
    }
    
}
    }
    fulllinks=fulllinks-brokenlinks;
    printf("The ending chain height is %d\n",counter-(brokenlinks+fulllinks));
printf("There are %d broken links and %d whole links on the floor\n", brokenlinks,fulllinks);

}
