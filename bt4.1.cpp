#include <iostream> 
using namespace std;
struct Node { 
    int data; 
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

/*
Ho va ten: Nguyen Hoang Nam
MSSV: 20225213
Ma lop: 738920
*/

// push a new element to the beginning of the list
Node* prepend(Node* head, int data) {
    Node *newNode = new Node(data);
    newNode->next = head;
    return newNode;
}

// print the list content on a line
void print(Node* head) {
    while(head != nullptr){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// return the new head of the reversed list
Node* reverse(Node* head) {
    Node *temp = head;
    Node *prev = nullptr;
    while(temp != nullptr){
        Node *nextTemp = temp->next; //Lưu Node kế tiếp
        temp->next = prev; //Đảo ngược liên kết
        prev = temp; //Di chuyển prev lên Node hiện tại
        temp = nextTemp; //Di chuyển temp lên Node kế tiếp
    }
    return prev;
}


  
int main() {
    int n, u;
    cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; ++i){
        cin >> u;
        head = prepend(head, u);
    } 
    
    cout << "Original list: ";
    print(head);

    head = reverse(head);
    
    cout << "Reversed list: ";
    print(head);

    return 0; 
}