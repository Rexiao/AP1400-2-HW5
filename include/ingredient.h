#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>

class Ingredient {
   public:
    double get_price_unit() const {
        return price_unit;
    }
    size_t get_units() const {
        return units;
    }
    virtual std::string get_name() const = 0;

    double price() const {
        return units * price_unit;
    }
    virtual ~Ingredient() = default;

   protected:
    Ingredient(double price_unit, size_t units) : price_unit{price_unit}, units{units} {}

    double price_unit;
    size_t units;
    std::string name;
};

#endif  // INGREDIENT_H