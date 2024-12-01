#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const Animal* animals[4];

    for (int i = 0; i < 2; ++i) {
        animals[i] = new Dog();
    }
    for (int i = 2; i < 4; ++i) {
        animals[i] = new Cat();
    }

    // Verificar comportamiento del Brain
    Dog* dog = dynamic_cast<Dog*>(const_cast<Animal*>(animals[0]));
    if (dog) {
        dog->setBrainIdea(0, "Chase the cat");
        std::cout << "Dog idea: " << dog->getBrainIdea(0) << std::endl;
    }

    // Liberar memoria
    for (int i = 0; i < 4; ++i) {
        delete animals[i];
    }

    return 0;
}
