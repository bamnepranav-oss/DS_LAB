#include <iostream>
#include <string>
using namespace std;

struct Folder {
    string name;
    Folder* left;
    Folder* right;

    Folder(string n) {
        name = n;
        left = nullptr;
        right = nullptr;
    }
};

class FolderManagement {
private:
    Folder* root;

    Folder* searchFolder(Folder* node, string name) {
        if (node == nullptr)
            return nullptr;

        if (node->name == name)
            return node;

        Folder* found = searchFolder(node->left, name);

        if (found != nullptr)
            return found;

        return searchFolder(node->right, name);
    }

    void display(Folder* node, int level) {
        if (node == nullptr)
            return;

        for (int i = 0; i < level; i++)
            cout << "    ";

        cout << "|-- " << node->name << endl;

        display(node->left, level + 1);
        display(node->right, level + 1);
    }

public:
    FolderManagement() {
        root = nullptr;
    }

    void createRoot(string name) {
        if (root == nullptr) {
            root = new Folder(name);
            cout << "Main folder created successfully!\n";
        } else {
            cout << "Main folder already exists!\n";
        }
    }

    void addSubFolder(string parent, string child) {
        Folder* p = searchFolder(root, parent);

        if (p == nullptr) {
            cout << "Parent folder not found!\n";
            return;
        }

        if (p->left == nullptr) {
            p->left = new Folder(child);
            cout << "Subfolder added to left successfully!\n";
        }
        else if (p->right == nullptr) {
            p->right = new Folder(child);
            cout << "Subfolder added to right successfully!\n";
        }
        else {
            cout << "Folder can have only two subfolders!\n";
        }
    }

    void search(string name) {
        if (searchFolder(root, name) != nullptr)
            cout << "Folder '" << name << "' found!\n";
        else
            cout << "Folder not found!\n";
    }

    void displayStructure() {
        if (root == nullptr) {
            cout << "No folders available!\n";
            return;
        }

        cout << "\n----- FOLDER STRUCTURE -----\n";
        display(root, 0);
    }
};

int main() {
    FolderManagement fm;
    int choice;
    string folder, parent, child;

    do {
        cout << "\n===== FOLDER MANAGEMENT SYSTEM =====\n";
        cout << "1. Create Main Folder\n";
        cout << "2. Add Subfolder\n";
        cout << "3. Search Folder\n";
        cout << "4. Display Folder Structure\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter main folder name: ";
            cin >> folder;
            fm.createRoot(folder);
            break;

        case 2:
            cout << "Enter parent folder name: ";
            cin >> parent;

            cout << "Enter subfolder name: ";
            cin >> child;

            fm.addSubFolder(parent, child);
            break;

        case 3:
            cout << "Enter folder name to search: ";
            cin >> folder;
            fm.search(folder);
            break;

        case 4:
            fm.displayStructure();
            break;

        case 5:
            cout << "Exiting Folder Management System...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
