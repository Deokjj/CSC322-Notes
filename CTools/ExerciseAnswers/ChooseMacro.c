//-----------------------------------------------------------------------------
#include <stdio.h>

#ifdef LARGE
#define CHOOSE(A,B) (((A) > (B)) ? (A) : (B))
#else
#define CHOOSE(A,B) (((A) < (B)) ? (A) : (B))
#endif
//-----------------------------------------------------------------------------
int main(void) {

  int i1,i2;

  printf("Enter two integers :");
  scanf("%d %d",&i1,&i2);

#ifdef LARGE
  printf("The large one is %d\n",CHOOSE(i1,i2));
#else
  printf("The small one is %d\n",CHOOSE(i1,i2));
#endif
}
//----------------------------------------------------------------------------
