#include <bits/stdc++.h>
using namespace std;
 
//MAKING STACK
class Node {
public:
    char data;
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
 
    void push(char data)
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



void InfixToPostfix(string s){
    Stack st;
    string res;

    for(int i = 0;i<s.length();i++){
        if((s[i] >= 'a' && s[i]<= 'z') || (s[i] >= 'A' && s[i]<= 'Z') ||(s[i] >= '0' && s[i]<= '9')){
            res += s[i];
        }
        else if (s[i] == '(')
			st.push('(');

		
		else if (s[i] == ')') {
			while (st.peek() != '(') {
				res += st.peek();
				st.pop();
			}
			st.pop();
		}
        else{
            if(st.isEmpty()){
                st.push(s[i]);
            }
            else if(prec(st.peek())< prec(s[i]) ) {
                st.push(s[i]);
            }
            else{
                while(true){
                if(prec(st.peek())>= prec(s[i])){
                    res += st.peek();
                    st.pop();
                    if(st.isEmpty()){
                        st.push(s[i]);
                        break;
                    }
                }
                else{
                    st.push(s[i]);
                    break;
                }
                }

            }
        }
    }
    while(!st.isEmpty()){
        res += st.peek();
        st.pop();
    }

    cout<<res;


}
int main()
{
    
    
    //string exp = "a+b*c-d+e";
    string exp = "a*b+c/d*e-f";

	
	InfixToPostfix(exp);
    
 
    return 0;
}



// #include <iostream>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* link;
//     Node(int n)
//     {
//         this->data = n;
//         this->link = NULL;
//     }
// };
 
// class Stack {
//     Node* top;
 
// public:
//     Stack() { top = NULL; }
 
//     void push(int data)
//     {
 
        
//         Node* temp = new Node(data);
//         if (!temp) {
//             cout << "\nStack Overflow";
//             exit(1);
//         }
 
        
//         //temp->data = data;
 
        
//         temp->link = top;
//         top = temp;
//     }
 
    
//     bool isEmpty()
//     {
//         return top == NULL;
//     }
 
    
//     int peek()
//     {
//         if (!isEmpty())
//             return top->data;
//         else
//             cout<<"stack is empty\n";
//             return;
//     }
 
    
//     void pop()
//     {
//         Node* temp;
 
        
//         if (top == NULL) {
//             cout << "\nStack Underflow" << endl;
//             return;
//         }
//         else {
 
//             temp = top;
//             top = top->link;
            
//             free(temp);
//         }
//     }
 
    
    
// };
 

// int prec(char c)
// {
// 	if (c == '^')
// 		return 3;
// 	else if (c == '/' || c == '*')
// 		return 2;
// 	else if (c == '+' || c == '-')
// 		return 1;
// 	else
// 		return -1;
// }


// void infixToPostfix(string s)
// {

// 	Stack st;
// 	string result;

// 	for (int i = 0; i < s.length(); i++) {
// 		char c = s[i];

		
// 		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
// 			|| (c >= '0' && c <= '9'))
// 			result += c;

		
// 		else if (c == '(')
// 			st.push('(');

		
// 		else if (c == ')') {
// 			while (st.peek() != '(') {
// 				result += st.peek();
// 				st.pop();
// 			}
// 			st.pop();
// 		}

//*************************************************************		
// 		else {
// 			while (!st.isEmpty()
// 				&& prec(s[i]) <= prec(st.peek())) {
// 				result += st.peek();
// 				st.pop();
// 			}
// 			st.push(c);
// 		}
// 	}
//**************************************************************
	
// 	while (!st.isEmpty()) {
// 		result += st.peek();
// 		st.pop();
// 	}

// 	cout << result << endl;
// }


// int main()
// {
// 	string exp = "a+b*c-d+e";

	
// 	infixToPostfix(exp);
	
// 	return 0;
// }