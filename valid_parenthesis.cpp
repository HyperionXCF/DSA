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

    ~Stack(){
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

bool isValid(string s){
    Stack<char> charStack(s.size());
    for(int i=0;i<s.length();i++){
        char c = s[i];
        if (c == '(' || c == '[' || c == '{'){
            charStack.push(c);
        }else{
            if(charStack.isEmpty()){
                return false;
            }

            if((c == ')' && charStack.peek() == '(') ||
                (c == ']' && charStack.peek() == '[') ||
                (c == '}' && charStack.peek() == '{'))
            {
                charStack.pop();
            }else{
                return false;
            }
        }
    }

    return charStack.top == -1;
}

int main(){
    // manual testing
    string expression;
    cout << "enter expression : ";
    cin >> expression;

    if(isValid(expression)){
        cout << "Valid Parenthesis" << endl;
    }else{
        cout << "Invalid Parenthesis" << endl;
    }

    // automatic testing
    vector<string> tests = {
        "()",
        "()[]{}",
        "{[()()]}",
        "(]",
        "([)]",
        "(((",
        "{{[[(())]]}}",
        "){",
        ""};

    for (string expr : tests)
    {
        cout << "Expression: " << expr << " -> "
             << (isValid(expr) ? "Valid" : "Invalid") << endl;
    }

    return 0;
}
