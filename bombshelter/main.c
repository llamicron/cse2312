#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>


typedef struct _B_PACKED {
    uint32_t taxId;
    char name[27];
    char direction;
    char street[35];
    uint32_t addNo;
    char city[30];
    char state[3];
    uint32_t zip;
} __attribute__((packed)) B_PACKED;

typedef struct _B_UNPACKED {
    uint32_t taxId;
    char name[27];
    char direction;
    char street[35];
    uint32_t addNo;
    char city[30];
    char state[3];
    uint32_t zip;
} B_UNPACKED;

int main(void) {

    printf("--- Unpacked ---\n");
    printf("sizeof(foo) = %ld\n", sizeof(B_UNPACKED));
    printf("%ld\t uint32_t taxId   \t(ind. size %ld)\n", offsetof(B_UNPACKED, taxId), sizeof(uint32_t));
    printf("%ld\t char name[27]   \t(ind. size %ld)\n", offsetof(B_UNPACKED, name), sizeof(char));
    printf("%ld\t char direction   \t(ind. size %ld)\n", offsetof(B_UNPACKED, direction), sizeof(char));
    printf("%ld\t char street[35]   \t(ind. size %ld)\n", offsetof(B_UNPACKED, street), sizeof(char));
    // padding here, 1 byte
    printf("1\t char pad[1]\n");
    printf("%ld\t uint32_t addNo   \t(ind. size %ld)\n", offsetof(B_UNPACKED, addNo), sizeof(uint32_t));
    printf("%ld\t char city[30]   \t(ind. size %ld)\n", offsetof(B_UNPACKED, city), sizeof(char));
    printf("%ld\t char state[3]   \t(ind. size %ld)\n", offsetof(B_UNPACKED, state), sizeof(char));
    // padding here, 3 bytes
    printf("1\t char pad[3]\n");
    printf("%ld\t uint32_t zip   \t(ind. size %ld)\n", offsetof(B_UNPACKED, zip), sizeof(uint32_t));

    printf("\n\n--- Packed ---\n");
    printf("sizeof(foo) = %ld\n", sizeof(B_PACKED));
    printf("%ld\t uint32_t taxId\n", offsetof(B_PACKED, taxId));
    printf("%ld\t char name[27]\n", offsetof(B_PACKED, name));
    printf("%ld\t char direction\n", offsetof(B_PACKED, direction));
    printf("%ld\t char street[35]\n", offsetof(B_PACKED, street));
    printf("%ld\t uint32_t addNo\n", offsetof(B_PACKED, addNo));
    printf("%ld\t char city[30]\n", offsetof(B_PACKED, city));
    printf("%ld\t char state[3]\n", offsetof(B_PACKED, state));
    printf("%ld\t uint32_t zip\n", offsetof(B_PACKED, zip));
    

}
