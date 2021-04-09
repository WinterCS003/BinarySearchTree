#include "arrayBT.h"

#include <iostream>

/**********************************************************
 *
 * CONSTRUCTOR arrayBT
 *_________________________________________________________
 * This function receives nothing and initializes
 * data to zero, and is_present to false.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   This function will set data to zero and is_present to 
 *   false.
 ***********************************************************/
arrayBT::arrayBT()
{
  data = new int[SIZE];
  is_present = new bool[SIZE];

  // null initialize the array
  for(int i = 0; i < SIZE; i++)
  {
    data[i] = 0;
    is_present[i] = false;
  }
}

/**********************************************************
 *
 * CONSTRUCTOR arrayBT
 *_________________________________________________________
 * This function receives a reference to an arrayBT object.
 * and creates a new arrayBT object that is identical
 * to the parameter
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     tree: reference to arrayBT object to copy from
 *
 * POST-CONDITIONS
 *   This function will create a new object that is identical
 *   to the passed parameter.
 ***********************************************************/
arrayBT::arrayBT(const arrayBT& tree) // IN - tree to copy from
{
  data = new int[SIZE];
  is_present = new bool[SIZE];
  
  // null initialize the array
  for(int i = 0; i < SIZE; i++)
  {
    data[i] = 0;
    is_present[i] = false;
  }
  assignmentHelper(tree, 0);
}

/**********************************************************
 *
 * DESTRUCTOR ~arrayBT
 *_________________________________________________________
 * This function receives nothing and deallocates all
 * memory held by the data and is_present array.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none.
 *
 * POST-CONDITIONS
 *   This function will free all memory in the data and 
 *   is_present arrays using delete.
 ***********************************************************/
arrayBT::~arrayBT()
{
  std::cout << "Deleting data and is_present arrays" << std::endl;
  delete [] data;
  delete [] is_present;
}

/**********************************************************
 *
 * FUNCTION insert
 *_________________________________________________________
 * This function receives an int value and inserts it 
 * into the tree. The function makes sure that it is 
 * inserted into the proper index to maintain binary
 * search tree. A helper insert function is called to 
 * start insert from the root node.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     value: unique int to insert into tree.       
 *     The function assumes that value is not already in
 *     the tree
 *          
 * POST-CONDITIONS
 *  This function inserts value into the tree. If value is
 *  smaller than the node, it is inserted to the left, right
 *  otherwise.
 ***********************************************************/
void arrayBT::insert(int value) // IN - value to insert to tree
{
  insert(0, value);
}

/**********************************************************
 *
 * FUNCTION insert
 *_________________________________________________________
 * This is a private helper function that allows the calling 
 * function to specify a node to begin inserting from.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     node: an int that represents the level of a node
 *     value: unique int to insert into tree.
 *     The function assumes that value is not already in
 *     the tree
 *          
 * POST-CONDITIONS
 *  This function inserts value into the tree. If value is
 *  smaller than the node, it is inserted to the left, right
 *  otherwise.
 ***********************************************************/
void arrayBT::insert(int node,  // IN - node to begin inserting from
                     int value) // IN - value to insert
{
  if(node >= SIZE)
  {
    std::cout << "Not enough space!" << std::endl;
    return;
  }
  while(node < SIZE)
  {
    // if a node exists
    if(is_present[node])
    {
      // if the value is less than the data at the node
      // check the left child node
      if(value < data[node])
      {
        node = 2*node + 1;
      }
      // if the value is greater than the data at the node
      // check the right child node
      else if(value > data[node])
      {
        node = 2*node + 2;
      }
    }
    // insert value at the first correct empty node
    else
    {
      data[node] = value;
      is_present[node] = true;
      break;
    }
  }
}

/**********************************************************
 *
 * FUNCTION copyBranch
 *_________________________________________________________
 * This is a helper function that receives an array of ints,
 * the number of elements in the array, and the node to 
 * begin copying from. The data in each node beginning at
 * the parameter node is deleted then stored in the array.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     branch: a pointer to an array of ints
 *     index: a reference to the number of elements in the 
 *            array, also used as the index of the array
 *     node: the index of the node in the array to start from.
 *          
 * POST-CONDITIONS
 *  This function begins at the given node and deletes then
 *  copies the data in each node into the given array.
 ***********************************************************/
void arrayBT::copyBranch(int* branch, // IN - array of ints
                         int& index,  // IN - number of elements in branch
                         int node)    // IN - node to start from
{
  if(index > SIZE-1    || 
     index < 0         ||
     node > SIZE-1     || 
     !is_present[node] || 
     node < 0)
  {
    return;
  }
  
  branch[index++] = data[node];
  is_present[node] = false;

  int left = 2*node + 1;
  if(left < SIZE && is_present[left])
  {
    copyBranch(branch, index, left);
  }

  int right = 2*node + 2;
  if(right < SIZE && is_present[right])
  {
    copyBranch(branch, index, right);
  }
} 

/**********************************************************
 *
 * FUNCTION remove
 *_________________________________________________________
 * This function receives an int value and removes it 
 * from the tree if it exists. This function calls 
 * the copyBranch and insert functions.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     value: int to remove
 *
 * POST-CONDITIONS
 *   This function will delete the node that has value
 *     the rest of the tree is properly maintained in order. 
 ***********************************************************/
void arrayBT::remove(int value) // IN - value to remove
{
  int node = Search(value);
  if(node != -1)
  {
    // delete the node
    is_present[node] = false;

    int left = 2*node + 1;
    int right = 2*node + 2;
    if(is_present[left] && is_present[right])
    {
      int valNode = right;
      int valLeft = 2*valNode+1;
      int successor = data[valNode];
      while(valLeft < SIZE && is_present[valLeft])
      {
        if(data[valLeft] < successor){
          successor = data[valLeft];
          valNode = valLeft;
          valLeft = 2*valLeft + 1;
        }
      }
      // replace the node with the successor
      data[node] = successor;
      is_present[node] = true;
      // update the successor branch
      int* successorBranch = new int[SIZE];
      int i = 0;
      copyBranch(successorBranch, i, valNode); // includes successor at 0
      for(int j = 1; j < i; j++) // start at 1 to skip the successor
        insert(valNode, successorBranch[j]);
      delete [] successorBranch;
    }
    // only a right branch exists
    else if(is_present[right])
    {
      // find the successor
      int valNode = right;
      int valLeft = 2*valNode+1;
      int successor = data[valNode];
      while(valLeft < SIZE && is_present[valLeft])
      {
        if(data[valLeft] < successor){
          successor = data[valLeft];
          valNode = valLeft;
          valLeft = 2*valLeft + 1;
        }
      }
      // replace the node with the successor
      data[node] = successor;
      is_present[node] = true;
      // Update the successor branch
      int* successorBranch = new int[SIZE];
      int i = 0;
      copyBranch(successorBranch, i, valNode); // includes successor at 0
      for(int j = 1; j < i; j++) // start at 1 to skip the successor
      {
        insert(valNode, successorBranch[j]);
      }
      delete [] successorBranch;
    }
    // replace with left branch if right doesn't exist
    else if(is_present[left])
    {
      int* leftBranch = new int[SIZE];
      int i = 0;
      copyBranch(leftBranch, i, left);
      for(int j = 0; j < i; j++)
      {
        insert(node, leftBranch[j]);
      }
      delete [] leftBranch;
    }
  }
}

/**********************************************************
 *
 * Function operator=
 *_________________________________________________________
 * This function overloads the assignment operator and
 *   sets all values of the parameter tree, to the calling
 *   object. This function calls the assignmentHelper.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     tree: binary tree to copy from
 *
 * POST-CONDITIONS
 *   This function deletes all contents of the current 
 *   tree and makes a new one completely identical to the
 *   parameter
 ***********************************************************/
arrayBT& arrayBT::operator=(const arrayBT& tree) // IN - tree to copy from
{
  for(int i = 0; i < SIZE; i++)
  {
    data[i] = 0;
    is_present[i] = false;
  }

  assignmentHelper(tree, 0);

  return *this;
}

/**********************************************************
 *
 * Function assignmentHelper
 *_________________________________________________________
 * This is a helper function that allows the calling
 * function to copy all nodes in the given tree to its
 * own tree beginning from the given node.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     tree: binary tree to copy from
 *     node: node to begin copying from
 *
 * POST-CONDITIONS
 *   This function deletes all contents of the current 
 *   tree and makes a new one completely identical to the
 *   parameter
 ***********************************************************/
void arrayBT::assignmentHelper(const arrayBT& tree, // IN - tree to copy from
                               int node) // IN -node to start from
{
  if(node >= SIZE || !tree.is_present[node])
  {
    return;
  }

  int left = 2*node + 1;
  if(left < SIZE && tree.is_present[left])
  {
    assignmentHelper(tree, left);
  }

  int right = 2*node + 2;
  if(right < SIZE && tree.is_present[right])
  {
    assignmentHelper(tree, right);
  }

  data[node] = tree.data[node];
  is_present[node] = true;
}

/**********************************************************
 *
 * FUNCTION Search
 *_________________________________________________________
 * This function receives a target to search for and
 * returns its index in the array.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     target: int value to find.
 *
 * POST-CONDITIONS
 *   This function will return the index of the node with 
 *   data that has the parameter target. -1 is returned If
 *   the value is not found.
 ***********************************************************/
int arrayBT::Search(int target) const // IN - value to search for
{
  int node = 0;
  while(node < SIZE)
  {
    if(is_present[node])
    {
      if(target == data[node])
      {
        return node;
      }
      // if the target is less than the node
      // check the left child
      else if(target < data[node])
      {
        node = 2*node + 1;
      }
      // if the target is greater than the node
      // check the right child
      else if(target > data[node])
      {
        node = 2*node + 2;
      }
    }
    else
    {
      break;
    }
  }

  return -1;
}

/**********************************************************
 *
 * FUNCTION inOrderDisplay
 *_________________________________________________________
 * This function prints out the contents of the tree in
 * InOrder ordering. Left child then Node, then Right child.
 * A helper function is used to specify printing from the
 * root node.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none.
 *
 * POST-CONDITIONS
 *   This function will print the contents of the tree in
 *   InOrder notation to the terminal. A helper function is 
 *   called to specify the node.
 ***********************************************************/
void arrayBT::inOrderDisplay() const
{
  inOrderDisplay(0);
}

/**********************************************************
 *
 * FUNCTION inOrderDisplay
 *_________________________________________________________
 * This is a helper function so that the right node can
 * be displayed to the screen in InOrder order.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   node: int node to begin printing from.
 *
 * POST-CONDITIONS
 *   This function will print the contents of the tree in
 *   InOrder notation to the terminal beginning at the node.
 ***********************************************************/
void arrayBT::inOrderDisplay(int node) const // IN - node to begin printing from
{
  if(node >= SIZE || !is_present[node])
  {
    return;
  }

  // Visit left node first
  int left = 2*node+1;
  if(left < SIZE)
  {
    if(is_present[left])
    {
      inOrderDisplay(left);
      std::cout << data[node] << " ";
    }
    // Print Current Node if there is no Left
    else
    {
      std::cout << data[node] << " ";
    } 
  }
  // Finally visit right node
  int right = 2*node + 2;
  if(right < SIZE)
  {
    if(is_present[right])
    {
      inOrderDisplay(right);
    }
  }
}
/**********************************************************
 *
 * FUNCTION inOrderDisplay
 *_________________________________________________________
 * This function prints out the contents of the tree in
 * preOrder ordering. Node, then Left child, then Right child.
 * A helper function is used to specify printing from the 
 * root node
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none.
 *
 * POST-CONDITIONS
 *   This function will print the contents of the tree in
 *   preOrder notation to the terminal. A helper function is 
 *   called to specify printing from the root node.
 ***********************************************************/
void arrayBT::preOrderDisplay() const
{
  preOrderDisplay(0);
}

/**********************************************************
 *
 * FUNCTION inOrderDisplay
 *_________________________________________________________
 * This is a helper function to print the tree in preOrder
 * ordering starting at the specified node.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   node: int node to begin printing from.
 *
 * POST-CONDITIONS
 *   This is a helper function that wil print the contents 
 *   of the tree in preOrder notation to the terminal 
 *   starting from the specified node.
 ***********************************************************/
void arrayBT::preOrderDisplay(int node) const // IN - node to start printing from
{
  if(node >= SIZE || !is_present[node])
  {
    return;
  }
  // Print current node first
  if(is_present[node])
  {
    std::cout << data[node] << " ";
  }

  // Then visit Left Node
  int left = 2*node + 1;
  if(left < SIZE)
  {
    if(is_present[left])
    {
      preOrderDisplay(left);
    }
  }
  // Finally Visit Right Node
  int right = 2*node + 2;
  if(right < SIZE)
  {
    if(is_present[right])
    {
      preOrderDisplay(right);
    }
  }
}

/**********************************************************
 *
 * FUNCTION postOrderDisplay
 *_________________________________________________________
 * This function prints out the contents of the tree in
 * postOrder ordering. Left child, then Right child, then 
 * Node. A helper function is used to specify printing from 
 * the root node.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none.
 *
 * POST-CONDITIONS
 *   This function will print the contents of the tree in
 *   postOrder notation to the terminal. A helper function is 
 *   called to specify printing from the root node.
 ***********************************************************/
void arrayBT::postOrderDisplay() const
{
  postOrderDisplay(0);
}

/**********************************************************
 *
 * FUNCTION postOrderDisplay
 *_________________________________________________________
 * This is a helper function that prints the tree to the
 * terminal in postOrder beginning from the specified node.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   node: int to begin printing from.
 *
 * POST-CONDITIONS
 *   This function will print the contents of the tree in
 *   postOrder notation to the terminal. Printing begins at
 *   the specified node.
 ***********************************************************/
void arrayBT::postOrderDisplay(int node) const // IN - node to begin printing from
{
  if(node >= SIZE || !is_present[node])
  {
    return;
  }
  
  // Visit Left Node first
  int left = 2*node + 1;
  if(left < SIZE)
  {
    if(is_present[left])
    {
      postOrderDisplay(left);
    }
  }

  // Then Right Node
  int right = 2*node + 2;
  if(right < SIZE)
  {
    if(is_present[right])
    {
      postOrderDisplay(right);
    }
  }
  // Finally Print Current Node
  std::cout << data[node] << " ";
}

/**********************************************************
 *
 * Function printArr
 *_________________________________________________________
 * This function prints the nodes of the tree and their
 * corresponding index in the array. Mainly used for
 * debugging purposes.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none.
 *
 * POST-CONDITIONS
 *   This function prints the initialized nodes of the array 
 *   to the screen.
 ***********************************************************/
void arrayBT::printArr() const
{
  for(int i=0; i<SIZE; i++ )
  {
    if(is_present[i])
    {  
      std::cout << "\ni: " << i;
      std::cout << "\ndata[i]: " <<data[i];
    }
  }
  std::cout <<'\n';
}
