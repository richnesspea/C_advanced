#include <iostream>
using namespace std;

class Account {
public:
    static int totalAccounts;//Declaration of static data member 
    static const int maxAccounts = 100;  // Allowed: static const integral type
    void printMaxAccounts() const {
        cout << "Max accounts allowed: " << maxAccounts << endl;
    }
};

// Definition and initialization of static data member
int Account::totalAccounts = 0;


int main() {
    Account acc;
    cout << "Total accounts: " << Account::totalAccounts << endl;
    acc.printMaxAccounts();
    return 0;
}
