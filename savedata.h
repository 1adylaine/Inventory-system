#ifndef SAVEDATA_H
#define SAVEDATA_H

#include "product.h"
#include <vector>

void saveToFile(const std::vector<Product>& list);
void loadFromFile(std::vector<Product>& list);

#endif