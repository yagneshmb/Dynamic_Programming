#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void trace (int **track_table, int i, int j);
int main(){
    int n_matrix, i;
    cout << "Enter number of matrix to be multiplied : "; 
    cin >> n_matrix;
    int dimension[n_matrix + 1];
    cout << "Enter number of rows for first matrix : ";
    cin >> dimension[0];
    cout << "Enter number of columns for first matrix : ";
    cin >> dimension[1];

    for (i = 2 ; i < n_matrix + 1 ; i++){
        cout << "Number of rows for the matrix " << i << " must be : " << dimension[i - 1] << endl;
        cout << "Enter number of columns for matrix " << i << " : ";
        cin >> dimension[i];
    }

    int matrix_table[n_matrix][n_matrix];
    int** track_table;
    track_table = new int* [n_matrix];
    for (i = 0; i < n_matrix; i++){
        track_table[i] = new int[n_matrix];
    }
    //make diagonal entries 0
    for (int i_r = 0; i_r < n_matrix; i_r++){
        matrix_table[i_r][i_r] = 0;
    }
    int q, j;
    //core logic
    for (int m_length = 2; m_length < n_matrix + 1; m_length++){    //2 to n_matrix
        for (i = 0; i < n_matrix - m_length + 1; i++){
            j = i + m_length - 1;
            //cout << "(" << i << " , " << j << ")" << endl;
            matrix_table[i][j] = INT_MAX;
            for (int k = i; k < j ; k++){
              //  cout << "i = " << i << " j = " << j << " k = " << k << endl;
                q = matrix_table[i][k] + matrix_table[k+1][j] + dimension[i]*dimension[k+1]*dimension[j+1];
               // cout << " q = " << q << " matrix["<<i<<"]["<<j<<"] = "<<matrix_table[i][j]<<endl;
                if (q < matrix_table[i][j]){
                    matrix_table[i][j] = q;
                    track_table[i][j] = k;
                }     
            }
        }

    }
    cout << "Matrix table" << endl;
    cout << "________________________________" << endl;
    for(i = 0; i < n_matrix; i++){
        cout << "|";
        for(j = 0; j < n_matrix; j++){
            cout << matrix_table[i][j] << "|";
        }
        cout <<endl << "________________________________" << endl;
    }
    cout << "The number of multiplications required = " << matrix_table[0][n_matrix - 1] << endl;
    
    cout << "Trace table" << endl;
    cout << "________________________________" << endl;
    for(i = 0; i < n_matrix; i++){
        cout << "|";
        for(j = 0; j < n_matrix; j++){
            cout << track_table[i][j] << "|";
        }
        cout <<endl << "________________________________" << endl;
    }
    trace(track_table, 0, n_matrix - 1);
}



void trace(int** s, int i, int j){
        if(i == j){
            cout << "A{" << i << "}" ;
        }
        else{
            cout << "(";
            trace(s, i, s[i][j]);
            trace(s, s[i][j] + 1, j);
            cout << ")";
        }
}
