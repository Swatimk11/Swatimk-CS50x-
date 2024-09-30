#include <cs50.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]) {
    // Check for correct number of arguments
    if (argc != 2) {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // Convert key from string to integer
    int key = atoi(argv[1]);

    // Check if key is a non-negative integer
    if (key < 0) {
        printf("Key must be a non-negative integer.\n");
        return 1;
    }

    // Get plaintext from user
    string plaintext = get_string("plaintext: ");

    // Encrypt plaintext using Caesar's cipher
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++) {
        char c = plaintext[i];  // Use descriptive variable name

        // Check if character is alphabetic
        if (isalpha(c)) {
            // Determine case and offset
            char case_offset = isupper(c) ? 'A' : 'a';

            // Encrypt letter using Caesar's cipher
            char encrypted_char = ((c - case_offset + key) % 26) + case_offset;

            // Print encrypted letter
            printf("%c", encrypted_char);
        } else {
            // Print non-alphabetic characters unchanged
            printf("%c", c);
        }
    }
    printf("\n");

    return 0;
}
