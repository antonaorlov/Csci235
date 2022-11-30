#include <iostream>

using namespace std;

//Network class and Accoutn class store pointers to Post
//in linkedlist	
linkedlist<Post*> feed; //Network
linkedlist<Post*> posts; //Account

template<typename ItemType>
bool linkedlist<ItemType>::insert(const ItemType &item, const int &position){
	Node<ItemType>*node=new Node<ItemType>; //create new node
	node_>setItem(item); //set node item
	if(size_==0){ //if only node exists set head to node
		head=node;
	}
	else{
		Node<ItemType> *iterator; //iterator node create
		if(position==0){ //if position at beginning 
			node->setNext(head); //node poitns to head
			head=node; //head equals node
		}
		else if(postion==size){ //if position is at the end
			iteraator->getAtPos(size_-1); //iteraator gets lat position of linkedlist
			iteraator->setNext(node); //iteraator points to node
		}
		else{
			iterator=getatPosition(position-1); //iteraator gets position -1
			node->setNext(iterator->getNext()); //node points to iterator points to next node
			iterator->setNext(node); //iterator get next node
		}
		}

	size++;
	return true;
}

template<typename ItemType>
bool linkedlist<ItemType>::remove(const int &position){
	Node<ItemType> *iteraator;
	if(position==0){
		iteraator=head;
		head=head->getNext();
	}
	else{
		iteraator=getatPosition(position-1);
		iteraator->setNext(iterator->getnext()->getNext());
		iterator=iteraator->getNext();
	}
	size--;
	return true;
}

int linkedlist<ItemType>::getIndexOf(const itemType &item) const{
	Node<ItemType>* curr_item=head; //node current equals to head
	int count=0;
	while(curr_item!=nullptr){ //if current item not last
		if(curr_item->getItem()==item){ //current item gets item
			return counter; //return postion
		}
		counter++; //if not found go to next node
		curr_item=curr_item->getNext();
	}
}

Node<ItemType>* linkedlist<itemType>::getAtPos(const int &position) const{
	Node<ItemType>* curr_item=head;
	int count=0;
	while(count<position && curr_item!=nullptr){
		counter++;
		curr_item=curr_item->getNext();
	}
	return curr_item;
}

bool linkedlist<ItemType>::moveItemToTop(const itemType &item){
	if(getIndexOf(item)<1){ //if item dosent exist or its already at the top
		return false;
	}
	else{
		Node<ItemType>*new_head=new Node<itemType>(); //create new head node
		new_head=setItem(item); //set new node to item
		remove(getIndexOf(item)); //remove current node, item from list
		new_head=setNext(head_); //new head points to current head
		head=new_head; //list head euqls to new head pointer
	}
}

void linkedlist<ItemType>::reverseCopy(const linkedlist,<ItemType> &alist){
	linkedlist<itemType> newList(alist); //new list made
	Node<itemType>* current= newList.getHeadPtr(); //current node equlas head node
	const int Start=0; //start at position 0
	const int End=newList.getSize(); //get the last position of list
	while(current!=nullptr){ //if current not last node
		insert(current->getItem(), START); //insert current node at start at 0
		current=current->getNext(); //current set to next node
		remove(end); //remove last node;
	}
}

void linkedlist<itemType>::clear(){
	Node<ItemType>* curr_item=head; //new node curr_item point to head
	Node<ItemType>*temp=curr_item; //temp node point to curr_item
	for(int i=0;i<size;i++){
		temp=curr_item; //temo equals curr_item
		curr_item=curr_item->getNext(); //curr_item poits to next node
		delete temp; //deletre temp
	}
	temp=nullptr; //temp nullptr
	size=0;
}



template<typename ItemType>
Node<ItemType>* LinkedList<ItemType>::getHeadPtr() const {

    return head_; //returns head pointer

}

template<typename ItemType>
int LinkedList<ItemType>::getSize() const {

    return size_;

}



template<typename ItemType>
bool LinkedList<ItemType>::isEmpty() const {

    return size_ == 0 ? true : false;

}



//Account take const pointer to Post in addPost function
bool addPost(Post* const posted){
	posts.insert(Posted,0);
	if(point_N!=nullptr){
	point_N->addToFeed(posted);
	}
}
