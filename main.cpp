#include <iostream>

using namespace std;

class Node {
  public:
    int item;
  struct Node * next;
};

void insertBeginning(struct Node ** head_ref, int new_item) {
  //allocate memory to node
  struct Node * new_node = new Node();
  //insert data
  new_node -> item = new_item;
  new_node -> next = ( * head_ref);
  //move head to new node
  ( * head_ref) = new_node;
}

void insertAfter(struct Node * prev_node, int new_item) {
  if (prev_node == NULL) {
    cout << "given Previous node cannot be Null";
  }
  //make new node
  struct Node * new_node = new Node();
  //insert data
  new_node -> item = new_item;
  //new node points to previous node
  new_node -> next = prev_node -> next;
  prev_node -> next = new_node;
}

void insertAtEnd(struct Node ** head_ref, int new_item) {

  //make new node
  struct Node * new_node = new Node();

  //last node equals to head node
  struct Node * last_node = * head_ref;

  //new node gets item
  new_node -> item = new_item;

  //points to next node which is NULL
  new_node -> next = NULL;

  // if head node points to nothing start pointing to new node
  if ( * head_ref == NULL) {
    * head_ref = new_node;
  }

  //check if last in last node
  while (last_node -> next != NULL) {
    last_node = last_node -> next; //last node points to next node
    last_node -> next = new_node; //last points to next to new node
  }
}

bool SearchNode(struct Node ** head_ptr, int key) {

  //current node= head node
  struct Node * current = * head_ptr;

  //if current is not last node
  while (current != NULL) {

    //if current item= key item
    if (current -> item == key) {
      return true;
    }

    //current item not key item go to next node
    current = current -> next;

  }
  return false;
}

void sortLinkedList(struct Node ** head_ptr) {

  //current Node = head node, index pointer to NULL
  struct Node * current = * head_ptr, * index = NULL;
  int temp;
  if (head_ptr == NULL) {
    cout << "boo";
  } else {
    while (current != NULL) {
      //index pointer = current point to next node
      index = current -> next;

      //if index not last node
      while (index != NULL) {

        //if current item more than index item
        if (current -> item > index -> item) {

          //temp=current item;
          temp = current -> item;

          //current item=index item
          current -> item = index -> item;

          //index item=temp item
          index -> item = temp;

        }
        //index=next node
        index = index -> next;
      }
      //current = next node
      current = current -> next;
    }
  }

}

void printList(struct Node * node) {
  while (node != NULL) {
    cout << node -> item << " ";
    node = node -> next;
  }
}

int main() {
  cout << "Hello world!" << endl;
  struct Node * head = NULL;
  Node * one = NULL;
  Node * two = NULL;
  Node * three = NULL;
  //allocate Nodes
  one = new Node();
  two = new Node();
  three = new Node();
  //Assign value items
  one -> item = 1;
  two -> item = 2;
  three -> item = 3;
  //connect Nodes
  one -> next = two;
  two -> next = three;
  three -> next = NULL;
  //print linked list value
  head = one;
  while (head !=
    NULL) {
    cout << head -> item;
    head = head -> next;
  }

  insertAtEnd( & head, 1);
  insertBeginning( & head, 2);
  insertBeginning( & head, 3);
  insertAtEnd( & head, 4);
  insertAfter(head -> next, 5);

  cout << "Linked list: ";
  printList(head);

  cout << "\nAfter deleting an element: ";

  printList(head);

  int item_to_find = 3;
  if (SearchNode( & head, item_to_find)) {
    cout << endl << item_to_find << " is found";
  } else {
    cout << endl << item_to_find << " is not found";
  }

  sortLinkedList( & head);
  cout << "\nSorted List: ";
  printList(head);
}
//Search Worst case: 0(n)
//Insert worst case: O(1)
//Deletion Worst case: O(1)








//correct
// Linked list operations in C++

// #include <stdlib.h>

// #include <iostream>
// using namespace std;

// // Create a node
// struct Node {
//   int data;
//   struct Node* next;
// };

// void insertAtBeginning(struct Node** head_ref, int new_data) {
//   // Allocate memory to a node
//   struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

//   // insert the data
//   new_node->data = new_data;
//   new_node->next = (*head_ref);

//   // Move head to new node
//   (*head_ref) = new_node;
// }

// // Insert a node after a node
// void insertAfter(struct Node* prev_node, int new_data) {
//   if (prev_node == NULL) {
//   cout << "the given previous node cannot be NULL";
//   return;
//   }

//   struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
//   new_node->data = new_data;
//   new_node->next = prev_node->next;
//   prev_node->next = new_node;
// }

// // Insert at the end
// void insertAtEnd(struct Node** head_ref, int new_data) {
//   struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
//   struct Node* last = *head_ref; /* used in step 5*/

//   new_node->data = new_data;
//   new_node->next = NULL;

//   if (*head_ref == NULL) {
//   *head_ref = new_node;
//   return;
//   }

//   while (last->next != NULL) last = last->next;

//   last->next = new_node;
//   return;
// }

// // Delete a node
// void deleteNode(struct Node** head_ref, int key) {
//   struct Node *temp = *head_ref, *prev;

//   if (temp != NULL && temp->data == key) {
//   *head_ref = temp->next;
//   free(temp);
//   return;
//   }
//   // Find the key to be deleted
//   while (temp != NULL && temp->data != key) {
//   prev = temp;
//   temp = temp->next;
//   }

//   // If the key is not present
//   if (temp == NULL) return;

//   // Remove the node
//   prev->next = temp->next;

//   free(temp);
// }

// // Search a node
// bool searchNode(struct Node** head_ref, int key) {
//   struct Node* current = *head_ref;

//   while (current != NULL) {
//   if (current->data == key) return true;
//   current = current->next;
//   }
//   return false;
// }

// // Sort the linked list
// void sortLinkedList(struct Node** head_ref) {
//   struct Node *current = *head_ref, *index = NULL;
//   int temp;

//   if (head_ref == NULL) {
//   return;
//   } else {
//   while (current != NULL) {
//     // index points to the node next to current
//     index = current->next;

//     while (index != NULL) {
//     if (current->data > index->data) {
//       temp = current->data;
//       current->data = index->data;
//       index->data = temp;
//     }
//     index = index->next;
//     }
//     current = current->next;
//   }
//   }
// }

// // Print the linked list
// void printList(struct Node* node) {
//   while (node != NULL) {
//   cout << node->data << " ";
//   node = node->next;
//   }
// }

// // Driver program
// int main() {
//   struct Node* head = NULL;

//   insertAtEnd(&head, 1);
//   insertAtBeginning(&head, 2);
//   insertAtBeginning(&head, 3);
//   insertAtEnd(&head, 4);
//   insertAfter(head->next, 5);

//   cout << "Linked list: ";
//   printList(head);

//   cout << "\nAfter deleting an element: ";
//   deleteNode(&head, 3);
//   printList(head);

//   int item_to_find = 3;
//   if (searchNode(&head, item_to_find)) {
//   cout << endl << item_to_find << " is found";
//   } else {
//   cout << endl << item_to_find << " is not found";
//   }

//   sortLinkedList(&head);
//   cout << "\nSorted List: ";
//   printList(head);
// }






