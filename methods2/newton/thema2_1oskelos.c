#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float func1(float x);
float parag1(float x);   //orismoi twn synarthsewn
float func2(float x);    //kai twn paragwgwn tous
float parag2(float x);

int main(int argc, char *argv[])
{
  float x0, tol, xk;
  
  x0 = 1; //arikh timh
  tol = pow(10,-10); //h epi8ymhth akriveia
  xk = 0; //h arxikopoihsh ths epomenhs proseggish ths lyshs
  
  while((func1(x0)!=0)&&(fabs(x0-xk)>tol)) //h epanalhpsh ths me8odou
  {
    xk = x0;
    x0 = x0 - (func1(x0)/parag1(x0));    //h evresh ths epomenhs proseggishs rizas
  }
  
  printf("H riza ths exiswshs1 einai : %f\n", x0);
  
  x0 = 3.14/2;
  xk = 0;
  
  while((func2(x0)!=0)&&(fabs(x0-xk)>tol))
  {
    xk = x0;
    x0 = x0 - (func2(x0)/parag2(x0));    
  }
  
  printf("H riza ths exiswshs2 einai : %f\n", x0);
  
  system("PAUSE");	
  return 0;
}

float func1(float x)
{
   return pow(x,3) - x + 1;
}

float parag1(float x)
{
   return 3*pow(x,2) - 1; 
}

float func2(float x)
{
   return exp(-x) - cos(x);
}

float parag2(float x)
{
   return -exp(-x) +sin(x);
}
