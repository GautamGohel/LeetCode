class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' or s[i]=='[' or s[i]=='{'){
                st.push(s[i]);
            }
            else{
                if(s[i]==')' and !st.empty() and st.top()=='('){
                    st.pop();
                }
                else if(s[i]==']' and !st.empty() and st.top()=='['){
                    st.pop();
                }
                else if(s[i]=='}' and !st.empty() and st.top()=='{'){
                    st.pop();
                }
                else{
                return false;
                }
            }
        }
        return st.empty();
    }
};