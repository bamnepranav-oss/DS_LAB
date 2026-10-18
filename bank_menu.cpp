
#include <iostream>
using namespace std;

int tokens[100];
int count = 0;
int served = 0;

void showMenu()
{
    int choice;

    cout << "\n===== BANK TOKEN SYSTEM =====\n";
    cout << "1. Issue Token\n";
    cout << "2. Display All Tokens\n";
    cout << "3. Serve Customer\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 4)
    {
        cout << "Thank you! Goodbye!\n";
        return;
    }

    switch (choice)
    {
        case 1:
            if (count < 100)
            {
                tokens[count] = count + 1;
                cout << "Token issued: " << tokens[count] << endl;
                count++;
            }
            else
            {
                cout << "Token limit reached!\n";
            }
            break;

        case 2:
            if (served == count)
                cout << "No waiting customers.\n";
            else
            {
                cout << "Waiting tokens: ";
                for (int i = served; i < count; i++)
                    cout << tokens[i] << " ";
                cout << endl;
            }
            break;

        case 3:
            if (served < count)
            {
                cout << "Serving token: "
                     << tokens[served] << endl;
                served++;
            }
            else
                cout << "No customers to serve.\n";
            break;

        default:
            cout << "Invalid choice!\n";
    }

    showMenu();
}

int main()
{
    showMenu();
    return 0;
}
