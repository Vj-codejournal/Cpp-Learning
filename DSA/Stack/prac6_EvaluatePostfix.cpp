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
            exit(1);
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
int evaluatePostfix(char * exp)
{
	
	Stack st;

	int checker=1;
	for (int i = 0; exp[i] != '\0'; i++) {
		if(exp[i] == ' '){
            continue;
        }
		
		if (exp[i] <= '9' && exp[i]>='0'){
            int value = exp[i] - '0';
            while(checker){
                
                if(exp[++i] != ' ')
                value = value*10 + (exp[i] - '0');
                else
                checker = 0;
            }
			st.push(value);
			i--;
			
        }
		
		else {
			int val1 = st.peek();
			st.pop();
			int val2 = st.peek();
			st.pop();
			switch (exp[i]) {
			case '+':
				st.push(val2 + val1);
				break;
			case '-':
				st.push(val2 - val1);
				break;
			case '*':
				st.push(val2 * val1);
				break;
			case '/':
				st.push(val2 / val1);
				break;
			}
		}

        checker =1;
	}
	return st.peek();
}


int main()
{
	char exp[] = "5 3 * 10 5 / 4 * + 8 -";
	//char exp[] = "5 6 3 * + 4 - 1 +";
	
    //15

	
	cout << "postfix evaluation: " << evaluatePostfix(exp);
	return 0;
}