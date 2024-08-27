class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int res=0;
        stack<string>st;
        int temp1=0;
        int temp2=0;
        int temp3=0;
        for(int i=0;i<tokens.size();i++){
          st.push(tokens[i]);
          if(tokens[i]=="+" && st.size()>=2){
              st.pop();
              temp1=stoi(st.top());
              st.pop();
              temp2=stoi(st.top());
              st.pop();
              temp3=temp1+temp2;
              st.push(to_string(temp3));
          }
               else if(tokens[i]=="-" && st.size()>=2){
              st.pop();
              temp1=stoi(st.top());
              st.pop();
              temp2=stoi(st.top());
              st.pop();
              temp3=temp2-temp1;
              st.push(to_string(temp3));
          }
            else if(tokens[i]=="*" && st.size()>=2){
              st.pop();
              temp1=stoi(st.top());
              st.pop();
              temp2=stoi(st.top());
              st.pop();
              temp3=temp1*temp2;
              st.push(to_string(temp3));
          }
            else if(tokens[i]=="/" && st.size()>=2){
              st.pop();
              temp1=stoi(st.top());
              st.pop();
              temp2=stoi(st.top());
              st.pop();
              temp3=temp2/temp1;
              st.push(to_string(temp3));
          }
        }
        res=stoi(st.top());
        return res;
    }
};