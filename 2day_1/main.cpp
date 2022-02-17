#include <iostream>

class Animal {
public:
        virtual void make_a_sound();
};

void Animal::make_a_sound() {
        std::cout << "some abstract sound" << std::endl;
}

class Dog : public Animal {
public:
        unsigned int width;
        unsigned int height;
        void make_a_sound();
};

void Dog::make_a_sound() {
        std::cout << "woof-woof!" << std::endl;
}

class Cat : public Animal {
public:
        unsigned int width;
        unsigned int height;
        void make_a_sound();
};

void Cat::make_a_sound() {
        std::cout << "Meow-Meow!" << std::endl;
}

int main()
{
        Animal anima;
        Dog rex;
        Cat barsik;
        Animal* pBarsik = &barsik;
        pBarsik->make_a_sound();
        return 0;
}
