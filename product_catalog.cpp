#include <iostream> #include <string> #include <vector> using namespace std;

const int SIZE = 10;

class Product { public: int id; string name; float price; int quantity; Product* next;

Product(int i, string n, float p, int q) {
    id = i;
    name = n;
    price = p;
    quantity = q;
    next = nullptr;
}


};

class ProductSystem { private: Product* head; vector<Product*> hashTable[SIZE];

int hashFunction(int id) {
    return id % SIZE;
}


public: ProductSystem() { head = nullptr; }

// Add Product
void addProduct(int id, string name, float price, int qty) {
    if (searchProduct(id) != nullptr) {
        cout << "Product ID already exists!\n";
        return;
    }

    Product* newNode = new Product(id, name, price, qty);

    newNode->next = head;
    head = newNode;

    int index = hashFunction(id);
    hashTable[index].push_back(newNode);

    cout << "Product added successfully!\n";
}

// Search Product
Product* searchProduct(int id) {
    if (id < 0)
        return nullptr;

    int index = hashFunction(id);

    for (Product* p : hashTable[index]) {
        if (p->id == id) {
            return p;
        }
    }

    return nullptr;
}

// Update Product
void updateProduct(int id) {
    Product* p = searchProduct(id);

    if (p == nullptr) {
        cout << "Product not found!\n";
        return;
    }

    cout << "Enter new name: ";
    cin >> p->name;

    cout << "Enter new price: ";
    cin >> p->price;

    cout << "Enter new quantity: ";
    cin >> p->quantity;

    cout << "Product updated successfully!\n";
}

// Remove Product
void removeProduct(int id) {
    Product* p = searchProduct(id);

    if (p == nullptr) {
        cout << "Product not found!\n";
        return;
    }

    // Remove from hash table
    int index = hashFunction(id);
    auto& bucket = hashTable[index];

    for (auto it = bucket.begin(); it != bucket.end(); ++it) {
        if (*it == p) {
            bucket.erase(it);
            break;
        }
    }

    // Remove from linked list
    Product* temp = head;
    Product* prev = nullptr;

    while (temp != nullptr && temp != p) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == nullptr) {
        head = temp->next;
    }
    else {
        prev->next = temp->next;
    }

    delete temp;

    cout << "Product removed successfully!\n";
}

// Display Products
void displayProducts() {
    Product* temp = head;

    if (temp == nullptr) {
        cout << "No products available!\n";
        return;
    }

    cout << "\n--- Product Catalog ---\n";

    while (temp != nullptr) {
        cout << "\nProduct ID: " << temp->id << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Price: " << temp->price << endl;
        cout << "Quantity: " << temp->quantity << endl;
        cout << "-------------------\n";

        temp = temp->next;
    }
}

// Destructor
~ProductSystem() {
    Product* temp = head;

    while (temp != nullptr) {
        Product* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
}


};

int main() { ProductSystem obj;

int choice, id, qty;
string name;
float price;

do {
    cout << "\n===== PRODUCT MANAGEMENT SYSTEM =====";
    cout << "\n1. Add Product";
    cout << "\n2. Update Product";
    cout << "\n3. Remove Product";
    cout << "\n4. Display Products";
    cout << "\n5. Search Product";
    cout << "\n6. Exit";

    cout << "\nEnter choice: ";
    cin >> choice;

    switch (choice) {

    case 1:
        cout << "Enter Product ID: ";
        cin >> id;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Price: ";
        cin >> price;

        cout << "Enter Quantity: ";
        cin >> qty;

        if (id < 0 || price < 0 || qty < 0) {
            cout << "Invalid product details!\n";
            break;
        }

        obj.addProduct(id, name, price, qty);
        break;

    case 2:
        cout << "Enter Product ID: ";
        cin >> id;
        obj.updateProduct(id);
        break;

    case 3:
        cout << "Enter Product ID: ";
        cin >> id;
        obj.removeProduct(id);
        break;

    case 4:
        obj.displayProducts();
        break;

    case 5:
        cout << "Enter Product ID: ";
        cin >> id;

        if (obj.searchProduct(id) != nullptr) {
            cout << "Product found!\n";
        }
        else {
            cout << "Product not found!\n";
        }
        break;

    case 6:
        cout << "Exiting program...\n";
        break;

    default:
        cout << "Invalid choice! Please try again.\n";
    }

} while (choice != 6);

return 0;


}
