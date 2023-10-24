/*
* Alex Heidorn
* Teammates: Aidan Carlson, Anna Wolf, Toren Kalin, Samuel Draeger
* Created: 10-17-23
* CS2 HW7
*  
*/

/* Output:
Queue is empty
hi
bruh
bruh
Queue size: 4
Queue size: 8
eh
foo
bar
Queue is not empty.
lol
Queue is empty.
Queue is empty
Queue is empty
Queue is empty
hello there
Queue is not empty.
Queue size: 8
PS C:\Users\alexh\CS2> 
*/

#include <iostream> 
#include <vector>
#include <string>

using namespace std;

class Queue{
private:
    vector<string> data;
    int currentFront = 0; //current "front" of the queue
    int nextAvail = -1; //next available index location for newly pushed data
public:
    Queue(){
        data.resize(4);
    }
    void size(){ cout << "Queue size: " << data.size() << endl; }
    void empty() { 
        if (nextAvail == -1){ //if empty
            cout << "Queue is empty.\n";
        }
        else{
            cout << "Queue is not empty.\n";
        }
    }
    void push(string v) { 
        if (currentFront == nextAvail){ //if queue is full
            //cerr << "Queue is full\n";
            //add doubling process here!!!
            int oldSize = data.size();
            vector<string> temp;
            temp.resize(oldSize * 2);
            for (int i = 0; i < data.size(); i++){
                temp[i] = data[currentFront];
                currentFront = (currentFront + 1) % data.size();
            }
            data = temp;
            currentFront = 0;
            nextAvail = oldSize;
            

            //push item normally
            data[nextAvail] = v;
            nextAvail = (nextAvail + 1) % data.size();
        }
        else if (nextAvail == -1){ //queueue is empty
            data[0] = v;
            currentFront = 0;
            nextAvail = 1;
        }
        else{
            data[nextAvail] = v;
            nextAvail = (nextAvail + 1) % data.size();
        }
    }
    void pop(){
        if (nextAvail == -1){ // queue empty
            cout << "Queue is empty\n";
        }
        else{
            data[currentFront] = " ";
            currentFront = (currentFront + 1) % data.size();
            if (currentFront == nextAvail){ //if becomes empty
                currentFront = 0;
                nextAvail = -1;
            }
        }
        
    }
    void front() { 
        if (nextAvail == -1){ //if queue empty
            cerr << "Queue is empty\n";
        }
        else{
            cout << data[currentFront] << endl; 
        }
    }
};

int main()
{
    Queue myQueue;
    myQueue.front(); //queue is empty

    myQueue.push("hi");
    myQueue.push("bruh");

    myQueue.front(); //hi
    myQueue.pop();

    myQueue.front(); //bruh

    myQueue.push("eh");
    myQueue.push("foo");
    myQueue.push("bar");
    myQueue.front(); //bruh
    myQueue.size(); //4

    myQueue.push("lol");// double
    myQueue.size(); //8
    myQueue.pop();

    myQueue.front(); //eh
    myQueue.pop();

    myQueue.front(); //foo
    myQueue.pop();

    myQueue.front(); //bar
    myQueue.pop();
    myQueue.empty(); //not empty

    myQueue.front(); //lol
    myQueue.pop();
    myQueue.empty(); //empty

    myQueue.front(); // queue empty 
    myQueue.pop(); // ''

    myQueue.front(); // '' queue empty x4

    myQueue.push("hello there");
    myQueue.front(); //hello there
    myQueue.empty(); //not empty

    myQueue.push("lmao");
    myQueue.size(); //8
}