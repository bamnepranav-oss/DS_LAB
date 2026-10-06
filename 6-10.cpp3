#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> bankQueue;
    int token;

    // Accept 5 customer token numbers
    cout << "===== BANK TOKEN MANAGEMENT SYSTEM =====\n";
    cout << "Enter 5 customer token numbers:\n";

    for (int i = 0; i < 5; i++)
    {
        cin >> token;
        bankQueue.push(token);
    }

    // Serve customers in the same order
    cout << "\n===== CUSTOMER SERVICE =====\n";

    while (!bankQueue.empty())
    {
        cout << "Now serving customer with Token No. "
             << bankQueue.front() << endl;

        bankQueue.pop();
    }

    cout << "\nAll customers have been served.\n";

    return 0;
}
