#include <iostream>

namespace MyLibrary {
    inline namespace v2 {  // This is the default version
        void show() {
            std::cout << "This is version 2" << std::endl;
        }
    }

    namespace v1 {  // Older version
        void show() {
            std::cout << "This is version 1" << std::endl;
        }
    }
}

int main() {
    MyLibrary::show();    // Calls v2::show() because v2 is inline
    MyLibrary::v1::show(); // Explicitly calls v1::show()
}
