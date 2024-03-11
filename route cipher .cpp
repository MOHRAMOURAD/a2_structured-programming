#include <bits/stdc++.h>
using namespace std;
class Matrix {
public:
    vector<vector<char>> route_get_matrix(string temp, int rows,int key) {
        vector<vector<char>> route_matrix(rows, vector<char>(key, 'X'));
        int cnt = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < key; ++j) {
                if (cnt < temp.length()) {
                    route_matrix[i][j] = temp[cnt];
                    cnt++;
                }
            }
        }
        return route_matrix;
    }
};

void route_cipher(vector<vector<char>> route_matrix,int rows,int cols){
    int up=0,bottom=rows-1,right=cols-1,left=0;
    string ciphered;

    while(left<=right && up<=bottom) {
        if(right==left){
            for (int i = up; i <=bottom ; ++i) {
                ciphered += route_matrix[i][right];
            }
            break;
        }
        if(bottom==up){
            for (int i = right; i >=left ; --i) {
                //cout << route_matrix[bottom][i] << ' ';
                ciphered += route_matrix[bottom][i];
            }
            break;
        }

        //add right col
        for (int i = up; i <= bottom; ++i) {
            //cout << route_matrix[right][i] << ' ';
            ciphered += route_matrix[i][right];
        }
        //cout<<endl;
        if(right>left)
            right--;
        //add bottom row
        for (int i = right; i >=left ; --i) {
            //cout << route_matrix[bottom][i] << ' ';
            ciphered += route_matrix[bottom][i];
        }
        if(bottom>up)
            bottom--;
        //cout<<endl;
        //add left col
        for (int i = bottom; i >= up ; --i) {
            //cout << route_matrix[left][i] << ' ';
            ciphered += route_matrix[i][left];
        }
        left++;
        //cout<<endl;
        //add upper row
        for (int i = left; i <= right; ++i) {
            //cout << route_matrix[up][i] << ' ';
            ciphered += route_matrix[up][i];
        }
        up++;
        //cout<<endl;
    }
    cout<<ciphered<<endl;
}

void route_decipher(string ciphered,int rows,int cols){
    vector<vector<char>> route_matrix(rows,vector<char>(cols));
    int up=0,bottom=rows-1,right=cols-1,left=0;
    int c=0;
    while(left<=right && up<=bottom) {
        if(right==left){
            for (int i = up; i <=bottom ; ++i) {
                route_matrix[i][right]=ciphered[c];
                c++;
            }
            break;
        }
        if(bottom==up){
            for (int i = right; i >=left ; --i) {
                //cout << route_matrix[bottom][i] << ' ';
                route_matrix[bottom][i]=ciphered[c];
                c++;
            }
            break;
        }

        //add right col
        for (int i = up; i <= bottom; ++i) {
            //cout << route_matrix[right][i] << ' ';
            route_matrix[i][right]=ciphered[c];
            c++;
        }
        //cout<<endl;
        if(right>left)
            right--;
        //add bottom row
        for (int i = right; i >=left ; --i) {
            //cout << route_matrix[bottom][i] << ' ';
            route_matrix[bottom][i]=ciphered[c];
            c++;
        }
        if(bottom>up)
            bottom--;
        //cout<<endl;
        //add left col
        for (int i = bottom; i >= up ; --i) {
            //cout << route_matrix[left][i] << ' ';
            route_matrix[i][left]=ciphered[c];
            c++;
        }
        left++;
        //cout<<endl;
        //add upper row
        for (int i = left; i <= right; ++i) {
            //cout << route_matrix[up][i] << ' ';
            route_matrix[up][i]=ciphered[c];
            c++;
        }
        up++;
    }
    string deciphered;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            deciphered+=route_matrix[i][j];
        }
    }
    cout<<deciphered<<endl;
}


int main() {
    Matrix m;
    string msg;
    cout<<"enter the text you want to cipher\n";
    getline(cin,msg);
    cout<<"enter the key\n";
    int key;
    while(!(cin>>key)||key<2 || key>msg.length()/2){
        cout<<"invalid input! please enter an integer greater than two\n and less than the length of the text divided two\n";
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cin.clear();
    }

    string original=msg,temp;
    for (char c:original) {
        if(isalpha(c)){
            if(islower(c)){
                temp+= toupper(c);
            }
            else{
                temp+=c;
            }
        }
    }

    int row = (temp.length() % key == 0) ? temp.length() / key : temp.length() / key + 1;
    //vector<vector<char>> matrix = m.route_get_matrix(temp, row,key);
    //route_cipher(matrix,row,key);
    route_decipher(temp,row,key);
    return 0;
}
