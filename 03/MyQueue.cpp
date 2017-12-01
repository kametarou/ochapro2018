#include <iostream>
using namespace std;
#include <cstdio>
#include <cstdlib>
#include <cmath>
const int SIZE=10;

//@chiaki-i から拝借したものに追記
template <class T>class Stack{
public:
  T stack[SIZE];
  int top;

  Stack(){
    top = 0;
  }

  void push(T item){
    if(top == SIZE){
      std::cout << "Stack is full" << std::endl;
      throw FullStackException();
    }
    stack[top] = item;
    top++;
  }

  T pop(){
    if(top == 0){
      std::cout << "Stack is empty" << std::endl;
      throw EmptyStackException();
    }
    top--;
    return stack[top];
  }

  T peek(){
    if(top==0){
      std::cout << "Stack is empty" << std::endl;
      throw EmptyStackException();
    }
    return stack[top];
  }

  bool isEmpty(){return (top==0);}

  class EmptyStackException{};
  class FullStackException{};
};

template <class T>class StackOperator{
public:
  void sort(Stack<T>stack){
    Stack<T> tempStack1 = Stack<T>();
    Stack<T> tempStack2 = Stack<T>();

    
  }
}

template <class T>class MyQueue{
private:
  Stack<T> container; 
  Stack<T> tempContainer;

  void shiftAll(Stack<T> &from,Stack<T> &to){
    while(!(from.isEmpty())){
      to.push(from.pop());
    }
    return;
  }
  
public: 
  MyQueue(){
    container = Stack<T>();
    tempContainer = Stack<T>();
  }
  void enqueue(T item){
    container.push(item);
    return;
  }
  
  T dequeue(){
    if(!tempContainer.isEmpty()){
      cout << "temporal container is not empty!" << endl;
      throw TempContainerNotEmpty();
    }
    shiftAll(container,tempContainer);
    T ans = tempContainer.pop();
    shiftAll(tempContainer,container);
    return ans;
  }
  class TempContainerNotEmpty{};
};



int main(int argc, char *argv[]){
  MyQueue<int> queue= MyQueue<int>();
  int items[] = {1,2,3,4,5,6,7};
  for(int i =0; i<7 ; i++){
    queue.enqueue(items[i]);
  }
  for(int i=0; i<7; i++){
    std::cout<<queue.dequeue()<<endl;
  }
  /*
  double parameter1;
  if( argc != 2 ){
    fprintf(stderr, "usage: ./a.out parameter1\n");
    exit(0);
  }
  parameter1=atof(argv[1]);
  
  fprintf(stderr, "parameter1 = %f\n", parameter1);
  */
  
}
