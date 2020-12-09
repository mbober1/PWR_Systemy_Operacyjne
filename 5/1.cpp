#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
// do 20:30

int main(int argc, char *argv[]) {
    pid_t cpid; //proces id
    int pipefd[2]; 
    pipe(pipefd);

    cpid = fork();

    if(cpid == 0) { //dziecko
        printf("jestem dzieckiem\n");
        close(pipefd[1]);          // zamykamy czesc do zapisu
        char buf;
        while (read(pipefd[0], &buf, 1) > 0) std::cout << "#" << buf << "#"; //czytanie z potoku do bufora
        std::cout << std::endl;
        close(pipefd[0]);          // zamykamy czesc do odczytu
        _exit(EXIT_SUCCESS);
        
    } else { //rodzic
        printf("jestem rodzicem\n");
        close(pipefd[0]);          // zamykamy czesc do odczytu

        std::string line;
        std::ifstream file;
        file.open ("plik.txt");

        if (file.is_open())
        {
            while (getline(file,line))
            {
                write(pipefd[1], line.c_str(), line.length()); //czytanie z pliku do potoku
            }
            file.close();
        }

        close(pipefd[1]);          // zamykamy czesc do zapisu
        wait(NULL);                //czekamy na smierc dziecka, miało piękny pogrzeb
        exit(EXIT_SUCCESS);
    }


    return 0;
}