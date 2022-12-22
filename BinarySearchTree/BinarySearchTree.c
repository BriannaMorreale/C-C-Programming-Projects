#include <stdio.h>
#include <stdlib.h>


    typedef struct Node{
        int data;
        struct Node *left;
        struct Node *right;
    }NODE;

     NODE* newNode(int data){
       NODE* result = malloc(sizeof(NODE));
       if(result != NULL){
        result -> data = data;
        result -> left = NULL;
        result -> right = NULL;
       }

       return result;
    }


    NODE* root;

    void BinarySearchTree(){
        root = NULL;
    };

    int factorial(int num){
        int fact =1; //fix this
        if(num == 0){
            return 1;
        } else {
            while( num >1){
                fact = fact * num;
                num--;
            }
            return fact;
        }
    }

    int numOfBST(int key){
         int catalanNumber = factorial(2 * key)/(factorial(key + 1) * factorial(key));    
        return catalanNumber;
    }
    int main() {
          
         printf("Total number of possible Binary Search Trees with given key: %d \n", numOfBST(5));
        return 0;
    }