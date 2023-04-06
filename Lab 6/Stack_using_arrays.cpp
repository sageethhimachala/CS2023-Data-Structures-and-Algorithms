#include <iostream>
#include<chrono>
using namespace std;

const int MAX_SIZE = 10;
class Stack {
private:
    int t;           
    int arr[MAX_SIZE]; 

public:
    
    Stack() {
        t = -1;
    }
    
    bool isEmpty() {
        if(t == -1){
           return true;
        }
        else{
           return false;
        }
    }
    
    bool isFull() {
        if(t == MAX_SIZE - 1){
           return true;
        }
        else{
            return false;
        }
    }
    
    void push(int val) {
        if (isFull()) {
            cout << "Stack overflow" << endl;
        } else {
            t++;
            arr[t] = val;
        }
    }
    
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return -1; 
        } else {
            int val = arr[t];
            t--;
            return val;
        }
    }
    void display(){
        for (int i=t;i>=0;i--){
            cout<<arr[i]<<endl;
        }
    }
    int stackTop(){
        if (t==-1){
            cout<<"stack is empty";
        }
        else{
            return arr[t];
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
    auto timeTaken = chrono::duration_cast<chrono::microseconds>(end-start).count();
    cout<<"Time taken to execute :"<<timeTaken<<"micro seconds"<<endl;
    return 0;
}
