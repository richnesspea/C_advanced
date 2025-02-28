#ifndef ARRAY_MANAGER_H
#define ARRAY_MANAGER_H

#include <stdbool.h>

void clear_array();
void create_array(int size);
void print_array();
bool insert_element(int value, int position);
bool delete_element(int position);
void sort_array(bool ascending);
bool search_element(int value);
void clear_array();

#endif