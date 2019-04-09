#include<stdio.h>
#include<stdlib.h>
struct node
{
    int age;
    char name[20];
    char usn[20];
    char address[20];
    
    struct node *link;
};
typedef struct node *NODE;

NODE getnode();
void display(NODE head);
NODE insert_front(NODE head);
NODE insert_last(NODE head);
NODE insert_position(NODE head,int);
NODE delete_front(NODE head);
void delete_last(NODE head);
NODE delete_position(NODE head,int);
void search(NODE head,char []);
int main()
{
    NODE head=NULL;
    char name1[20];
    int num,ch,pos;
    printf("Please Enter the below choices to chose the operation\n");
    while(ch!=9)
    {
        printf("\n\n1:Insert at the front of list\n2:Display the list\n3:Insert at last of the list\n4:Delete first node of list\n5:Delete last node\n6:Insert at any position\n7:Delete at any position\n8:Search an Element\n9:Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head=insert_front(head);
                    break;
            case 2: display(head);
                    break;
            case 3: head=insert_last(head);
                    break;
            case 4: head=delete_front(head);
                    break;
            case 5: delete_last(head);
                    break;
            case 6: printf("Enter the position you want to insert into list\n");
                    scanf("%d",&pos);
                    head=insert_position(head,pos);
                    break;
            case 7: printf("Enter the position to be deleted\n");
                    scanf("%d",&pos);
                    delete_position(head,pos);
                    break;
            case 8: printf("Enter name to be searched\n");
                    scanf("%s",name1);
                    search(head,name1);
                    break;
            default: printf("Enter the correct choice\n");
                    break;
        }

    }
}
NODE getnode()
{
    NODE temp;
    temp = malloc(sizeof(struct node));
	
    printf("Enter the student details into list\n");
    printf("USN:");
    scanf("%s",temp->usn); 
    printf("\n");
    printf("Name:");
    scanf("%s",temp->name);
    printf("\n");
    printf("Age:");
    scanf("%d",&temp->age);
    printf("\n");
    printf("Address:");
    scanf("%s",temp->address);
    printf("\n");
    temp->link = NULL;
    return temp;
}

NODE insert_front(NODE head)
{
    NODE new_node;
    new_node = getnode();
    if(head==NULL)
	head=new_node;
    else
    {
	new_node->link = head;
        head = new_node;
    }
    return head;
}
void display(NODE head)
{
    NODE temp;
    if(head==NULL)
    {
        printf("List is Empty\n");
        exit(0);
    }
    temp = head;
    printf("The Contents of the list is as below:\n");
    while(temp != NULL)
    {
        //printf("Entered AGE,Name and Address into list\n");
        printf("AGE:%d\t Name:%s\t Address:%s\n",temp->age,temp->name,temp->address);
        temp = temp->link;
    }
    printf("\n");
}
NODE insert_last(NODE head)
{
    NODE new_node,cur;
    new_node = getnode();
    new_node->link = NULL;
    if(head == NULL)
    {
        return new_node;
    }
   
     cur = head;
    while(cur->link!=NULL)
    {
        cur = cur->link;
    }
    cur->link = new_node;
    return head;
}
NODE insert_position(NODE head,int pos)
{
    int count=0;
    NODE new_node,cur,prev;
    new_node = getnode();
    new_node->link = NULL;
    if(head == NULL && pos==1)
    {
        return new_node;
    }
    if(head == NULL)
    {
        printf("Invalid Position\n");
        return head;
    }
    if(pos==1)
    {
        new_node->link=head;
	return new_node;
    }
    count = 1;
    prev = NULL;
    cur = head;
    while(cur->link!= NULL && count!=pos)
    {
        prev = cur;
        cur = cur->link;
        count++;
    }
    if(count==pos)
    {
        prev->link = new_node;
        new_node->link =cur;
        return head;

    }

}
NODE delete_front(NODE head)
{
    NODE temp;
    if(head==NULL)
    {
        printf("List is empty\n");
        return head;
    }
    temp = head;
    head = head->link;
    printf("First Node deleted is:%d\n",temp->age);
    free(temp);
    return head;

}
void delete_last(NODE head)
{
    NODE cur,prev;
    if(head == NULL)
    {
        printf("List is empty\n");
        exit(0);
    }
    cur = head;
    while(cur->link!=NULL)
    {
        prev=cur;
        cur = cur->link;
    }
    printf("Last Node deleted is:%d",cur->age);//prev->link=NULL;
    free(cur);
    prev->link=NULL;
    //return head;

}
NODE delete_position(NODE head,int pos)
{
    int count=0;
    NODE new_node,cur,prev;
    if(head == NULL && pos<=0)
    {
        printf("Invalid Position\n");
        return NULL;
    }
    if(pos==1)
    {
        cur = head;
        head = head->link;
        free(cur);
        return head;
    }
    count = 1;
    prev = NULL;
    cur = head;
    while(cur!= NULL)
    {
        if(count==pos)
            break;
        prev = cur;
        cur = cur->link;
        count++;
    }
    if(count!=pos)
    {
        printf("Invalid count Position\n");
        return head;
    }
    prev->link = cur->link;
    free(cur);
    return head;
}
void search(NODE head,char name[20])
{
    NODE cur;
    int count=0;
    if(head == NULL)
    {
        printf("List is empty\n");
        exit(0);
    }
    cur = head;
    while(cur->name!=name)
    {
        cur = cur->link;
        count++;
    }
    if(cur->name==name)
    {
        printf("Key element found at position:%d\n",count+1);
    }
}
