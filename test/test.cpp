#include <iostream>

class Media {
public:
    virtual void play(){
        std::cout << "This is media ...\n";
    }; // Pure virtual function
    virtual ~Media() { std::cout << "Media destroyed\n"; } // Virtual destructor
};

class Audio : public Media {
public:
    void play() override {
        std::cout << "Playing audio...\n";
    }

    ~Audio() { std::cout << "Audio destroyed\n"; }
};

int main() {
    Media* media = new Audio; // Dynamically allocating derived class object

    media->play(); // Calls overridden function in Audio class

    delete media; // Deleting object, ensures derived destructor is called

    return 0;
}
