#include <stdio.h>

// Function to encode an 8-bit data byte into a 12-bit Hamming code
unsigned short hamming_encode(char data) {
    // Calculate parity bits
    unsigned short p1 = (data & 0x01) ^ ((data >> 1) & 0x01) ^ ((data >> 3) & 0x01) ^ ((data >> 7) & 0x01);
    unsigned short p2 = (data & 0x01) ^ ((data >> 2) & 0x01) ^ ((data >> 3) & 0x01) ^ ((data >> 7) & 0x01);
    unsigned short p4 = ((data >> 1) & 0x01) ^ ((data >> 2) & 0x01) ^ ((data >> 3) & 0x01) ^ ((data >> 7) & 0x01);
    unsigned short p8 = ((data >> 4) & 0x01) ^ ((data >> 5) & 0x01) ^ ((data >> 6) & 0x01) ^ ((data >> 7) & 0x01);

    // Combine data and parity bits
    return (data << 4) | (p1 << 3) | (p2 << 2) | (p4 << 1) | p8;
}

// Function to decode a 12-bit Hamming code into an 8-bit data byte
char hamming_decode(unsigned short code) {
    // Calculate syndrome bits
    unsigned short s1 = (code & 0x01) ^ ((code >> 1) & 0x01) ^ ((code >> 3) & 0x01) ^ ((code >> 7) & 0x01);
    unsigned short s2 = (code & 0x01) ^ ((code >> 2) & 0x01) ^ ((code >> 3) & 0x01) ^ ((code >> 7) & 0x01);
    unsigned short s4 = ((code >> 1) & 0x01) ^ ((code >> 2) & 0x01) ^ ((code >> 3) & 0x01) ^ ((code >> 7) & 0x01);
    unsigned short s8 = ((code >> 4) & 0x01) ^ ((code >> 5) & 0x01) ^ ((code >> 6) & 0x01) ^ ((code >> 7) & 0x01);

    // Check for errors and correct if possible
    unsigned short syndrome = (s8 << 3) | (s4 << 2) | (s2 << 1) | s1;
    if (syndrome != 0) {
        // Flip the bit at the position indicated by the syndrome
        code = code ^ (1 << (11 - syndrome));
    }

    // Extract and return the 8 data bits
    return (code >> 4) & 0xFF;
}

int main() {
    // Example usage
    char input[] = "Hello";
    printf("Original String: %s\n", input);

    for (int i = 0; input[i] != '\0'; i++) {
        // Encode each character
        char encoded = hamming_encode(input[i]);
        printf("Encoded Char: %c -> 0x%04X\n", input[i], encoded);

        // Decode the encoded character
        char decoded = hamming_decode(encoded);
        printf("Decoded Char: 0x%04X -> %c\n", encoded, decoded);
    }

    return 0;
}

