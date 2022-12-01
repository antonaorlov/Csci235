#include <iostream>
#include <stack>
#include <queue>
using namespace std;




Stack Big O notation
Size: O(1)
isEmpty: O(1)
push: O(1)
pop: O(1)
top: O(1)
allocate new array: O(1)
copy elements in new array: O(n)
delete old array: O(1)

Vector Growth by 1, O(N^2) over time (n pushes)
Vector Growth by 2, push takes half the steps O(N^2)
Vector Growth doubles the size, O(1)

Array: O(1) for push pop, size is bounded
Vector: Size not bounded, 







void display_stack(stack<int> st);
void printQueue(queue<int> queue){
    while(!queue.empty()){
        cout<<queue.front();
        queue.pop(); //pops first item in queue
    }
    cout<<endl;
}

int main(){
stack<int> integer_stack;
integer_stack.push(2); //add to stack
integer_stack.push(3); //add on top of stack
integer_stack.push(4); //add on top of 3
cout<<integer_stack.top()<<endl; //outpus 4. LIFO element inserted last is retrieved first
while(!integer_stack.empty()){
    cout<<integer_stack.top()<<".";
    integer_stack.pop(); //removes top of stack item
}
int size=integer_stack.size();
cout<<size;

if(integer_stack.empty()){ //returns 1 true if empty. return 0 if false
    cout<<"true";
}
else{
    cout<<"false";
}

//queue
//FIFO first in first out

queue<int>myqueue;
myqueue.push(1);
myqueue.push(4);
myqueue.push(3);
cout<<"size is"<<myqueue.size()<<endl;
cout<<"first element is"<<myqueue.front()<<endl;
cout<<"last element is "<<myqueue.back()<<endl;
printQueue(myqueue);
}

