#include <unistd.h>

int i;

void main() {
    for(;;) {
        i++;
        sleep(1);
    }
}