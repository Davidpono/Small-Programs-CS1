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
    //node *subtracting = top->next; // start from node below new node
    /*/while(subtracting!=NULL) { 
        subtracting->data = subtracting->data - 1; 
        subtracting = subtracting->next;
        
    }
    */
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

/*/void display( int counter,node *head)
{
   
   int counter2, counter3=0;
   int differ;

   node*lowest = head;
    node*crawler = head;
    node*crawler2=head;
    printf("%d \n", crawler->data);
    while (crawler->next != NULL)
    {
       
        crawler=crawler->next;
        if( crawler->data < -1){
            lowest=crawler;
            
            
        }
        counter3++;
        
     printf("the crawler has traversed this many times %d \n", counter3);
        printf("the lowest stack is %d \n", lowest->data);
       printf("%d \n", crawler->data);
        
        
    }
    while (crawler2->next != lowest)
    {  
        crawler2=crawler2->next;
        printf("helo\n");
        pop();
        counter2++;
        
    }
    
    printf("the count of the lowest is %d \n", counter3);
    printf("the lowest stack is %d \n", lowest->data);
    printf("the count is %d \n", counter);
    differ=lowest->data-counter3;
    printf("the difference %d\n", differ);
    if(differ<=-1){  
    for( int a = 0; a < counter3+1; a++){
  
        pop();
        counter2++;
}
    }
    printf("the pop count is %d \n", counter2);
  
}
*/
int main()
{
    int choice=1, data=0, counter, max, counter2;
    initialize();
printf("Enter data to push into stack: ");

while(data>=0)
{
    
scanf("%d", &data);
if(data==-1){

    break;
}
if(isempty()){
push(data);
top->data=max;
}
else {
    push(data);
    max=max-counter;
}
if(max>top->data){
counter=0;
max=top->data;
}
if(max==top->data){
counter2++;

}
if(max==-1);
{
    for(int i = 0; i<counter; i++){
        pop();
        printf("size of the array is ");
    }
}
    counter++;
}
}
/*/}
counter=counter-1;
printf("the count is %d \n", counter);
    node*copyofhead=top;
    //copyofhead->data--;
    
    printf("The top is %d and the imposter is %d\n",Top(), copyofhead->data);
    printf("The top after pop is %d\n",Top());
    
    display(counter, top);
   
    return 0;
}*/