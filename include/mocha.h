#ifndef MOCHA_H
#define MOCHA_H

#include <iostream>
#include <string>
#include <vector>

#include "espresso_based.h"
#include "ingredient.h"
#include "sub_ingredients.h"

class Mocha : public EspressoBased {
   public:
    Mocha();
    Mocha(const Mocha& Moc);
    ~Mocha();
    void operator=(const Mocha& Moc);

    virtual std::string get_name() const;
    virtual double price() const;

    void add_side_item(Ingredient* side);
    std::vector<Ingredient*>& get_side_items();

   private:
    std::vector<Ingredient*> side_items;
};

#endif  // MOCHA_H