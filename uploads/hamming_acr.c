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
    int data[10], hamming[20];
    int m, r = 0, i, j, k;

    printf("Enter number of data bits: ");
    scanf("%d", &m);

    printf("Enter the data bits (one by one):\n");
    for (i = 1; i <= m; i++) {
        scanf("%d", &data[i]);
    }

    while (!(pow(2,r)>= m+r+1)) {
        r++;
    }

    int n = m + r; 

    
    j = 0; 
    k = 1; 

    for (i = 1; i <= n; i++) {
        // Check if current position 'i' is a power of 2
        if (i == (pow (2,j))) {
            hamming[i] = 0; // Reserve for parity bit
            j++;

        } else {
            hamming[i] = data[k++]; // Insert data bit
        }
    }

    // 4. Calculate parity bits
    for (i = 0; i < r; i++) {
        int pos = (pow(2,i)); // Position of the current parity bit
        int parity = 0;

        // Check bits covered by this parity bit
        for (j = 1; j <= n; j++) {
            if ((j & pos) != 0) {
                parity ^= hamming[j];
            }
        }
        hamming[pos] = parity;
    }
 
    // 5. Display the final Hamming Code
    printf("\nHamming Code is: ");
    for (i = n; i >= 1; i--) {
        printf("%d", hamming[i]);
    }
    printf("\n");
//-------------------------error detection--------------------












    return 0;
}