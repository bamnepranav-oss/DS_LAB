#include<iostream>
using namespace std;

int main()
{
    int rollNo[10];
    int marks[10];
    int n = 0;
    int choice;
    int searchRollNo;

    do
    {
        cout << "\n\n==== STUDENT MANAGEMENT SYSTEM ====";
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Search Student";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter Roll No: ";
            cin >> rollNo[n];

            cout << "Enter Marks: ";
            cin >> marks[n];

            n++;
            cout << "Student Added!";
        }
 else if (choice == 2)
        {
            cout << "\nStudents in System:\n";

            for(int i = 0; i < n; i++)
            {
                cout << "Roll No: " << rollNo[i];
                cout << "  Marks: " << marks[i] << endl;
            }
        }

        else if (choice == 3)
        {
            cout << "Enter Roll No to search: ";
            cin >> searchRollNo;

            bool found = false;

            for (int i = 0; i < n; i++)
            {
                if (rollNo[i] == searchRollNo)
                {
                    found = true;
                    cout << "Student Found!";
                }
             }
            if (!found)
            {
                cout << "Student Not Found!";
            }
        }
else if (choice == 4)
        {
            cout << "Thank you!";
        }

        else
        {
            cout << "Invalid Choice!";
        }

    } while (choice != 4);

    return 0;
}

