#include <iostream>
using namespace std;
#include <list>

//文字列を与えられて、奇数個含まれている文字の種類が1種類以下ならtrueを、そうでないならfalseを返す
bool kaibun_able(string s){
  string message;
  sort(s.begin(),s.end());
  cout << "sorted string:" << s << endl;
  if(s.length()<2){return true;}
  string::iterator it;
  
  for(it = s.begin(); it <s.end()-1; it=it+2){
    if(*it != *(it+1)){
      for(it=it+1; it < s.end()-1; it = it+2){
	if(*it != *(it+1)){ return false;}
      }
    }
  }
  return true;
}


int main(int argc, char *argv[]){
  list<string> l;
  l.push_back("a");//T
  l.push_back("aiai");//T
  l.push_back("bba");//T
  l.push_back("bb");//T
  l.push_back("a");//T
  l.push_back("abbbbbcca");//T
  l.push_back("");//T
  l.push_back("abc");//F
  l.push_back("abbb");//F

  for(list<string>::iterator it=l.begin();it!=l.end();it++){
    cout << (kaibun_able(*(it))?"true":"false") << endl;
  }
}
