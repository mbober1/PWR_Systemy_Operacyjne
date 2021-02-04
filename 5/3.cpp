#include <fstream>
#include <sys/stat.h>

int main(int argc, char *argv[]) {

    mkfifo("fifka", 0666);

    std::ifstream file;
    std::ofstream fifka;
    
    fifka.open("fifka", std::ios::out);

    for(int i = 1; i<=argc; ++i) {
        file.open(argv[i], std::ios::in);

        if (file.is_open())
        {
            fifka << file.rdbuf();
            file.close();
        }
    }

    fifka.close();
    return 0;
}