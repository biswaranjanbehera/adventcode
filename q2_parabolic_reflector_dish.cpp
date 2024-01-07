#include <bits/stdc++.h>

using namespace std;

int print(int row, int col, vector<vector<char>> &c) {
    cout<<"This is initially input matrix:- "<<endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    cout<<"-----------------"<<endl;
    for(int j=0;j<col;j++){
        for(int i=0;i<row;i++){
            if(c[i][j] == '0'){
                int cur = i-1;
                int f = 1;
                while(cur>=0 && c[cur][j]!='0' && c[cur][j]!='#'){
                    cur--;
                    f=0;
                }
                if(f==0){
                    c[cur+1][j] = '0';
                    c[i][j] = '.';
                }
            }
        }
    }
    cout<<"This is modified matrix after moving toward to all to the north:- "<<endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    int ans = 0;
    int x = row;
    for(int i=0;i<row;i++){
        int temp = 0;
        for(int j=0;j<col;j++){
            if(c[i][j]=='0')
                temp++;
        }
        ans = ans + (x * temp);
        x--;
    }
    return ans;

}

int main() {
    int row, col;
    cout<<"Enter number of rows:- ";
    cin>>row;
    cout<<"Enter number of columns:- ";
    cin >>col;
    vector<vector<char>> c(row, vector<char>(col));
    cout<<"Filled the matrix"<<endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            char cp;
            cin >> cp;
            c[i][j] = cp;
        }
    }

    int ans = print(row, col, c);
    cout<<"The total sum of load is:- "<<ans<<endl;

    return 0;
}
