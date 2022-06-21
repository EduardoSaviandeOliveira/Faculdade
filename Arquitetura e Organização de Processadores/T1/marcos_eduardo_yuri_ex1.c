#include <stdio.h>
#include <stdint.h>

#define i32 int32_t

int main(){
  i32 A[8], B[8], limit, tmp;
  while(1){
    printf("Tamanho(1~8): ");
    scanf("%d", &limit);
    if(limit > 0 && limit <= 8)
      break;
    else
     printf("Valor invalido\n");
  }

  for(i32 i=0; i < limit; i++){
    printf("A[%d] = ", i);
    scanf("%d", &A[i]);
  }

  for(i32 i=0; i < limit; i++){
    printf("B[%d] = ", i);
    scanf("%d", &B[i]);
  }

  for(i32 i=0; i < limit; i++){
    tmp = A[i];
    A[i] = B[i];
    B[i] = tmp;
  }

  for(i32 i=0; i < limit; i++) printf("A[%d] = %d\n", i, A[i]);

  for(i32 i=0; i < limit; i++) printf("B[%d] = %d\n", i, B[i]);

  return 0;
}
