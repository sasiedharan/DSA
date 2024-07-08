#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1 = nullptr, Node* back1 = nullptr) 
        : data(data1), next(next1), back(back1) {}
};

Node* convert(vector<int>& arr) {
    if (arr.empty()) return nullptr;
    
    Node* head = new Node(arr[0]);
    Node* mover = head;
    
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        temp->back = mover;
        mover = temp;
    }
    return head;
}
Node* Return_doublely_LL(vector<int>&arr){
    Node* head=new Node(arr[0]);
    Node* previous=head;
    if(head==NULL) return head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],NULL,previous);
        previous->next=temp;
        previous=previous->next;
    }
    return head;

} 
Node* Delete_K(Node* Head,int k) {
    if(Head==nullptr) return Head;
    if(Head->data==k){
        Node* temp=Head;
        Head=Head->next;
        delete temp;
        return Head;
    }
    Node* temp=Head;
    Node* previous=nullptr;
    while(temp!=nullptr){
        if(temp->data==k){
            previous->next=previous->next->next;
            free(temp);
            break;
        }   
        previous=temp;
        temp=temp->next;
}
    return Head;
}
Node* InsertVal(Node* Head,int Val,int k){
    if (Head == nullptr) {
        if(k==1){
        Head = new Node(Val);
        return Head;
        }
        return nullptr;
    }
    if(k==1){
        Node* newNode=new Node(Val,Head);
        return newNode;
    }
    int count=1;
    Node* temp = Head;
    Node* newNode=new Node(Val);
    while (temp!= nullptr) {
        count++;
        if(count==k){
            newNode->next=temp->next;
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
    return Head;
}
void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> arr = {1, 8, 9, 3};;
    Node* Head = convert(arr);
    Head = InsertVal(Head,9000,5);
    print(Head);
    return 0;
}
