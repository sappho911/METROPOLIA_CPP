#include <stdio.h>


int main(void) {

    float bus_price  = 0;
    float taxi_price = 0;
    float money = 0;
    int selection;
    bool enough_money = true;

    printf("Enter price of bus ticket: ");
    scanf("%f", &bus_price);
    printf("Enter price of taxi ticket: ");
    scanf("%f", &taxi_price);
    printf("How much money you have: ");
    scanf("%f", &money);

    printf("You have %.2f euros left. \n", money );

    while (enough_money) {

        printf("Do you want to take \n");
        printf("1) Bus (%.2f)\n", bus_price);
        printf("2) Taxi (%.2f)\n", taxi_price);

        printf("Enter selection: ");
        scanf("%d", &selection);

        if (money < bus_price && money < taxi_price) {
            printf("You need to walk. Bye.");
            enough_money = false;
            break;
        }


        switch (selection) {

            case 1:
                printf("You chose bus. \n");
                if (money < bus_price && money < taxi_price) {
            printf("You need to walk. Bye.");
            enough_money = false;
            break;
        }
                if (money >= bus_price) {
                    money -= bus_price;
                    printf("You have %.2f euros left. \n", money );
                } else {
                    printf("You have %.2f euros left. \n", money );
                    printf("You don't have enough money for bus.\n");
                }
                break;
            case 2:
                printf("You chose taxi. \n");
                if (money >= taxi_price) {
                    money -= taxi_price;
                    printf("You have %.2f euros left.\n", money );
                } else {
                    printf("You have %.2f euros left. \n", money );
                    printf("You don't have enough money for taxi.\n");
                }
                break;
        }
    }
}