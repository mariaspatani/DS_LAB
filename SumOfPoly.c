/*
Author : Maria 
Date : 17 July 2025
Description : A program to find the sum of two polynomials.
*/

#include <stdio.h>
#define MAX 100

struct Term {
    int coeff;
    int expo;
};

int main() {
    struct Term poly1[MAX], poly2[MAX], resultPoly[MAX];
    int i = 0, j = 0, k = 0;
    int size1, size2;

    printf("Enter the Size of Poly1:");
    scanf("%d", &size1);
    printf("Enter the elements in Poly1(coeff and expo)\n");
    for (i = 0; i < size1; i++) {
        printf("Term: %d ", i + 1);
        scanf("%d %d", &poly1[i].coeff, &poly1[i].expo);
    }

    printf("Enter the Size of Poly2:");
    scanf("%d", &size2);
    printf("Enter the elements in Poly2(coeff and expo)\n");
    for (j = 0; j < size2; j++) {
        printf("Term: %d ", j + 1);
        scanf("%d %d", &poly2[j].coeff, &poly2[j].expo);
    }

    i = j = 0;
    while (i < size1 && j < size2) {
        if (poly1[i].expo == poly2[j].expo) {
            resultPoly[k].expo = poly1[i].expo;
            resultPoly[k].coeff = poly1[i].coeff + poly2[j].coeff;
            k++;
            i++;
            j++;
        } else if (poly1[i].expo > poly2[j].expo) {
            resultPoly[k] = poly1[i];
            k++;
            i++;
        } else {
            resultPoly[k] = poly2[j];
            k++;
            j++;
        }
    }

    while (i < size1) {
        resultPoly[k++] = poly1[i++];
    }
    while (j < size2) {
        resultPoly[k++] = poly2[j++];
    }

    printf("Resultant Polynomial: ");
    for (int m = 0; m < k; m++) {
    if (resultPoly[m].coeff == 0)
        continue;
    printf(" + "); // ← This would print + even at the start
    printf("%d", resultPoly[m].coeff);
  
}

    return 0;
}
