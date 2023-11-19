//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    if(n)
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    else cout<< " ";
}


// } Driver Code Ends
/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution
{
    public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code goes here.
        Node *ptr = head1;
        Node *ptr1 = head2;
        unordered_map<int, int> mp;
        while(ptr!=nullptr){
            mp[ptr->data]++;
            ptr=ptr->next;
        }
        vector<int> v;
        while(ptr1!=nullptr){
            if (mp.find(ptr1->data)!=mp.end() and mp[ptr1->data]>0) {
                v.push_back(ptr1->data);
                mp[ptr1->data]--;
            }
            ptr1=ptr1->next;
        }
        if (v.size()==0) return NULL;
        Node *np;
        np = new Node(v[0]);
        Node *pp = np;
        for(int i=1; i<v.size(); i++){
            Node *nn; 
            nn = new Node(v[i]);
            pp->next=nn;
            pp=nn;
        }
        return np;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Solution ob;
	    Node* result = ob.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends