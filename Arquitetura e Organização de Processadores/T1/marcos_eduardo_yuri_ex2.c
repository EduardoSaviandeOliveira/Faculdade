#include <stdio.h>
#include <stdint.h>

#define i32 int32_t

int main() {
  i32 mask, days[16], p, d_select, s_select;

  while(1){
    mask = 0x1;
    printf("Dia(0~16): ");
    scanf("%d", &d_select);
    printf("Aluno(0~31): ");
    scanf("%d", &s_select);
    printf("Presenca(0/1): ");
    scanf("%d", &p);

    mask = mask << s_select;

    if(p)
      days[d_select] = days[d_select] | mask;
    else
      days[d_select] = days[d_select] & !mask;
  }
  return 0;
}
