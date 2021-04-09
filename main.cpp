/******************************************************************
 * AUTHOR       : Jaemok C. Lee
 * TITLE        : Dynamic Array Binary Search Tree
 * DATE CREATED : 04/09/2021
 ******************************************************************/
#include <iostream>

#include "arrayBT.h"

void menu();

/************************************************************
*
* Dynamic Array Binary Search Tree
*___________________________________________________________
* This program implements a Binary Search Tree using
*   a dynamic array. The user can insert integers,
*   delete a value, search for a value, and print the
*   values of the tree in either In Order, Pre Order, or 
*   Post Order.
*___________________________________________________________
* INPUTS:
*   This Tree holds integer values in binary search order.
*
* OUTPUTS:
*   The user can print the values of the tree in In Order,
*   Post Order, or Pre Order.
*************************************************************/
int main() {
  arrayBT myTree;

  menu();
  int choice = 0;
  while(choice != 11)
  {
    std::cout << "Please choose a Function (Press 10 to show menu): ";
    std::cin >> choice;
    std::cout << std::endl;

    int value;
    if(choice == 1){
      value = -1;
      std::cout << "Please specify a value to insert: ";
      std::cin >> value;
      std::cout << std::endl;
      std::cout << "Inserting: " << value << std::endl << std::endl;
      myTree.insert(value);
    } 
    else if(choice == 2){
      value = -1;
      std::cout << "Please specify a value to Search: ";
      std::cin >> value;
      std::cout << std::endl;
      std::cout << "Value: " << value << " at index: " << myTree.Search(value);
      std::cout << std::endl << std::endl;
    } 
    else if(choice == 3){
      value = -1;
      std::cout << "Please specify a value to remove: ";
      std::cin >> value;
      std::cout << std::endl;
      std::cout << "Removing: " << value << std::endl << std::endl;
      myTree.remove(value);
    } 
    else if(choice == 4){
      std::cout << "Printing in order sequence: ";
      myTree.inOrderDisplay();
      std::cout << std::endl << std::endl;
    }
    else if(choice == 5){
      std::cout << "Printing pre order sequence: ";
      myTree.preOrderDisplay();
      std::cout << std::endl << std::endl;
    }
    else if(choice == 6){
      std::cout << "Printing post order sequence: ";
      myTree.postOrderDisplay();
      std::cout << std::endl << std::endl;
    }
    else if(choice == 7){
      std::cout << "Printing array: ";
      myTree.printArr();
      std::cout << std::endl;
    }
    else if(choice == 8){
      std::cout << "Calling copy constructor: \n";
      std::cout << "Printing original tree: " << std::endl;
      myTree.printArr();
      std::cout << std::endl;

      arrayBT copyTree = myTree;
      std::cout << "Printing copy tree(should be equal): " << std::endl;
      copyTree.printArr();
      std::cout << std::endl;
    }
    else if(choice == 9){
      std::cout << "Calling assignment operator: \n";
      std::cout << "Printing original tree: " << std::endl;
      myTree.printArr();
      std::cout << std::endl;
      arrayBT assign;

      assign = myTree;
      std::cout << "Printing Assigned tree(should be equal): " << std::endl;
      assign.printArr();
      std::cout << std::endl;
    }
    else if(choice == 10){
      menu();
    }
    else if(choice == 11){
      std::cout << "Good bye..." << std::endl;
      return 0;
    }
    else
       std::cout << "Not a valid choice!" << std::endl;
  }
  
  return 0;
}

/**********************************************************
 *
 * FUNCTION menu
 *_________________________________________________________
 * This function prints out all the options the user can
 * perform on the binary tree.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   The menu is printed to the screen
 ***********************************************************/
void menu()
{
  std::cout << "**********************************" << std::endl;
  std::cout << "Dynamic Array Binary Search Tree" << std::endl;
  std::cout << "1) bool insert(int value)\n"
            << "2) int Search(int value)\n"
            << "3) bool remove(int target)\n"
            << "4) void inOrder()\n"
            << "5) void preOrder()\n"
            << "6) void postOrder()\n"
            << "7) void printArr()\n"
            << "8) Copy Constructor\n"
            << "9) Assignment operator\n"
            << "10) Show menu\n"
            << "11) Quit\n";
  std::cout << "**********************************" << std::endl;
}
