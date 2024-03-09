// Name : zaid , Section SE-A , Roll No : 22i-2513

#include<iostream>
#include<string>
using namespace std;


template<typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T value) : data(value), next(nullptr) {}
};



template<typename T>

class Linked_List {
private:
    Node<T>* head;
    int Size;

public:
    Linked_List() : head(nullptr), Size(0) {}

    void insert(T val) {
        Node<T>* NewNode = new Node<T>(val);
        NewNode->next = head;
        head = NewNode;
        Size++;
    }
    
    int getSize() {
        return Size;
    }

    bool IsPalindrome() {
        if (Size <= 1) 
            return true;

        Node<T>* SlowPre = head;
        
        Node<T>* FastNex = head;
       
        Node<T>* prev = nullptr;
        
        while (FastNex !=NULL && FastNex->next != NULL) {
            FastNex = FastNex->next->next;

            Node<T>* NxtNode = SlowPre->next;
            SlowPre->next = prev;
            prev = SlowPre;
            SlowPre = NxtNode;
        }

        
        if (FastNex != NULL)
            SlowPre = SlowPre->next;

        
        while (prev != NULL&& SlowPre != NULL) {
            if (prev->data != SlowPre->data)
                return false;
           
            
            prev = prev->next;
            
            
            SlowPre = SlowPre->next;
        }

        return true;
    }
};
template<typename T>
int Lenght(string cha) {

}

int main() {
    Linked_List<char> LIST;

    
    string STR1 = "deed";
    string STR2 = "radar";
    string STR3 = "hello";

    
    for (char c : STR1) {
        LIST.insert(c);
    }

    
    if (LIST.IsPalindrome())
        cout << "\"" << STR1 << "\" Is an " << (LIST.getSize() % 2 == 0 ? "Even" : "Odd") << " Palindrome .."<< endl;
    else
        cout << "\"" << STR1 << "\" Is not Palindrome." << endl;

    
    LIST = Linked_List<char>();

   
    for (char c : STR2) {
        LIST.insert(c);
    }

    
    if (LIST.IsPalindrome())
        cout << "\"" << STR2 << "\" Is an " << (LIST.getSize() % 2 == 0 ? "Even" : "Odd") << " Palindrome .." << endl;

    else
        cout << "\"" << STR2 << "\" is not a palindrome." << endl;

    LIST = Linked_List<char>();

    for (char c : STR3) {
        LIST.insert(c);
    }

    if (LIST.IsPalindrome())
        cout << "\"" << STR3 << "\" Is an " << (LIST.getSize() % 2 == 0 ? "Even" : "Odd") << " Palindrome .." << endl;

    else
        cout << "\"" << STR3 << "\" Is not  Palindrome..." << endl;

    return 0;
}
