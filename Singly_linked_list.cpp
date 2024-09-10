#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(NULL) {}
};

class LinkedList {
private:
    Node* head;
    
    // Utility method to get the length of the list
    int getLength() const {
        int length = 0;
        Node* temp = head;
        while (temp != NULL) {
            length++;
            temp = temp->next;
        }
        return length;
    }

public:
    LinkedList() : head(NULL) {}

    // Traversal
    void traverse() const {
        Node* temp = head;
        while (temp != NULL) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }

    // Searching
    bool search(int value) const {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Length
    int length() const {
        return getLength();
    }

    // Insertion at the beginning
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Insertion at the end
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Insertion at a specific position
    void insertAtPosition(int data, int position) {
        if (position < 0 || position > getLength()) {
            std::cout << "Invalid position!" << std::endl;
            return;
        }
        if (position == 0) {
            insertAtBeginning(data);
        } else {
            Node* newNode = new Node(data);
            Node* temp = head;
            for (int i = 1; i < position; ++i) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Deletion from the beginning
    void deleteFromBeginning() {
        if (head == NULL) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Deletion from the end
    void deleteFromEnd() {
        if (head == NULL) return;
        if (head->next == NULL) {
            delete head;
            head = NULL;
        } else {
            Node* temp = head;
            Node* prev = NULL;
            while (temp->next != NULL) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
            delete temp;
        }
    }

    // Deletion of a specific node
    void deleteNode(int value) {
        if (head == NULL) return;

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        Node* previous = NULL;

        while (current != NULL && current->data != value) {
            previous = current;
            current = current->next;
        }

        if (current == NULL) return; // Value not found

        previous->next = current->next;
        delete current;
    }

    // Destructor to clean up the list
    ~LinkedList() {
        Node* current = head;
        while (current != NULL) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    LinkedList list;
    int choice, data, position;

    while (true) {
        std::cout << "\nLinked List Operations Menu:\n";
        std::cout << "1. Insert at Beginning\n";
        std::cout << "2. Insert at End\n";
        std::cout << "3. Insert at Position\n";
        std::cout << "4. Delete from Beginning\n";
        std::cout << "5. Delete from End\n";
        std::cout << "6. Delete a Specific Node\n";
        std::cout << "7. Traverse\n";
        std::cout << "8. Search\n";
        std::cout << "9. Length\n";
        std::cout << "10. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: // Insert at Beginning
                std::cout << "Enter value to insert at beginning: ";
                std::cin >> data;
                list.insertAtBeginning(data);
                break;
            
            case 2: // Insert at End
                std::cout << "Enter value to insert at end: ";
                std::cin >> data;
                list.insertAtEnd(data);
                break;
            
            case 3: // Insert at Position
                std::cout << "Enter value and position to insert: ";
                std::cin >> data >> position;
                list.insertAtPosition(data, position);
                break;
            
            case 4: // Delete from Beginning
                list.deleteFromBeginning();
                break;
            
            case 5: // Delete from End
                list.deleteFromEnd();
                break;
            
            case 6: // Delete a Specific Node
                std::cout << "Enter value to delete: ";
                std::cin >> data;
                list.deleteNode(data);
                break;
            
            case 7: // Traverse
                std::cout << "List contents: ";
                list.traverse();
                break;
            
            case 8: // Search
                std::cout << "Enter value to search: ";
                std::cin >> data;
                std::cout << "Searching for " << data << ": " << (list.search(data) ? "Found" : "Not Found") << std::endl;
                break;
            
            case 9: // Length
                std::cout << "Length of the list: " << list.length() << std::endl;
                break;
            
            case 10: // Exit
                return 0;
            
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}

