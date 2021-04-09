#ifndef ARRAYBT_H_
#define ARRAYBT_H_

const int SIZE = 100;

class arrayBT
{
  private:
    int* data; // IN - dynamic array representation of binary Tree
    bool* is_present; // IN - contains which positions have values

  /**********************
   ** ACCESSOR HELPERS **
   **********************/
    void inOrderDisplay(int node) const; // IN - node to start print from
    void preOrderDisplay(int node) const; // IN - node to start print from
    void postOrderDisplay(int node) const; // IN - node to start print from

  /*********************
   ** MUTATOR HELPERS **
   *********************/
    void insert(int node,   // IN - node to start insert from
                int value); // IN - value to insert
    void assignmentHelper(const arrayBT& tree, // IN - tree to copy from
                          int node); // IN - node to start copying from
    void copyBranch(int* branch, // IN - branch to copy
                    int& index,  // IN - number of nodes copied
                    int node);   // IN - node to start copying from

  public:
  /******************************
   ** CONSTRUCTOR & DESTRUCTOR **
   ******************************/
    arrayBT();
    arrayBT(const arrayBT& tree); // IN - tree to copy from
    ~arrayBT();

  /**************
   ** MUTATORS **
   **************/
    void insert(int value); // IN - value to insert
    void remove(int value); // IN - value to delete
    arrayBT& operator=(const arrayBT& tree); // IN - tree to copy from

  /***************
   ** ACCESSORS **
   ***************/
    int Search(int target) const; // IN - value to search fro
    void inOrderDisplay() const;
    void preOrderDisplay() const;
    void postOrderDisplay() const;
    void printArr() const;
};

#endif // ARRAYBT_H_


/****************************************************************
 * arrayBT Class
 *   This class represents a Binary Search Tree implemented using
 *   a dynamic array. This class manages a data attribute, 
 *   which is the array that holds all information, and another
 *   dynamic array is_premium to store which positions have a 
 *   value
 ***************************************************************/


/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
 ******************************/

/****************************************************************
 * arrayBT();
 *   Constructor; Initializes class attributes to 0 or false.
 *   Parameters: none
 *   Return: none
 ***************************************************************/

/****************************************************************
 * arrayBT(const arrayBT& copy);
 *   Constructor; Initializes class attributes to be identical
 *                to the parameter copy.
 *   Parameters: copy (const arrayBT&) // IN - value to copy
 *   Return: none
 ***************************************************************/

/****************************************************************
 * ~className();
 *   Destructor; Deletes the dynamic arrays data and is_premium.
 *   Parameters: none
 *   Return: none
 ***************************************************************/


/**************
 ** MUTATORS **
 **************/

/*******************************************************************
 * void insert(int value); 
 *
 *   Mutator; This method will insert the parameter value into the
 *            dynamic array tree. Proper order is maintained, to
 *            ensure it remains a binary search tree. A helper 
 *            function is called to specify copying from the root.
 *------------------------------------------------------------------
 *   Parameter: value (int) // IN - value to insert
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 *void remove(int value);
 *
 *   Mutator; This method will remove the parameter value from the
 *            tree. The value is replaced with the successor and
 *            the tree is updated to ensure it remains a binary 
 *            search tree. The copyBranch and insert function is 
 *            called
 *------------------------------------------------------------------
 *   Parameter: value (int) // IN – the value to remove
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * arrayBT& operator=(const arrayBT& tree);
 *
 *   Mutator; This method will update binary tree to be exactly the
 *            same as the parameter tree. The assignmentHelper 
 *            function is called.
 *------------------------------------------------------------------
 *   Parameter: tree (const arrayBT&) // IN - reference to tree
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void insert(int node, int value);
 *
 *   Mutator; This is a helper method that will insert the value
 *            starting at the specified node.
 *------------------------------------------------------------------
 *   Parameter: node (int)  // IN - node to start insert from
                value (int) // IN - value to insert
 *------------------------------------------------------------------
 *   Return: none 
 *******************************************************************/

/*******************************************************************
 * void assignmentHelper(const arrayBT& tree, int node);
 *
 *   Mutator; This is a helper function that will copy the nodes 
 *            from the parameter tree starting at the given node
 *------------------------------------------------------------------
 *   Parameter: tree (const arrayBT&) // IN - tree to copy from
 *              node (int)           // IN - node to start copying from
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void copyBranch(int* branch, int& index, int node);
 *
 *   Mutator; This is a helper function that will copy and delete
 *            all nodes starting at the specified node.
 *------------------------------------------------------------------
 *   Parameter: branch (int*) // IN - branch to copy
 *              index (int&)  // IN - number of nodes copied
 *              node (int)    // IN - node to start copying from
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/


 /***************
  ** ACCESSORS **
  ***************/

/****************************************************************
 * int Search(int target) const; 
 *
 *   Accessor; This method will find and return the index of 
 *             target in the tree.
 * --------------------------------------------------------------
 *   Parameters: target (int) // IN - value to search for
 * --------------------------------------------------------------
 *   Return: index (int)
 ***************************************************************/
 
/****************************************************************
 * void inOrderDisplay() const;
 *
 *   Accessor; This method will print the data in the tree in 
 *             InOrder notation. The corresponding helper 
 *             function is called.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none - data in tree is printed to terminal.
 ***************************************************************/

/****************************************************************
 * void preOrderDisplay() const;
 *
 *   Accessor; This method will print the data in the tree in 
 *             preOrder notation. The corresponding helper 
 *             function is called.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none - data in tree is printed to terminal.
 ***************************************************************/

/****************************************************************
 * void postOrderDisplay() const;
 *
 *   Accessor; This method will print the data in the tree in 
 *             postOrder notation. It calls the corresponding 
 *             helper function.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none - data in tree is printed to terminal.
 ***************************************************************/
 
 /****************************************************************
 * void printArr() const;
 *
 *   Accessor; This method prints all nodes and their index in the
 *             array. Mainly for debugging purposes.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none - data in tree is printed to terminal.
 ***************************************************************/

 /****************************************************************
 * void preOrderDisplay(int node); const
 *
 *   Accessor; This method is a helper function that allows the 
 *             calling function to specify a node to start from.
 * --------------------------------------------------------------
 *   Parameters: node (int) // IN - node to begin printing tree
 * --------------------------------------------------------------
 *   Return: none - data in tree is printed to terminal.
 ***************************************************************/
 
 /****************************************************************
 * void postOrderDisplay(int node) const;
 *
 *   Accessor; This method is a helper function that allows the
 *             calling function to specify a node to begin printing
 *             from.
 * --------------------------------------------------------------
 *   Parameters: node (int) // IN - node to begin printing tree
 * --------------------------------------------------------------
 *   Return: none - data in tree is printed to terminal.
 ***************************************************************/
 
 /****************************************************************
 * void inOrderDisplay(int node) const;
 *
 *   Accessor; This method is a helper function that allows the
 *             calling function to specify a node to start from.
 * --------------------------------------------------------------
 *   Parameters: node (int) // IN - node to begin printing tree
 * --------------------------------------------------------------
 *   Return: none - data in tree is printed to terminal.
 ***************************************************************/

