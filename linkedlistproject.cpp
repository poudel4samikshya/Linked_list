//
// Created by samikshya poudel on 4/6/21.
//



#include <iostream>
using namespace std;

struct node{
    string name;
    double gpa;
    int ID;
    node *next; //pointer to the node next
};
node *head=NULL;

bool isempty(node* head)
{
    if(head == NULL)
        return true;
    else
        return false;

}
void insert_asfirstelement(node * &head,node* &last,int value,string name,double GPA)
{
    node *temp = new node;
    temp->ID=value;
    temp->name=name;
    temp->gpa=GPA;
    temp->next = NULL;
    head =temp;
    last = temp;

}

void insert (node * &head,node* &last,int value,string name,double GPA )
{

    node *temp1=new node;
    node *temp2=new node;
    //node * tempb=new node;
    node *temp=new node;
    //prompt to enter input
    temp->ID=value;
    temp->name=name;
    temp->gpa=GPA;
    temp1=head;
    temp2=temp1->next;

    if(temp->ID<temp1->ID)
    {
        head=temp;
        temp->next=temp1;
    }
    else
    {
        temp1->next=temp;
        temp->next=temp2;


        if(temp2 != NULL)
        {

            while(temp->ID>temp2->ID)
            {


                temp1->next=temp2;
                temp1=temp2;
                temp2=temp2->next;


                temp->next = temp2;
                temp1->next=temp;
                if(temp2==NULL)
                    break;
            }
        }

    }
}


void remove ()
{    node* del = new node;
    node*previous= new node;
    del = head;
    previous = head;
    int id;
    cout<<"please enter the ID which you wanna delete?"<<endl;
    cin>>id;

    if (isempty (head))
        cout<<" the list is already empty "<<endl;
    else
    {
        while(del->ID!=id)//moving delete pointer
        {
            del=del->next;
            if (del->next ==NULL && del->ID!=id)
            {
                cout<<"Invalid ID! Enter again "<<endl;
                cin>>id;
                del = head;
            }
        }
        if (del!=head)
        { while (previous->next!=del)
            {
                previous = previous->next;
            }

            previous->next=del->next;
            delete del;
        }
        else
        {
            previous =del;
            del=del->next;
            head =del;
            delete previous;
        }
    }
    cout<<" Node is sucessfully removed"<<endl;
}


void showlist ()
{
    node * tempo=new node;
    tempo=head;

    if(tempo==NULL)
        cout<<"The linklist is empty"<<endl;
    else
    {
        cout<<"Linked list:"<<endl;
        do{
            cout<<"ID: "<<tempo->ID<<" Name: "<<tempo->name<<" GPA: "<<tempo->gpa<<endl;
            tempo=tempo->next;

        }while(tempo!=NULL);

    }
}

int main()
{
    // node*head = NULL;
    node*last = NULL;
    int option;
    char repeat = 'y';
    int id;
    string name;
    double gpa=0;

    do{
        cout<<" 1.Insert 1st element "<<endl;
        cout<<" 2.Insert  element "<<endl;
        cout<<" 3.Delete element "<<endl;
        cout<<" 4.show list "<<endl;
        cin>>option;

        switch(option)
        {
            case 1:
                cout<<"please enter your ID you wanna Insert"<<endl;
                cin>>id;
                cout<<"enter name"<<endl;
                cin>>name;
                cout<<"enter gpa"<<endl;
                cin>>gpa;
                insert_asfirstelement(head,last,id,name,gpa);
                break;
            case 2:
                cout<<"please enter your ID you wanna Insert"<<endl;
                cin>>id;
                cout<<"enter name"<<endl;
                cin>>name;
                cout<<"enter gpa"<<endl;
                cin>>gpa;
                if (isempty (head))
                    insert_asfirstelement( head,last,id,name,gpa);
                else
                    insert(head,last,id,name,gpa);
                break;
            case 3: remove();
                break;
            case 4: showlist ();
                break;
            default:
                cout<<" exiting "<<endl;

        }
        cout<<"to repeat please enter y and to Quit enter any key : ";
        cin>>repeat;
    }while(repeat == 'y');


    return 0;
}







