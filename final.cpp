#include <iostream>


using namespace std;
//ArrayBag
#ifndef ARRAY_BAG_H_
#define ARRAY_BAG_H_
template<class T>
class ArrayBag
{
public:
ArrayBag();
int getCurrentSize() const;
bool isEmpty() const;
bool add(const T& new_entry);
bool remove(const T& an_entry);
void clear();
bool contains(const T& an_entry) const;
int getFrequencyOf(const T& an_entry) const;
std::vector<T> toVector() const;
private:
static const int DEFAULT_CAPACITY = 200; // Maximum Bag size
T items_[DEFAULT_CAPACITY]; // Array of Bag items
int item_count_; // Current count of Bag items
/** @return index of target or -1 if target not found*/
int getIndexOf(const T& target) const;
}; //end ArrayBag
#endif

template<class T>
ArrayBag<T>::ArrayBag(){
    //initize private variables itemcount
    item_count_=0;
}

template<class T>
int ArrayBag<T>::getCurrentSize() const{
    //return current size priave variable due to being a getter
    return item_count_;
}

template<class T>
bool ArrayBag<T>::isEmpty() const{
    //check if item count exists
    return item_count_==0;
}

template<class T>
bool ArrayBag<T>::add(const T& new_entry){
    //check if there is room to add new entry. item_count<items_.size()
    if(item_count_<DEFAULT_CAPACITY){
        items_[item_count_]=new_entry;
        return true;

    }
    //Add new_entry into the items_ array at the end

    //increment item_count by 1
    item_count_++;
    //else return false
    return false;
}

template<class T> 
bool ArrayBag<T>::remove(const T& an_entry){
    //check if an_entry is in the array, bag not empty 
    if(!isEmpty() && getIndexOf(an_entry)>-1){
        item_count_--;
        items_[getIndexOf(an_entry)]=items_[item_count_];
    }
    //see where the index of an_entry is and return true
    //subtract itemcount by 1 if removed if true
    //set the badg of entry to the last item of the bag
}

template<class T>
int ArrayBag<T>::getFrequencyOf(const T& an_entry) const{
    //see if bag not empty and loop through array while < item_count_ and see if an Entry is in array
    int count=0;
    if(!isEmpty()){
        for(int i-0;i<item_count_;i++){
            if(an_entry==items_[i]){
                count++;
            }
        }
    }
    return count;
    //count it how many times occcurs
}

template<class T>
std::vector<T>ArrayBag<T>::toVector() const{
    std::vector<T> bag_contents;
    for(int i=0;i<item_count;i++){
        bag_contents.push_back(items_[i]));
    }
    return bag_contents;
}

template<class T>
int ArrayBag<T>::getIndexOf(const T& target) const{
    //loop through arrray check if target is in array return the index
    for(int i=0;i<item_count_;i++){
        if(target==item_(i)){
            return i;
        }
    }
    return -1;
}

template<class T>
void ArrayBag<T>::clear(){
    item_count=0;
}

template<class T>
bool ArrayBag<T>::contains(const T& an_entry) const{
    return getIndex(an_entry)>-1;
}










//Node Implementation
#ifndef NODE_H_
#define NODE_H_
template<class T>
class Node
{
public:
Node();
Node(const T& an_item);
Node(const T& an_item, Node<T>* next_node_ptr);
void setItem(const T& an_item);
void setNext(Node<T>* next_node_ptr);
T getItem() const;
Node<T>* getNext() const;
private:
T item_; // A data item
Node<T>* next_; // Pointer to next node
}; // end Node
#endif // NODE_H_

template<class T> //End Default
Node<T>::Node(){
    next_=nullptr;
}

template<class T> //End constructor
Node<T>::Node(const T& an_item){
    an_item=0;
}

template<class T> //End Constructor
Node<T>::Node(const T& an_item, Node<T>* next_node_ptr){
    item_=an_item;
    next_=next_node_ptr;
}

template<class T>
void Node<T>::setItem(const T& an_item){
    item_=an_item;
}

template<class T>
void Node<T>::setNext(Node<T>* next_node_ptr){
    next=next_node_ptr;
}

template<class T>
T Node<T>::getItem() const
{
 return item_;
} // end getItem

template<class T>
Node<T>* Node<T>::getNext() const
{
 return next_;
} // end getNext



//Array BAg implementation
//LinkedBag
#ifndef LINKED_BAG_H_
#define LINKED_BAG_H_
template<class F>
class LinkedBag
{
public:
LinkedBag();    //O(1) Efficient
 LinkedBag(const LinkedBag<F>& a_bag); // Copy constructor 
 ~LinkedBag(); // Destructor O(n) expensive
 int getCurrentSize() const; //O(1)
 bool isEmpty() const; //O(1)
 bool add(const T& new_entry); //O(1)
 bool remove(const T& an_entry); //O(n)
 void clear(); //O(n)
 bool contains(const T& an_entry) const; //O(n)
 int getFrequencyOf(const T& an_entry) const; // O(n)
 std::vector<F> toVector() const; // O(n)
private:
Node<F>* head_ptr_; // Pointer to first node
 int item_count_; // Current count of bag items
 // Returns either a pointer to the node containing a given entry
// or the null pointer if the entry is not in the bag.
Node<F>* getPointerTo(const T& target) const; //O(n)
}; //end LinkedBag
#endif


template<class F>
LinkedBag<F>::LinkedBag() : head_ptr_{nullptr},
item_count_{0}
{
} 

template<class F>
bool LinkedBag<F>::add(const T& new_entry){
    //make new node, let temp_ptr point to it
    Node<T>* new_node=new Node<T>;
    //Add new Entry as item of new node using SetItem
    new_node_ptr->setItem(new_entry);
    //set new node to point to head node
    new_node_ptr->setNext(head_ptr_);
    //head= new node
    head_ptr_=new_node_ptr;
    //item count +1 due to addign new node
    item_count_++;
    return true;

}
/*Create a new node and assign two pointers O(1)
What about adding to end of chain? O(n)
What about adding to front of array? O(1) or O(n)
No order Order*/

template<class T>
std::vector<T> LinkedBag<T>::toVector() const{
    //make an vector 
    std::vector<T> bag_contents;
    //make current node pointer equal to head pointer
    Node<T>* cur_ptr=head_ptr_;
    //while cur pointer is not in the end of the list
    while(cur_ptr!=nullptr){
        //push cur pointer item to bag content vector
        bag_contents.push_back(cur_ptr->getItem());
        //point current node to next node
        cur_ptr=cur_ptr->getNext();
    }
    //return vector
    return bag_contents;
}

template<class T>
Node<T>* LinkedBag<T>::getPointerTo(const T& an_entry) const
{
    //if entry not found is false
 bool found = false;
    // make current node poointer = head pointer
 Node<T>* cur_ptr = head_ptr_;
    //while found false and cur pointer is not at the end of the list
 while (!found && (cur_ptr != nullptr))
 {
    //if an entry euqlas to cur node item 
 if (an_entry == cur_ptr->getItem())
 found = true;
 else
 //if not go to next node
 cur_ptr = cur_ptr->getNext();
 } // end while
    //return current node
 return cur_ptr;
} // end getPointerTo

template<class T>
bool LinkedBag<T>::remove(const T& an_entry){
    //FInd the index of an_entry, the node
    Node<T>*entry_ptr=getPointerTo(an_entry);
    //Loop until entry_ptr not at end of list
    while(entry_ptr!=nullptr){
        //set the node of entry item to head pointer item
        entry_ptr->setItem(head_ptr_->getItem());
        //make delete node point ot head node
        Node<T>* node_delete=head_ptr_;
        //head node points to next node
        head_ptr_=head_ptr_->getNext();
        //node delete points to nullptr
        node_delete->setNext(nullPtr);
        //delete node
        delete node_delete;
        //set node delete to nullptr
        node_delete=nullptr;
        //count--
        item_count--;
        return true;
    }
    return false;
}

template<class T>
void LinkedBag<T>::clear(){
    //make new node delete point to head
    Node<T>* node_delete=head_ptr_;
    //while head not last in list
    while(head_ptr_!=nullptr){
        //head points to next node
        head_ptr_=head_ptr_->getNext();
        //delete node points to nullptr
        node_delete->SetNext(nullptr);
        //delete node
        delete node_delete;
        //node equals to head
        node_delete=head_ptr_;
    }
    item_count=0;
}


//Copy Constructor
template<class T>
LinkedBag<T>::LinkedBag(const LinkedBag<T>& a_bag){
    //get pointer node a_bag item count
item_count_=a_bag.item_count_;
    //new node origin equal to a_bag head pointer
Node<T>* origin_chainptr=a_bag.head_ptr_;
    //if origin is last in list head is nu,llptr
if(origin_chainptr==nullptr){
    head_ptr_=nullptr;
}
else{
    //make head new node
    head_ptr_= new Node<T>();
    //head ptr get item of origin points to next node
    head_ptr_->setItem(origin_chainptr->getNext());
 Node<T>* new_chain_ptr = head_ptr_; 
 orig_chain_ptr = orig_chain_ptr->getNext(); 
 while (orig_chain_ptr != nullptr)
 {
 T next_item = orig_chain_ptr->getItem();
 Node<T>* new_node_ptr = new Node<T>(next_item);
 new_chain_ptr->setNext(new_node_ptr);
 new_chain_ptr = new_chain_ptr->getNext();
 orig_chain_ptr = orig_chain_ptr->getNext();
 } // end while
 new_chain_ptr->setNext(nullptr); // Flag end of chain
 } // end if
} // end copy constructor

//Copy first node
head_ptr=new Node<T>();
head_ptr->setItem(origin_chain->getItem());

//copy remaining nodes
Node<T>* new_chain=head_ptr;
originchain=originchain->getNext();

while (orig_chain_ptr != nullptr)
 {
 // Get next item from original chain
 T next_item = orig_chain_ptr->getItem();
 // Create a new node containing the next item
 Node<T>* new_node_ptr = new Node<T>(next_item);
 // Link new node to end of new chain
 new_chain_ptr->setNext(new_node_ptr);
 // Advance pointer to new last node
 new_chain_ptr = new_chain_ptr->getNext();
 // Advance original-chain pointer
 orig_chain_ptr = orig_chain_ptr->getNext();
 } 

// For linked chain:
// - Traverse entire chain to copy ( n “steps”)
// - Traverse entire chain to destroy ( n “steps”)
// Preferred call by const reference:
// myFunction(const MyClass& object);
// But what if you want to modify object?
// Also, passing to function is not the only situation for copy
// (e.g., MyClass two = one;
//  or one = two;)
// 22
// O(n)
// O(n)

// lvalue = rvalue
// Examples:
// int x = 2;
// int y = x+1;
// x = y; both l values
// x = y + z;
// string msg = “hello”;
// bool pass = computeGrades(student);
// Lvalues can be referred to by name, pointer or lvalue reference: i.e. they have an
// address
// Rvalues are literals or temporary objects copied into or returned by functions, they
// don’t have an address and cannot have a value assigned to it
// Can have lvalue and rvalue of same type.

//move function converts lvalue to rvalue, allows efficient transfer of resources from moved object to another
void swap(vector<string>& x, vector<string>& y)
{
 vector<string> temp = std::move(x);
 x = std::move(y);
 y = std::move(temp);
}


//List Insert
template<class T>
bool List<T>::insert(size_t position, const T& new_element){
    //make new node containing new entry pointer to position
    Node<T>* new_node_ptr=new Node<T>(new_element);
    Node<T>* pos_ptr=getPointerTo(position);

    //if first is the only one in list
    if (first==nullptr){
        //new node is the only node
        new_node_ptr->setNext(nullptr);
        new_node_ptr->setPrevious(nullptr);
        first=new_node_ptrl;
        last=new_node_ptr;
    }

    //if po_ptr is first node
    else if(pos_ptr=first){
        new_node_ptr->setNext(first_);
        new_node_ptr->setPrevious(nullptr);
        first->setPrevious(new_node_ptr);
        first=new_node_ptr;
    }

    else if(pos_ptr=nullptr){
        new_node_ptr->setNext(nullptr);
        new_node_ptr->setPrevious(last);
        last->setNext(new_node_ptr);
        last=new_node_ptr;
    }

    else{
        new_node_ptr->setNext(pos_ptr);
        new_node_ptr->setPrevious(pos_ptr->getPrevious());
        pos_ptr->getPrevious()->setNext(new_node_ptr);
        pos_ptr->setPrevious(new_node_ptr);
    }
}

template < class T >
  bool List < T > ::remove(size_t position) {
    // get pointer to position
    Node < T > * pos_ptr = getPointerTo(position);
    if (pos_ptr == nullptr) // no node at position
      return false;
    else {
      if (pos_ptr == first_) {
        // Remove first node
        first_ = pos_ptr -> getNext();
        first_ -> setPrevious(nullptr);
        // Return node to the system
        pos_ptr -> setNext(nullptr);
        delete pos_ptr;
        pos_ptr = nullptr;
      }
     
      else if (pos_ptr == last_) {
        //remove last_ node
        last_ = pos_ptr -> getPrevious();
        last_ -> setNext(nullptr);
        // Return node to the system
        pos_ptr -> setPrevious(nullptr);
        delete pos_ptr;
        pos_ptr = nullptr;
      } else {
        //Remove from the middle
        pos_ptr -> getPrevious() -> setNext(pos_ptr -> getNext());
        pos_ptr -> getNext() -> setPrevious(pos_ptr -> getPrevious());
        // Return node to the system
        pos_ptr -> setNext(nullptr);
        pos_ptr -> setPrevious(nullptr);
        delete pos_ptr;
        pos_ptr = nullptr;
      }
      item_count_—;
      return true;
    }
  } // end remove 



template < class T >
  Node < T > * List < T > ::getPointerTo(size_t position) const {

    //make new find pointer node to nullptr
    Node <T>* find_ptr = nullptr; 

    //if position is in list
    if (position < item_count) {

      //findpointer becomes first pointer
      find_ptr = first_;

      // loop through position of list
      for (size_t i = 0; i < position; ++i) {

        //find pointer gtes next node
        find_ptr = find_ptr -> getNext();
      }
      //find_ptr points to the node at position
    }
    return find_ptr;
  } //end getPointerTo















//Exception HAnding

Exception Handling Syntax
try {
  //statement(s) that might throw exception
} catch (ExceptionClass1 identifier) {
  //statement(s) that react to an exception
  // of type ExceptionClass1
} catch (ExceptionClass2 identifier) {
  //statement(s) that react to an exception
  // of type ExceptionClass2
}
...

//Polymorphism
class Document {
  public:
    //Constructor, destructor
    virtual void convertToPixelArray() const = 0; //Pure virtual function
  virtual int getPriority() const = 0; //Pure virtual function
  virtual void convertToPixelArray() const override;
  virtual int getPriority() const override;
  private:
  //stuff here
}; //end Document
/*
  Abstract class
- Has at least one pure virtual function
- Cannot be instantiated because does not have
implementation for some/all its member functions
*/

//Polymorphism
Base * base_ptr = new Base;
Base * derived_ptr = new Derived;
// stuff here
base_ptr -> someMethod(); //calls Base function
derived_ptr -> someMethod(); // call Derived function - LATE BINDING!!!!

//inheritance
Base base_object;
Derived derived_object;
// stuff here
base_object.someMethod(); //calls Base function
derived_object.someMethod(); // calls Derived function - Overriding!!!

//override specifier
//Explicitly tell compiler you mean to override a function
//Compiler will check!
//Also self-documenting
class BaseClass {
  virtual void f(int);
};
class DerivedClass: public BaseClass {
  virtual void f(float) override; //Compile-time error
};

//final specifier
//- Prevents inheritance
//- Prevents deriving classes from overriding methods
class A {
  virtual void f();
};
class B: public A {
  void f() final override; //cannot override f()
};
class C: public B final //cannot inherit from C
{
  void f() override; //Error, f is final!
}
class D: public C {} //Error C is final!

/* 
Function call overhead
- C++ maintains virtual function tables that store
pointers to each virtual function
- Determine which function to call at execution time
by looking-up v-table of object being pointed to
Clever! But still
Slower
Extra space for v-tables
Overhead ->mark individual functions virtual to
take advantage of polymorphism only when
appropriate
Fully polymorphic inheritance would be overkill in
most cases
*/

//linear search O(n)
template < class Comparable >
  int linearSearch(const std::vector < Comparable > & a, const Comparable & value) {

  //start from beginnign of loop to end and see where value is
    for (int i = 0; i < a.size(); i++) {
      if (a[i] == value) {
        return i;
      }
    }
    return -1;
  }

  //bianry search Binary search is O(log(n))
  template < class Comparable >
  int binarySearch(const std::vector < Comparable > & v, const Comparable & x) {

      //low at 0 high last item
    int low = 0, high = v.size() - 1;

     //loop 
    while (low <= high) {

        //middle is (low+high)/2
      int mid = (low + high) / 2;

        //see if vector at index mid<x
      if (v[mid] < x)
        low = mid + 1; //search upper half

        //see if vector at index mid>x
      else if (v[mid] > x)
        high = mid - 1; // search lower half

      else
        return mid; //found
    }
    return -1; //not found
  }



  //Selection Sort run time is O( n2)
template <class Comparable>
void selectionSort(const std::vector<Comparable>& the_array)
{
int size = the_array.size();
// first = index of the first item in the subarray of items yet
// to be sorted;
// smallest = index of the smallest item found
for (int first = 0; first < size; first++)
{
// At this point, the_array[0 ...first-1] is sorted, and its
// entries are <= those in the_array[first ... size-1].
// Select the smallest entry in the_array[first ... size-1]
int smallest_index = findIndexOfSmallest(the_array, first, size);
// Swap the smallest entry, the_array[smallest_index], with
// the first in the unsorted subarray the_array[first]
std::swap(the_array[smallest_index], the_array[first]);
} // end for
} // end selectionSort

/*
A sorting algorithm is Stable if elements that are
equal remain in same order relative to each other
after sorting

If size of input increases by factor of 100
Execution time increases by factor of 10,000
T(100n) = 10,000T(n)
Assume n = 100,000 and T(n) = 17 seconds
Sorting 10,000,000 takes 10,000 longer
Sorting 10,000,000 entries takes ≈ 2 days
Multiplying input by 100 to go from 17sec to 2 days!!!
*/


//Bubble Sort run time is O(n2) Worst Case. O(n) best Case
template <class Comparable>
void bubbleSort(const std::vector<Comparable>& the_array)
{
int size = the_array.size();
bool swapped = true; // Assume unsorted
int pass = 1;
while (swapped && (pass < size))
{
swapped = false;
for (int index = 0; index < size - pass; index++)
{
// At this point, all entries in the_array[0 ... index-1]
// are <= the_array[index]
if (the_array[index] > the_array[index+1])
{
std::swap(the_array[index], the_array[index+1]); //swap
swapped = true; // indicates array not yet sorted
}// end if
} // end for
// Assertion: the_array[0 ... size-pass-1] < the_array[size-pass]
pass++;
} // end while
} // end bubbleSort


//Insertion Sort run time is O(n2) Worst Case. O(n) best case
template <class Comparable>
void insertionSort(const std::vector<Comparable>& the_array)
{
int size = the_array.size();
// unsorted = first index of the unsorted region,
// Initially, sorted region is the_array[0],
// unsorted region is the_array[1 ... size-1].
// In general, sorted region is the_array[0 ... unsorted-1],
// unsorted region the_array[unsorted ... size-1]
for (int unsorted = 1; unsorted < size; unsorted++)
{
// At this point, the_array[0 ... unsorted-1] is sorted.
// Keep swapping item to be inserted currently at the_array[unsorted]
// with items at lower indices as long as its value is >
int current = unsorted; //the index of the item currently being inserted
while ((current > 0) && (the_array[current - 1] > the_array[current]))
{
std::swap(the_array[current], the_array[current - 1]); // swap
current--;
} // end while
} // end for
} // end insertionSort

//Merge Sort is O(nlog n) best and worst case
void mergeSort(array)
{
if array size <= 1
return //base case
split array into left_array and right_array
mergeSort(left_array)
mergeSort(right_array)
merge(left_array, right_array, array)
}

//QuickSort O(n^2) worst case. O(n log n) best case
template <class Comparable>
void quickSort(const std::vector<Comparable>& the_array,int first, int last)
{
if (last - first + 1 < MIN_SIZE)
{
insertionSort(the_array, first, last);
}
else
{
// Create the partition: S1 | Pivot | S2
int pivot_index = partition(the_array, first, last);
// Sort subarrays S1 and S2
// Sort subarrays S1 and S2
quickSort(the_array, first, pivot_index);
quickSort(the_array, pivotIndex + 1, last);
} // end if
} // end quickSort





//Recursions reverse string O(n)
void recursiveReverse(string &str)
{
   stack<char> st;
   for (int i=0; i<str.length(); i++)
       st.push(str[i]);
 
   for (int i=0; i<str.length(); i++) {
       str[i] = st.top();
       st.pop();
   }      
}
// Driver program
int main()
{
    string str = "geeksforgeeks";
    recursiveReverse(str);
    cout << str; //skeegrofskeeg
    return 0;
}

int factorial(int n)
{
if (n == 0)
return 1;
else // n > 0, so n-1 >= 0. Thus, fact(n-1) returns (n-1)!
return n * factorial(n - 1); // n * (n-1)! is n!
} // end fact


bool findPath(map, origin, destination)
{
//mark origin as visited in map
if origin == destination
return true
else
for each unvisited city C reachable from origin
if findPath(map, C, destination)
return true
return false //recursive backtracking
}











//Stack O(n)
/*
A data structure representing a stack of things
Objects can be pushed onto the stack or
popped from the stack
LIFO: Last In First Out
Only top of stack is accessible (top), no other
objects on the stack are visible
*/
for(char ch : st)
{
if ch is an open parenthesis character
push it on the stack
else if ch is a close parenthesis character
if it matches the top of the stack
pop the stack
else
return unbalanced
// else it is not a parenthesis
}
if stack is empty
return balanced
else
return unbalanced

//Stack array
/*
size : O(1)
isEmpty: O(1)
push: O(1)
pop : O(1)
top : O(1
*/

//stack vector
/*size : O(1)
isEmpty: O(1)
push: O(1)
pop : O(1)
top : O(1)
*/

/* Vector
If it grows by 1, O(n2) over time (n pushes -
AMORTIZED ANALYSIS)
If it grows by 2, push takes roughly half the“steps”
but still O(n2) over time ( n pushes - AMORTIZED
ANALYSIS)
If it doubles its size, push takes O(1) over time (n
pushes - AMORTIZED ANALYSIS)
*/

/* Linked List
size : O(1)
isEmpty: O(1)
push: O(1)
pop : O(1)
top : O(1)
*/

#ifndef STACK_H_
#define STACK_H_
template<class T>
class Stack
{
public:
Stack();
~Stack(); // destructor
Stack(const Stack<T>& a_stack); //copy constructor
void push(const T& newEntry); // adds an element to top of stack
void pop(); // removes element from top of stack
T top() const; // returns a copy of element at top of stack
int size() const; // returns the number of elements in the stack
bool isEmpty() const; // returns true if no elements on stack false otherwise
private:
Node<T>* top_; // Pointer to top of stack
int item_count; // number of items currently on the stack
}; //end Stack
#include "Stack.cpp"
#endif // STACK_H_

//Implementation

//default constructor
template<class T>
Stack<T>::Stack(){
    top_=nullptr;
    item_count-=0;
}

template<class T>
Stack<T>::Stack(const Stack<T>& a_stack){
    //make origin node point to top of stack
    node<T>* originPtr=a_stack->top_;

    //if bag empty
    if(originPtr==nullptr){
        top_=nullptr;
    }
    else{
        //copy first node
        top_=new Node<T>():
        top_->SetItem(orig_chain_ptr->getItem());

        //new node equals to top node of stack
        Node<T>* new_chain_ptr=top_;

    while(orig_chain_ptr!-nullptr){
        //origin points to next node in stack
        orig_chain_ptr=orig_chain_ptr->getNext();

        T next_=orig_chain_ptr->getItem();
        // Create a new node containing the next item
        Node<T>* newNodePtr = new Node<T>(nextItem);
        // Link new node to end of new chain
        newChainPtr->setNext(newNodePtr);
        // Advance pointer to new last node
        newChainPtr = newChainPtr->getNext();
    }
    }
}

template< class ItemType>
LinkedStack<ItemType>::~LinkedStack()
{
// Pop until stack is empty
while (!isEmpty())
pop();
} // end destructor


template< class ItemType>
bool LinkedStack<ItemType>::isEmpty() const
{
return topPtr == nullptr ;
} // end isEmpty


template< class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newItem)
{
    //make new node having newItem and top pointer node
Node<ItemType>* newNodePtr = new Node<ItemType>(newItem, topPtr);
    //topPtr equals newNode
topPtr = newNodePtr;
newNodePtr = nullptr;
return true;
} // end push


template< class ItemType>
bool LinkedStack<ItemType>::pop()
{
bool result = false ;
if (!isEmpty())
{
// Stack is not empty; delete top
Node<ItemType>* nodeToDeletePtr = topPtr;
topPtr = topPtr->getNext();
// Return deleted node to system

nodeToDeletePtr->setNext(nullptr);
delete nodeToDeletePtr;
nodeToDeletePtr = nullptr;

result = true ;
} // end if
return result;
} // end pop











//Queue
/*
A data structure representing a waiting line
Objects can be enqueued to the back of the line
or dequeued from the front of the line
FIFO: First In First Out
Only front of queue is accessible (front), no other
objects in the queue are visible
*/

#ifndef QUEUE_H_
#define QUEUE_H_
template<class T>
class Queue
{
public:
Queue();
void enqueue(const T& new_entry); // adds an element to back queue
void dequeue(); // removes element from front of queue
T front() const; // returns a copy of element at the front of queue
int size() const; // returns the number of elements in the queue
bool isEmpty() const; // returns true if no elements in queue, false otherwise
private:
static const int DEFAULT_SIZE = 100;; // Max queue size
T items_[DEFAULT_SIZE]; // the queue
int front_; // index of front of queue
int back_; // index of back of queue
int item_count; // number of items currently on the stack
}; //end Queue
#include "Queue.cpp"
#endif // QUEUE_H_ `


template< class ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType& newEntry)
{
Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
// Insert the new node
if (isEmpty())
frontPtr = newNodePtr; // The queue was empty
else
backPtr->setNext(newNodePtr); // The queue was not empty
backPtr = newNodePtr; // New node is at back
return true;
} // end 

template< class ItemType>
bool LinkedQueue<ItemType>::dequeue()
{
bool result = false;
if (!isEmpty())
{
// Queue is not empty; remove front
Node<ItemType>* nodeToDeletePtr = frontPtr;
if (frontPtr == backPtr)
{ // Special case: one node in queue
frontPtr = nullptr;
backPtr = nullptr;
}
else
frontPtr = frontPtr->getNext();
// Return deleted node to system
nodeToDeletePtr->setNext(nullptr);
delete nodeToDeletePtr;
nodeToDeletePtr = nullptr ;
result = true ;
} // end if
return result;
} // end dequeue











//Binary Trees
#ifndef BinaryTree_H_
#define BinaryTree_H_
template<class T>
class BinaryTree
{
public:
BinaryTree(); // constructor
BinaryTree(const BinaryTree<T>& tree); // copy constructor
~BinaryTree(); // destructor
bool isEmpty() const;
size_t getHeight() const;
size_t getNumberOfNodes() const;
void add(const T& new_item);
void remove(const T& new_item);
T find(const T& item) const;
void clear();
void preorderTraverse(Visitor<T>& visit) const;
void inorderTraverse(Visitor<T>& visit) const;
void postorderTraverse(Visitor<T>& visit) const;
BinaryTree& operator= (const BinaryTree<T>& rhs);
private: // implementation details here
}; // end BST
#include "BinaryTree.cpp"
#endif // BinaryTree_H_


search(bs_tree, item)
{
if (bs_tree is empty) //base case
item not found
else if (item == root)
return root
else if (item < root)
search(T L , item)
else // item > root
search(T R , item)
}

add(bs_tree, item)
{
if (bs_tree is empty) //base case
make item the root
else if (item < root)
add(T L , item)
else // item > root
add(T R , item)
}

inorder(bs_tree)
{
//implicit base case
if (bs_tree is not empty)
{
inorder(T L )
visit the root
inorder(T R )
}
}
/*
Operation              In Full        Tree Worst-case
Search                log2(n+1)            𝜪(h)
Add                   log2(n+1)            𝜪(h)
Remove                log2(n+1)            𝜪(h)
Traverse              n                    𝜪(n)
*/


//Binary Node
#ifndef BinaryNode_H_
#define BinaryNode_H_
#include <memory>
template<class T>
class BinaryNode
{
public:
BinaryNode();
BinaryNode(const T& an_item);
void setItem(const T& an_item);
T getItem() const;
bool isLeaf() const;
auto getLeftChildPtr() const;
auto getRightChildPtr() const;
void setLeftChildPtr(std::shared_ptr<BinaryNode<T>> left_ptr);
void setRightChildPtr(std::shared_ptr<BinaryNode<T>> right_ptr);
private:
T item_; // Data portion
std::shared_ptr<BinaryNode<T>> left_; // Pointer to left child
std::shared_ptr<BinaryNode<T>> right_; // Pointer to right child
}; // end BST
#include "BinaryNode.cpp"
#endif // BinaryNode_H_


template<class T>
BinaryNode<T>::BinaryNode(const T& an_item)
: item_(an_item){ } // end constructor


template<class T>
bool BinaryNode<T>::isLeaf() const
{
return ((left_ == nullptr) && (right_ == nullptr));
} // end isLeaf


template<class T>
void BinaryNode<T>::setLeftChildPtr(std::shared_ptr<BinaryNode<T>> left_ptr)
{
left_ = left_ptr;
} // end setLeftChildPtr

















#ifndef BST_H_
#define BST_H_
#include <memory>
template<class T>
class BST
{
public:
BST(); // constructor
BST(const BST<T>& tree); // copy constructor
~ BST(); // destructor
bool isEmpty() const;
size_t getHeight() const;
size_t getNumberOfNodes() const;
void add(const T& new_item);
void remove(const T& new_item);
T find(const T& item) const;
void clear();
void preorderTraverse(Visitor<T>& visit) const;
void inorderTraverse(Visitor<T>& visit) const;
void postorderTraverse(Visitor<T>& visit) const;
BST& operator= (const BST<T>& rhs);
private:
std::shared_ptr<BinaryNode<T>> root_ptr_;
}; // end BST
#include "BST.cpp"
#endif // BST_H_

template<class T>
BST<T>::BST(const BST<T>& tree)
{
root_ptr_ = copyTree(tree.root_ptr_); // Call helper function
} // end copy constructor

template<class T>
auto BST<T>::copyTree(const std::shared_ptr<BinaryNode<T>> old_tree_root_ptr) const
{
std::shared_ptr<BinaryNode<T>> new_tree_ptr;
// Copy tree nodes during a preorder traversal
if (old_tree_root_ptr != nullptr)
{
// Copy node
new_tree_ptr = std::make_shared<BinaryNode<T>>(old_tree_root_ptr
->getItem(), nullptr, nullptr);
new_tree_ptr->setLeftChildPtr(copyTree(old_tree_root_ptr->getLeftChildPtr()));
new_tree_ptr->setRightChildPtr(copyTree(old_tree_root_ptr
->getRightChildPtr()));
} // end if
return new_tree_ptr;
} // end copyTree

template<class T>
BST<T>::BST(const BST<T>&& tree)
{
root_ptr_ = tree.root_ptr_;
tree.root_ptr_.reset();
} // end move constructor

template<class T>
BST<T>::~BST()
{
destroyTree(root_ptr_); // Call helper function
} // end destructor

template<class T>
void BST<T>::destroyTree(std::shared_ptr<BinaryNode<T>> sub_tree_ptr)
{
if (sub_tree_ptr != nullptr)
{
destroyTree(sub_tree_ptr->getLeftChildPtr());
destroyTree(sub_tree_ptr->getRightChildPtr());
sub_tree_ptr.reset(); // same as sub_tree_ptr = nullptr for smart pointers
} // end if
} // end destroyTree

template<class T>
void BST<T>::clear()
{
destroyTree(root_ptr_); // Call helper method
} // end clear

template<class T>
int BST<T>::getHeight() const
{
return getHeightHelper(root_ptr_);
} // end getHeight

template<class T>
int BST<T>::getHeightHelper(std::shared_ptr<BinaryNode<T>> sub_tree_ptr) const
{
if (sub_tree_ptr == nullptr)
return 0;
else
return 1 + std::max(getHeightHelper(sub_tree_ptr->getLeftChildPtr()),
getHeightHelper(sub_tree_ptr->getRightChildPtr()));
} // end getHeightHelper

template<class T>
void BST<T>::add(const T& new_item)
{
auto new_node_ptr =
std::make_shared<BinaryNode<T>>(new_item);
placeNode(root_ptr_, new_node_ptr);
} // end add


template<class T>
auto BST<T>::placeNode(std::shared_ptr<BinaryNode<T>> subtree_ptr,
std::shared_ptr<BinaryNode<T>> new_node_ptr)
{
if (subtree_ptr == nullptr)
return new_node_ptr; //base case
else
{
if (subtree_ptr->getItem() > new_node_ptr->getItem())
subtree_ptr->setLeftChildPtr(placeNode(subtree_ptr->getLeftChildPtr(),
new_node_ptr));
else
subtree_ptr->setRightChildPtr(placeNode(subtree_ptr->getRightChildPtr(),
new_node_ptr));
return subtree_ptr;
} // end if
} // end placeNode

template<class T>
bool BST<T>::remove(const T& target)
{
bool is_successful = false;
// call may change is_successful
root_ptr_ = removeValue(root_ptr_, target, is_successful);
return is_successful;
} // end remove

template<class T>
auto BST<T>::removeValue(std::shared_ptr<BinaryNode<T>>
subtree_ptr, const T target, bool& success)
{
if (subtree_ptr == nullptr)
{
// Not found here
success = false;
return subtree_ptr;
}
if (subtree_ptr->getItem() == target)
{
// Item is in the root of this subtree
subtree_ptr = removeNode(subtree_ptr);
success = true;
return subtree_ptr;
}
else
{
if (subtree_ptr->getItem() > target)
{
// Search the left subtree
subtree_ptr->setLeftChildPtr(removeValue(subtree_ptr
->getLeftChildPtr(), target, success));
}
else
{
// Search the right subtree
subtree_ptr->setRightChildPtr(removeValue(subtree_ptr
->getRightChildPtr(), target, success));
}
return subtree_ptr;
} // end if
} // end removeValue

template<class T>
auto BST<T>::removeNode(std::shared_ptr<BinaryNode<T>> node_ptr)
{
// Case 1) Node is a leaf - it is deleted
if (node_ptr->isLeaf())
{
node_ptr.reset();
return node_ptr; // delete and return nullptr
}
// Case 2) Node has one child - parent adopts child
else if (node_ptr->getLeftChildPtr() == nullptr) // Has rightChild only
{
return node_ptr->getRightChildPtr();
}
else if (node_ptr->getRightChildPtr() == nullptr) // Has left child only
{
return node_ptr->getLeftChildPtr();
}
// Case 3) Node has two children:
else
{
T new_node_value;
node_ptr->setRightChildPtr(removeLeftmostNode(node_ptr->getRightChildPtr(),
new_node_value));
node_ptr->setItem(new_node_value);
return node_ptr;
} // end if
} // end removeNode

template<class T>
auto BST<T>::removeLeftmostNode(std::shared_ptr<BinaryNode<T>>
nodePtr, T& inorderSuccessor)
{
if (nodePtr->getLeftChildPtr() == nullptr)
{
inorderSuccessor = nodePtr->getItem();
return removeNode(nodePtr);
}
else
{
nodePtr->setLeftChildPtr(removeLeftmostNode(nodePtr->getLeftChildPtr(),
inorderSuccessor));
return nodePtr;
} // end if
} // end removeLeftmostNode


template<class T>
void BST<T>::preorderTraverse(Visitor<T>& visit) const
{
preorder(visit, root_ptr_);
} // end preorderTraverse
template<class T>
void BST<T>::inorderTraverse(Visitor<T>& visit) const
{
inorder(visit, root_ptr_);
} // end inorderTraverse
template<class T>
void BST<T>::postorderTraverse(Visitor<T>& visit) const
{
postorder(visit, root_ptr_);
} // end postorderTraverse


template<class T>
void BST<T>::inorder(Visitor<T>& visit,
std::shared_ptr<BinaryNode<T>> tree_ptr) const
{
if (tree_ptr != nullptr)
{
inorder(visit, tree_ptr->getLeftChildPtr());
T the_item = tree_ptr->getItem();
visit(the_item);
inorder(visit, tree_ptr->getRightChildPtr());
} // end if
} // end inorder

template<class T>
void BST<T>::preorderTraverse(Visitor<T>& visit) const
{
preorder(visit, root_ptr_);
} // end preorderTraverse
template<class T>
void BST<T>::inorderTraverse(Visitor<T>& visit) const
{
inorder(visit, root_ptr_);
} // end inorderTraverse
template<class T>
void BST<T>::postorderTraverse(Visitor<T>& visit) const
{
postorder(visit, root_ptr_);
} // end postorderTraverse











//pointers
shared_ptr
std::shared_ptr<Song> song_ptr1; //declaration only automatically set to nullptr
auto song_ptr2 = std::make_shared<Song>();// equivalent to Song* ptr = new Song()
//but creates manager and object in single memory allocation
// do stuff
std::cout << song_ptr2->getTitle() << std::endl;

weak_ptr
auto shared_song_ptr = std::make_shared<Song>();
std::weak_ptr<Song> weak_song_ptr1 = shared_song_ptr;
auto weak_song_ptr2 = weak_song_ptr1;

unique_ptr
auto song_ptr = std::make_unique<Song>();
std::unique_ptr<Song> another_song_ptr;
//declaration only automatically set to nullptr
another_song_ptr = song_ptr;
//ERROR!!! copy assignment not permitted with unique_ptr


































































































































































































