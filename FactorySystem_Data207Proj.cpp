#include <bits / stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
//#include <bits/stdc++.h>
using namespace std;

//The array that unique IDs are generated and stored into
int existing_ids[1001] = { 0 };

//Counters to keep track of everything
int counting_processs = 0;
int counting_suppliers = 0;
int counting_parts = 0;

// Function that generates Unique IDs randomly
int generateUniqueId() {
    while (true) {
        int new_id = rand() % 1000 + 1;    // Random ID between 1 and 1000
        if (existing_ids[new_id] == 0) {   // to not repeat a random ID that has been generated before
            existing_ids[new_id] = 1;
            return new_id;
        }
    }
}

// Class of Spare Parts
class spare_parts
{
private:

    string part_name;
    int part_id, part_count;
    double part_cost;

public:

    //Default values Constructor
    spare_parts() { part_name = " "; part_count = 0;part_cost = 0.0; set_part_id(); }

    //User values Constructor
    spare_parts(string name, double cost, int cnt)
    {
        part_name = name;part_count = cnt; part_cost = cost; set_part_id();
    }


    //Setters and Getters

    void set_part_name(string name) { part_name = name; }
    string get_part_name() { return part_name; }

    void set_part_id() { part_id = generateUniqueId(); }
    int get_part_id() { return part_id; }

    void set_part_count(int cnt) { part_count = cnt; }
    int get_part_count() { return part_count; }

    void set_part_cost(double num) { part_cost = num; }
    double get_part_cost() { return part_cost; }


    //Insert new spare part
    void Insert_Part()
    {
        cout << "ADD Spare Part details:\n-----------------------------------------------\n";

        //Inform the user with the ID saved in the system
        cout << "Part ID: " << get_part_id() << "\n";

        cout << "Enter Part Name: " << "\n";
        string name;        cin >> name;
        set_part_name(name);

        cout << "Enter Part Count: " << "\n";
        int cnt;            cin >> cnt;
        set_part_count(cnt);

        cout << "Enter Part Cost: \n";
        double cost;        cin >> cost;
        set_part_cost(cost);
    }

    //Modify the spare part Count and Cost
    void modify_part_class(int choice, double modified)
    {
        while (true)
        {
            //Exit condition
            if (choice == 0) break;

            //Modify the Count
            if (choice == 2)
            {
                set_part_count(modified);
                break;
            }

            //Modify the Cost
            else if (choice == 3)
            {
                set_part_cost(modified);
                break;
            }
        }
    }

    //Modify the spare part Name
    void modify_part_class(int choice, string modified)
    {
        while (true)
        {
            //Exit condition
            if (choice == 0) break;

            //Modify the Name
            if (choice == 1)
            {
                set_part_name(modified);
                break;
            }
        }
    }

    //Display spare part Info
    void display_part()
    {
        cout << "Display Spare Part:\n-----------------------------------------------\n";
        cout << "Part Name: " << get_part_name() << "\n";
        cout << "Part ID: " << get_part_id() << "\n";
        cout << "Part Count: " << get_part_count() << "\n";
        cout << "Part Cost: " << get_part_cost() << "\n";
    }
};


//Class of Supplier
class supplier
{
private:

    string supplier_name, supplier_address, supplier_email;
    int supplier_code, supplier_phone;

public:

    //Default values Constructor
    supplier() { supplier_name = ""; supplier_address = ""; supplier_phone = 0; supplier_email = ""; set_supplier_code(); }

    //User Values Constructor
    supplier(string name, int code, string address, int phone, string email)
        : supplier_name(name), supplier_code(generateUniqueId()), supplier_address(address), supplier_phone(phone), supplier_email(email) {}


    //Setters and Getters

    void set_supplier_name(string name) { supplier_name = name; }
    string get_supplier_name() { return supplier_name; }

    void set_supplier_code() { supplier_code = generateUniqueId(); }
    int get_supplier_code() { return supplier_code; }

    void set_supplier_address(string address) { supplier_address = address; }
    string get_supplier_address() { return supplier_address; }

    void set_supplier_phone(int phone) { supplier_phone = phone; }
    int get_supplier_phone() { return supplier_phone; }

    void set_supplier_email(string email) { supplier_email = email; }
    string get_supplier_email() { return supplier_email; }


    //Display Supplier Info
    void display_supplier()
    {
        cout << "Display Supplier details:\n";
        cout << "Supplier Name: " << get_supplier_name() << "\n";
        cout << "Supplier Code: " << get_supplier_code() << "\n";
        cout << "Supplier Address: " << get_supplier_address() << "\n";
        cout << "Supplier Phone: " << get_supplier_phone() << "\n";
        cout << "Supplier Email: " << get_supplier_email() << "\n";
    }

    //Insert new Supplier
    void add_supplier()
    {
        cout << "Add Supplier details:\n-----------------------------------------------\n";

        //Inform the user with the ID saved in the system
        cout << "Supplier Code: " << get_supplier_code() << "\n";

        cout << "Enter Supplier Name: ";
        string name;          cin >> name;
        set_supplier_name(name);

        cout << "Enter Supplier Address: ";
        string address;       cin >> address;
        set_supplier_address(address);

        cout << "Enter Supplier Phone: ";
        int ph;               cin >> ph;
        set_supplier_phone(ph);

        cout << "Enter Supplier Email: ";
        string mail;          cin >> mail;
        set_supplier_email(mail);
    }

    //Modify Supplier Name - Address - Email
    void modify_supplier_class(int choice, string modified)
    {
        //Modify Name
        if (choice == 1)
        {
            set_supplier_name(modified);
        }

        //Modify Address
        else if (choice == 2)
        {
            set_supplier_address(modified);
        }

        //Modify Email
        else if (choice == 4)
        {
            set_supplier_email(modified);
        }
    }

    //Modify Supplier Phone number
    void modify_supplier_class(int choice, int modified)
    {
        if (choice == 3)
        {
            set_supplier_phone(modified);
        }
    }


};
//-----------------------------------------
//Add bridge class using linked list for linking the realtion between classes

//Node of the bridge class
class BridgeNode {
public:
    int part_id;  //Spare part
    int supplier_code;  //Supplier Code
    BridgeNode* next;

    BridgeNode(int partId, int supplierCode) : part_id(partId), supplier_code(supplierCode), next(nullptr) {}
};

class BridgeList {
private:
    BridgeNode* head;

public:
    BridgeList() : head(nullptr) {}

    //Add a new node representing the link between the classes
    bool addLink(int partId, int supplierCode)
    {
        //Check if they don't exist
        if (existing_ids[partId] == 0 || existing_ids[supplierCode] == 0)
        {
            cout << "ID Doesn't Exist!\n";
            return 0;
        }

        //If the ID and Code exist add the new node at the head
        BridgeNode* newNode = new BridgeNode(partId, supplierCode);
        newNode->next = head;
        head = newNode;
        return 1;
    }

    //Display all links
    void displayLinks()
    {
        BridgeNode* current = head;

        while (current != nullptr)
        {
            cout << "There is a Link between Spare Part with ID: " << current->part_id << ",and Supplier with Code: " << current->supplier_code << "\n";
            current = current->next;
        }
    }

    //------------------------------------------------------------------------------------------
    //Three Cases for deleting a link (With both Info - with Supplier Code - with Spare Part ID)
    //------------------------------------------------------------------------------------------

    //Delete a node link taking both Info
    bool removeLink(int partId, int supplierCode)
    {
        BridgeNode* current = head;
        BridgeNode* prev = nullptr;

        while (current != nullptr)
        {
            //Finding the desired two values to delete
            if (current->part_id == partId && current->supplier_code == supplierCode)
            {
                // If it's the first node
                if (prev == nullptr) { head = current->next; }
                else { prev->next = current->next; }

                delete current;
                return true;
            }

            prev = current;
            current = current->next;
        }
        // Link not found
        return false;
    }

    //Delete a node link taking supplier Code only (delete all supplier occurrenece)
    void remove_supplier_link(int supplier_code)
    {
        BridgeNode* curr = head;
        BridgeNode* prev = nullptr;

        while (curr != nullptr)
        {
            if (curr->supplier_code == supplier_code)
            {
                if (prev == nullptr) { head = curr->next; delete curr; }
                else prev->next = curr->next;
                delete curr;
            }
            else
            {
                prev = curr;
                curr = curr->next;

            }
        }
    }

    //Delete a node link taking Spare Part ID only (delete all Parts occurrenece)
    void remove_part_link(int id)
    {
        BridgeNode* curr = head;
        BridgeNode* prev = nullptr;

        while (curr != nullptr)
        {
            if (curr->part_id == id)
            {
                if (prev == nullptr) { head = curr->next; delete curr; }
                else prev->next = curr->next;
                delete curr;
            }
            else
            {
                prev = curr;
                curr = curr->next;

            }
        }
    }

};

//-----------------------------------------------------------------------
//Double linked list Node
template <class T>
class Node_DLL
{
public:

    T value;
    Node_DLL<T>* next;
    Node_DLL<T>* prev;

    Node_DLL(T info)
    {
        value = info;
        next = nullptr;
        prev = nullptr;
    }

};

//-------------------------------------------------------------------------

//Double linked list for Supplier
template <class T>
class supplier_DLL {
public:
    Node_DLL<T>* head;
    Node_DLL<T>* tail;

    //Constructor
    supplier_DLL()
    {
        head = nullptr;
        tail = nullptr;
    }

    //Display all suppliers in the DLL
    void Display_all()
    {
        Node_DLL<T>* temp = head;

        while (temp != nullptr) {
            temp->value.display_supplier();
            temp = temp->next;
        }
        cout << endl;
    }

    //Insert a new node (new supplier) at the tail
    void insertAtTail(T entry_Values)
    {
        Node_DLL<T>* newNode = new Node_DLL<T>(entry_Values);

        //In case the DLL is empty
        if (tail == nullptr)
        {
            head = tail = newNode;
        }

        //Not empty
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    //Delete a Supplier Node by Supplier ID
    void delete_supplier(int id)
    {
        Node_DLL<T>* temp = head;

        //DLL is empty
        if (head == nullptr)
        {
            cout << "There is nothing to delete" << endl;
            return;
        }

        //Deleted node is the first one / handled lw hya bs elly mwgoda fl DLL
        else if (head->value.get_supplier_code() == id)
        {
            head = head->next;

            //In case no node after the deleted one
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }

        //Delete from middle or end
        else
        {
            //once found the id break the loop with temp on the desired node to delete
            while (temp != nullptr && temp->value.get_supplier_code() != id)
            {
                temp = temp->next;
            }

            //Reached end of DLL and ID doesn't exist
            if (temp == nullptr)
            {
                cout << "This ID doesn't exist" << endl;
                return;
            }
            //Found the node with the ID need to be deleted
            //Delete the last Node
            if (temp->value.get_supplier_code() == id && temp->next == nullptr)
            {
                temp->prev->next = temp->next;    // making it's next be nullptr
            }

            //Delete from middle
            else if (temp->value.get_supplier_code() == id && temp->next != nullptr)
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            delete temp;
            return;
        }
    }

    //Search for the Supplier in the DLL with it's ID and display it when found
    bool search_supplier(int id)
    {
        Node_DLL<T>* temp = head;

        while (temp != nullptr)
        {
            if (id == temp->value.get_supplier_code())
            {
                temp->value.display_supplier();
                return 1;
            }
            else
            {
                temp = temp->next;
            }
        }
        return 0;
    }

    //Modify int values of a certain supplier in DLL 
    //ID -> node code in DLL  || choice -> which int value do u want to modify || modified -> new value
    void modify_supplier(int id, int choice, int modified)
    {
        Node_DLL<T>* temp = head;

        while (temp != nullptr)
        {
            //Found the code of supplier need to be modified
            if (id == temp->value.get_supplier_code())
            {
                temp->value.modify_supplier_class(choice, modified);
                return;
            }
            else
            {
                temp = temp->next;
            }
        }
        //End of DLL without finding the node needs to be modified
        if (temp == nullptr) {
            cout << "ID doesn't exist" << endl;
            return;
        }
    }

    //Modify string values of a certain supplier in DLL 
    //ID -> node code in DLL  || choice -> which int value do u want to modify || modified -> new value
    void modify_supplier(int id, int choice, string modified)
    {
        Node_DLL<T>* temp = head;
        while (temp != nullptr)
        {
            //Found the code of supplier need to be modified
            if (id == temp->value.get_supplier_code())
            {
                temp->value.modify_supplier_class(choice, modified);
                return;
            }
            else
            {
                temp = temp->next;
            }
        }
        //End of DLL without finding the node needs to be modified
        if (temp == nullptr)
        {
            cout << "ID doesn't exist" << endl;
            return;
        }
    }
};
//-------------------------------------------------------------------

//Double linked list for Spare Part
template <class T>
class spare_parts_DLL
{
public:
    Node_DLL<T>* head;
    Node_DLL<T>* tail;

    //Constructor
    spare_parts_DLL()
    {
        head = nullptr;
        tail = nullptr;
    }

    //Display all spare parts nodes in DLL 
    void Display_all()
    {
        Node_DLL<T>* temp = head;

        while (temp != nullptr)
        {
            temp->value.display_part();
            temp = temp->next;
        }
        cout << endl;
    }

    //Insert new node(new spare part) at the tail
    void insertAtTail(T entryValues)
    {
        Node_DLL<T>* newNode = new Node_DLL<T>(entryValues);

        //In case the DLL is empty
        if (tail == nullptr)
        {
            head = tail = newNode;
        }

        //Not empty
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    //--------------------------------------------------------------

    //Delete a spare part node from DLL by it's ID
    void delete_part(int id)
    {
        Node_DLL<T>* temp = head;

        //DLL is empty
        if (head == nullptr)
        {
            cout << "There is nothing to delete" << endl;
            return;
        }

        //Deleted node is the first one / handled lw hya bs elly mwgoda fl DLL
        else if (head->value.get_part_id() == id)
        {
            head = head->next;

            ////In case no node after the deleted one
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }

        //Delete from middle or end
        else
        {
            while (temp != nullptr && temp->value.get_part_id() != id)
            {
                temp = temp->next;
            }

            //Reached end of DLL and ID doesn't exist
            if (temp == nullptr)
            {
                cout << "This ID doesn't exist" << endl;
                return;
            }
            //Found the node with the ID need to be deleted

            //Delete the last Node
            if (temp->value.get_part_id() == id && temp->next == nullptr)
            {
                temp->prev->next = temp->next;   // making it's next be nullptr
            }

            //Delete from middle
            else if (temp->value.get_part_id() == id && temp->next != nullptr)
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

            }
            delete temp;
            return;
        }
    }

    //Modify int values of a certain spare part in DLL 
    //ID -> node code in DLL  || choice -> which int value do u want to modify || modified -> new value
    void modify_part(int id, int choice, int modified)
    {
        Node_DLL<T>* temp = head;

        while (temp != nullptr)
        {
            //Found the code of supplier need to be modified
            if (id == temp->value.get_part_id())
            {
                temp->value.modify_part_class(choice, modified);
                return;
            }
            else
            {
                temp = temp->next;
            }
        }
        //End of DLL without finding the node needs to be modified
        if (temp == nullptr)
        {
            cout << "ID doesn't exist" << endl;
            return;
        }
    }

    //Modify string values of a certain spare part in DLL 
    //ID -> node code in DLL  || choice -> which int value do u want to modify || modified -> new value
    void modify_part(int id, int choice, string modified)
    {
        Node_DLL<T>* temp = head;
        while (temp != nullptr)
        {
            //Found the code of supplier need to be modified
            if (id == temp->value.get_part_id())
            {
                temp->value.modify_part_class(choice, modified);
                return;
            }
            else
            {
                temp = temp->next;
            }
        }
        //End of DLL without finding the node needs to be modified
        if (temp == nullptr)
        {
            cout << "ID doesn't exist" << endl;
            return;
        }
    }

    //Search for the spare part in the DLL with it's ID and display it when found
    bool search_part(int id)
    {
        Node_DLL<T>* temp = head;

        while (temp != nullptr)
        {
            if (id == temp->value.get_part_id())
            {
                temp->value.display_part();
                return 1;
            }
            else
            {
                temp = temp->next;
            }
        }
        return 0;
    }
};

//---------------------------------------------------------

//Node of the Binary Tree
template <class T>
class Node_BST
{
public:
    Node_BST<T>* right;
    Node_BST<T>* left;
    T value;

    Node_BST(T info)
    {
        value = info;
        right = nullptr;
        left = nullptr;
    }
};

//----------------------------------------------------
template <class T>
class BST_suppliers
{
public:
    Node_BST<T>* root;

    BST_suppliers()
    {
        root = nullptr;
    }


    Node_BST<T>* insert_supplier(Node_BST<T>*& root, T info)
    {
        Node_BST<T>* newNode = new Node_BST<T>(info);
        if (root == nullptr) {
            root = newNode;
            return root;
        }
        else if (info.get_supplier_code() > root->value.get_supplier_code())
        {
            root->right = insert_supplier(root->right, info);
        }
        else
        {
            root->left = insert_supplier(root->left, info);
        }
        return root;
    }

    void BST_Display_supplier(Node_BST<T>* root) {
        Node_BST<T>* temp = root;
        if (temp == nullptr)
            return;
        BST_Display_supplier(temp->left);
        temp->value.display_supplier();
        BST_Display_supplier(temp->right);
    }

    bool BST_search_supplier(int id) {
        Node_BST<T>* temp = root;
        while (temp != nullptr) {
            if (id == temp->value.get_supplier_code()) {
                temp->value.display_supplier();
                return 1;
            }
            else if (id < temp->value.get_supplier_code()) {
                temp = temp->left;
            }
            else {
                temp = temp->right;
            }
        }
        return 0; // if not found
    }
    bool BST_search_supplier_(int id) {
        Node_BST<T>* temp = root;
        while (temp != nullptr) {
            if (id == temp->value.get_supplier_code()) {
                return 1;
            }
            else if (id < temp->value.get_supplier_code()) {
                temp = temp->left;
            }
            else {
                temp = temp->right;
            }
        }
        return 0; // if not found
    }
    void BST_modify_Supplier(int id, int choice, int modified) {
        Node_BST<T>* temp = root;
        if (temp == nullptr) {
            cout << "Tree is Empty\n";
            return;
        }
        while (temp != nullptr) {
            if (id == temp->value.get_supplier_code()) {
                temp->value.modify_supplier(choice, modified);
                return;
            }
            else if (id < temp->value.get_supplier_code()) {
                temp = temp->left;
            }
            else {
                temp = temp->right;
            }
        }
        if (temp == nullptr) {
            cout << "ID not found";
            return;
        }

    }


    void BST_modify_Supplier(int id, int choice, string modified) {
        Node_BST<T>* temp = root;
        if (temp == nullptr) {
            cout << "Tree is Empty\n";
            return;
        }
        while (temp != nullptr) {
            if (id == temp->value.get_supplier_code()) {
                temp->value.modify_supplier_class(choice, modified);
                return;
            }
            else if (id < temp->value.get_supplier_code()) {
                temp = temp->left;
            }
            else {
                temp = temp->right;
            }
        }
        if (temp == nullptr) {
            cout << "ID not found";
            return;
        }

    }

    Node_BST<T>* BST_delete_supplier(int id) {
        root = BST_delete_supplier(root, id);
        return root;
    }

    Node_BST<T>* findMinValue(Node_BST<T>* root) {
        if (root == nullptr) {
            return nullptr;
        }

        while (root->left != nullptr) {
            root = root->left;
        }

        return root;
    }

    Node_BST<T>* BST_delete_supplier(Node_BST<T>* root, int id) {
        if (root == nullptr) {
            return root;
        }

        if (id < root->value.get_supplier_code()) {
            root->left = BST_delete_supplier(root->left, id);
        }
        else if (id > root->value.get_supplier_code()) {
            root->right = BST_delete_supplier(root->right, id);
        }
        else {
            if (root->left == nullptr) {
                Node_BST<T>* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                Node_BST<T>* temp = root->left;
                delete root;
                return temp;
            }

            Node_BST<T>* temp = findMinValue(root->right);

            root->value = temp->value;

            root->right = BST_delete_supplier(root->right, temp->value.get_supplier_code());
        }

        return root;
    }
};


//--------------------------------------------------


template <class T>
class BST_spare_parts {
public:
    Node_BST<T>* root;

    BST_spare_parts() {
        root = nullptr;
    }

    Node_BST<T>* insert_part(Node_BST<T>*& root, T info) {
        Node_BST<T>* newNode = new Node_BST<T>(info);
        if (root == nullptr) {
            root = newNode;
            return root;
        }
        else if (info.get_part_id() > root->value.get_part_id()) {
            root->right = insert_part(root->right, info);
        }
        else {
            root->left = insert_part(root->left, info);
        }
        return root;
    }

    void BST_Display_part(Node_BST<T>* root) {
        Node_BST<T>* temp = root;
        if (temp == nullptr)
            return;
        BST_Display_part(temp->left);
        temp->value.display_part();
        BST_Display_part(temp->right);
    }


    //search with displaying
    bool BST_search_part(int id) {
        Node_BST<T>* temp = root;
        while (temp != nullptr) {
            if (id == temp->value.get_part_id()) {
                temp->value.display_part();
                return 1;
            }
            else if (id < temp->value.get_part_id()) {
                temp = temp->left;
            }
            else {
                temp = temp->right;
            }
        }
        return 0; // if not found
    }

    //search chaeck only
    bool BST_search_part_(int id) {
        Node_BST<T>* temp = root;
        while (temp != nullptr) {
            if (id == temp->value.get_part_id()) {
                return 1;
            }
            else if (id < temp->value.get_part_id()) {
                temp = temp->left;
            }
            else {
                temp = temp->right;
            }
        }
        return 0; // if not found
    }



    void BST_modify_Parts(int id, int choice, int modified) {
        Node_BST<T>* temp = root;
        if (temp == nullptr) {
            cout << "Tree is Empty\n";
            return;
        }
        while (temp != nullptr) {
            if (id == temp->value.get_part_id()) {
                temp->value.modify_part_class(choice, modified);
                return;
            }
            else if (id < temp->value.get_part_id()) {
                temp = temp->left;
            }
            else {
                temp = temp->right;
            }
        }
        if (temp == nullptr) {
            cout << "ID not found";
            return;
        }

    }

    void BST_modify_Parts(int id, int choice, string modified) {
        Node_BST<T>* temp = root;
        if (temp == nullptr) {
            cout << "Tree is Empty\n";
            return;
        }
        while (temp != nullptr) {
            if (id == temp->value.get_part_id()) {
                temp->value.modify_part_class(choice, modified);
                return;
            }
            else if (id < temp->value.get_part_id()) {
                temp = temp->left;
            }
            else {
                temp = temp->right;
            }
        }
        if (temp == nullptr) {
            cout << "ID not found";
            return;
        }

    }

    Node_BST<T>* BST_delete_part(int id) {
        root = BST_delete_part(root, id);
        return root;
    }

    Node_BST<T>* findMinValue(Node_BST<T>* root) {
        if (root == nullptr) {
            return nullptr;
        }

        while (root->left != nullptr) {
            root = root->left;
        }

        return root;
    }

    Node_BST<T>* BST_delete_part(Node_BST<T>* root, int id) {
        if (root == nullptr) {
            return root;
        }

        if (id < root->value.get_part_id()) {
            root->left = BST_delete_part(root->left, id);
        }
        else if (id > root->value.get_part_id()) {
            root->right = BST_delete_part(root->right, id);
        }
        else {
            if (root->left == nullptr) {
                Node_BST<T>* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                Node_BST<T>* temp = root->left;
                delete root;
                return temp;
            }

            Node_BST<T>* temp = findMinValue(root->right);

            root->value = temp->value;

            root->right = BST_delete_part(root->right, temp->value.get_part_id());
        }

        return root;
    }
};
class QSNode {
public:
    string data;
    QSNode* next;

    QSNode() {
        data = "";
        next = nullptr;
    }
    QSNode(string newData) : data(newData), next(nullptr) {}
};
class Stack {
public:
    QSNode* top;


    Stack() {
        top = nullptr;
    }


    void push(string happened) {
        QSNode* new_node = new QSNode();
        new_node->data = happened;
        new_node->next = top;
        top = new_node;
    }

    void DisplayHistory() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Displaying History: " << endl;
        QSNode* temp = top;
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
        cout << "\n";
    }
    void DeleteHistory() {
        while (top != nullptr) {
            QSNode* temp = top;
            top = top->next;
            delete temp;
        }
    }
};
class Queue {
public:
    QSNode* front, * rear;
    Stack stack;

    Queue() {
        front = rear = NULL;
    }
    void enqueue(string action) {
        QSNode* new_action = new QSNode(action);
        if (rear == nullptr) {
            front = rear = new_action;
            return;
        }
        rear->next = new_action;
        rear = new_action;
    }
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        QSNode* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;  // Queue is empty after dequeue
        }
        delete temp;
    }

    //taking string and put it in the queue then stack
    void display(string what_happen) {1
        enqueue(what_happen);
        cout << "Processing: " << front->data << '\n';
        dequeue();
        what_happen = "At process number " + to_string(counting_processs) + " : " + what_happen;
        stack.push(what_happen);

    }
};
//-----------------------------------------------------------------------------
int main() {
    std::srand(std::time(0));
    supplier_DLL<supplier> suppliersList;
    spare_parts_DLL<spare_parts> partsList;
    BridgeList bridge;
    BST_suppliers<supplier> suppliersTree;
    BST_spare_parts<spare_parts> partsTree;
    Queue queue;
    //  Stack stack
    while (true)
    {
        int choice;
        cout << "\nMenu:\n";
        cout << "1. Add Supplier\n";
        cout << "2. Add Spare Part\n";
        cout << "3. Display Certain Supplier Details\n";
        cout << "4. Display Certain Spare Part's Details\n";
        cout << "5. Modify Certain Supplier Details\n";
        cout << "6. Modify Certain Spare Part's Details\n";
        cout << "7. Display Suppliers Tree\n";
        cout << "8. Display Parts Tree\n";
        cout << "9. Display Suppliers Linked list\n";
        cout << "10. Display Parts Linked list\n";
        cout << "11. Link Part to Supplier\n";
        cout << "12. Display Linked Parts and Suppliers\n";
        cout << "13. Remove Link Between Part and Supplier\n";
        cout << "14. Remove Supplier and Associated Links\n";
        cout << "15. Remove Spare Part and Associated Links\n";
        cout << "16. Display History Stack\n";
        cout << "17. Delete History Stack\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.clear();
        cin.ignore();
        counting_processs++;
        if (choice == 0) break;
        //1. Add Supplier
        if (choice == 1)
        {
            if (counting_suppliers > 20) cout << "Can't add\n";
            else {
                supplier newSupplier;
                newSupplier.add_supplier();
                suppliersList.insertAtTail(newSupplier);
                suppliersTree.insert_supplier(suppliersTree.root, newSupplier);
                string st = "User added new supplier, Suppliers Code is: " + to_string(newSupplier.get_supplier_code());
                queue.display(st);
                counting_suppliers++;
            }
        }
        //2. Add Spare Part
        else if (choice == 2)
        {
            if (counting_parts > 100) cout << "Can't add\n";
            else {
                spare_parts newPart;
                newPart.Insert_Part();
                partsList.insertAtTail(newPart);
                partsTree.insert_part(partsTree.root, newPart);
                counting_parts++;
                string st = "User added new spare part, Part ID is: " + to_string(newPart.get_part_id());
                queue.display(st);
            }
        }
        //3. Display Certain Supplier Details
        else if (choice == 3)
        {
            int code;
            cout << "Enter Supplier Code: ";
            cin >> code;
            cin.clear();
            cin.ignore();
            suppliersTree.BST_search_supplier(code);
            string st = "User Searched for supplier using code: " + to_string(code);
            queue.display(st);
        }
        //4. Display Certain Spare Part's Details
        else if (choice == 4)
        {
            int id;
            cout << "Enter Part ID: ";
            cin >> id;
            cin.clear();
            cin.ignore();
            partsTree.BST_search_part(id);
            string st = "User Searched for part using id: " + to_string(id);
            queue.display(st);
        }
        //5. Modify Certain Supplier Details
        else if (choice == 5)
        {
            int id;
            cout << "Enter Supplier ID: ";
            cin >> id;
            cin.clear();
            cin.ignore();
            if (suppliersTree.BST_search_supplier_(id))
            {
                cout << "Which Supplier Info would you like to modify:\n";
                cout << "Enter 0 to Exit\n" << "Enter 1 for Name.\n" <<
                    "Enter 2 for the address\n" << "Enter 3 for Phone\n"
                    << "Enter 4 for the email\n";
                while (true)
                {
                    int choice;
                    cin.ignore();
                    cin >> choice;
                    if (choice == 0) break;
                    if (choice == 1)
                    {
                        string name;
                        cout << "\nEnter the new Name here: ";
                        cin >> name;
                        cin.clear();
                        cin.ignore();
                        suppliersList.modify_supplier(id, choice, name);
                        suppliersTree.BST_modify_Supplier(id, choice, name);
                        break;
                    }
                    else if (choice == 2)
                    {
                        string addre;
                        cout << "\nEnter the new address here: ";
                        cin >> addre;
                        suppliersList.modify_supplier(id, choice, addre);
                        suppliersTree.BST_modify_Supplier(id, choice, addre);
                        break;
                    }
                    else if (choice == 3)
                    {
                        int num;
                        cout << "\nEnter the new phone number here: ";
                        cin >> num;
                        cin.clear();
                        cin.ignore();
                        suppliersList.modify_supplier(id, choice, num);
                        suppliersTree.BST_modify_Supplier(id, choice, num);
                        break;
                    }
                    else if (choice == 4)
                    {
                        string mail;
                        cout << "\nEnter the new email here: ";
                        cin >> mail;
                        suppliersList.modify_supplier(id, choice, mail);
                        suppliersTree.BST_modify_Supplier(id, choice, mail);
                        break;
                    }
                }
                string st = "User Modified a supplier using code: " + to_string(id);
                queue.display(st);
            }
            else
            {
                cout << "ID Not found\n";
                string st = "User attempted to Modify a supplier using code: " + to_string(id) + "but code wasn't found.";
                queue.display(st);
            }
        }
        //6. Modify Certain Spare Part's Details
        else if (choice == 6)
        {
            int id;
            cout << "Enter Part ID: ";
            cin >> id;
            cin.clear();
            cin.ignore();
            if (partsTree.BST_search_part_(id))
            {
                cout << "Which Spare Part property would you like to modify:\n";
                cout << "Enter 0 to Exit\n" << "Enter 1 for Name.\n" << "Enter 2 for count\n" << "Enter 3 for the cost\n";
                while (true)
                {
                    int choice;
                    cin.ignore();
                    cin >> choice;
                    if (choice == 0) break;
                    if (choice == 1)
                    {
                        string name;
                        cout << "\nEnter the new Name here: ";
                        cin >> name;
                        cin.clear();
                        cin.ignore();
                        partsList.modify_part(id, choice, name);
                        partsTree.BST_modify_Parts(id, choice, name);
                        break;
                    }
                    else if (choice == 2)
                    {
                        int num;
                        cout << "\nEnter the new count here: ";
                        cin >> num;
                        cin.clear();
                        cin.ignore();
                        partsList.modify_part(id, choice, num);
                        partsTree.BST_modify_Parts(id, choice, num);
                        break;
                    }
                    else if (choice == 3)
                    {
                        double cost;
                        cout << "\nEnter the new Cost here: ";
                        cin >> cost;
                        partsList.modify_part(id, choice, cost);
                        partsTree.BST_modify_Parts(id, choice, cost);
                        break;
                    }
                }
                string st = "............\nUser Modified a spare part using id: " + to_string(id);
                queue.display(st);
            }
            else
            {
                cout << "ID wasn't found\n";
                string st = "............\nUser attempted to Modify a spare part using id: " + to_string(id) + "but id wasn't found.";
                queue.display(st);
            }
        }
        //7. Display Suppliers Tree
        else if (choice == 7)
        {
            string st = "............\nUser requested to display the supplier tree\n";
            queue.display(st);
            suppliersTree.BST_Display_supplier(suppliersTree.root);
        }
        //8. Display Parts Tree\n
        else if (choice == 8)
        {
            string st = "............\nUser requested to display the spare parts tree\n";
            queue.display(st);
            partsTree.BST_Display_part(partsTree.root);
        }
        //9. Display Suppliers Linked list
        else if (choice == 9)
        {
            string st = "............\nUser requested to display the supplier linked list\n";
            queue.display(st);
            suppliersList.Display_all();
        }
        //10. Display Parts Linked list
        else if (choice == 10)
        {
            string st = "............\nUser requested to display the spare parts linked list\n";
            queue.display(st);
            partsList.Display_all();
        }
        //11. Link Part to Supplier
        else if (choice == 11)
        {
            int partId;
            int supplierCode;
            cout << "Enter Part ID: ";
            cin >> partId;
            cout << "Enter Supplier Code: ";
            cin >> supplierCode;
            cin.clear();
            cin.ignore();
            if (suppliersTree.BST_search_supplier_(supplierCode))
            {
                bridge.addLink(partId, supplierCode);
                string st = "User added link between the spare part has id : " + to_string(partId) + "and supplier has code : " + to_string(supplierCode);
                queue.display(st);
            }
            else
            {
                cout << "Supplier code isn't found.\n";
                string st = "User attempted to add link between the spare part has id : " + to_string(partId) + "and supplier has code : " + to_string(supplierCode);
                queue.display(st);
            }
        }
        //12. Display Linked Parts and Suppliers
        else if (choice == 12)
        {
            string st = "............\nUser requested to display all the links between the spare parts and suppliers\n";
            queue.display(st);
            bridge.displayLinks();
        }
        //13. Remove Link Between Part and Supplier
        else if (choice == 13)
        {
            int partId;
            int supplierCode;
            cout << "Enter Part ID: ";
            cin >> partId;
            cout << "Enter Supplier Code: ";
            cin >> supplierCode;
            cin.clear();
            cin.ignore();
            if (suppliersTree.BST_search_supplier_(supplierCode) == 0 || existing_ids[partId] == 0)
            {
                cout << "Code or Id doesn't exist\n";
            }
            bridge.removeLink(partId, supplierCode);
            string st = "............\nUser requsted to remove the link between the spare part has id : " + to_string(partId) + "and supplier has code : " + to_string(supplierCode);
            queue.display(st);
        }
        //14. Remove Supplier and Associated Links
        else if (choice == 14)
        {
            int supplierCode;
            cout << "Enter Supplier Code: ";
            cin >> supplierCode;
            cin.clear();
            cin.ignore();
            bridge.remove_supplier_link(supplierCode);
            suppliersTree.BST_delete_supplier(supplierCode);
            suppliersList.delete_supplier(supplierCode);
            string st = "............\nUser requsted to delete the supplier : " + to_string(supplierCode);
            queue.display(st);
            counting_suppliers--;

            // to let the id be randomly chosen again
            existing_ids[supplierCode] = 0;
        }
        //15. Remove Spare Part and Associated Links
        else if (choice == 15)
        {
            int partId;
            cout << "Enter Part ID: ";
            cin >> partId;
            cin.clear();
            cin.ignore();
            bridge.remove_part_link(partId);
            partsTree.BST_delete_part(partId);
            partsList.delete_part(partId);
            string st = "............\nUser requsted to delete the spare part : " + to_string(partId);
            queue.display(st);
            counting_processs--;

            // to let the id be randomly chosen again
            existing_ids[partId] = 0;
        }
        //16. Display History Stack
        else if (choice == 16)
        {
            string st = "User requsted to display the history\n";
            queue.display(st);
            queue.stack.DisplayHistory();

        }
        //17. Delete History Stack
        else if (choice == 17)
        {
            string st = "............\nUser requsted to delete the history\n";
            queue.display(st);
            queue.stack.DeleteHistory();
        }
        else cout << "Invalid choice. Please enter a valid option.\n";
    }
    cout << "Displaying the stack\n";
    queue.stack.DisplayHistory();
    cout << "Exiting program. Goodbye!\n";

    return 0;
}
