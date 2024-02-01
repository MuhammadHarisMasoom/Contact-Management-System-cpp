// Including header files
#include <iostream>
#include <conio.h>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

struct node
{
    string firstName, lastName, phoneNumber, email;
    node *next;
} *head = NULL;

void insertion()
{
    // Inputing contact data to file using ofstream class object "out"
    ofstream out;
    out.open("contactList.txt", ios::app);

    cin.ignore();
    node *temp = new node;

    cout << "First name: ";
    getline(cin, temp->firstName);
    out << temp->firstName << " ";

    cout << "Last name: ";
    getline(cin, temp->lastName);
    out << temp->lastName << "\t";

    cout << "Contact number: ";
    getline(cin, temp->phoneNumber);
    out << temp->phoneNumber << "\t";

    cout << "Email address: ";
    getline(cin, temp->email);
    out << temp->email << endl;

    out.close();

    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        node *ref;
        ref = head;
        while (ref->next != NULL)
        {
            ref = ref->next;
        }
        ref->next = temp;
    }
}

node *deletion(string name1)
{
    if (head == NULL)
    {
        cout << "Contact list is empty" << endl;
    }
    else
    {

        node *p;
        node *q;
        q = head;
        p = head->next;
        if (q->firstName == name1) // if node to be deleted found at the start of linked list
        {
            head = p;
            delete (q);
        }
        else
        {
            while (p->firstName != name1)
            {
                p = p->next;
                q = q->next;
            }
            if (p->next == NULL) // if node to be deleted found at the end of linked list
            {
                q->next = NULL;
                delete (p);
            }
            else
            {
                q->next = p->next; // if node to be deleted found at the middle of linked list
                delete (p);
            }
        }
    }
    return head; //
}

void update(string name2)
{
    cin.ignore();
    node *p;
    p = head;
    while (p != NULL)
    {
        if (p->firstName == name2)
        {
            char c;
            cout << "Press n for updating name\nPress p for updating phone number\nPress e for updating email"
                 << endl;
            cin >> c;
            if (c == 'n' || c == 'N')
            {
                cin.ignore();
                cout << "First name: ";
                getline(cin, p->firstName);
                cout << "Last name: ";
                getline(cin, p->lastName);
                cout << "Contact information updated successfully" << endl;
            }
            else if (c == 'p' || c == 'P')
            {
                cin.ignore();
                cout << "Enter new phone number: ";
                getline(cin, p->phoneNumber);
                cout << "Contact information updated successfully" << endl;
            }
            else if (c == 'e' || c == 'E')
            {
                cin.ignore();
                cout << "Enter new email: ";
                getline(cin, p->email);
                cout << "Contact information updated successfully" << endl;
            }
            break;
        }
        else if (p->firstName != name2)
        {
            cout << "Invalid input" << endl; //
        }
        p = p->next;
    }
}

void search(string search)
{
    cin.ignore();
    node *p;
    p = head;
    while (p != NULL)
    {
        if (p->firstName == search)
        {
            cout << "Name: " << p->firstName << " " << p->lastName << "\t";
            cout << "Phone number: " << p->phoneNumber << "\t";
            cout << "Email: " << p->email << endl;
            return;
        }
        p = p->next;
    }
    cout << "Contact not found" << endl;

    // int offset;
    // string line;

    // ifstream myFile;
    // myFile.open("contactList.txt");

    // if (myFile.is_open())
    // {
    //     while (!myFile.eof())
    //     {
    //         getline(myFile, line);
    //         if ((offset = line.find(search, 0)) != string::npos)
    //         {
    //             cout << "Contact found and contact name is " << search << endl;
    //         }
    //     }
    //     myFile.close();
    // }
    // else
    // {
    //     cout << "File not found" << endl;
    // }
}

void display()
{
    // ifstream in;
    // string st;
    // in.open("contactList.txt");

    // cout << endl;
    // if (!in)
    // {
    //     cout << "File not found" << endl;
    // }
    // else
    // {
    //     cout << "----------------------------------------------------------" << endl;
    //     cout << "Name\t\t"
    //          << "Number\t\t\t"
    //          << "email" << endl;
    //     cout << "----------------------------------------------------------" << endl;
    //     while (in.eof() == 0)
    //     {
    //         getline(in, st);
    //         cout << st << endl;
    //         cout << "----------------------------------------------------------" << endl;
    //     }
    //     in.close();
    
    cout << endl;
    node *ref;
    ref = head;
    if (ref == NULL)
    {
        cout << "Contact list is empty";
    }
    else
    {
        cout << "---------------------------------------------------------------" << endl;
        cout << "NAME\t\t\t"
             << "PHONE NUMBER\t\t"
             << "EMAIL" << endl;
        while (ref != NULL)
        {
            cout << "---------------------------------------------------------------" << endl;
            cout << "" << ref->firstName << " " << ref->lastName << "\t\t";
            cout << ref->phoneNumber << "\t\t\t";
            cout << ref->email << endl;
            ref = ref->next;
        }
    }
    cout << "---------------------------------------------------------------" << endl;
    cout << endl;
}

void menu()
{
    int x = 1;
    while (x == 1)
    {
        cout << endl;
        system("color 0A");
        cout << "\t\t\t\t--------------------------" << endl;
        cout << "\t\t\t\t|CONTACT MANAGEMENT SYSTEM|" << endl;
        cout << "\t\t\t\t--------------------------" << endl;

        cout << endl;
        cout << "\t\t\tPress 1 for adding new contact number" << endl;
        cout << "\t\t\tPress 2 for deleting a contact number" << endl;
        cout << "\t\t\tPress 3 for updating a contact" << endl;
        cout << "\t\t\tPress 4 for searching a contact number" << endl;
        cout << "\t\t\tPress 5 to display all contact numbers" << endl;
        cout << "\t\t\tPress 6 to exit" << endl;
        cout << endl;
        cout << "\t\t\t> ";
        char y;
        cin >> y;
        switch (y)
        {
        case '1':
        {
            insertion();
            break;
        }
        case '2':
        {
            string name1;
            cout << "Enter only first name: ";
            cin >> name1;
            deletion(name1);
            break;
        }
        case '3':
        {
            string name2;
            cout << "Enter only first name: ";
            cin >> name2;
            update(name2);
            break;
        }
        case '4':
        {
            string name3;
            cout << "Enter only first name: ";
            cin >> name3;
            search(name3);
            break;
        }
        case '5':
        {
            display();
            break;
        }
        case '6':
        {
            cout << "Exit successfully" << endl;
            exit(EXIT_SUCCESS);
        }
        default:
            cout << "Invalid input" << endl;
            cout << "Press any key to continue..." << endl;
            getch();
            menu();
            break;
        }
    }
}

int main()
{
    menu();
    return 0;
}
