#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Stack
{
public:
    T *arr;
    int top;
    int Capacity;

    Stack(int size)
    {
        top = -1;
        Capacity = size;
        arr = new T[size];
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(T x)
    {
        if (isFull())
        {
            cout << "stack is full" << endl;
            return;
        }
        arr[++top] = x;
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "stack empty" << endl;
            // return default value of T datatype
            return T();
        }
        return arr[top--];
    }

    T peek()
    {
        if (isEmpty())
        {
            cout << "empty stack" << endl;
            return T();
        }
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == Capacity - 1;
    }

    void printStack()
    {
        if (!isEmpty())
        {
            for (int i = 0; i <= top; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "empty stack" << endl;
        }
    }
};

string reverse(string s){
    Stack<char> cs(s.length());
    for(int i=0;i<s.length();i++){
        cs.push(s[i]);
    }
    string reversed = "";
    for(int i=0;i<s.length();i++){
        reversed += cs.pop();
    }
    return reversed;
}

// tolower works only on characters and not on string, therefore creating a utility function
string toLowercase(string s){
    string result = "";
    for(int i=0;i<s.length();i++){
        result += tolower(s[i]);
    }
    return result;
}

bool isPalindrome(string s){
    if(reverse(toLowercase(s)) == toLowercase(s)){
        return true;
    }

    return false;
}

int main(){
    string expression;
    cout << "enter expression : ";
    cin >> expression;

    // checking palindrome
    if(isPalindrome(expression)){
        cout << "is a palindrome" << endl;
    }else{
        cout << "is not a palindrome" << endl;
    }
}
