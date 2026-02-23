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

  tax_rate  /= 100.0;
  over_limit_rate /= 100.0;

  for (int i = 0; i < MONTHS; i++) {
    printf("Enter income for month %d : ", i + 1);
    scanf("%f", &income[i]);
  }

  float total_income = 0;

  for (int i = 0; i < MONTHS; i++) {
    float monthly_tax = 0;

    if (total_income >= income_limit) {
      monthly_tax = income[i] * over_limit_rate;
    }
    else if (total_income  +  income[i] <= income_limit) {
      monthly_tax += income[i] * tax_rate;
    }
    else {
      float low_part = income[i] - total_income;
      float high_part = income[i] - low_part;

      monthly_tax  = low_part * tax_rate + high_part * over_limit_rate;
    }
    tax[i] = monthly_tax;
    total_income += income[i];
  }
  printf("%5s %10s %10s\n", "month", "income", "tax");

  for (int i = 0; i < MONTHS; i++) {
    printf("%5d %10.2f %10.2f\n", i+1, income[i], tax[i]);
  }
}
