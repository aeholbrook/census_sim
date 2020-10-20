#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

// class is templated
template <class DataType>
class List
{
private:
    // You may NOT add any data members
    struct node;
    typedef node *nodePtr;
    struct node
    {
        DataType info;
        nodePtr next;
        node(const DataType info, const nodePtr next) : info(info), next(next) {}
    };

    nodePtr head;

    // You can add any private member functions you want

    //so for this I think I might improve by removing that node constructor
    //above and just working out a way to make it with one private member function.

    nodePtr createNode(const DataType info, nodePtr next)
    {
        return new node(info, next);
    }

    bool recursiveChecker(DataType inInfo, nodePtr n) {
        if (n->next != nullptr)
        {
            if (n->info != inInfo)
                return recursiveChecker(inInfo, n->next);
            else return 1;
        }
        else return 0;
    }

    //Do you think it would be wise to try to combine these? 

    bool recursiveCheckDeleter(DataType inInfo, nodePtr n) {
        if (n->next != nullptr) {
            if (n->info != inInfo)
                return recursiveChecker(inInfo, n->next);
            else
            {
                delete n;
                return 1;
            }
        }
        else return 0;
    }

    void recursiveDelete(nodePtr n) {
        if (n->next!=nullptr)
        recursiveDelete(n->next);
        delete n;
    }

public:
    // Default constructor
    List()
    {
        head = createNode(DataType{}, nullptr);
    }

    // Copy Constructor
    //leader node takes info from copy list and follower node holds position in 
    //new list to make new nodes with leader info.
    List(const List<DataType> &copyList)
    {
        this->head = createNode(DataType{}, nullptr);
        if (copyList.head->next != nullptr) {
            nodePtr leader = copyList.head->next;
            nodePtr follower = head;
            while (leader->next != nullptr)
            {
                follower->next = createNode(leader->info, nullptr);
                leader = leader->next;
                follower = follower->next;
            }
            follower->next = createNode(leader-> info, nullptr);
        }
    }

    // Destructor
    ~List()
    {
        recursiveDelete(head);
    }

    // Overloaded equal operator

    const List& operator=(const List& rhs)
    {
         return List(rhs);
    }


    // insert into the list
    // if it is already in the list, it does NOT add it
    void insert(const DataType& x)
    {
        if (head->next == nullptr)
        {
            nodePtr ins = createNode(x, nullptr);
            head->next = ins;
        }
        else if (!isInList(x))
        {
            nodePtr iter = head;
            while (iter->next != nullptr && iter->next->info <= x)
            {
                iter = iter->next;
            }
            nodePtr ins = createNode(x, iter->next);
            iter->next = ins;
        }
    }


    // returns true if in list and false if not
    bool isInList(DataType x)
    {
        return recursiveChecker(x, head);
    }

    // Prints the list to the screen by calling the
    // overloaded printList and passing cout into it
    // Function is completed
    void printList()
    {
        printList(cout);
    }

    // Prints the list to the ostream passed into it
    void printList(ostream &out)
    {
        if (!isEmpty())
        {
            nodePtr iter = head->next;
            while (iter->next != nullptr)
            {
                out << iter->info;
                iter = iter->next;
            }
            out << iter->info;
        }
    }

    // Deletes the item passed in from the list
    // returns a true if an item is deleted and a false
    // if the item wasn't in the list
    bool deleteListItem(DataType inInfo)
    {
        return recursiveCheckDeleter(inInfo, head);
    }

    // algorithm which utilizes the deleter function below and iterates over every node
    bool deleteAndPassBackListItem(DataType inInfo, DataType& outInfo)
    {
        outInfo = inInfo;
        return recursiveCheckDeleter(inInfo, head);
    }


    // Deletes the first item from the list, it
    // also passes the item that is deleted back
    // returns a true if an item is deleted and a false
    // if the item wasn't in the list
    bool deleteFirstAndPassBackListItem(DataType &outInfo)
    {
        if (!isEmpty())
        {
            nodePtr holder = head->next;
            head->next = holder->next;
            outInfo = holder->info;
            delete holder;
            return 1;
        }
        return 0;
    }

    // returns true if list is empty, otherwise returns false
    bool isEmpty()
    {
        return head->next == nullptr;
    }
};

#endif
