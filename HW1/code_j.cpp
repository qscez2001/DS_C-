#include "function.h"
#include <iostream>

class CharStack {
private:
    long int top;
    char stack[1000000];
public:
    CharStack() {
        // init top
        top = -1;
    }
    
    void push(char c) {
        // update stack and top
        top += 1;
        stack[top] = c;
    }
    
    char pop() {
        char poped_value;
        
        if (top > -1) {
            poped_value = stack[top];
            
            // update top
            top -= 1;
        }
        else {
            poped_value = '\0'; // TODO: refactor
        }
        
        return poped_value;
    }
    
    std::string to_string() {
        /*
         char str[top+2];
         for (long int i=top; i>-1; i--) {
         str[i] = stack[i];
         }
         str[top+1] = '\0';*/
        
        //std::cout<<"DEBUG: str = "<<std::string(str)<<std::endl;
        return std::string(stack);
    }
    
    char get_top_char() {
        if (top > -1) {
            return stack[top];
        }
        else {
            return '\0';
        }
    }
};

class IntStack {
private:
    long int top;
    int stack[100000];
public:
    IntStack() {
        // init top
        top = -1;
    }
    
    void push(int i) {
        // update stack and top
        top += 1;
        stack[top] = i;
        //std::cout<<"DEBUG: stack[top] = "<<stack[top]<<std::endl;
    }
    
    int pop() {
        int poped_value;
        
        if (top > -1) {
            poped_value = stack[top];
            
            // update top
            top -= 1;
        }
        else {
            poped_value = 0; // TODO: refactor
        }
        
        //std::cout<<"DEBUG: poped_value = "<<poped_value<<std::endl;
        return poped_value;
    }
};


class Implement : public Parenthesis {
private:
    bool has_operand;
    std::string revised_expression;
    std::string postfix_expression;
    
    bool c1_greater_than_c2(char c1, char c2) {
        if (c2 == '\0') {
            return true;
        }
        else if (c2 == '(') {
            return true;
        }
        else if ((c1 == '*' || c1 == '/') && (c2 == '+' || c2 == '-')) {
            return true;
        }
        else {
            return false;
        }
    }
    
    void eval_postfix() {
        /*
         Algorithm
         1. Create a stack to store operands (or values).
         2. Scan the given expression and do following for every scanned element.
         …..a) If the element is a number, push it into the stack
         …..b) If the element is a operator, pop operands for the operator from stack. Evaluate the operator and push the result back to the stack
         3. When the expression is ended, the number in the stack is the final answer
         */
        
        int value = 0;
        
        IntStack *stack = new IntStack();
        
        char c;
        int left_operand;
        int right_operand;
        
        // scan each character of postfix_expression, from left to right, one chracter one time till \0
        for (long int i=0; ; i++) {
            c = postfix_expression[i];
            
            if (c == '\0') {
                // break for loop when the end of line \0 is scanned
                break;
            }
            else {
                // update stack
                switch (c) {
                    case '+':
                        right_operand = stack->pop();
                        left_operand = stack->pop();
                        stack->push(left_operand + right_operand);
                        //std::cout<<"DEBUG: "<<left_operand<<" + "<<right_operand<<" = "<<left_operand + right_operand<<std::endl;
                        break;
                    case '-':
                        right_operand = stack->pop();
                        left_operand = stack->pop();
                        stack->push(left_operand - right_operand);
                        //std::cout<<"DEBUG: "<<left_operand<<" - "<<right_operand<<" = "<<left_operand - right_operand<<std::endl;
                        break;
                    case '*':
                        right_operand = stack->pop();
                        left_operand = stack->pop();
                        stack->push(left_operand * right_operand);
                        //std::cout<<"DEBUG: "<<left_operand<<" * "<<right_operand<<" = "<<left_operand * right_operand<<std::endl;
                        break;
                    case '/':
                        right_operand = stack->pop();
                        left_operand = stack->pop();
                        stack->push(left_operand / right_operand);
                        //std::cout<<"DEBUG: "<<left_operand<<" / "<<right_operand<<" = "<<left_operand / right_operand<<std::endl;
                        break;
                    default:
                        stack->push(c - '0');
                        //std::cout<<"DEBUG: c = "<<c<<std::endl;
                        break;
                }
            }
        }
        
        // update value
        value = stack->pop();
        
        // print the evaluated value
        std::cout<<value<<std::endl;
    }
    
    void infix_to_postfix() {
        /*
         Algorithm
         1. Scan the infix expression from left to right.
         2. If the scanned character is an operand, output it.
         3. Else,
         …..3.1 If the precedence of the scanned operator is greater than the precedence of the operator in the stack(or the stack is empty), push it.
         …..3.2 Else, Pop the operator from the stack until the precedence of the scanned operator is less-equal to the precedence of the operator residing on the top of the stack. Push the scanned operator to the stack.
         4. If the scanned character is an ‘(‘, push it to the stack.
         5. If the scanned character is an ‘)’, pop and output from the stack until an ‘(‘ is encountered.
         6. Repeat steps 2-6 until infix expression is scanned.
         7. Pop and output from the stack until it is not empty.
         
         */
        
        CharStack *stack1 = new CharStack();
        CharStack *stack2 = new CharStack();
        
        char c1;
        char c2;
        
        // scan each character of revised_expression, from left to right, one chracter one time till \0
        for (long int i=0; ; i++) {
            c1 = revised_expression[i];
            
            if (c1 == '\0') {
                // break for loop when the end of line \0 is scanned
                break;
            }
            else {
                switch (c1) {
                    case '+':
                        c2 = stack1->get_top_char();
                        while (! c1_greater_than_c2(c1, c2)) {
                            c2 = stack1->pop();
                            stack2->push(c2);
                            c2 = stack1->get_top_char();
                        }
                        stack1->push(c1);
                        break;
                    case '-':
                        c2 = stack1->get_top_char();
                        while (! c1_greater_than_c2(c1, c2)) {
                            c2 = stack1->pop();
                            stack2->push(c2);
                            c2 = stack1->get_top_char();
                        }
                        stack1->push(c1);
                        break;
                    case '*':
                        c2 = stack1->get_top_char();
                        while (! c1_greater_than_c2(c1, c2)) {
                            c2 = stack1->pop();
                            stack2->push(c2);
                            c2 = stack1->get_top_char();
                        }
                        stack1->push(c1);
                        break;
                    case '/':
                        c2 = stack1->get_top_char();
                        while (! c1_greater_than_c2(c1, c2)) {
                            c2 = stack1->pop();
                            stack2->push(c2);
                            c2 = stack1->get_top_char();
                        }
                        stack1->push(c1);
                        break;
                    case '{':
                        stack1->push('(');
                        break;
                    case '}':
                        while (true) {
                            c2 = stack1->pop();
                            if (c2 == '(') {
                                break;
                            }
                            else {
                                stack2->push(c2);
                            }
                        }
                        break;
                    case '[':
                        stack1->push('(');
                        break;
                    case ']':
                        while (true) {
                            c2 = stack1->pop();
                            if (c2 == '(') {
                                break;
                            }
                            else {
                                stack2->push(c2);
                            }
                        }
                        break;
                    case '(':
                        stack1->push(c1);
                        break;
                    case ')':
                        while (true) {
                            c2 = stack1->pop();
                            if (c2 == '(') {
                                break;
                            }
                            else {
                                stack2->push(c2);
                            }
                        }
                        break;
                    default:
                        stack2->push(c1);
                        break;
                }
            }
        }
        
        // pop until stack1 is empty
        while (true) {
            c2 = stack1->pop();
            if (c2 == '\0') {
                break;
            }
            else {
                stack2->push(c2);
            }
        }
        
        // set postfix_expression
        postfix_expression = stack2->to_string();
        //std::cout<<"DEBUG: "<<postfix_expression<<std::endl;
    }
    
    void validate_and_revise_if_needed(std::string s) {
        bool is_valid = true;
        
        CharStack *stack1 = new CharStack();
        CharStack *stack2 = new CharStack();
        
        char c1;
        char c2;
        
        // scan each character of the input line, from left to right, one chracter one time till \0
        // set is_valid false if any correction made
        // set has_operand true if any operand found
        for (long int i=0; ; i++) {
            c1 = s[i];
            
            if (c1 == '\0') {
                // break for loop when the end of line \0 is scanned
                break;
            }
            else {
                // check expression validity before push character into stack
                switch (c1) {
                    case '{':
                        // no check, just push
                        stack1->push(c1);
                        stack2->push(c1);
                        break;
                    case '}':
                        // check
                        // if c2 == '{' then make no correction
                        // if c2 == '\0' then make a correction by ignoring c1
                        // if c2 == something else then make a correction by replacing c1
                        c2 = stack1->pop();
                        switch (c2) {
                            case '{':
                                stack2->push(c1);
                                break;
                            case '\0':
                                is_valid = false;
                                break;
                            case '[':
                                is_valid = false;
                                stack2->push(']');
                                break;
                            case '(':
                                is_valid = false;
                                stack2->push(')');
                                break;
                        }
                        break;
                    case '[':
                        // no check, just push
                        stack1->push(c1);
                        stack2->push(c1);
                        break;
                    case ']':
                        // check
                        // if c2 == '[' then make no correction
                        // if c2 == '\0' then make a correction by ignoring c
                        // if c2 == something else then make a correction by replacing c
                        c2 = stack1->pop();
                        switch (c2) {
                            case '[':
                                stack2->push(c1);
                                break;
                            case '\0':
                                is_valid = false;
                                break;
                            case '{':
                                is_valid = false;
                                stack2->push('}');
                                break;
                            case '(':
                                is_valid = false;
                                stack2->push(')');
                                break;
                        }
                        break;
                    case '(':
                        // no check, just push
                        stack1->push(c1);
                        stack2->push(c1);
                        break;
                    case ')':
                        // check
                        // if c2 == '(' then make no correction
                        // if c2 == '\0' then make a correction by ignoring c
                        // if c2 == something else then make a correction by replacing c
                        c2 = stack1->pop();
                        switch (c2) {
                            case '(':
                                stack2->push(c1);
                                break;
                            case '\0':
                                is_valid = false;
                                break;
                            case '{':
                                is_valid = false;
                                stack2->push('}');
                                break;
                            case '[':
                                is_valid = false;
                                stack2->push(']');
                                break;
                        }
                        break;
                    default:
                        // no check, just push
                        has_operand = true;
                        stack2->push(c1);
                        break;
                }
            }
        }
        
        // complement ')' ']' '}' if stack1 is not empty
        while ((c2 = stack1->pop()) != '\0') {
            is_valid = false;
            switch (c2) {
                case '{':
                    stack2->push('}');
                    break;
                case '[':
                    stack2->push(']');
                    break;
                case '(':
                    stack2->push(')');
                    break;
            }
        }
        
        // set revised_expression
        revised_expression = stack2->to_string();
        
        // print True of False
        if (is_valid) {
            std::cout<<"True"<<std::endl;
        }
        else {
            std::cout<<"False"<<std::endl;
            
            // print the revised expression
            std::cout<<revised_expression<<std::endl;
        }
    }
    
public:
    void isValid(std::string s) {
        has_operand = false;
        
        validate_and_revise_if_needed(s);
        if (has_operand) {
            infix_to_postfix();
            eval_postfix();
        }
        else {
            std::cout<<"0"<<std::endl;
        }
    }
};
