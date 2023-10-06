//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    void rearrange(struct Node *head)
    {
        //add code here
        int pos=1;
        Node* temp=head;
        Node* forward=head->next;
        Node* mark=head->next;
        Node* even=head->next;
        int count=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        temp=head;
        if(count%2==0) count=count-1;
        while(temp->next!=NULL)
        {
            
            if(pos%2==0 && pos==2)
            {
               temp->next=NULL;
            }
            else if(pos%2==0)
            {
                temp->next=even;
                even=temp;
            }
            else
            {
                if(pos!=count)
                temp->next=temp->next->next;
            }
            temp=forward;
            forward=forward->next;
            pos++;
            
        }
        temp->next=even;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends