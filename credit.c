#include <cs50.h>
#include <stdio.h>

long long get_valid_long_long (void);
long long checksum (long long l);
void check_type (long long l, int i, int j, int k);
int first_digit (long long l);
int second_digit (long long l);
int length (long long l);

int main(void){
    long long card = get_valid_long_long();
    check_type(checksum(card), first_digit(card), second_digit(card), length(card));
}

long long get_valid_long_long (void){
    long long l;
    
    do{
        printf("Credit Card Number: ");
        l = get_long_long();
    } while (false);
    
    return l;
}

long long checksum (long long l){
    int a = 0;
    int b = 0;
    int i = 0;
    while (l != 0){
        if (i%2 == 0){
            b = b+l%10;
        } else {
            if (((l%10*2)/10) != 0){
                a = a+1+((l%10*2)%10);
            } else {
                a = a+(l%10*2);
            }
        }
        l/=10;
        i++;
    }
    return (a+b)%10;
}

void check_type (long long l, int i, int j, int k){
    if (l == 0){
        if (i == 3){
            if (j == 4 || j==7){
                if (k == 15){
                    printf("AMEX\n");
                }else{
                    printf("INVALID\n");
                }
            }else {
                printf("INVALID\n");
            }
        } else if (i == 5) {
            if (j == 1 || j == 2 || j == 3 || j == 4 || j ==5) {
                if (k == 16){
                    printf("MASTERCARD\n");
                } else {
                    printf("INVALID\n");
                }
            } else {
                printf("INVALID\n");
            }
        } else if (i == 4){
            if (k == 13 || k == 16){
                printf("VISA\n");
            } else {
                printf("INVALID\n");
            }
        } else {
            printf("INVALID\n");
        }
    } else {
        printf("INVALID\n");
    }
}

int first_digit (long long l){
    int a;
    for (int i = 0; l != 0; i++) {
        a = l%10;
        l /= 10;
    }
    return a;
}

int second_digit (long long l){
    int a;
    for (int i = 0; (l/10) != 0; i++) {
        a = l%10;
        l /= 10;
    }
    return a;
}

int length (long long l){
    int a;
    int i;
    for (i = 0; l != 0; i++) {
        a = l%10;
        l /= 10;
    }
    return i;
}