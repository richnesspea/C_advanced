#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;

public:
    // Constructor
    Book(const std::string& t, const std::string& a) : title(t), author(a) {}

    // Return a non-const reference to the title (allows modification)
    std::string& getTitle() {
        return title;
    }

    // Return a const reference to the author (prevents modification)
    const std::string& getAuthor() const {
        return author;
    }
};

int main() {
    Book myBook("1984", "George Orwell");

    // Access title by non-const reference and modify it
    std::string& title = myBook.getTitle();
    std::cout << "Title (before modification): " << title << std::endl;
    title = "Brave New World";  // Modifying the title through the reference
    std::cout << "Title (after modification): " << myBook.getTitle() << std::endl;

    // Access author by const reference (read-only)
    const std::string& author = myBook.getAuthor();
    std::cout << "Author: " << author << std::endl;

    // Uncommenting the following line will cause a compilation error
    // because `author` is a const reference:
    // author = "Aldous Huxley";

    return 0;
}
