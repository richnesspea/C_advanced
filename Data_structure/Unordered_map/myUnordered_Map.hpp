#ifndef __MY_UNORDERED_MAP_H__
#define __MY_UNORDERED_MAP_H__

#include <functional>  // Contains std::hash
#include <utility>     // Contains std::pair
#include <memory>      // Contains std::allocator
#include <vector> // Contains std::vector
#include <list> // Contains std::list

template <typename Key, //Represent the key in the map
          typename T, //Represent the value associated with the key
          typename Hash = std::hash<Key>, //Hash functionfor type Key
          typename Pred = std::equal_to<Key>, //This defines how keys are compared for equality
          typename Alloc = std::allocator<std::pair<const Key, T>>> //standared dynamic memory allocation
class unordered_map{
public:

private:

};




#endif