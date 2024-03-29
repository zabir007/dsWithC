#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list *next;
};

// prototype
void display(struct list*);
void countNode(struct list*);
void addEnd(struct list*, int);
void addBegin(struct list **, int);
void addAnyPos(struct list*, int, int);
void delFirst(struct list**);
void delLast(struct list*);
void delAnyPos(struct list**, int);
struct list* reverse(struct list*);
struct list* delList(struct list*);

int main()
{
    struct list *head = NULL;
    head =(struct list*)malloc(sizeof(struct list));
    head->data=40;
    head->next=NULL;

    addBegin(&head,30);
    addEnd(head,50);
    addAnyPos(head,35,2);

    delAnyPos(&head,1);
    printf("print list: ");
    display(head);

    head = reverse(head);
    printf("reverse list: ");
    display(head);

    head = delList(head);
    delList(head);


    return 0;
}


// define function-> as below
// display node
void display(struct list *head)
{
    if (head==NULL)
        printf("linked list is empty");

    struct list *ptr = NULL;
    ptr = head;

    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    } 
    printf("\n");
}

// count of node
void countNode(struct list *head)  
{
    int count = 0;
    if (head==NULL)
        printf("linked list is empty");

    struct list *ptr = NULL;
    ptr = head;

    while (ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    } 
    printf("%d",count);
}

// add at the end
void addEnd(struct list *head, int data)
{
    struct list *ptr, *temp;
    ptr = head;
    temp = (struct list*)malloc(sizeof(struct list));

    temp->data=data;
    temp->next=NULL;

    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=temp;
    
}

// add at the begining
void addBegin(struct list **head, int data)
{
    struct list* temp = (struct list*)malloc(sizeof(struct list));
    temp->data=data;
    temp->next=NULL;
    temp->next=*head;
    *head=temp;
}

// add at any position
void addAnyPos(struct list* head, int data, int pos)
{
    struct list *ptr, *var;
    ptr = head;
    var = malloc(sizeof(struct list));
    var->data = data;
    var->next = NULL;

    pos--;
    while (pos!=1)
    {
        ptr=ptr->next;
        pos--;
    }

    var->next=ptr->next;
    ptr->next=var;
    
}

// delet first
void delFirst(struct list** head)
{
    if(*head==NULL)
        printf("list is empty: ");
    struct list *temp = *head;
    *head = temp->next;
    free(temp);
    temp=NULL;
}


// delet last node
void delLast(struct list* head)
{
    if(head==NULL)
        printf("list is empty: ");

    else if (head->next==NULL) {
        free(head);
        head = NULL;
    }  

    else {
        
        struct list *temp = head;
        while (temp->next->next!=NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}


// delet any position
void delAnyPos(struct list** head, int pos) {
    struct list *current, *previous;
    current = previous = *head;

    if(*head==NULL)
        printf("linked list is empty");

    else if(pos==1) {
        *head = current->next;
        free(current);
        current = NULL;
    }

    else {
        while (pos!=1)
        {
            previous = current;
            current = current->next;
            pos--;
        }
        previous->next = current->next;
        free(current);
        current = NULL;
    } 
}

// delet entire list
struct list* delList(struct list* head)
{
    struct list *temp = head;

    while (temp!=NULL)
    {
        temp = temp->next;
        free(head);
        head = temp;
    }
    return head;
}

// reverse list
struct list* reverse(struct list* head)
{
    struct list *prev, *curr;
    prev = curr = NULL;

    while (head != NULL)
    {
        curr = head->next;
        head->next = prev;
        prev = head;
        head = curr;
    }
    head = prev;
    return head;
}


