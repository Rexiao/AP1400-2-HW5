#include "cappuccino.h"

#include "sub_ingredients.h"

Cappuccino::~Cappuccino() {
    for (const auto& i : side_items)
        delete i;
    side_items.clear();
}

Cappuccino::Cappuccino() : EspressoBased() {
    name = "Cappuccino";
    ingredients.push_back(new Espresso(2));
    ingredients.push_back(new Milk(2));
    ingredients.push_back(new MilkFoam(1));
}
Cappuccino::Cappuccino(const Cappuccino& cap) : Cappuccino() {
    append_ingredients(side_items, cap.side_items);
}

void Cappuccino::operator=(const Cappuccino& cap) {
    if (this == &cap) {
        return;
    }
    clear_ingredients(side_items);
    append_ingredients(side_items, cap.side_items);
}

std::string Cappuccino::get_name() const {
    return name;
}
double Cappuccino::price() const {
    double total_price = 0.;
    for (const auto& i : ingredients) {
        total_price += i->price();
    }
    for (const auto& si : side_items) {
        total_price += si->price();
    }
    return total_price;
}

void Cappuccino::add_side_item(Ingredient* side) {
    side_items.push_back(side);
}
std::vector<Ingredient*>& Cappuccino::get_side_items() {
    return side_items;
}