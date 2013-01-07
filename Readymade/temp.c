#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
/*
 * RC4 implementation. usage: rc4 <plaintext> <key>
 *
 */
 
unsigned char S[256]; /* S-box */
unsigned int len;
 
void swap(unsigned char *a, unsigned char *b) {
 
    unsigned char tmp = *a;
    *a = *b;
    *b = tmp;
}
 
void rc4_init(char *key, int keylen) {
 
    int i;
    int j;
 
    for(i = 0; i < 256; i++) {
 
        S[i] = i;
    }
 
    /* randomize S-box */
    for(i = j = 0; i < 256; i++) {
 
        j = (j + key[i % keylen] + S[i]) % 256;
        swap(&S[i], &S[j]);
    }
    for(i=0;i<256;i++)
	printf("%d  ",S[i]);
}
 
void rc4_crypt(const char *in, unsigned char *out, size_t buflen) {
 
    int i;
    int j;
    int ks;
 
    for(i = j = 0; i < buflen; ) {
 
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        swap(&S[i], &S[j]);
        ks = (S[i] + S[j]) % 256;
 
        printf("%c  %d", in[i-1], S[ks]);             // correctly prints key stream
        //printf("%.2X", S[ks] ^ in[i - 1]); // correctly prints ciphertext
        out[i - 1] = S[ks] ^ in[i - 1];
    }
}
 
void print_ciphertext(unsigned char *ciphertext) {
 
    int i;
 
    for(i = 0; i < len; i++) {
        printf("%.2X", ciphertext[i]);
    }
}
 
int main(int argc, char **argv) {
 
    if(argc != 3) {
        printf("usage: rc4 <plaintext> <key>\n");
        exit(1);
    }
 
    char *key = argv[2];
    char *plaintext = argv[1];
    len = strlen(plaintext);
    unsigned char ciphertext[strlen(plaintext)];
 
    rc4_init(key, strlen(key));
    rc4_crypt(plaintext, ciphertext, strlen(plaintext));
 
    /* for(int i = 0; i < strlen(ciphertext); i++) {
            printf("%.2X", ciphertext[i]);
        } */
    print_ciphertext(ciphertext);
 
    return 0;
}
