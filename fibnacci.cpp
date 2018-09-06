/**encoding:GBK **/
#include <iostream>

int fibnacci_recursion(int);
int fibnacci_loop(int);
int main(){
  // �ݹ��㷨���� 10��
  std::cout<<"쳲���������"<<std::endl;
  std::cout<<"�ݹ��㷨���н��:"<<std::endl;
  for(int i=1;i<=10;i++){
    std::cout<<fibnacci_recursion(i)<<" ";  
  }
  std::cout<<std::endl;

  // �ǵݹ��㷨����
  std::cout<<"�ǵݹ��㷨���н��:"<<std::endl;
    for(int i=1;i<=10;i++){
    std::cout<<fibnacci_loop(i)<<" ";  
  }
  std::cout<<std::endl;
}

/**
* �����n��쳲�������
* param:  n int - Ŀ������
* return: int - ��õĵ�n����
**/
int fibnacci_recursion(int n){
  if(n<=1) return n;
  if(n>1) return fibnacci_recursion(n-1) 
		+ fibnacci_recursion(n-2); 
}

/**
* ��쳲��������еķǵݹ��㷨
* param: n int - Ŀ������
* return: int - 쳲��������е�n����
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
