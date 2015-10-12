#include <iostream>

#define MAX_N 100 //最大のn

int main()
{
    int a[MAX_N][MAX_N]; //行列A
    int b[MAX_N][MAX_N]; //行列B
    int c[MAX_N][MAX_N]; //行列C
    int n;

    //nの入力(1<=n<=MAX_Nを満たすまで繰り返す)
    do{
        std::cout << "n=";
        std::cin >> n;
    }while(n<1 || MAX_N<n);
    //行列Aの入力
    std::cout<<"A = "<<std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin>>a[i][j];
        }
    }
    //行列Bの入力
    std::cout<<"B = "<<std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin>>b[i][j];
        }
    }
    //AB=Cを計算
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c[i][j]=0;
            for (int k = 0; k < n; ++k) {
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    //行列Cを出力
    std::cout<<"C = "<<std::endl;
    for (int l = 0; l < n; ++l) {
        for (int i = 0; i < n; ++i) {
            std::cout<<c[l][i]<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}