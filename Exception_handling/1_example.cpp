#include <iostream>

class Printer
{
private:
    std::string name;
    int availablePaper;

public:
    Printer(const std::string &name, int availablePaper)
    {
        this->name = name;
        this->availablePaper = availablePaper;
    }
    void Print(std::string textDoc)
    {
        int requiredPaper = textDoc.length() / 10;
        std::cout << "The requiredPaper: " << requiredPaper << std::endl;
        if (requiredPaper > this->availablePaper)
        {
            throw "No paper";
        }
        std::cout << "Printing: " << textDoc << std::endl;
        this->availablePaper -= requiredPaper;
    }
};

int main()
{
    Printer myPrinter("Canon", 10);
    int n;
    try
    {
        std::cout << "Enter n value: " << std::endl;
        std::cin >> n;
        for (int i = 0; i < n; i++)
        {
            myPrinter.Print("Hello, my name is Long");
        }
    }
    catch (const char* txtException)
    {
        std::cout << "Exception: " << txtException << std::endl;
    }

    return 0;
}
