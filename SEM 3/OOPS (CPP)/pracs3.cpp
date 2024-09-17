#include <iostream>
using namespace std;

class MAT{
    private:
        int m, n;
        int **mat;
    public: 
        MAT(int m, int n):m(m), n(n){
            mat = new int*[m];
            for(int i=0; i<m; i++){
                mat[i] = new int[n];
                for(int j=0; j<n; j++)
                    mat[i][j] = i+j;
            }
        }
        MAT operator +(MAT &m1){
            MAT m2(m, n);
            for(int i=0; i<m; i++)
                for(int j=0; j<n; j++)
                    m2.mat[i][j] = mat[i][j] + m1.mat[i][j];
            return m2;
        }
        MAT operator -(MAT &m1){
            MAT m2(m, n);
            for(int i=0; i<m; i++)
                for(int j=0; j<n; j++)
                    m2.mat[i][j] = mat[i][j] - m1.mat[i][j];
            return m2;
        }
        MAT operator *(MAT &m1){
            MAT m2(m, m1.n);
            for(int i=0; i<m; i++)
                for(int j=0; j<m1.n; j++){
                    m2.mat[i][j] = 0;
                    for(int k=0; k<n; k++)
                        m2.mat[i][j] += mat[i][k] * m1.mat[k][j];
                }
            return m2;
        }
        void display(){
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++)
                    cout << mat[i][j] << " ";
                cout << endl;
            }
            cout<<endl;
        }
};
int main() {
    MAT m1(2, 2), m2(2, 2);
    cout<<"Matrix 1:\n";
    m1.display();
    cout<<"Matrix 2:\n";
    m2.display();
    cout<<"Matrix 1 + Matrix 2:\n";
    MAT m3 = m1 + m2;
    m3.display();
    cout<<"Matrix 1 - Matrix 2:\n";
    m3 = m1 - m2;
    m3.display();
    cout<<"Matrix 1*Matrix 2:\n";
    m3 = m1 * m2;
    m3.display();
    return 0;
}