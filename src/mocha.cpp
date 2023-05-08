#include "mocha.h"

Mocha::Mocha() {
    name = "Mocha";
    ingredients.push_back(new Espresso(2));
    ingredients.push_back(new Milk(2));
    ingredients.push_back(new MilkFoam(1));
    ingredients.push_back(new Chocolate(1));
}

Mocha::~Mocha() {
    for (const auto& i : side_items)
        delete i;
    side_items.clear();
}

std::string Mocha::get_name() const {
    return this->name;
}

double Mocha::price() const {
    double money{0.0};
    for (auto i : side_items)
        money += i->price();
    for (auto i : ingredients)
        money += i->price();
    return money;
}

void Mocha::add_side_item(Ingredient* side) {
    side_items.push_back(side);
}

std::vector<Ingredient*>& Mocha::get_side_items() {
    return side_items;
}

void Mocha::operator=(const Mocha& Moc) {
    if (this == &Moc)
        return;

    for (const auto& i : side_items)
        delete i;
    side_items.clear();

    for (auto i : const_cast<Mocha&>(Moc).get_side_items()) {
        if (i->get_name() == "MilkFoam")
            this->add_side_item(new MilkFoam(i->get_units()));
        else if (i->get_name() == "Water")
            this->add_side_item(new Water(i->get_units()));
        else if (i->get_name() == "Sugar")
            this->add_side_item(new Sugar(i->get_units()));
        else if (i->get_name() == "Cinnamon")
            this->add_side_item(new Cinnamon(i->get_units()));
        else if (i->get_name() == "Chocolate")
            this->add_side_item(new Chocolate(i->get_units()));
        else if (i->get_name() == "Cookie")
            this->add_side_item(new Cookie(i->get_units()));
        else if (i->get_name() == "Espresso")
            this->add_side_item(new Espresso(i->get_units()));
        else if (i->get_name() == "Milk")
            this->add_side_item(new Milk(i->get_units()));
    }
}

Mocha::Mocha(const Mocha& Moc) : EspressoBased(Moc) {
    for (auto i : const_cast<Mocha&>(Moc).get_side_items()) {
        if (i->get_name() == "MilkFoam")
            this->add_side_item(new MilkFoam(i->get_units()));
        else if (i->get_name() == "Water")
            this->add_side_item(new Water(i->get_units()));
        else if (i->get_name() == "Sugar")
            this->add_side_item(new Sugar(i->get_units()));
        else if (i->get_name() == "Cinnamon")
            this->add_side_item(new Cinnamon(i->get_units()));
        else if (i->get_name() == "Chocolate")
            this->add_side_item(new Chocolate(i->get_units()));
        else if (i->get_name() == "Cookie")
            this->add_side_item(new Cookie(i->get_units()));
        else if (i->get_name() == "Espresso")
            this->add_side_item(new Espresso(i->get_units()));
        else if (i->get_name() == "Milk")
            this->add_side_item(new Milk(i->get_units()));
    }
}