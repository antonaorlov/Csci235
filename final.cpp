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
















