#include <iostream>
using namespace std;

const int queue_capacity = 5;

class CircularQueue {
public:
    CircularQueue() {
        front = rear = 0; 
    }
    
    bool isEmpty() {
        return front == rear; 
    }
    
    bool isFull() {
        
        if (rear + 1 == queue_capacity) {
            if (front == 0) {
                return true; 
            }
        } else if (rear + 1 == front) {
            return true; 
        }
        return false; 
    }
    
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is Full" << endl;
        } else {
            myArray[rear] = value; 
            rear++; 
            if (rear == queue_capacity) { 
                rear = 0;
            }
        }
    }
    
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1; 
        } else {
            int value = myArray[front];
            front++; 
            if (front == queue_capacity) { 
                front = 0;
            }
            return value; 
        }
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Queue elements ";
            for (int i = front; i != rear; ) { 
                cout << myArray[i] << " ";
                i++; 
                if (i == queue_capacity) { 
                    i = 0;
                }
                if (i == rear) break; 
            }
            cout << endl;
        }
    }

private:
    int myArray[queue_capacity];
    int front, rear;
};

int main() {
    CircularQueue q;
    q.enqueue(6);
    q.enqueue(12);
    q.enqueue(20);
    q.enqueue(47);
    q.enqueue(69);
    
    cout << "Queue " << endl;
    q.display();  

    q.dequeue();
    cout << "After one dequeue " << endl;
    q.display(); 

    
    q.enqueue(33);
   
    q.display();

    q.enqueue(50);
    
    q.display();

    return 0;
}


        
    
