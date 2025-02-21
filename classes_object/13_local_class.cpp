#include <iostream>
using namespace std;

class Outer {
private:
    class Inner_private {  // Private nested class
    public:
        void show() {
            std::cout << "Inside private Inner class\n";
        }
    };

protected:
    class Inner_protected {  // Protected nested class
        public:
            void show() {
                std::cout << "Inside protected Inner class\n";
            }
        };
public:
    class Inner_public {  // Protected nested class
        public:
            void show() {
                std::cout << "Inside public Inner class\n";
            }
        };

    void display_private() {
        Inner_private obj_private;  
        obj_private.show();
    }
};

class Derived : public Outer {
public:
    Outer::Inner_protected obj_protected;
};

int main() {
    //Private nested class
    Outer outerObj;
    outerObj.display_private();

    //Protected nested class
    Derived Derived;
    Derived.obj_protected.show(); 
    
    //Public nested class
    Outer::Inner_public obj_public;
    obj_public.show();
}
