#include <iostream>
#include <fstream>

using namespace std;
    

int main() {
    int N, M;
    ifstream in("in.txt");
    if (!in.is_open()) {
    cout << "in.txt not open" << std::endl;
    return 1;
  }
    in >> N;
    int *arr1 = new int[N];
    for (int i = 0; i < N; i++){
        in >> arr1[i];
    }

    in >> M;
     int *arr2 = new int[M];
    for (int i = 0; i < M; i++){
        in >> arr2[i];
    }


    int tmp = arr2[M-1];
    for (int i = M - 1; i >= 0; i--)
    {
        arr2[i] = arr2[i-1];
    }
    arr2[0] = tmp;

    tmp = arr1[0];
    for (int i = 0; i < N; i++)
    {
        arr1[i] = arr1[i+1];
    }
    arr1[N-1] = tmp;

    ofstream out("out.txt");
        if (!out.is_open()) {
    cout << "out.txt not open" << std::endl;
    in.close();
    delete[] arr1;
    delete[] arr2;
    return 1;
  }
    out << M;
    out << "\n";
    for (int i = 0; i < M; i++){
        out << arr2[i] << " ";
    }
    out << "\n";
    out << N;
    out << "\n";
    for (int i = 0; i < N; i++){
        out << arr1[i] << " ";
    }
    in.close();
    out.close();
    delete[] arr1;
    delete[] arr2;
}