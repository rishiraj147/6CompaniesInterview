class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        
        for(auto str:tokens){
            int val1,val2;
            
            if(str.length()==1&&(str[0]=='-'||str[0]=='+'||str[0]=='*'||str[0]=='/')){
                val2=stk.top();
                stk.pop();
                val1=stk.top();
                stk.pop();

                if(str[0]=='+') stk.push(val1+val2);
                else if(str[0]=='-') stk.push(val1-val2);
                else if(str[0]=='*') stk.push(val1*val2);
                else stk.push(val1/val2);
            }
            else{
                stk.push(stoi(str));
            }
        }
        return stk.top();
    }
};