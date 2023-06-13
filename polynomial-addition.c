#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

struct Node* createNode(int coefficient, int exponent) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

void insertTerm(struct Node** poly, int coefficient, int exponent) {
    struct Node* newNode = createNode(coefficient, exponent);
    if (*poly == NULL) {
        *poly = newNode;
    } else {
        struct Node* current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void addPolynomials(struct Node* poly1, struct Node* poly2, struct Node** resultPoly) {
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            insertTerm(resultPoly, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            insertTerm(resultPoly, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int sum = poly1->coefficient + poly2->coefficient;
            if (sum != 0) {
                insertTerm(resultPoly, sum, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL) {
        insertTerm(resultPoly, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insertTerm(resultPoly, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }
}

void displayPolynomial(struct Node* poly) {
    if (poly == NULL) {
        printf("0");
    } else {
        while (poly != NULL) {
            printf("%d", poly->coefficient);
            if (poly->exponent != 0) {
                printf("x^%d", poly->exponent);
            }
            if (poly->next != NULL) {
                printf(" + ");
            }
            poly = poly->next;
        }
    }
    printf("\n");
}

void printMenu() {
    printf("\nPolynomial Addition Menu:\n");
    printf("1. Add polynomials\n");
    printf("2. Exit\n");
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* resultPoly = NULL;
    int choice, n, coefficient, exponent;

    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the degree of the polynomials: ");
                scanf("%d", &n);

                printf("Enter the coefficients and exponents of the first polynomial:\n");
                for (int i = n; i >= 0; i--) {
                    printf("Coefficient for x^%d: ", i);
                    scanf("%d", &coefficient);
                    insertTerm(&poly1, coefficient, i);
                }

                printf("Enter the coefficients and exponents of the second polynomial:\n");
                for (int i = n; i >= 0; i--) {
                    printf("Coefficient for x^%d: ", i);
                    scanf("%d", &coefficient);
                    insertTerm(&poly2, coefficient, i);
                }

                addPolynomials(poly1, poly2, &resultPoly);

                printf("\nPolynomial 1: ");
                displayPolynomial(poly1);
                printf("Polynomial 2: ");
                displayPolynomial(poly2);
                printf("Resultant Polynomial: ");
                displayPolynomial(resultPoly);

                // Clearing the polynomials for the next iteration
                poly1 = NULL;
                poly2 = NULL;
                resultPoly = NULL;

                break;

            case 2:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
