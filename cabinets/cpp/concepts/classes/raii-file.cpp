#include <cstdio>
#include <stdexcept>

class FileOwner {
public:
    explicit FileOwner(const char* path)
        : file_{std::fopen(path, "w")}
    {
        if (file_ == nullptr) {
            throw std::runtime_error{"could not open file"};
        }

        std::puts("constructor: file acquired");
    }

    ~FileOwner()
    {
        if (file_ != nullptr) {
            if (std::fclose(file_) == 0) {
                std::puts("destructor: file closed");
            } else {
                std::fputs("destructor: close failed\n", stderr);
            }

            file_ = nullptr;
        }
    }

    FileOwner(const FileOwner&) = delete;
    FileOwner& operator=(const FileOwner&) = delete;

    void write(const char* text)
    {
        if (std::fputs(text, file_) == EOF) {
            throw std::runtime_error{"could not write to file"};
        }
    }

private:
    std::FILE* file_;
};

int main()
{
    const char* path{"raii-example.txt"};

    std::puts("before scope");
    {
        FileOwner file{path};
        file.write("owned by scope\n");
        std::puts("inside scope");
    }
    std::puts("after scope");

    if (std::remove(path) != 0) {
        std::perror("could not remove temporary file");
        return 1;
    }
}
