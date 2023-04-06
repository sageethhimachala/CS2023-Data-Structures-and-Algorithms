#include <iostream>
#include <chrono>

using namespace std;

class Node {
public:
    int value;
    Node* nxt;
    
    Node(int val) {
        value = val;
        nxt = NULL;
    }
};

class Stack {
private:
    Node* head; 
    
public:
    Stack() {
        head = NULL;
    }

    bool is_empty() {
        return head == NULL;
    }

    void push(int val) {
        Node* new_node = new Node(val);
        if (is_empty()) {
            head = new_node;
        } else {
            new_node->nxt = head;
            head = new_node;
        }
    }

    int pop() {
        if (is_empty()) {
            cout << "Stack underflow" << endl;
            return -1; 
        } else {
            int val = head->value;
            Node* temp = head;
            head = head->nxt;
            delete temp;
            return val;
        }
    }
   
    void display() {
        if (is_empty()) {
            cout << "Stack is empty" << endl;
        } else {
            Node* curr = head;
            while (curr != NULL) {
                cout << curr->value <<endl;
                curr = curr->nxt;
            }
        }
    }
    
    int top() {
        if (is_empty()){
            cout << "Stack is empty" << endl;
        } else {
            return head->value;
        } 
    }
};

int main() {
    auto start = chrono::high_resolution_clock::now();
    Stack s;
    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    
    s.display();
    s.pop();
    s.pop(); 
    s.pop(); 
    s.pop(); 
    s.pop();
    
    s.display();
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    
    s.display();
    auto end = chrono::high_resolution_clock::now();
    auto time_taken = chrono::duration_cast<chrono::microseconds>(end-start).count();
    cout << "Time taken to execute: " << time_taken << " microseconds" << endl;
    return 0;
} 
