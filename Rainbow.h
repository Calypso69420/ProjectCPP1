#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>

class Rainbow {
private:
    std::vector<sf::Color> colors = {
        {255, 0, 0},
        {255, 255, 0},
        {0, 255, 0},
        {0, 255, 255},
        {0, 0, 255},
        {255, 0, 255},
    };
    float currColor = 0;
public:
    sf::Color Lerp(sf::Color A, sf::Color B, float Alpha);

    size_t GetIndex(size_t idx);

    // conversion operator
    // converting "to color" returns current color
    operator sf::Color() {
        size_t beginIdx = (int)currColor;
        float progressIntoNext = currColor - beginIdx;
        return Lerp(colors[GetIndex(beginIdx)], colors[GetIndex(beginIdx + 1)], progressIntoNext);
    }

    // overloaded +=(rainbow, int)
    // eg Rainbow += 2 moves color 2 slots forward
    void operator += (float count) {                                    /* Przeciążenie operatora (rozszerzanie dziedziny operatora) */
        currColor = fmod((currColor + count), colors.size());
    }

    // Rainbow++ moves color one forward and returns old color
    sf::Color operator++(int){                                          /* Przeciążenie operatora */
        auto lastColor = colors[currColor];
        (*this) += 1.0f;
        return lastColor;
    }

    // add two rainbows together to merge their index
    friend void operator+= (Rainbow self, const Rainbow& other){            /* Friend declaration */
        self += other.currColor;
    }

    // left-value const reference (reference to an object bound to a variable)
    // copy constuctor
    Rainbow(const Rainbow& other){              /* Copy constructor */
        this->currColor = other.currColor;
    }

    // right-value ref (reference to an object created "in fly", not bound to a var)
    // since it's not bound to a var, we can MOVE it, thus it's called a move constructor
    Rainbow(Rainbow&& other){
        currColor = other.currColor;            /* Move constructor */
        // zero-out the other object
        other.currColor = 0;
    }

    Rainbow(){}
};


