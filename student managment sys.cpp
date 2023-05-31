#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class node {
public:
    int roll_no;// id
    string name;
    float mark, per;
    node* next;// pointer to next node
};
class linked_list {
public:
    node* head = NULL;
    node* tail = NULL;
    void insert_info() {
        int r;
        string n;
        float m;
        cout << "Enter Roll Number: ";
        cin >> r;

        cout << "Enter Your Name: ";
        cin >> n;

        do {
            cout << "Enter Marks (out of 150): ";
            cin >> m;
            if (m < 0 || m > 150)
            {

                cout << "Wrong value, Please Enter again\n";
            }
        } while (m < 0 || m > 150);// not responding to next block of code untill right marks inserted


        node* newnode = new node;// create new node
        // assign values 
        newnode->roll_no = r;
        newnode->name = n;
        newnode->mark = m;
        newnode->per = m / 150 * 100;

        if (head == NULL) {
            head = tail = newnode;
            newnode->next = NULL;
        }
        else {
            tail->next = newnode;
            tail = newnode;
            newnode->next = NULL;
        }

        cout << "NEW NODE INSERTED SUCCEFULLY \n";
        cout << "**********************************\n";
    }


    void search() {
        if (head == NULL) {
            cout << "No records yet...";
        }
        else {
            int r;
            bool found = 0;
            cout << "enter roll_no for search: ";
            cin >> r;
            node* ptr = head;
            while (ptr != NULL) {
                if (r == ptr->roll_no) {
                    cout << "roll_no: " << ptr->roll_no << endl;
                    cout << "Name: " << ptr->name << endl;
                    cout << "Marks: " << ptr->mark << endl;
                    cout << "Per %: " << ptr->per << endl;
                    found = true;
                    break;
                }
                ptr = ptr->next;
            }
            if (!found) {// if not found
                cout << " search roll_no " << r << " can't found... ";
            }
        }

        cout << "**********************************\n";
    }


    void display() {
        if (head == NULL) {
            cout << "No records yet...";
        }
        else {
            int r;
            node* ptr = head;
            while (ptr != NULL) {

                cout << "roll_no:" << ptr->roll_no << endl;
                cout << "Name:" << ptr->name << endl;
                cout << "Marks:" << ptr->mark << endl;
                cout << "Per %:" << ptr->per << endl;
                ptr = ptr->next;
            }

        }

        cout << "**********************************\n";
    }


    void del()
    {
        if (head == NULL)
        {
            cout << "No records yet...";
        }
        else
        {
            int r;
            cout << "Enter Roll no. For Delete:";
            cin >> r;
            node* ptr = head;
            node* prev = head;
            if (r == ptr->roll_no)
            {
                head = ptr->next;
                cout << "Record Delete Successefully...\n";
                delete ptr;
                return;
            }
            else
            {
                while (r != ptr->roll_no)
                {
                    prev = ptr;
                    ptr = ptr->next;
                }
                prev->next = ptr->next;
                delete ptr;
                cout << "Delete Roll no." << r << endl;
            }
        }

        cout << "**********************************\n";
    }


    void count() {
        if (head == NULL) {
            cout << "No records yet...\n";
        }
        else {
            int cnt = 0;
            node* ptr = head;
            while (ptr != NULL) {
                cnt++;
                ptr = ptr->next;
            }
            cout << "total number of node is: " << cnt << endl;
        }

        cout << "**********************************\n";

    }


    void save_to_file()
    {
        if (head == NULL)
        {
            cout << "No records yet...";
        }
        else
        {
            ofstream file;
            file.open("students.txt");
            node* ptr = head;
            while (ptr != NULL) {
                file << ptr->roll_no << " " << ptr->name << " " << ptr->mark << " " << ptr->per << "%" << endl;
                ptr = ptr->next;
            }
            file.close();
        }

        cout << "File saved Successefully" << endl;
        cout << "**********************************\n";
    }
};


int main()
{
    linked_list obj;
    int ch;
    cout << endl;
    cout << "\t\t\t********** STUDENT MANAGMENT SYSTEM **********\t\t\t\n";
    cout << endl;
    cout << "\t\t\t\t__PLEASE SELECT ONE OPTION__\t\t\t\n";
    cout << endl;
    cout << "1) INSERT INFO \n";
    cout << "2) SEARCH RECORD \n";
    cout << "3) DISPALY ALL RECORD \n";
    cout << "4) DELETE RECORD \n";
    cout << "5) COUNT NODE \n";
    cout << "6) Save \n";
    cout << "0) EXIT \n";
    cout << endl;

    do
    {
        cout << "YOUR CHOICE-> ";
        cin >> ch;
        switch (ch)
        {
        case 1: {obj.insert_info(); break; }
        case 2: {obj.search(); break; }
        case 3: {obj.display(); break; }
        case 4: {obj.del(); break; }
        case 5: {obj.count(); break; }
        case 6: {obj.save_to_file(); break; }
        case 0: {cout << "EXIT\n"; break; }
        default: {cout << "INVALID CHOICE \n"; }
        }

    } while (ch != 0);
}
