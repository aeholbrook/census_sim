 // bstree.h file

 #ifndef bstree_h
 #define bstree_h
 #include <iostream>
 #include <iomanip>
 using namespace std;

 // class must be templated
 template <class datatype>
 class BSTree
 {
 private:
     // you may not add any data members
     struct node;
     typedef node *nodeptr;

     struct node
     {
         datatype element;
         nodeptr right;
         nodeptr left;
         node(const datatype element, 
             const nodeptr right, 
             const nodeptr left) 
             : element(element), 
               right(right),
               left(left){}
     };
     int count;
     nodeptr root;

 // you may add any private member functions here

     nodeptr createNode(const datatype element, nodeptr right, nodeptr left)
     {
         return new node(element , right, left);
     }
     void insert(nodeptr n, nodeptr parent, datatype x) {
         if (n == nullptr) {
             n = createNode(x, nullptr, nullptr);
             if (x > parent->element)
                 parent->right = n;
             else
                 parent->left = n;
         }
         if (x > n->element)
         {
             insert(n->right, n, x);
         }
         if (x < n->element)
         {
             insert(n->left, n, x);
         }
     }
     void recursiveCopy(nodeptr leader, bool isLeft, nodeptr copy)
     {
         nodeptr n = createNode(copy->element, nullptr, nullptr);

         if (isLeft)
         {
             leader->left = n;
         }
         else
         {
             leader->right = n;
         }
         if (copy->left != nullptr) {
             recursiveCopy(n, true, copy->left);
         }
         if (copy->right != nullptr) {
             recursiveCopy(n, false, copy->right);
         }
     }

 // this method is given – it is called by printtree
     void printTreeHelper(int depth, nodeptr cur) const
     {
         const int spacing = 4;
         if (cur != nullptr) 
         {
             if (depth == 0) 
                 cout << cur->element;
             else 
                 cout << setw(spacing*depth) <<" "<< cur->element;
             cout << endl;
             printTreeHelper(depth+1, cur->right);
             printTreeHelper(depth+1, cur->left);
         }  
     else
         cout << setw(spacing*depth) <<" " << "****" << endl;

     } 


 public:
     // default constructor
     BSTree()
     {
         root = nullptr;
     }
 
     // copy constructor
     BSTree(const BSTree<datatype> &copytree)
     {
         count = copytree.count;
         if (copytree.root != nullptr)
         {
             root = createNode(copytree.root->element, nullptr, nullptr);
             if (copytree.root->left != nullptr)
             {
                 recursiveCopy(root, true, copytree.root->left);
             }
             if (copytree.root->right != nullptr)
             {
                 recursiveCopy(root, false, copytree.root->right);
             }
         }
         else root = nullptr;
     }

     // equal overload
     const BSTree& operator =(const BSTree& rhs) 
     { 
         return BSTree(rhs);
     }

     // destructor
     ~BSTree()
     {
         deleteTree();
     }

     // inserts element into the tree
     // if value is already in the tree do not add it
     // a second time
     void insert(datatype x)
     {
         if (root == nullptr)
         {
             root = createNode(x, nullptr, nullptr);
         }
         else
             insert(root, nullptr, x);
     } 

     //print the tree as a tree
     // this (and its helper function) is given to you
     // see sample output and understand how the tree is displayed
     // because it can help when testing the code
     bool printTree() const
     {
         if (root == nullptr)
             return false;
         else 
         {       
             printTreeHelper(0, root);
             return true;
         } 
     }  

     // prints tree in order to the screen
     // call printinorder with  cout passed in
     // this function is done for you
     void printInorder()
     {
         printinorder(cout);

     }

     // prints the tree in order to
     // the ostream passed into it
     void printInorder(ostream &out)
     {
         inorderRecursive(root, out);
     }

     void inorderRecursive(nodeptr n, ostream &out) {
         if (n != nullptr) {
             inorderRecursive(n->left, out);
             out << n->element;
             inorderRecursive(n->right, out);
         }
     }

     // prints tree in preorder to the screen
     // call printpreorder with  cout passed in
     // this function is done for you
     void printPreorder()
     {
         printPreorder(cout);

     }
     // prints the tree in preorder to
     // the ostream passed into it
     void printPreorder(ostream &out)
     {
         preorderRecursive(root, out);
     }

     void preorderRecursive(nodeptr n, ostream& out) {
         if (n != nullptr) {
             out << n->element;
             inorderRecursive(n->left, out);
             inorderRecursive(n->right, out);
         }
     }

     // deletes the item passed in from the tree
     // it returns a true if it finds it and deletes it, otherwise
     // it returns a false
     bool  deleteNode(datatype x)
     {
         deleteHelper(x, root);
         return 1;
     } 

     // deletes the item passed in from the tree
     // it also passes back the item to the calling function
     // it returns a true if it finds it and deletes it, otherwise
     // it returns a false
    bool  deleteNodePassBackData(datatype x, datatype &temp)
     {
        nodeptr n = deleteHelper(x, root);
        if (n == nullptr) return 0;
        temp = n->element;
        return 1;
     } 

     // deletes the whole tree
     void deleteTree()
     {
     }

     nodeptr deleteHelper(datatype x, nodeptr n) {
         if (n == nullptr) return n;

         else if (n->left == nullptr || n->right == nullptr)
         {
             if (n->left == nullptr)
             {
                 nodeptr temp = n->right;
                 delete n;
                 return temp;
             }
             else if (n->right == nullptr)
             {
                 nodeptr temp = n->left;
                 delete n;
                 return temp;
             }
             else {
                 if (x < n->element)
                     n->left = deleteHelper(x, n->left);

                 else if (x > n->element)
                     n->right = deleteHelper(x, n->right);
             }

             nodeptr temp = minValueNode(n->right);

             n->element = temp->element;

             n->right = deleteHelper(temp->element, n->right);
         }
         return n;
     }
     
     nodeptr minValueNode(nodeptr n)
     {

         /* loop down to find the leftmost leaf */
         while (n->left != nullptr)
             n = n->left;

         return n;
     }
 };

 #endif
