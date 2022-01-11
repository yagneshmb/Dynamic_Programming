#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void trace(string a, char** track_table,int i, int j){
    if(i == -1 || j == -1){
        return;
    }
    else{
        if(track_table[i][j] == 'l'){
            trace(a, track_table, i-1, j-1);
            cout << a[i];
        }
        else{
            if(track_table[i][j] == '^'){
                trace(a, track_table, i-1, j);
            }
            else{
                trace(a, track_table, i, j-1);
            }
        }
    }
}

int main(){
    string a, b;
    int i, j;
    cout << "Enter strings" << endl;
    cin >> a >> b;
    int lcs_table[a.length() + 1][b.length() + 1];
    
    char** track_table;
    track_table = new char* [a.length()];
    for (i = 0; i < a.length(); i++){
        track_table[i] = new char[b.length()];
    } 

    for(i = 0; i < a.length() + 1; i++){
        lcs_table[i][0] =0;
    }
    for(i = 0; i < b.length() + 1;i++){
        lcs_table[0][i] = 0;
    }

    for(i = 1; i < a.length() + 1; i++){
        for(j = 1; j < b.length() + 1; j++){
            if(a[i - 1] == b[j - 1]){
                lcs_table[i][j] = lcs_table[i - 1][j - 1] + 1;
                track_table[i-1][j-1] = 'l';
            }
            else{
                if(lcs_table[i - 1][j] >= lcs_table[i][j - 1]){
                    lcs_table[i][j] = lcs_table[i-1][j];
                    track_table[i-1][j-1] = '^';
                }
                else{
                    lcs_table[i][j] = lcs_table[i][j-1];
                    track_table[i-1][j-1] = '<';
                }
            }
        }
    }
 
    cout << "Printing length table" << endl;
    cout << "    ";
    for(i = 0; i < b.length(); i++){
        cout << b[i] << " ";
    }
    cout << endl;
    cout << "  ";
    for(int k = 0; k < a.length() + 1; k++){
         for(int m = 0; m < b.length() + 1; m++){
            cout << lcs_table[k][m] << " ";
        }
        cout << endl;
        cout << a[k] << " ";
    }
    cout << endl;
    cout << "Printing track table" << endl;
    cout << "  ";
    for(i = 0; i < b.length(); i++){
        cout << b[i] << " ";
    }
    cout << endl;
    for(int k = 0; k < a.length(); k++){
        cout << a[k] << " ";
        for(int m = 0; m < b.length(); m++){
            cout << track_table[k][m] << " ";
        }
        cout << endl;
    }
    cout << "Length of the longest subsequence is "<< lcs_table[a.length()][b.length()] << endl;
    trace(a, track_table, a.length() - 1, b.length() - 1);
}

