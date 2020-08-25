//p6 DeQueue
//Rowan Briggs
//May 15, 2018 - May 16, 2018
/* Description:
Implement a double ended queue (dequeue) :
•	insertLeft (int value)
•	insertRight (int value)
•	Beware and handle any wraparound issues
(pages 5,6,7)!!
 */
#include <iostream>
using namespace std;

class DeQueue {
private:
    int size, front, rear, number_items;
    int *queueArray;

public:
    DeQueue(int newSize) { //constructor
        size = newSize;
        queueArray = new int[size];
        front = 0; //front moves forward (+) upon remove
        rear = -1; //nothing there yet, rear moves forward (+) upon insert
        number_items = 0;
    }

    //assignment 2
    void insertLeft(int value){
        //deal with wraparound
        if(front == 0) {    //front is the only thing in the array
            front= size;
        }
        front--;
        queueArray[front] = value;
        number_items++;
    }

    //assignment 2
    void insertRight(int value){
        //deal with wraparound
        if(rear == size){
            rear = -1;
        }
        rear++;
        queueArray[rear] = value;
        number_items++;
    }

    int removeLeft(){
        int temp = queueArray[front++];
        if(front == size){
            front = 0;
        }
        number_items--;
        return temp;
    }

    int removeRight(){
        int temp = queueArray[rear--];
        if (rear == 0) {
            rear = size;
        }
        number_items--;
        return temp;
    }

    int peekFront() {
        return queueArray[front];
    }
    int peekRear(){
        return queueArray[rear];
    }
    bool isEmpty(){
        return (number_items == 0);
    }
    bool isFull(){
        return (number_items == size);
    }
    int qsize(){
        return number_items;
    }
    void showArray(){
        cout << "The array looks like:\n";
        for (int i = 0; i < number_items; i++) {
            cout << queueArray[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    DeQueue aQueue(5); //{   };                   front = 0, rear = -1

    cout << "Test 1\n";
    aQueue.insertLeft(15);
    aQueue.insertRight(25);
    cout << aQueue.peekFront() << " is in the front\n";
    cout << aQueue.peekRear() << " is in the rear\n";

    cout << "Test 2\n";
    aQueue.insertLeft(5);
    cout << aQueue.peekFront() << " is in the front\n";

    cout << "Test 3\n";
    aQueue.removeLeft();
    cout << aQueue.peekFront() << " is in the front\n";
    cout << aQueue.peekRear() << " is in the rear\n";

    cout << "Test 4\n";
    aQueue.insertRight(35);
    aQueue.insertRight(45);
    cout << aQueue.peekFront() << " is in the front\n";
    cout << aQueue.peekRear() << " is in the rear\n";

    cout << "Test 5\n";
    aQueue.insertRight(55);
    cout << aQueue.peekFront() << " is in the front\n";
    cout << aQueue.peekRear() << " is in the rear\n";

    cout << "Test 6\n";
    aQueue.removeLeft();
    cout << aQueue.peekFront() << " is in the front\n";
    cout << aQueue.peekRear() << " is in the rear\n";

    aQueue.showArray();

    cout << "Test 7\n";
    aQueue.removeRight();
    cout << aQueue.peekFront() << " is in the front\n";
    cout << aQueue.peekRear() << " is in the rear\n";
}
/* Output:
Test 1
15 is in the front
25 is in the rear
Test 2
5 is in the front
Test 3
15 is in the front
25 is in the rear
Test 4
15 is in the front
45 is in the rear
Test 5
15 is in the front
55 is in the rear
Test 6
25 is in the front
55 is in the rear
The array looks like:
25 35 45 55
Test 7
25 is in the front
45 is in the rear

Process finished with exit code 0
 */