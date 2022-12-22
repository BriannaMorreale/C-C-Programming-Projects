//Brianna Morreale
//Assignment 4
#include <iostream>
#include <stdio.h>
#include <random>
#include <vector>
using namespace std;


class Actions { //interface of actions
    public:
        void move();
        void die();
        void eat();
        void reproduce();
};

class Thing{ //Thing class that will have children: Food and Creature
            //Created so we can make a 2D array with both Creature and Food
    public:
        int row;
        int column;
};


class Food: public Thing{
    
    public:
        int nutrition; // affect hunger
        int row; //position for the map
        int column;

        int getNutrition(){ //returns food's nutrition
            return nutrition;
        }
    
    Food(int r, int c){ //Food constructor to create Food
        this -> row = r;
        this -> column = c;
    }

};


class Creature: public Actions, public Thing{
    
    public:
        int row; //position on the map
        int column;
        int hunger = 10; 
        int age = 0;

    Creature(int r, int col){ //Constructor to create Creature
        this -> row = r;
        this -> column = col;
    }

        bool eat(Food f){ //takes in a Food object
         if((this -> row == f.row && this -> column == f.column)){
                this -> hunger += f.getNutrition();
                return true;
            }
            return false;
        }

        
        bool reproduce(Creature c1){ //rolls chances to make another creature
           int randomNum = (int)(rand() % 2);
            if (this -> row == c1.row && this -> column == c1.column){
                if(randomNum <= 1){
                    return true;
                }
            }
            return false;
        }

};

class World{
   public:
        vector<Creature> cList; //holds the creatures
        vector<Food> fList; //holds the food
        int population =0;
        int totalDeaths =0;

    void spawnCreature(){ //creates the creature 
         int randomNum = (int)(rand() % 10);
            if (randomNum == 1){
                int randomX = (int)(rand() % 10);
                int randomY = (int)(rand() % 10);
                Creature* c = new Creature(randomX, randomY);
                population++;
                cList.push_back(*c);
            }
    }

    void spawnFood(){ //creates the food
      int randomNum = (int)(rand() % 10);
        if (randomNum == 1){
            if (randomNum == 1){
                int randomX = (int)(rand() % 10);
                int randomY = (int)(rand() % 10);
                Creature* c = new Creature(randomX, randomY);
                cList.push_back(*c);
                cout << "More food has appeared." << endl;
            }   
        }
    }

     void deleteCreature(Creature c, int i){ //removes the creautre 
        cList.erase(cList.begin() + i);
        c.row = NULL;
        c.column = NULL;
        population--;
        totalDeaths++;
     }

     void deleteFood(Food f, int i){ //removes the food
        fList.erase(fList.begin() + i);
        f.row = NULL;
        f.column = NULL;
     }


};

int main(){
    World* w = new World(); //creating a world with two creatures
    Creature* c1 = new Creature(1,1);
    w->population++;
    Creature* c2 = new Creature(1,1);
    w->population++;

    w -> cList.push_back(*c1); //adding creatures to the array
    w -> cList.push_back(*c2);

    int avgHunger = 0;
    int avgAge = 0;

    //Main Loop
    for (int i = 1; i <= 10; i++){
        w -> spawnCreature();
        w -> spawnFood();
         

        for (int j = 0; j < w -> cList.size(); j++){
            for (int k = 0; k < w -> fList.size(); k++){
                 if (w -> cList[j].row == w -> fList[k].row && w -> cList[j].
                    row == w -> fList[k].row){ //allows the creature to eat
                    cout << "Creature ate a yummy meal!" << endl;
                    w -> cList[j].eat(w -> fList[k]);
                    w->deleteFood(w -> fList[k], k);
                    }
            }

        for(int l = 0; l < w -> cList.size(); l++){
            if (w -> cList[j].row == w -> cList[l].row && w -> cList[j].
                column == w -> cList[l].column && j != i && !w->cList.empty()){
                if(w -> cList[j].reproduce(w -> cList[l])){ //allows creature to reproduce
                    cout << "The creatures have fornicated and created a Creature" << endl;
                    w -> spawnCreature();
                }   
            }

        if (w -> cList[j].hunger <= 0){ //if hunger is 0, the creature dies
            cout << "Creature has entered the land of the dead at the age of " << w -> cList[j].age << endl;
            w -> deleteCreature(w -> cList[j], j);
        }

    }
    w -> cList[j].hunger -= 4;
    avgHunger += w -> cList[j].hunger;
    w -> cList[j].age++;
    avgAge += w ->cList[j].age;
    }
    avgHunger = avgHunger / w -> cList.size();
    avgAge = avgAge / w -> cList.size();

    cout << "---------------------------------------------------" << endl;
    cout << "END OF STAGE " << i << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "The current number of creatures is " << w->population << endl;
    cout << "The average hunger of the creatures is " << avgHunger << endl;
    cout << "The average age of the creatures is " << avgAge << endl;
    cout << "The number of deaths is " << w->totalDeaths << endl;
    cout << "---------------------------------------------------" << endl;
    }
    cout << "END OF SIMULATION" << endl;
    return 0;
}
