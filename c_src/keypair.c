#include "ed25519.h"
#include "sha512.h"
#include "ge.h"


int ed25519_create_keypair(unsigned char *public_key, unsigned char *private_key, const unsigned char *seed) {
    ge_p3 A;

    sha512(seed, 32, private_key);
    private_key[0] &= 248;
    private_key[31] &= 63;
    private_key[31] |= 64;

    ge_scalarmult_base(&A, private_key);
    ge_p3_tobytes(public_key, &A);
    return 0;
}

int ed25519_public_key(unsigned char *public_key, unsigned char *private_key)
{
    ge_p3 A;
    ge_scalarmult_base(&A, private_key);
    ge_p3_tobytes(public_key, &A);
    return 0;
}

