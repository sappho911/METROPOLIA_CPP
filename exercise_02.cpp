#include <stdio.h>

#define MONTHS 12

int main() {

  float tax[MONTHS];
  float income[MONTHS];

  float tax_rate = 0;
  int income_limit = 0;
  float over_limit_rate = 0;


  printf("Enter tax rate: ");
  scanf("%f", &tax_rate);
  printf("Enter income limit: ");
  scanf("%d", &income_limit);
  printf("Enter tax rate for income over the limit: ");
  scanf("%f", &over_limit_rate);

  printf("You entered tax rate: %.f\n", tax_rate);
  printf("You entered income limit: %.d\n", income_limit);
  printf("You entered income over the limit %.f\n", over_limit_rate);

  for (int i = 0; i < MONTHS; i++) {
    printf("Enter income for month %d : ", i + 1);
    scanf("%f", &income[i]);
  }
}
