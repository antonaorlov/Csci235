#include <iostream>

using namespace std;
bool Post::operator<(const Post &object) const{
    string user1=this->getUsername();
    string user2=object.getUsername();
    if(user2>user1){
        return true;
    }
    return false;
}

bool Post::operator>(const Post &object) const{
    string user1=this->getUsername();
    string user2=object.getUsername();
    if(user2>user1){
        return true;
    }
    return false;
}

template <typename ItemType> 
template <typename Comparator>
LinkedList<Post*> Newtwork<ItemType>::bSortByUsername(Comparator check, int *count){
    LinkedList<Post*>Listed(feed);
    Listed.bubbleSortPosts(check, count);
    return listed;
}

 template <typename ItemType> 
   void Network<ItemType>::printUsers(){
    Node<Post*>* posted = feed_.getHeadPtr(); //gets head pointer of feed original list
    while (posted != nullptr) { //while linked list of post didnt end
        //couts node of pointer item and its username
        std::cout<< posted->getItem()->getUsername()<< std::endl; 
        posted = posted->getNext(); //gets next node in linkedlist
    }

   }


template <typename ItemType>
template <typename Comparator>
void LinkedList<ItemType>::bubbleSortPosts(Comparator check, int* count){
    Node<itemType>*Item=head;
    bool swap=true;
    int next=1;
    while(swap &&(size>next)){
        swap==false;
        item=head;
        int i=0;
       while(i<size_-1){
           // for(int i=0;i<size_-next;i++){
                if( !(check(*(Item->getItem()), *(Item->getNext()->getItem()) ))) {
                 Node<ItemType>* nextNode = Item->getNext(); //next node gets next item of node
                 swapping(Item, nextNode); //swap current node with nextNode item
                 (*count)++;  //count increments for next node in linked list of Posts
                 swap = true; //swap occured
             } //end if loop
              i++;
              Item = Item->getNext(); //item gets next item of list
        } //end inside while loop
         next++; //next linked list post
        
    } //end first while loop
}

void LinkedList<ItemType>::swap(Node<ItemType>*one, Node<ItemType>*two){
    ItemType old= one->getItem();
    one->setItem(two->getItem());
    two->setItem(old);
}


