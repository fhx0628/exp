#include <math.h>
#include <stdlib.h>
#include <stdio.h>

float myexp(float x){
  float z, w, u, myE7, twoM, finalResult, temp;
  int m; //this was int m;
  //note: might have to do some extra shit if x is negative...
  
  //initializing products and their respective variables here
  z = x * M_LOG2E;
  m = round(z);
  w = z - m;
  u = w * M_LN2;
  
  if (m < 0){
    temp = 1 << (-m);
     twoM = 1 / temp;
    
  }
  else {
    temp = 1 << m;
   twoM = (float) temp;}

  
  myE7 = 1 + u*(1 + u/2*(1 + u/3*(1 + u/4*(1 + u/5*(1 + u/6*(1 + u/7))))));

  return (finalResult = twoM * myE7);

}

int main(){

  double y1, y2; //y1 will store my exp's result, y1 the math library's
  double result; //this will the relative error 
  double i = 20.0; //this will essentially be a loop counter to input values 20 through -10

  while(i > -10){
    y1 = myexp(i);
    y2 = expl(i);
    result = (fabsl(y1-y2)) / (fabsl(y2));
    printf("for x = %lf: myexp = %.9lf expl() =  %.9lf relative error = %.10lf\n", i, y1, y2, result);
    i -= 1.0;
    

  }

  return 0;
}
