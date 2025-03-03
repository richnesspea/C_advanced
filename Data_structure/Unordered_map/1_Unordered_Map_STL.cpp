#include <iostream>
#include <unordered_map>

int main(){
    std::unordered_map<int, std::string> myMap = {{1, "Do"}, {2, "Quang"}, {3, "Long"}};
    for(const auto& pair : myMap){
        std::cout << pair.first << " : " << pair.second << std::endl; 
    }   
}
