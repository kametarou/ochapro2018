#include<iostream>
using namespace std;


//ゆうきちゃんからもらったプログラム
bool isSubstring(std::string str1, std::string str2) {
    // 片方の文字列が，もう片方の文字列の一部分になっているかどうかを調べる
    return str1.find(str2) != std::string::npos || str2.find(str1) != std::string::npos;
}

bool isRotated(string s1, string s2){
  if( (s1.length()==s2.length()) && isSubstring(s1+s1,s2) ){
    return true;
  }else{
    return false;
  }
}

bool test0109(string t1, string t2, bool ans){
  bool result = isRotated(t1,t2);
  bool judge = (result == ans);

  cout << t1 << " " << t2 << endl;
  cout << "result:" << (result?"true":"false") << " "<< "answer:" << (ans?"true":"false") <<endl;
  cout << (judge?"ok!":"oops!") << endl << endl;

  return judge;
}
int main(int argc, char const *argv[]) {
  string s1("aiueo");
  string s2("iueoa");
  test0109(s1,s2,true);

  string s3("aiueo");
  string s4("ueoa");
  test0109(s3,s4,false);

  string s5("");
  string s6("");
  test0109(s5,s6,true);

  return 0;
}
