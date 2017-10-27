#include <iostream>
using namespace std;
#include <utility>
#include <list>

//文字列s1, s2を与えられて、どちらかの1文字を削除または置換することで両者が同じ文字列になるか判定する
bool close_enough(string s1, string s2){
  string s,l; //shorter and longer
  if(s1.length()< s2.length()){
    s = s1; l = s2;
  }else{
    s = s2; l = s1;
  }

  if(s.length() < l.length()-1 ){
    return true;
  }

  string::iterator its, itl;
  its = s.begin(); itl = l.begin();
  for(;its <s.end();){
    if( *its != *itl ){
      itl = itl+1;
      if(s1.length()== s2.length()){
 	its = its + 1;
      }
      for(;its < s.end();){
	if(*its != *itl){
	  return false;
	}
	its = its + 1;
	itl = itl + 1;
      }
    }
    its = its + 1;
    itl = itl + 1;
  }
  return true;
}

int main(int argc, char *argv[]){
  list<pair <string,string> > l;
  l.push_back(pair<string,string>("aa","bb")); // F
  l.push_back(pair<string,string>("aa","ab")); // T
  l.push_back(pair<string,string>("aa","b"));  // F
  l.push_back(pair<string,string>("a","b")); // T
  l.push_back(pair<string,string>("a","")); // T
  l.push_back(pair<string,string>("","")); // T
  l.push_back(pair<string,string>("sit","sat")); // T
  l.push_back(pair<string,string>("sat","sad")); // T
  l.push_back(pair<string,string>("sat","cat")); // T
  l.push_back(pair<string,string>("cat","sad")); // F
  for( list< pair<string,string> >::iterator it=l.begin();it!=l.end();it++){
    cout << (close_enough((*it).first,(*it).second)?"true":"false") << endl;
  }
}
