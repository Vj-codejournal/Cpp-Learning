#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* link;
    Node(int n)
    {
        this->data = n;
        this->link = NULL;
    }
};
 
class Stack {
    Node* top;
 
public:
    Stack() { top = NULL; }
 
    void push(int data)
    {
 
        
        Node* temp = new Node(data);
        if (!temp) {
            cout << "\nStack Overflow";
            exit(1);
        }
 
        
        //temp->data = data;
 
        
        temp->link = top;
        top = temp;
    }
 
    
    bool isEmpty()
    {
        return top == NULL;
    }
 
    
    int peek()
    {
        if (!isEmpty())
            return top->data;
        else
            cout<<"stack is empty\n";
            return -1;
    }
 
    
    void pop()
    {
        Node* temp;
 
        
        if (top == NULL) {
            cout << "\nStack Underflow" << endl;
            return;
        }
        else {
 
            temp = top;
            top = top->link;
            
            free(temp);
        }
    }
 
    
    
};
 

int prec(char c)
{
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}


void infixToPostfix(string s)
{

	Stack st;
	string result;

	for (int i = 0; i < s.length(); i++) {
		char c = s[i];

		
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9'))
			result += c;

		
		else if (c == '(')
			st.push('(');

		
		else if (c == ')') {
			while (st.peek() != '(') {
				result += st.peek();
				st.pop();
			}
			st.pop();
		}

		
		else {
			while (!st.isEmpty()
				&& prec(s[i]) <= prec(st.peek())) {
				result += st.peek();
				st.pop();
			}
			st.push(c);
		}
	}

	
	while (!st.isEmpty()) {
		result += st.peek();
		st.pop();
	}

	cout << result << endl;
}


int main()
{
	string exp = "a+b*c-d+e";

	cout<<exp<<endl;
	infixToPostfix(exp);
	
	return 0;
}