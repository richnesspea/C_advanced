#include <iostream>
#include <unordered_set>

void findKey(const std::unordered_set<std::string> &stringSet, const std::string &key){
    if(stringSet.find(key) == stringSet.end()){
        std::cout << key << " not found!" << std::endl;
    }
    else {
        std::cout << key << " is found!" << std::endl;
    }
}

void printElementsInUnorderedSet(const std::unordered_set<std::string> &stringSet){
    std::unordered_set<std::string>::iterator itr;
    for(auto itr = stringSet.begin(); itr != stringSet.end(); itr++){
        std::cout << (*itr) << std::endl;
    }
}


int main(){
    std::unordered_set<std::string> stringSet;
    // Insert function
    stringSet.insert("LongDQ8");
    stringSet.insert("ChienNV");
    stringSet.insert("DucNP");
    stringSet.insert("SonLV");
    
    std::string key = "HoaDT";
    findKey(stringSet, key);

    key = "LongDQ8";
    findKey(stringSet, key);

    //erase key element
    stringSet.erase(key);
    //print all elements in UnorderedSet
    std::cout << "All elements in UnorderedSet" << std::endl;
    printElementsInUnorderedSet(stringSet);

}