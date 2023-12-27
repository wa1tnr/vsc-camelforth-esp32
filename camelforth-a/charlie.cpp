#include <Arduino.h>

extern unsigned int *psp;         /* stack pointers */

#ifdef __cplusplus
extern "C" {
#endif

/* dump 16 bytes of RAM in hex with ascii on the side */

void dumpRAM() {
    char buffer[9] = "";
    char *ram;
    // int p = pop();
    // int p = 1; /*                 KLUDGE  FIX ME */

    int p = psp[0]; psp++;

    ram = (char *)p;

    snprintf(buffer, sizeof(buffer), "%8x", p);
    Serial.print(buffer);
    Serial.print(" ");
    for (int i = 0; i < 16; i++) {
        char c = *ram++;
        snprintf(buffer, sizeof(buffer), " %2x", (c & 0xff));
        Serial.print(buffer);
    }
    ram = (char *)p;
    Serial.print(" ");
    for (int i = 0; i < 16; i++) {
        buffer[0] = *ram++;
        if (buffer[0] > 0x7f || buffer[0] < ' ')
            buffer[0] = '.';
        buffer[1] = '\0';
        Serial.print(buffer);
    }

// CODE(dup) {
//   --psp;
//   psp[0] = psp[1];
// }

    --psp;
    psp[0] = (p + 16);

    // push(p + 16);
    /*                                   KLUDGE  FIX ME */
}

/* dump 256 bytes of RAM */
void rdumps() {
    for (int i = 0; i < 16; i++) {
        Serial.println();
        dumpRAM();
    }
}

#ifdef __cplusplus
}
#endif

