#include <iostream>

using namespace std;
const int M=5;

//M x M の正方行列を左に90度回転させる。
void rotate90(int p[M][M]){
  for(int i=0;i<M; i++){
    for(int j=i; j<M-i-1; j++){
      int tmp = p[i][j];
      p[i][j] = p[j][M-1-i];
      p[j][M-1-i] = p[M-1-i][M-1-j];
      p[M-1-i][M-1-j] = p[M-1-j][i];
      p[M-1-j][i] = tmp;
    }
  }
}

//エクササイズ0107のテストをする
void test0107(int t[M][M]){
  cout << "before" << endl;

  for(int i=0;i<M;i++){
    for(int j=0; j<M; j++){
      cout << t[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  rotate90(t);

  cout << "after" << endl;
  for(int i=0;i<M;i++){
    for(int j=0; j<M; j++){
      cout << t[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}
int main(int argc, char const *argv[]) {
  int t1[M][M] = {
    {0,1,2,3,4},
    {5,6,7,8,9},
    {10,11,12,13,14},
    {15,16,17,18,19},
    {20,21,22,23,24}
  };
test0107(t1);

  return 0;
}
