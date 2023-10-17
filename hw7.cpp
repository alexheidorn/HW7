/*
* Alex Heidorn
* Teammates: Aidan Carlson, Anna Wolf
* Created: 10-17-23
* CS2 HW7
*  
*/

#include <iostream> 
#include <vector>
#include <string>

using namespace std;

class Queue{
private:
    vector<string> data;
    int currentFront = 0;
    int nextAvail = -1;
public:
    Queue(){
        data.resize(4);
    }
    bool empty() { return data.empty(); }
    void push(string v) { 
        if (currentFront == nextAvail){ //if queue is full
            cerr << "Queue is full\n";

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
            if (currentFront == nextAvail){ //if because empty
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
    myQueue.front();

    myQueue.push("hi");
    myQueue.push("bruh");
    myQueue.front(); //hi

    myQueue.pop();
    myQueue.front(); //bruh

    myQueue.push("eh");
    myQueue.push("foo");
    myQueue.push("bar");
    myQueue.front(); //bruh

    myQueue.push("lol"); //full

    myQueue.pop();
    myQueue.front(); //eh

    myQueue.pop();
    myQueue.front(); //foo

    myQueue.pop();
    myQueue.front(); //bar

    myQueue.pop();
    myQueue.front(); //empty?? //front should NOT work

    myQueue.pop();
    myQueue.front(); 

    myQueue.pop();
    myQueue.front();

    myQueue.push("hello there");
    myQueue.front();
}
//need to fix push so it doubles & size & rearranges
//need to fix pop to fully remove the elements