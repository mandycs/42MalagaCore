#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    // No se permite crear un objeto de tipo Animal
    // const Animal* meta = new Animal(); // Esto dará error

    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;

    dog->makeSound(); // Salida: Woof!
    cat->makeSound(); // Salida: Meow!

    delete dog;
    delete cat;

    return 0;
}
