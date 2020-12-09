#include <iostream>
#include <fstream>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

// do 21:30
// part 2 to jutra 10:00

int main() {
    std::string filename;
    char * memory;
    int fileDescriptor;
    struct stat fileStat;


    fileDescriptor = open("sharedmemory", O_RDWR | O_CREAT, (mode_t)0600); //odczyt i zapis/create/uprawnienia

    while (1)
    {
        std::cin >> filename;
        std::ifstream file (filename);

        if(file) {
            stat(filename.c_str(), &fileStat);  //pobieramy dane o pliku
            memory = (char *)mmap(NULL, fileStat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fileDescriptor, 0); //odczyt, zapis, udostepnianie innym procesom
            ftruncate(fileDescriptor, fileStat.st_size);

            file >> memory;
            printf("zapis do pliku\n");
        } else break;
    }
    
    ftruncate(fileDescriptor, 0);
    munmap((void *)memory, fileStat.st_size);
    close(fileDescriptor);
    return 0;

}