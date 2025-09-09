#include <iostream>
using namespace std;

class Stack {
private:
    struct Node {
        int info;
        Node* next;
    };
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(int n);
    void pop();
    void peek();
};

void Stack::push(int n) {
    Node* newNode = new Node;
    newNode->info = n;
    newNode->next = top;
    top = newNode;
}

void Stack::pop() {
    if (top == NULL) {
        cout << "\nStack empty";
    } else {
        Node* temp = top;
        top = top->next;
	cout << "\nDeleted element is " << temp->info;
	delete temp;
}
}

void Stack::peek()
{
    Node* current = top;
    if (current == NULL) 
        cout << "\nStack is empty";
    else {
        cout << "\nStack elements:\n";
        while (current != NULL) {
            cout << current->info << "\n";
            current = current->next;
        }
    }
}

int main() {
    Stack obj;
    char choice;
    int ch, data;

    do {
        cout << "\nStack Operations";
        cout << "\n*****************";
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Peek";
        cout << "\n4. Exit";
        cout << "\nWhich operation do you want to perform? ";
        cin >> ch;

        switch (ch) {
            case 1:{
		            cout << "\nEnter the data you want to push: ";
		            cin >> data;
		            obj.push(data);
		            break;
            }
	        case 2:{ 
    		        obj.pop();
	                break;
	        }
	        case 3:{ 
    		        obj.peek();
    		        break;
	        }
	        case 4:{ 
    		        exit(0);
    		        break;
	        }
	        default:
    		    cout << "\nPlease enter a valid choice";
}
cout << "\nDo you want to continue? (y/n): ";
cin >> choice;
} while (choice == 'y' || choice == 'Y');

return 0; 
}

