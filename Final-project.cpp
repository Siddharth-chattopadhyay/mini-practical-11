#include<iostream>
#include<vector>
using namespace std;
class Node{        
    public:
        int data;
        Node *next;
};

class LinkedList{
    Node
        *HEAD,
        *newNode,
        *nextNode;
    public:
        LinkedList(): HEAD(NULL), newNode(NULL), nextNode(NULL){}

        // There were a lot of errors that I could not understand and for too long I searched for it and I did not had much time so I used ChatGPT
        ~LinkedList(){
            Node* ptr = HEAD;
            while (ptr != NULL){
                Node* forward = ptr->next;
                delete ptr;
                ptr = forward;
            }
            HEAD = nullptr;
        }


        void insert_at_beginning(int data){
            if (this -> HEAD == NULL){
                this -> HEAD = new Node;
                this -> HEAD -> next = NULL;
            } else {
                this -> newNode = new Node;
                this -> newNode -> next = HEAD;
                HEAD = newNode;
                newNode = NULL;
            }
            this -> HEAD -> data = data;
            cout << "Inserted the values at the beginning of the list" << endl;
        }

        void insert_at_pos(int key, int data){
            if (key < 0){
                cout << "Invalid key" << endl;
            }
            else if (key == 0) this ->insert_at_beginning(data);

            else {
                int count = 0;
                Node* ptr = HEAD;
                while (ptr != NULL){
                    ptr = ptr -> next;
                    count++;
                }

                if (key >= count)
                    cout << "key overflow" << endl;

                else {
                    newNode = new Node;
                    newNode -> data = data;
                    ptr = HEAD;
                    for (int i = 0; i < key; i++){
                        nextNode = ptr;
                        ptr = ptr -> next;
                    }
                    newNode -> next = ptr;
                    
                    if (nextNode != NULL)
                        nextNode -> next = newNode;

                    if (key == 0){
                        HEAD = newNode;
                    }
                    cout << "Inserted an element at pos: " << key << endl;
                }
                nextNode = newNode = ptr = NULL;
            }
        }

        void search(int key){
            if (key < 0) {
                cout << "Invalid key" << endl;
                return;
            }
            Node* ptr = HEAD;
            for (int i = 0; i < key; i++)
                if (ptr != NULL)
                    ptr = ptr -> next;

            if (ptr == NULL)
                cout << "Node key overflow" << endl;
            else
                cout << "Searched data is " << ptr -> data << endl;
            
        }

        void delete_node(int key){
            if (key < 0)
                cout << "Invalid key number: " << key << endl;
            else {
                Node* ptr = HEAD;
                if (key == 0){
                    ptr = ptr -> next;
                    delete HEAD;
                    HEAD = ptr;
                }
                else {
                    ptr = HEAD;
                    for (int i = 0; i < key - 1; i++)
                        if (ptr != NULL)
                            ptr = ptr -> next;
                        else {
                            cout << "Node key overflow" << endl;
                            return;
                        }
                
                    nextNode = ptr -> next -> next;
                    delete ptr -> next;
                    ptr -> next = nextNode;
                    nextNode = NULL;
                    ptr = NULL;
                    cout << "Deleted the node from key: " << key << endl;
                }
            }
        }

        void delete_from_end(){
            if (HEAD == NULL){
                cout << "No value is present" << endl;
            }
            else if (HEAD -> next == NULL){
                delete HEAD;
                HEAD = NULL;
                cout << "Deleted node from the end" << endl;
            }
            else {
                Node* ptr = HEAD, *prev;
                while (ptr -> next != NULL){
                    prev = ptr;
                    ptr = ptr -> next;
                }
                delete ptr;
                prev -> next = NULL;
                cout << "Deleted node from the end" << endl;
            }
        }

        void delete_node_by_value(int data){
            Node* ptr = HEAD;
            if (ptr -> data == data){
                ptr = ptr -> next;
                delete HEAD;
                HEAD = ptr;
            }
            else {
                Node* prev = NULL;
                Node* deleteNode = NULL;
                while (ptr != NULL && deleteNode == NULL){
                    if (ptr -> data == data)
                        deleteNode = ptr;
                    else {
                        prev = ptr;
                        ptr = ptr -> next;
                    }
                }
                if (deleteNode == NULL)
                    cout << "Couldn't find a node by value: " << data << endl;
                else {
                    prev -> next = ptr -> next;
                    delete ptr;
                    cout << "Successfully deleted a node by value: " << data << endl;
                }
                prev = deleteNode = NULL;
            }
            ptr = NULL;
        }

        void reverse(){
            // from Google
            Node* prev = nullptr;
            Node* curr = HEAD;
            while (curr != nullptr) {
                Node* next_node = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next_node;
            }
            HEAD = prev;
            cout << "Linked list has been reversed" << endl;
        }

        void overrite(int key, int newValue){
            if (key < 0)
                cout << "Invalid key number: " << key << endl;

            else {
                int count = 0;
                Node* ptr = HEAD;
                while (ptr != NULL){
                    ptr = ptr->next;
                    count++;
                }

                
                if (key >= count){
                    cout << "Key value overflow" << endl;
                }
                
                else {
                    ptr = HEAD;
                    for (int i = 0; i < key; i++){
                        ptr = ptr -> next;
                    }
                    cout << "Overritten data from " << ptr -> data << " to " << newValue << " at key " << key << endl;
                    ptr -> data = newValue;
                }
            }
        }

        void display(){
            if (HEAD == NULL){
                cout << "Nothing is present" << endl;
            }
            else {
                Node* ptr = HEAD;
                cout << "Values are: ";
                while (ptr != NULL){
                    cout << ptr -> data << " ";
                    ptr = ptr -> next;
                }
                cout << endl;
            }
        }

        void insert_at_end(int data){
            newNode = new Node();
            if (newNode == NULL)
                cout << "Unable to append an integer value" << endl;
            else {
                newNode->data = data;
                newNode->next = NULL;
                Node* ptr = HEAD;
                if (HEAD == NULL){
                    HEAD = newNode;
                }
                else{
                    while (ptr -> next != NULL){
                        ptr = ptr -> next;
                    }
                    ptr -> next = newNode;
                }

    
                newNode = NULL;
                ptr = NULL;
                cout << "inserted a data at the end" << endl;
            }
        }

        int getCount(){
            int count = 0;
            Node* ptr = HEAD;
            while (ptr != NULL){
                ++count;
                ptr = ptr -> next;
            }
            return count;
        }

        int getValue(int pos){
            Node* ptr = HEAD;
            for (int i = 0; i < pos && ptr != NULL; ++i)
                ptr = ptr -> next;

            if (ptr == NULL) return -1;
            return ptr -> data;
        }
};

int binarySearch(int searchKey, LinkedList& l, int size){
    int first = 0;
    int last = size - 1;
    
    while (first <= last){
        int mid = (first + last) / 2;
        int value = l.getValue(mid);
        if (searchKey == value) return mid;
        if (searchKey < value) last = mid - 1;
        else first = mid + 1;
    }
    return -1;
}

void merge(LinkedList & l, int low, int mid, int high){
    int index = 0;
    LinkedList temp;
    int 
        left = low,
        right = mid + 1;

    while (left <= mid && right <= high)
        if (l.getValue(left) < l.getValue(right))
            temp.insert_at_end(l.getValue(left++));
        else 
            temp.insert_at_end(l.getValue(right++));

    while (left <= mid)
        temp.insert_at_end(l.getValue(left++));

    while (right <= high)
        temp.insert_at_end(l.getValue(right++));
    
    for (int i = low; i <= high; ++i)
        l.overrite(i, temp.getValue(i - low));
}

void mergeSort(LinkedList & l, int low, int high){
    int mid = (low + high) / 2;
    if (low >= high) return;
    mergeSort(l, low, mid);
    mergeSort(l, mid + 1, high);
    merge(l, low, mid, high);
}

int partition(LinkedList&, int, int);

void quickSort(LinkedList &l, int low, int high){
    if (low >= high) return;
    int part = partition(l, low, high);
    quickSort(l, low, part - 1);
    quickSort(l, part + 1, high);
}

int partition(LinkedList& l, int low, int high){
    int pivot = l.getValue(low);
    int 
        i = low + 1,
        j = high,
        temp;
    while (i < j){
        while (i <= high && l.getValue(i) <= pivot) i++;
        while (j >= low && l.getValue(j) > pivot) j--;

        if (i < j){
            temp = l.getValue(i);
            l.overrite(i, l.getValue(j));
            l.overrite(j, temp);
        }
    }

    temp = l.getValue(low);
    l.overrite(low, l.getValue(j));
    l.overrite(j, temp);
    return j;
}

class ListID{
    public:
        LinkedList* listptr;
        string ID;
        bool isSorted;
        ListID(string ID, LinkedList* listptr): isSorted(false), listptr(listptr), ID(ID){}
};

ListID* getList(vector<ListID*>& vl){
    string id;
    cout << "Enter the existing list ID: ";
    cin >> id;
    for (int i = 0; i < vl.size(); ++i)
        if (vl[i]->ID == id) return vl[i];
    return 0;
}

bool listExists(string id, vector<ListID*>& vl){
    for (int i = 0; i < vl.size(); ++i)
        if (vl[i]->ID == id) return true;
    return false;
}

bool deleteList(ListID* listID, vector<ListID*>& vl){
    if (listID == 0) return false;
    for (int i = 0; i < vl.size(); ++i)
        if (vl[i]->ID == listID->ID){
            delete vl[i]->listptr;
            vl.erase(vl.begin() + i);
            return true;
        }
        return false;
}

// Try exploring "struct". An alternative to class

int main(){
    vector<ListID*> linkedlists;
    int choice, value, value2;
    LinkedList* ptr;
    do {
        cout << endl;
        cout << "Choose an options" << endl;
        cout << "1. Manage linked list" << endl;
        cout << "2. Modify an existing list" << endl;
        cout << "3. Sort a list" << endl;
        cout << "4. Search for key" << endl;
        cout << "5. Display a list" << endl;
        cout << "0. Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;
        cout << endl;
        switch (choice){
            case 0: cout << "Thank you for using this system" << endl; break;
            case 1:{
                    cout << "1. Create a new list" << endl;
                    cout << "2. Delete an existing list" << endl;
                    cout << "0. Return" << endl;
                    cout << "Your choice: ";
                    cin >> choice;
                    cout << endl;
                    switch (choice){
                        case 0: break;
                        case 1: {
                                string id;
                                cout << "Enter the new ID of the list: ";
                                cin >> id;
                                if (listExists(id, linkedlists)){
                                    cout << "List with this id already exists" << endl;
                                    break;
                                }
                                ListID* list = new ListID(id, new LinkedList);
                                linkedlists.push_back(list);
                                cout << "New linked list has been created with id (" << id << ")" << endl;
                                break;
                        }

                        case 2:
                            if (!deleteList(getList(linkedlists), linkedlists))
                                cout << "List with this id does not exists" << endl;
                            else 
                                cout << "List deleted" << endl;
                            break;
                    }
                    
                    choice = -1;
                }
                break;

            case 2:{
                if (linkedlists.size() <= 0){
                    cout << "You need to create a new linked list first" << endl;
                    break;
                }
                ListID* list = getList(linkedlists);
                if (list == 0){
                    cout << "List was not found" << endl;
                    break;
                }

                do {
                    cout << "1. Add new elements at the start" << endl;
                    cout << "2. Add new elements at the end" << endl;
                    cout << "3. Add new elements at the position" << endl;
                    cout << "4. Delete node from the start" << endl;
                    cout << "5. Delete node from the end" << endl;
                    cout << "6. Delete node from the position" << endl;
                    cout << "7. Update elements at the position" << endl;
                    cout << "0. Return" << endl;
                    cout << "Your choice: ";
                    cin >> choice;
                    cout << endl;

                    switch (choice){
                        case 0 : break;
                        case 1: {
                            if (list == NULL) {
                                cout << "List with that id does not exists" << endl;
                                break;
                            };
                            ptr = list->listptr;
                            cout << "Enter an element value: ";
                            cin >> value;
                            ptr -> insert_at_beginning(value);
                            list->isSorted = false;
                            }
                            break;
    
                        case 2: {
                            if (list == NULL) {
                                cout << "List with that id does not exists" << endl;
                                break;
                            };
    
                            ptr = list->listptr;
                            cout << "Enter an element value: ";
                            cin >> value;
                            ptr -> insert_at_end(value);
                            list->isSorted = false;
                            }
                            break;
    
                        case 3: {
                            if (list == NULL) {
                                cout << "List with that id does not exists" << endl;
                                break;
                            };
    
                            ptr = list->listptr;
                            cout << "Enter the position: ";
                            cin >> value2;
                            if (value2 < 0 || value2 >= ptr->getCount()){
                                cout << "Position overflow" << endl;
                                break;
                            }
                            cout << "Enter an element value: ";
                            cin >> value;
                            ptr -> insert_at_pos(value2, value);
                            list->isSorted = false;
                            }
                            break;
    
                        case 4: {
                            if (list == NULL) {
                                cout << "List with that id does not exists" << endl;
                                break;
                            };
                            ptr = list->listptr;
                            ptr -> delete_node(0);
                            }
                            break;
                        
                        case 5: {
                            if (list == NULL) {
                                cout << "List with that id does not exists" << endl;
                                break;
                            };
                            ptr = list->listptr;
                            ptr -> delete_from_end();
                            }
                            break;
    
                        case 6: {
                            if (list == NULL) {
                                cout << "List with that id does not exists" << endl;
                                break;
                            };
                            ptr = list->listptr;
                            cout << "Enter a position: ";
                            cin >> value;
                            ptr -> delete_node(value);
                            }
                            break;
                        
                        case 7: {
                            if (list == NULL) {
                                cout << "List with that id does not exists" << endl;
                                break;
                            };
                            ptr = list->listptr;
    
                            cout << "Enter a new value: ";
                            cin >> value;
                            cout << "Enter a position: ";
                            cin >> value2;
                            ptr -> overrite(value2, value);
                            list->isSorted = false;
                            }
                            break;
    
                        default:
                            cout << "Invalid choice... returning to main menu" << endl;
                    }
                } while (choice != 0);
                choice = -1;
                break;
            }
            
            case 3:{

                if (linkedlists.size() <= 0){
                    cout << "You need to create a new linked list first" << endl;
                    break;
                }
                ListID* list = getList(linkedlists);
                if (list == 0){
                    cout << "List was not found" << endl;
                    break;
                }
                do {
                    cout << "1. Merge Sort" << endl;
                    cout << "2. Quick Sort" << endl;
                    cout << "0. Return" << endl;
                    cout << "Your Choice: ";
                    cin >> choice;
                    cout << endl;

                    switch (choice){
                        case 0 : break;
                        case 1: {
                            if (list == 0) {
                                cout << "That list does not exists" << endl;
                                break;
                            }
                            ptr = list->listptr;
                            mergeSort(*ptr, 0, ptr->getCount() - 1);
                            list->isSorted = true; 
                            cout << "List sorted" << endl;
                            }
                            break;
    
                        case 2: {
                            if (list == 0) {
                                cout << "That list does not exists" << endl;
                                break;
                            }
                            ptr = list->listptr;
                            quickSort(*ptr, 0, ptr->getCount() - 1);
                            list->isSorted = true; 
                            cout << "List sorted" << endl;
                            }
                            break;
                        default: cout << "Invalid choice... returning" << endl;
                    }
                } while (choice != 0);
            }

                choice = -1;
                break;

            case 4: {
                ListID* list = getList(linkedlists);
                if (list == 0) {
                    cout << "That list does not exists" << endl;
                    break;
                }
                if (!list->isSorted){
                    cout << "This list isn't sorted. Do you want to try anyway? [1 for yes | 0 for no]: ";
                    cin >> value;
                    if (value == 0) break;
                }
                ptr = list->listptr;
                cout << "Enter the search key: ";
                cin >> value;
                int index = binarySearch(value, *ptr, ptr->getCount());
                if (index == -1)
                    cout << "value could not be found" << endl;
                else cout << "Key is found at index " << index << endl;
                }
                break;

            case 5:{
                ListID* list = getList(linkedlists);
                if (list == 0){
                    cout << "List with this id does not exists" << endl;
                    break;
                }
                ptr = list->listptr;
                ptr->display();
                }
                break;
            default:
                cout << "Invalid choice... try again" << endl;
        }
    } while (choice != 0);
    ptr = NULL;
    return 0;
}