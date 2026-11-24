cpp
#include <iostream>
#include <string>
using namespace std;

struct Folder
{
    string name;
    Folder* left;
    Folder* right;
};

// Creates a new folder
Folder* createFolder(string name)
{
    Folder* newFolder = new Folder;

    newFolder->name = name;
    newFolder->left = NULL;
    newFolder->right = NULL;

    return newFolder;
}

// Search folder
Folder* searchFolder(Folder* root, string key)
{
    if (root == NULL)
        return NULL;

    if (root->name == key)
        return root;

    Folder* found = searchFolder(root->left, key);

    if (found != NULL)
        return found;

    return searchFolder(root->right, key);
}

// Add subfolder
void addSubFolder(Folder* root, string parent, string child)
{
    Folder* p = searchFolder(root, parent);

    if (p == NULL)
    {
        cout << "Parent folder not found!" << endl;
        return;
    }

    if (p->left == NULL)
    {
        p->left = createFolder(child);
        cout << "Subfolder added to left successfully!" << endl;
    }
    else if (p->right == NULL)
    {
        p->right = createFolder(child);
        cout << "Subfolder added to right successfully!" << endl;
    }
    else
    {
        cout << "Folder can have only two subfolders!" << endl;
    }
}

// Preorder traversal
void preorder(Folder* root)
{
    if (root == NULL)
        return;

    cout << root->name << " ";

    preorder(root->left);
    preorder(root->right);
}

// Display folder structure
void display(Folder* root, int level)
{
    if (root == NULL)
        return;

    for (int i = 0; i < level; i++)
        cout << "    ";

    cout << "|-- " << root->name << endl;

    display(root->left, level + 1);
    display(root->right, level + 1);
}

int main()
{
    Folder* root = NULL;

    int choice;
    string name, parent, child;

    do
    {
        cout << "\n===== FOLDER MANAGEMENT SYSTEM =====\n";
        cout << "1. Create Main Folder\n";
        cout << "2. Add Subfolder\n";
        cout << "3. Search Folder\n";
        cout << "4. Display Folder Structure\n";
        cout << "5. Preorder Traversal\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                if (root == NULL)
                {
                    cout << "Enter main folder name: ";
                    cin >> name;

                    root = createFolder(name);

                    cout << "Main folder created successfully!" << endl;
                }
                else
                {
                    cout << "Main folder already exists!" << endl;
                }
                break;

            case 2:
                cout << "Enter parent folder name: ";
                cin >> parent;

                cout << "Enter subfolder name: ";
                cin >> child;

                addSubFolder(root, parent, child);
                break;

            case 3:
                cout << "Enter folder name to search: ";
                cin >> name;

                if (searchFolder(root, name) != NULL)
                    cout << "Folder found!" << endl;
                else
                    cout << "Folder not found!" << endl;

                break;

            case 4:
                if (root == NULL)
                    cout << "No folders available!" << endl;
                else
                {
                    cout << "\n----- FOLDER STRUCTURE -----\n";
                    display(root, 0);
                }
                break;

            case 5:
                if (root == NULL)
                    cout << "No folders available!" << endl;
                else
                {
                    cout << "Preorder Traversal: ";
                    preorder(root);
                    cout << endl;
                }
                break;

            case 6:
                cout << "Exiting Folder Management System..." << endl;
                break;

            default:
                cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
