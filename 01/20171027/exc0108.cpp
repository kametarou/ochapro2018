#include<iostream>
using namespace std;

const int N=3;

//aの(i,j)成分が0ならば、i行とj列の全成分を0にする。
void fillZero(int a[N][N]){
  int flag_r[N]={};
  int flag_c[N]={};

  for(int i = 0;i < N; i++){
    for(int j = 0; j < N; j++){
      if(a[i][j]==0){
          flag_r[i] = 1;
          flag_c[j] = 1;
      }
    }
  }

  // cout << "flags:" << endl;
  // for(int i=0; i<N; i++){
  //   cout << flag_r[i] << " ";
  // }
  // cout << endl;
  // for(int j=0; j<N; j++){
  //   cout << flag_c[j] << " ";
  // }
  // cout << endl;

  for(int i=0; i < N; i++){
    if(flag_r[i]==1){
      for(int j=0; j<N; j++){
        a[i][j]=0;
      }
    }
  }

  for(int j=0; j < N; j++){
    if(flag_c[j]==1){
      for(int i=0; i<N; i++){
        a[i][j]=0;
      }
    }
  }
}

//exc1.08のテストをする
void test0108(int t[N][N]){
  cout << "before:" << endl;
  for(int i = 0; i<N; i++){
    for(int j = 0; j<N; j++){
      cout << t[i][j] << " ";
    }
    cout << endl;
  }

  fillZero(t);

  cout << "after:" << endl;
  for(int i = 0; i<N; i++){
    for(int j = 0; j<N; j++){
      cout << t[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

}

int main(int argc, char const *argv[]) {
  int t1[N][N]={
    {0,1,2},
    {3,0,5},
    {6,7,8}
  };

  int t2[N][N]={
    {1,2,3},
    {4,0,6},
    {7,8,9}
  };

  int t3[N][N]={
    {1,2,3},
    {4,5,6},
    {7,8,0}
  };

  test0108(t1);
  test0108(t2);
  test0108(t3);
  return 0;
}
