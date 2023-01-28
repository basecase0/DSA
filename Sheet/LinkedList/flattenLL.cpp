//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/
Node* merge(Node* root1,Node* root2){
    Node* head=root1;
    if(root1->data>root2->data){
        head=root2;
        root2=root2->bottom;
    }
    else{
        root1=root1->bottom;
    }
    Node* tail=head;
    while(root1!=NULL && root2!=NULL){
        if(root1->data<root2->data){
            tail->bottom=root1;
            tail=root1;
            root1=root1->bottom;
        }
        else{
            tail->bottom=root2;
            tail=root2;
            root2=root2->bottom;
        }
    }
    if(root1){
        tail->bottom=root1;
    }
    else{
        tail->bottom=root2;
    }
    return head;
}

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
    Node* temp1=root;
    Node* curr=root;
    Node* mergeNode=root;
    while(curr!=NULL && curr->next!=NULL){
      Node* root1=curr;
      Node* root2=curr->next;
      Node* next=curr->next;
      Node* mergeNode=merge(root1,root2); 
      curr=mergeNode;
      if(next->next==NULL) break;
      curr->next=next->next;
    }
    return mergeNode;
}
