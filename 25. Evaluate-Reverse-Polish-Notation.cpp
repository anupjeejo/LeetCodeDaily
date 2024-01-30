class Solution {
public:

    int performOperation(char operation, int operand1, int operand2)
    {
        if(operation == '+')
            return operand2 + operand1;
        else if(operation == '-')
            return operand2 - operand1;
        else if(operation == '/')
            return operand2 / operand1;
     
        return operand1 * operand2;
    }

    bool isOperator(char token)
    {
        return token == '+' ||
               token == '-' ||
               token == '/' ||
               token == '*';
    }

    int evalRPN(vector<string>& tokens){
        stack<int> st;

        for(auto token : tokens)
        {
            if(token.size() == 1)
            {
                char ch = token[0];
                if(isOperator(ch))
                {
                    int operand1 = st.top();
                    st.pop();
                    int operand2 = st.top();
                    st.pop();
                    int newOperand = performOperation(ch, operand1, operand2);
                    st.push(newOperand);
                    continue;
                }
            }
            int operand = stoi(token);
            st.push(operand);
        }

        return st.top();
    }











   
    // int evalRPN(vector<string>& tokens) {
    //     string t = tokens.back();
    //     tokens.pop_back();
        
    //     if(t != "+" && t != "-" && t != "*" && t != "/") return stoi(t);
    //     else{
    //         long long b = evalRPN(tokens);
    //         long long a = evalRPN(tokens);
    //         if(t == "+") return a + b;
    //         else if(t == "-") return a - b;
    //         else if(t == "*") return a * b;
    //         else return a / b;
    //     }
    // }
};