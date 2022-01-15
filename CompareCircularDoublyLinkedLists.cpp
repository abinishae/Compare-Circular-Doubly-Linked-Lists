#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

Node *newNode(int data) {
    Node *temp = new Node(data);

    return temp;
}

int getLength(Node *head) {
    Node *temp = head;

    int count = 0;
    while (temp->next != head) {
        count++;
        temp = temp->next;
    }
    return count + 1;
}


 


class Solution{
    public:
    bool compareCLL(Node* h1, Node* h2) {
            
        Node*c=h1, *d=h2;
        while(h1->next != c && h2->next != d){
          if(h1->data != h2->data)
             return 0;
    
         h1=h1->next;
         h2=h2->next;
     }
     if( (h1->next== c && h2->next == d))
      if(h1->data == h2->data)
       return 1;
       
      return 0;
  
  
    }
};




void makeCircular(Node *head) {
    Node *temp = head;

    while (temp->next) {
        temp = temp->next;
    }

    temp->next = head;
    head->prev = temp;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n1;
        cin >> n1;
        Node *head1 = NULL, *tail1 = NULL;
        int x1;
        cin >> x1;
        head1 = newNode(x1);
        tail1 = head1;

        for (int i = 0; i < n1 - 1; i++) {
            cin >> x1;
            Node *temp = newNode(x1);
            tail1->next = temp;
            temp->prev = tail1;
            tail1 = temp;
        }

        int n2;
        cin >> n2;
        Node *head2 = NULL, *tail2 = NULL;
        int x2;
        cin >> x2;
        head2 = newNode(x2);
        tail2 = head2;

        for (int i = 0; i < n2 - 1; i++) {
            cin >> x2;
            Node *temp = newNode(x2);
            tail2->next = temp;
            temp->prev = tail2;
            tail2 = temp;
        }

        makeCircular(head1);
        makeCircular(head2);
        Solution ob;
        cout << ob.compareCLL(head1, head2);

        cout << endl;
    }
    return 0;
}  
