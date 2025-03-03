#include "Street_loop.hpp"
#include "Street.hpp"

std::ostream &operator<<(std::ostream &COUT, uint8_t int8_var)
{
    COUT << static_cast<int>(int8_var);
    return COUT;
}

std::istream& operator>>(std::istream& CIN, uint8_t& int8_var) {
    int temp;
    CIN >> temp;
    

    if (temp < 0 || temp > 255) {
        CIN.setstate(std::ios::failbit); 
    } else {
        int8_var = static_cast<uint8_t>(temp);
    }

    return CIN;
}

void Street_loop(void)
{
    Street street;
    bool flag = true;
    int choice;
    while (flag)
    {
        std::cout << "\n===== MENU =====" << std::endl;
        std::cout << "1. Add Household" << std::endl;
        std::cout << "2. Add Person" << std::endl;
        std::cout << "3. Print All Households" << std::endl;
        std::cout << "4. Search Household by Number" << std::endl;
        std::cout << "5. Search Person by ID" << std::endl;
        std::cout << "6. Exit Program" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            street.addHousehold();
            break;
        case 2:
            street.addPerson();
            break;
        case 3:
            street.printHousehold();
            break;
        case 4:
            street.searchHousehold();
            break;
        case 5:
            street.searchPersonByID();
            break;
        case 6:
            street.exitProgram(flag);
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}



