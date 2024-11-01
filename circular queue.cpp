#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = NULL;
    }
};

class CircularQueue {
public:
    CircularQueue() {
        front = NULL;
        rear = NULL;
    }
    
    bool isEmpty() {
        return front == NULL;
    }
    
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
            rear->next = front; 
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front; 
        }
    }
    
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int removedValue = front->data;
        if (front == rear) { 
            delete front;
            front = rear = NULL;
        } else {
            Node* temp = front;
            front = front->next;
            rear->next = front; 
            delete temp;
        }
        return removedValue;
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            Node* temp = front;
            cout << "Queue elements ";
            do {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != front);
            cout << endl;
        }
    }

private:
    Node* front;
    Node* rear;
};

int main() {
    CircularQueue q;
    q.enqueue(6);
    q.enqueue(15);
    q.enqueue(20);
    q.enqueue(47);
    q.enqueue(69);
    

    q.display();

    q.dequeue();
    
    q.display();

    return 0;
}

