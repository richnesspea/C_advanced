#include "Employee_manager.hpp"
#include "Intern.hpp"
#include "loop.hpp"
#include "Validation.hpp"

void Employee_manager::addEmployee(void) {
    std::string employeeID;
    std::string fullname;
    std::string phone;
    std::string email;
    Employee_type employee_type;
    uint8_t day, month, year;

    std::cout << "Enter the employee ID: " << std::endl;
    std::cin >> employeeID;
    if (u_map.find(employeeID) == u_map.end()) {
        try {
            // Birthday validation
            std::cout << "Enter the Employee birth day: " << std::endl;
            std::cin >> day;
            std::cout << "Enter the Employee birth month: " << std::endl;
            std::cin >> month;
            std::cout << "Enter the Employee birth year: " << std::endl;
            std::cin >> year;
            Day birthday(day, month, year);
            validateBirthday(birthday);

            // Name validation
            std::cout << "Enter the employee name: " << std::endl;
            std::cin >> fullname;
            validateName(fullname);

            // Phone validation
            std::cout << "Enter the employee phone: " << std::endl;
            std::cin >> phone;
            validatePhone(phone);

            // Email validation
            std::cout << "Enter the employee email: " << std::endl;
            std::cin >> email;
            validateEmail(email);

            std::cout << "Enter the employee type: " << std::endl;
            std::cin >> employee_type;

            switch (employee_type) {
                case Employee_type::Experience_employee: {
                    // Experience
                    uint8_t expInYear;
                    std::string proSkill;

                    std::cout << "Enter the Experience's expInYear" << std::endl;
                    std::cin >> expInYear;

                    std::cout << "Enter the Experience's proSkill" << std::endl;
                    std::cin >> proSkill;
                    validateName(proSkill); // Validate professional skill as a name

                    Employee *expEmp = new Experience(employeeID, fullname, birthday, phone, email, employee_type, expInYear, proSkill);
                    expEmp->addCertificate();
                    u_map[employeeID] = expEmp;
                    break;
                }

                case Employee_type::Fresher_employee: {
                    // Fresher
                    Rank graduation_rank;
                    std::string education;

                    std::cout << "Enter the fresher graduation day: " << std::endl;
                    std::cin >> day;
                    std::cout << "Enter the fresher graduation month: " << std::endl;
                    std::cin >> month;
                    std::cout << "Enter the fresher graduation year: " << std::endl;
                    std::cin >> year;

                    Day graduation_date(day, month, year);
                    validateBirthday(graduation_date);

                    std::cout << "Enter the fresher graduation rank" << std::endl;
                    std::cin >> graduation_rank;

                    std::cout << "Enter the fresher education" << std::endl;
                    std::cin >> education;
                    validateName(education); // Validate education as a name

                    Employee *fresherEmp = new Fresher(employeeID, fullname, birthday, phone, email, employee_type, graduation_date, graduation_rank, education);
                    fresherEmp->addCertificate();
                    u_map[employeeID] = fresherEmp;
                    break;
                }

                case Employee_type::Intern_employee: {
                    // Intern
                    std::string majors;
                    std::string semester;
                    std::string university_name;

                    std::cout << "Enter the intern majors: " << std::endl;
                    std::cin >> majors;
                    validateName(majors);

                    std::cout << "Enter the intern semester" << std::endl;
                    std::cin >> semester;
                    validateName(semester);

                    std::cout << "Enter the intern university name" << std::endl;
                    std::cin >> university_name;
                    validateName(university_name);

                    Employee *internEmp = new Intern(employeeID, fullname, birthday, phone, email, employee_type, majors, semester, university_name);
                    internEmp->addCertificate();
                    u_map[employeeID] = internEmp;
                    break;
                }

                default:
                    std::cout << "Invalid Employee type!" << std::endl;
            }

            std::cout << "Successfully added a new employee!" << std::endl;
        } catch (const std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
            std::cout << "Failed to add new employee due to invalid input!" << std::endl;
        }
    } else {
        std::cout << "Employee ID already exists! Failed to add new employee!" << std::endl;
    }
}

void Employee_manager::deleteEmployeeByID() {
    if (u_map.empty()) {
        std::cout << "There are no employees to delete!" << std::endl;
        return;
    }

    std::string employee_id;
    std::cout << "Enter the employee ID to delete: ";
    std::cin >> employee_id;

    auto it = u_map.find(employee_id);
    if (it != u_map.end()) {
        delete it->second; // Free dynamically allocated memory
        u_map.erase(it);    // Remove from map
        std::cout << "Employee with ID " << employee_id << " deleted successfully!" << std::endl;
    } else {
        std::cout << "Employee ID not found!" << std::endl;
    }
}


void Employee_manager::printByEmployee_type() const {
    if (u_map.empty()) {
        std::cout << "There are no employees to display!" << std::endl;
        return;
    }

    Employee_type employee_type;
    std::cin >> employee_type; // Leverages the overloaded >> operator

    std::cout << "Employees of type " << employee_type << ":" << std::endl;

    bool found = false;
    for (const auto &i : u_map) {
        if (i.second->getEmployee_type() == employee_type) {
            i.second->showMe();
            found = true;
        }
    }

    if (!found) {
        std::cout << "No employees found for this type." << std::endl;
    }
}

void Employee_manager::modifyEmployeeByID() {
    if (u_map.empty()) {
        std::cout << "There are no employees to modify!" << std::endl;
        return;
    }

    std::string employeeID;
    std::cout << "Enter the employee ID to modify: ";
    std::cin >> employeeID;

    auto it = u_map.find(employeeID);
    if (it == u_map.end()) {
        std::cout << "Employee ID not found!" << std::endl;
        return;
    }

    Employee *employee = it->second;
    employee->showMe();

    try {
        std::cout << "What do you want to modify?" << std::endl;
        std::cout << "1. Name" << std::endl;
        std::cout << "2. Birthday" << std::endl;
        std::cout << "3. Phone" << std::endl;
        std::cout << "4. Email" << std::endl;
        std::cout << "5. Add Certificates" << std::endl;
        std::cout << "6. Specific Details (Experience, Fresher, Intern)" << std::endl;
        std::cout << "0. Cancel" << std::endl;

        int choice;
        std::cin >> choice;

        std::string inputStr;
        uint8_t day, month, year;

        switch (choice) {
            case 1: { // Modify Name
                std::cout << "Enter new name: ";
                std::cin >> inputStr;
                validateName(inputStr);
                employee->setName(inputStr);
                break;
            }

            case 2: { // Modify Birthday
                std::cout << "Enter new birth day: ";
                std::cin >> day;
                std::cout << "Enter new birth month: ";
                std::cin >> month;
                std::cout << "Enter new birth year: ";
                std::cin >> year;

                Day newBirthday(day, month, year);
                validateBirthday(newBirthday);
                employee->setDay(newBirthday);
                break;
            }

            case 3: { // Modify Phone
                std::cout << "Enter new phone: ";
                std::cin >> inputStr;
                validatePhone(inputStr);
                employee->setPhone(inputStr);
                break;
            }

            case 4: { // Modify Email
                std::cout << "Enter new email: ";
                std::cin >> inputStr;
                validateEmail(inputStr);
                employee->setEmail(inputStr);
                break;
            }

            case 5: { // Add Certificates
                employee->addCertificate();
                break;
            }

            case 6: { // Modify Specific Employee Type Details
                Employee_type type = employee->getEmployee_type();

                if (type == Employee_type::Experience_employee) {
                    auto *expEmp = dynamic_cast<Experience *>(employee);
                    if (expEmp) {
                        uint8_t expInYear;
                        std::string proSkill;

                        std::cout << "Enter new years of experience: ";
                        std::cin >> expInYear;

                        std::cout << "Enter new professional skill: ";
                        std::cin >> proSkill;
                        validateName(proSkill);

                        expEmp->setExpInYear(expInYear);
                        expEmp->setProSkill(proSkill);
                    }

                } else if (type == Employee_type::Fresher_employee) {
                    auto *fresherEmp = dynamic_cast<Fresher *>(employee);
                    if (fresherEmp) {
                        Day gradDate;
                        Rank gradRank;
                        std::string education;

                        std::cout << "Enter new graduation day: ";
                        std::cin >> day;
                        std::cout << "Enter new graduation month: ";
                        std::cin >> month;
                        std::cout << "Enter new graduation year: ";
                        std::cin >> year;

                        gradDate = Day(day, month, year);
                        validateBirthday(gradDate);

                        std::cout << "Enter new graduation rank: ";
                        std::cin >> gradRank;

                        std::cout << "Enter new education: ";
                        std::cin >> education;
                        validateName(education);

                        fresherEmp->setGraduation_date(gradDate);
                        fresherEmp->setGraduation_rank(gradRank);
                        fresherEmp->setEducation(education);
                    }

                } else if (type == Employee_type::Intern_employee) {
                    auto *internEmp = dynamic_cast<Intern *>(employee);
                    if (internEmp) {
                        std::string majors, semester, university;

                        std::cout << "Enter new majors: ";
                        std::cin >> majors;
                        validateName(majors);

                        std::cout << "Enter new semester: ";
                        std::cin >> semester;
                        validateName(semester);

                        std::cout << "Enter new university name: ";
                        std::cin >> university;
                        validateName(university);

                        internEmp->setMajors(majors);
                        internEmp->setSemester(semester);
                        internEmp->setUniversity_name(university);
                    }
                }
                break;
            }

            case 0: // Cancel
                std::cout << "Modification canceled." << std::endl;
                return;

            default:
                std::cout << "Invalid choice!" << std::endl;
                return;
        }

        std::cout << "Employee details updated successfully!" << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << "Failed to modify employee due to invalid input!" << std::endl;
    }
}

