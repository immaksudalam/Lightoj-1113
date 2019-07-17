#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int c=0;
    while(t--)
    {
         cout<<"Case "<<++c<<":";
         stack<string> st;
         stack <string> st2;
         string add="http://www.lightoj.com/";
         string s;
         st.push(add);
         while(cin>>s)
         {
              if(s[0]=='Q')
               break;
              if(s[0]=='V')
              {
                   cin>>add;
                   cout<<add<<endl;
                   st.push(add);
                   if(!st2.empty()){
                    while(!st2.empty()){
                         st2.pop();
                    }
                   }
              }
              else
              {
                  if(s[0]=='B'){
                  st2.push(st.top());
                  st.pop();
                  if(!st.empty()){
                    cout<<st.top()<<endl;
                  }
                  else{
                    cout<<"Ignored"<<endl;
                    st.push(st2.top());
                    st2.pop();
                  }
              }
              else if(s[0]=='F'){
                   if(!st2.empty()){
                    cout<<st2.top()<<endl;
                        st.push(st2.top());
                        st2.pop();
                   }
                   else{
                    cout<<"Ignored"<<endl;
                   }
              }
         }
    }
}
}




