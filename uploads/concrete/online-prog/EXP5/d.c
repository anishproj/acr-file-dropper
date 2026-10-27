#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    float coeff;
    int exp;
    struct node *next;
} node;

// Create dummy head node (exp = -1)
node* createHead() {
    node *h = (node*)malloc(sizeof(node));
    h->coeff = 0;
    h->exp = -1;
    h->next = h;
    return h;
}

// Insert term in descending exponent order
void attach(node *h, float coeff, int exp) {
    if (coeff == 0) return;

    node *prev = h;
    node *curr = h->next;

    while (curr != h && curr->exp > exp) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != h && curr->exp == exp) {
        curr->coeff += coeff;
        return;
    }

    node *nn = (node*)malloc(sizeof(node));
    nn->coeff = coeff;
    nn->exp = exp;
    nn->next = curr;
    prev->next = nn;
}

// Create Polynomial
void create(node *h) {
    int n, exp;
    float coeff;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Coeff and Exp: ");
        scanf("%f %d", &coeff, &exp);
        attach(h, coeff, exp);
    }
}

// Display Polynomial
void disp(node *h) {
    if (h->next == h) {
        printf("0\n");
        return;
    }
    node *curr = h->next;
    while (curr != h) {
        printf("%.1fx^%d", curr->coeff, curr->exp);
        curr = curr->next;
        if (curr != h) printf(" + ");
    }
    printf("\n");
}

// Add Two Polynomials
node* addpoly(node *h1, node *h2) {
    node *sum = createHead();
    node *c1 = h1->next;
    node *c2 = h2->next;

    while (c1 != h1 && c2 != h2) {
        if (c1->exp == c2->exp) {
            attach(sum, c1->coeff + c2->coeff, c1->exp);
            c1 = c1->next;
            c2 = c2->next;
        } else if (c1->exp > c2->exp) {
            attach(sum, c1->coeff, c1->exp);
            c1 = c1->next;
        } else {
            attach(sum, c2->coeff, c2->exp);
            c2 = c2->next;
        }
    }

    while (c1 != h1) { attach(sum, c1->coeff, c1->exp); c1 = c1->next; }
    while (c2 != h2) { attach(sum, c2->coeff, c2->exp); c2 = c2->next; }

    return sum;
}

int main() {
    node *h1 = createHead();
    node *h2 = createHead();
    node *h3 = NULL;
    int choice;

    while (1) {
        printf("\n1.Create P1 2.Create P2 3.Display P1 4.Display P2 5.Add 6.Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1) create(h1);
        else if (choice == 2) create(h2);
        else if (choice == 3) { printf("P1 = "); disp(h1); }
        else if (choice == 4) { printf("P2 = "); disp(h2); }
        else if (choice == 5) {
            h3 = addpoly(h1, h2);
            printf("P1 + P2 = ");
            disp(h3);
        }
        else if (choice == 6) break;
    }
    return 0;
}
