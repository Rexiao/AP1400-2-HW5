#include "espresso_based.h"

#include <chrono>
#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

#include "ingredient.h"
#include "sub_ingredients.h"

using namespace std::chrono_literals;

void clear_ingredients(std::vector<Ingredient*>& ingredients) {
    for (const auto& i : ingredients)
        delete i;
    ingredients.clear();
}

void append_ingredients(std::vector<Ingredient*>& ingredients, std::vector<Ingredient*> const& other_ingredients) {
    for (const auto& i : other_ingredients) {
        if (i->get_name() == "MilkFoam")
            ingredients.push_back(new MilkFoam(i->get_units()));
        else if (i->get_name() == "Water")
            ingredients.push_back(new Water(i->get_units()));
        else if (i->get_name() == "Sugar")
            ingredients.push_back(new Sugar(i->get_units()));
        else if (i->get_name() == "Cinnamon")
            ingredients.push_back(new Cinnamon(i->get_units()));
        else if (i->get_name() == "Chocolate")
            ingredients.push_back(new Chocolate(i->get_units()));
        else if (i->get_name() == "Cookie")
            ingredients.push_back(new Cookie(i->get_units()));
        else if (i->get_name() == "Espresso")
            ingredients.push_back(new Espresso(i->get_units()));
        else if (i->get_name() == "Milk")
            ingredients.push_back(new Milk(i->get_units()));
    }
}

EspressoBased::~EspressoBased() {
    clear_ingredients(ingredients);
}

void EspressoBased::brew() const {
    using namespace ftxui;
    // Define the document

    std::string reset_position;
    for (int i = 0; i <= 100; i++) {
        auto gauge_comp = gauge(float(i) / 100.0);
        auto header = border(hbox({text("brewing: "),
                                   gauge_comp,
                                   text(" " + std::to_string(i) + "/100")}));
        auto gap = 100.0 / float(ingredients.size());
        auto square_elements = Elements();
        for (auto j = 0; j < ingredients.size(); ++j) {
            if (i > j * gap) {
                square_elements.push_back(text(ingredients[j]->get_name()));
            }
        }
        auto squares = vbox(square_elements);
        auto document = vbox({header, squares});
        auto screen = Screen::Create(
            Dimension::Full(),        // Width
            Dimension::Fit(document)  // Height
        );
        ftxui::Render(screen, document);
        std::cout << reset_position;
        reset_position = screen.ResetPosition();
        screen.Print();
        std::this_thread::sleep_for(0.05s);
    }
}

EspressoBased::EspressoBased() : ingredients{}, name{""} {}

EspressoBased::EspressoBased(const EspressoBased& esp) : ingredients{}, name{esp.name} {
    append_ingredients(ingredients, esp.ingredients);
}

void EspressoBased::operator=(const EspressoBased& esp) {
    clear_ingredients(ingredients);
    append_ingredients(ingredients, esp.ingredients);
}
