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
    int first;
    int next;
public:
    Queue(){
        data.resize(4);
        first = 0;
        next = -1;
    }
    int size(){ return data.size(); }
    bool empty() { return data.empty(); }
    void push(string v) { 
        if (first == next){
            cerr 
        }
    }
    void pop()
    void front() { }
};

int main()
{
    cout << "Hello World!\n";

    return 0;
}