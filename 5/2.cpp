// do 22

#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include <fstream>


int main(int argc, char *argv[]) {
    pid_t cpid; //proces id
    int pipefd[2]; 
    pipe(pipefd);

    cpid = fork();

    if(cpid == 0) { //dziecko
        printf("jestem dzieckiem\n");
        dup2(pipefd[0], 0);
        close(pipefd[1]);

        char *newargv[] = { (char*)"display", NULL };
        execvp("/usr/bin/display", newargv);

        close(pipefd[0]);          // zamykamy czesc do odczytu
        _exit(EXIT_SUCCESS);
        

    } else { //rodzic
        printf("jestem rodzicem\n");
        close(pipefd[0]);          // zamykamy czesc do odczytu

        std::string line;
        std::ifstream file;
        file.open ("cat.jpg", std::ios::binary | std::ios::ate);

        if (file.is_open())
        {
            int fileSize = file.tellg();
            file.seekg(0);
            char* buf;
            buf = new char[fileSize];
            file.read(buf, fileSize);
            std::cout << buf; //czytanie z potoku do bufora

            write(pipefd[1], buf, fileSize); //czytanie z pliku do potoku
            file.close();
        }

        close(pipefd[1]);          // zamykamy czesc do zapisu
        wait(NULL);                //czekamy na smierc dziecka, miało piękny pogrzeb
        exit(EXIT_SUCCESS);
    }

    return 0;
}