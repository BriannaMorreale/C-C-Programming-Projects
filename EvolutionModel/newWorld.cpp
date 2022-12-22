//Brianna Morreale
//Assignment 3
#include <iostream>
#include <stdio.h>
using namespace std;


class World{
   public:
        int capacity;
        float chancesOfSpawning;

        Creature createCreature(float chancesOfSpawning){
            //return Creature;
        }

        Food spawnFood(float chancesOfSpawning){
    }

};

class Actions {
    public:
        void move();
        void die();
        void eat();
        void reproduce();
};

class Creature: public World, public Actions{
    
    private:
        float fertility;
        int hunger;

        void move(int index){
        }

        void die(){
        }

        void eat(){
        }

        Creature reproduce(float fertility, float fertility2){
        }

        int getHunger(){
        }

        void checkHealth(int health){
        }
};

class Food: public World{
    
    public:
        int nutrition;
        float toxicity;

        int getNutrition(){
        }

        float getToxicity(){
        }
};


