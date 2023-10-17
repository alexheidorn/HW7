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
    int size(){ return data.size(); }
    bool empty() { return data.empty(); }
    void push(string v) { 
        if (currentFront == nextAvail){ //if queue is full
            cerr << "Queue is empty";
        }
        else if (data.empty()){
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
        if (data.empty()){ // next == -1
            cout << "Queue is empty";
        }
        else{
            currentFront = (currentFront + 1) % data.size();
            if (currentFront == nextAvail){ //if because empty
                currentFront = 0;
                nextAvail = -1;
            }
        }
        
    }
    string front() { return data[currentFront]; }
};

int main()
{
    Queue myQueue;
    myQueue.push("hi");
    myQueue.push("bruh");
    myQueue.front();
    myQueue.pop();
    myQueue.front();
}