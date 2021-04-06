//DataStructure
//General practice of linked_list


#include <iostream>

//declaring  a node in linked list |Data|next|-->
struct
{ //datatype of my data is int
    int data;
// declaring next which holds the address of the data it pointed to.
// self referential structure
    struct node * next; // Here next is the self pointer because it is also the field of the same node

}*new ;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
