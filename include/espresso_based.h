#ifndef ESPRESSO_BASED_H
#define ESPRESSO_BASED_H

#include <string>
#include <vector>

#include "ingredient.h"

class EspressoBased {
   public:
    virtual std::string get_name() const = 0;
    virtual double price() const = 0;

    void brew() const;
    std::vector<Ingredient*>& get_ingredients() {
        // ingredients = std::vector<Ingredient*>();
        return ingredients;
    }

    virtual ~EspressoBased();

   protected:
    EspressoBased();
    EspressoBased(const EspressoBased& esp);
    void operator=(const EspressoBased& esp);

    std::vector<Ingredient*> ingredients;
    std::string name;
};

void clear_ingredients(std::vector<Ingredient*>&);
void append_ingredients(std::vector<Ingredient*>& ingredients, std::vector<Ingredient*> const& other_ingredients);

#endif  // ESPRESSO_BASED_H