#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void term(int signum)
{
   switch (signum)
   {
   case SIGTERM:
       printf("Sygnał %d przechwycony\n ", signum);
       _exit(0);
       break;

    case SIGALRM:
       printf("Sygnał %d przechwycony\n ", signum);
       printf("Kontynuję pracę\n");
       break;

   }
}

int i;


int main(int argc, char *argv[])
{
    struct sigaction action;
    memset(&action, 0, sizeof(action));
    action.sa_handler = term;
    sigaction(SIGTERM, &action, NULL);
    sigaction(SIGALRM, &action, NULL);

    for(;;) {
        i++;
        sleep(1);
        printf("jakiś tekst\n");
    }

    return 0;
}