#include <iostream>

class CircularQueue {
private:
    int* queue;
    int front;
    int rear;
    int capacity;

public:
    CircularQueue(int size) {
        capacity = size;
        queue = new int[capacity];
        front = -1;
        rear = -1;
    }

    ~CircularQueue() {
        delete[] queue;
    }

    void enqueue(int value) {
        if ((front == 0 && rear == capacity - 1) || (rear == (front - 1) % (capacity - 1))) {
            std::cout << "Queue is full. Cannot enqueue " << value << std::endl;
            return;
        }
        else if (front == -1) {
            front = rear = 0;
            queue[rear] = value;
        }
        else if (rear == capacity - 1 && front != 0) {
            rear = 0;
            queue[rear] = value;
        }
        else {
            rear++;
            queue[rear] = value;
        }
    }

    int dequeue() {
        if (front == -1) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return -1;
        }

        int value = queue[front];
        queue[front] = -1;

        if (front == rear) {
            front = rear = -1;
        }
        else if (front == capacity - 1) {
            front = 0;
        }
        else {
            front++;
        }

        return value;
    }

    void display() {
        if (front == -1) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }

        std::cout << "Queue elements: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                std::cout << queue[i] << " ";
            }
        }
        else {
            for (int i = front; i < capacity; i++) {
                std::cout << queue[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                std::cout << queue[i] << " ";
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    int size;
    std::cout << "Enter the size of the circular queue: ";
    std::cin >> size;

    CircularQueue cq(size);

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);

    cq.display();

    std::cout << "Dequeued element: " << cq.dequeue() << std::endl;

    cq.display();

    return 0;
}
