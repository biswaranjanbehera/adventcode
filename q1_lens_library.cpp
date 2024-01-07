#include <bits/stdc++.h>

using namespace std;

int calculate(string s){
    int n = s.length();
    int c  = 0;
    for(int i=0;i<n;i++){
        int ascii = int(s[i]);
        c+=ascii;
        c = c*17;
        c = c%256;
    }
    return c;
}

int output(string s){
    int n = s.length();
    string temp = "";
    int ans = 0;
    for(int i=0;i<n;i++){
        if(s[i]==','){
            int value = calculate(temp);
            cout<<temp<<" becomes "<<value<<endl;
            ans+=value;
            temp = "";
        }else
            temp = temp + s[i];
    }
    int res = calculate(temp);
    cout<<temp<<" becomes "<<res<<endl;
    ans = ans + res;
    return ans;

}
int main(){
    string input;
    cout<<"Give the input of the string:- ";
    cin>>input;
    int result = output(input);
    cout<<"The sum of the result is:- "<<result<<endl;
}

