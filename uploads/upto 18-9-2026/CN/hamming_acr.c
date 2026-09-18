/*#include <stdio.h>
#include<math.h>

int main (){

    int input[100], output [100], opbits;
    int size,r =0;

    printf("enter size  of data \n");
    scanf("%d",& size);

    for (int i =0;i<size;i++){
    scanf("%d",& input[i]);

    }

    for (int i=0;i<size ; i++){
        if (!((2^r)>= size + r + 1))
        {
            r++;
        }

    }

    opbits = size + r;

    for (int i=0;i<opbits;i++){
        if (i == pow(2,i)){
            output[i] = r;
        }




    }

}*/

#include <stdio.h>
#include <math.h>

int main() {
    int data[10], hamming[20], rec[20];
    int m, r = 0, i, j, k;

    printf("Enter number of data bits: ");
    scanf("%d", &m);

    printf("Enter the data bits (one by one):\n");
    for (i = 1; i <= m; i++) {
        scanf("%d", &data[i]);
    }

    while (!(pow(2, r) >= m + r + 1)) {
        r++;
    }

    int n = m + r;  

    j = 0;  
    k = 1;  

    for (i = 1; i <= n; i++) {
        // Check if current position 'i' is a power of 2
        if (i == (int)(pow(2, j))) {
            hamming[i] = 0; // Reserve for parity bit
            j++;
        } else {
            hamming[i] = data[k++]; // Insert data bit
        }
    }

    // Calculate parity bits (Sender side)
    for (i = 0; i < r; i++) {
        int pos = (int)(pow(2, i)); // Position of the current parity bit
        int parity = 0;

        // Check bits covered by this parity bit
        for (j = 1; j <= n; j++) {
            if ((j & pos) != 0) {
                parity ^= hamming[j];
            }
        }
        hamming[pos] = parity;
    }
 
    // Display the final Hamming Code
    printf("\nGenerated Hamming Code is: ");
    for (i = n; i >= 1; i--) {
        printf("%d", hamming[i]);
    }
    printf("\n");

    // ------------------------- Error Detection & Correction --------------------

    printf("\nEnter the received Hamming code bits one by one (from position %d down to 1):\n", n);
    for (i = n; i >= 1; i--) {
        scanf("%d", &rec[i]);
    }

    int error_pos = 0;

    // Calculate syndrome to check for errors
    for (i = 0; i < r; i++) {
        int pos = (int)(pow(2, i));
        int parity = 0;

        for (j = 1; j <= n; j++) {
            if ((j & pos) != 0) {
                parity ^= rec[j];
            }
        }
        
        // If parity check fails, add the bit weight to error position
        if (parity != 0) {
            error_pos += pos;
        }
    }

    if (error_pos == 0) {
        printf("\nCongratulations! There is no error in the received data.\n");
    } else {
        printf("\nError detected at position: %d\n", error_pos);
        
        // Correct the error by flipping the bit
        if (rec[error_pos] == 0) {
            rec[error_pos] = 1;
        } else {
            rec[error_pos] = 0;
        }

        printf("Corrected Hamming Code is: ");
        for (i = n; i >= 1; i--) {
            printf("%d", rec[i]);
        }
        printf("\n");
    }

    return 0;
}
