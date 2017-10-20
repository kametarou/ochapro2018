#include <iostream>
#include <string>

//Exc.1
//string s0に重複する文字が含まれるならtrueを、そうでないならfalseを返す。
bool duplicate(std::string s0){
  std::string s1 (s0); //copy 
  std::sort(s1.begin(),s1.end());
  for(std::string::iterator it=s1.begin(); it!=s1.end()-1;++it){
    if(*it==*(it+1))
      return false;
  }
  return true;
}

//Exc.2
//s0 が s1 の並び替えになっていれば trueを、そうでないなら false を返す。
bool sameElements(std::string s0,std::string s1){
  std::string s2(s0); //copy
  std::string s3(s1); //copy
  std::sort(s2.begin(),s2.end());
  std::sort(s3.begin(),s3.end());
  return !s2.compare(s3);
}

//Exc.3
//s に含まれる空白文字を文字列"%20"で置き換える
void spaceEncode(std::string &s){
  for(std::string::iterator it=s.begin(); it!=s.end(); ++it){
    if(*it==' '){
      s.replace(it,it+1,"%20",3);
    }
  }
}

int main(){
  std::string s,t;
  std::getline(std::cin,s);
  //std::getline(std::cin,t);
  //std::cout << duplicate(s) << std::endl;
  //std::cout << sameElements(s,t) << std::endl;
  spaceEncode(s);
  std::cout << s << std::endl;
}
