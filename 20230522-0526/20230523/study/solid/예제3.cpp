#include <iostream>

class Animal
{
    public:
        virtual void makeSound() const{
            std::cout << "Animal makes a sound." << std::endl;
        }
};

class Bird : public Animal{
    public:
        void makeSound() const override {
            std::cout << "Bird chirps" << std::endl;
        }

        void fly() const {
            std::cout << "Bird flies." << std::endl;
        }
};

void performSound(const Animal& animal){
    animal.makeSound();
}

int main(){
    Animal animal;
    Bird bird;

    performSound(animal);
    performSound(bird);

    return 0;
}
