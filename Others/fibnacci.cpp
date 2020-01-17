#include <iostream>

int fibnacci_recursion(int);
int fibnacci_loop(int);
int main(){
  // 递归算法测试 10个
  std::cout<<"斐波那契数列"<<std::endl;
  std::cout<<"递归算法运行结果:"<<std::endl;
  for(int i=1;i<=10;i++){
    std::cout<<fibnacci_recursion(i)<<" ";  
  }
  std::cout<<std::endl;

  // 非递归算法测试
  std::cout<<"非递归算法运行结果:"<<std::endl;
    for(int i=1;i<=10;i++){
    std::cout<<fibnacci_loop(i)<<" ";  
  }
  std::cout<<std::endl;
}

/**
* 输出第n个斐波那契数
* param:  n int - 目标序数
* return: int - 求得的第n个数
**/
int fibnacci_recursion(int n){
  if(n<=1) return n;
  if(n>1) return fibnacci_recursion(n-1) 
		+ fibnacci_recursion(n-2); 
}

/**
* 求斐波那契数列的非递归算法
* param: n int - 目标序数
* return: int - 斐波那契数列第n个数
**/
int fibnacci_loop(int n){
  int a=1,b=1;
  if(n<=2) return 1;
  else{
    int next = 0;
    for(;n>2;n--){
      next = a + b;
      a = b;
      b = next;
    }
    return next;
  }
}
