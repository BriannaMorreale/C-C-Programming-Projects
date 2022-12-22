#include <stdio.h>
#include <stdlib.h>

    typedef struct Node{
        int data;
        struct Node *next;

    }NODE;

    NODE* newNode(int data){
        NODE* result = malloc(sizeof(NODE));
        if(result != NULL){
            result -> data = data;
            result -> next = NULL;
        }

        return result;
    }

    NODE* head;
    NODE* tail;

    void addNode(int data){
        NODE* nNode = newNode(data);    
                
            if(head == NULL) {     
                head = nNode;    
                tail = nNode;    
            }    
            else {     
                tail -> next = newNode;      
                tail = newNode;    
            } 
    }

    void display(){
         NODE* current = head;    
            
        if(head == NULL) {    
            printf("List is empty");    
            return;    
        }    
        printf("Nodes of singly linked list: ");    
        while(current != NULL) {        
            printf(current -> data + " ");    
            current = current -> next;    
        }    
        printf("\n");
    }

    int main() {   
            
        //Add nodes to the list    
        addNode(1);    
        addNode(2);    
        addNode(3);    
        addNode(4);    
            
        //Displays the nodes present in the list    
        display();
        return 0;