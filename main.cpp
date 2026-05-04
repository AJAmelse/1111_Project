/*
 * CSCI 1111 Project 1
 * Artemis, Jude, Cameron
 *
 * */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <time.h>
#include "inventory.h"
#include "area.cpp"

using namespace std;

int addToInventory(char* thing, Inventory* inv){
    if(addItem(inv, thing)){
        printf("Added %s to inventory\n", thing);
        return 1;
    }else{
        printf("Inventory full\n");
        return 0;
    }
}

int useItem(char* thing, Inventory* inv){
    if(hasItem(inv, thing)){
        printf("Used %s\n", thing);
        removeItem(inv, hasItem(inv, thing)-1);
        return 1;
    }else{
        printf("not in inventory\n");
        return 0;
    }
}

bool actions(Area* area, Area * areas, Inventory* inventory, bool* lightningRodPlaced){
    char* item = (char*)malloc(sizeof(char)*inventory->str_length);
    string desiredArea;
    cout << area->getAreaDescription();
    if(area->getAreaName() == "button"){
        cout << "options: move(w), list inventory(i), search area(r), use item(f), press button(e), or quit(q): ";

    }else{
        cout << "options: move(w), list inventory(i), search area(r), use item(f), or quit(q): ";
    }
    char input;
    scanf(" %c", &input);
    if(input == 'w'){
        cout << "connected areas: ";
        for(string a : area->getConnectedAreas()){
            cout << a << ", ";
        }
        cout << endl;
        cout << "area to move to: ";
        cin >> desiredArea;
        for(string a : area->getConnectedAreas()){
            if(a == desiredArea){
                if(desiredArea == "downpour"){
                    *area = areas[0];
                }else if(desiredArea == "mountain"){
                    *area = areas[1];
                }else if(desiredArea == "lava"){
                    *area = areas[2];
                }else if(desiredArea == "snow"){
                    *area = areas[3];
                }else if(desiredArea == "forest"){
                    *area = areas[4];
                }else if(desiredArea == "lake"){
                    *area = areas[5];
                }else if(desiredArea == "river"){
                    *area = areas[6];
                }else if(desiredArea == "cave"){
                    *area = areas[7];
                }else if(desiredArea == "button"){
                    *area = areas[8];
                }else if(desiredArea == "win"){
                    cout << "YOU WIN!!!!";
                    return false;
                }
            }
        }

    }else if(input == 'i'){
        printInventory(inventory);
    }else if(input == 'r'){
        if(area->hasItem()){
            strcpy(item, area->getItem().c_str());
            addItem(inventory, item);
            area->removeItem();
            cout << "found " << item << "\n";
        }else{
            cout << "nothing was found\n";
        }

    }else if(input == 'f'){
        printf("Item to use:");
        scanf(" %[^\n]s", item);
        if(!area->getRequiredKey().empty()){
            if(area->getAreaName() == "button"){
                if(item == area->getRequiredKey()){
                    if(useItem(item, inventory)){
                        *lightningRodPlaced = true;
                    }
                    else{
                        cout << "item not in inventory\n";
                    }
                }else{
                    cout << "that item cannot be used here\n";
                }
            }else if(area->getAreaName() == "lake"){
                if(item == area->getRequiredKey()){
                    if(useItem(item, inventory)){
                        area->connectToArea("cave");
                    }else{
                        cout << "item not in inventory\n";
                    }
                }else{
                    cout << "that item cannot be used here\n";
                }

            }
        }else{
            printf("There was no use for that item here\n");
        }

    }else if(input == 'q'){
        free(item);
        item = NULL;
        return false;
    }else if(input == 'e' && area->getAreaName() == "button"){
        int num = rand() % 101;
                    if(num > 75){
                        printf("Confetti shoots into the sky\n");
                    }else if(num >50){
                        if(*lightningRodPlaced){
                            printf("Lightning strikes the lightning rod and you hear a click\n");
                            areas[7].connectToArea("win");
                        }else{
                            printf("Lightning strikes a tree next to you\n");
                        }
                    }else if(num > 25){
                        printf("The Northern Lights appear in the sky\n");
                    }else{
                        printf("Nothing happens\n");
                    }

    }else{
        cout << "invalid input\n";
    }
    free(item);
    item = NULL;
    return true;
}

int main(){
    Area* currentArea = new Area;
    bool running = true;
    Inventory* inventory = new_inventory(20, 5);
    //set rand seed to unix timestamp to have variable output from program
    srand(time(NULL));
    bool* lightningRodPlaced = new bool;
    *lightningRodPlaced = false;

    Area* areas = new Area[9];
    
    areas[0].setConnectedAreas({"snow", "forest"});
    areas[0].setAreaDescription("There is a torrential downpour and lightning crackles in the sky\n");
    areas[0].setAreaName("downpour");
    areas[0].setItemInArea("lightning rod");

    areas[1].setConnectedAreas({"lava", "forest"});
    areas[1].setAreaDescription("You come up to the side of a mountain \n");
    areas[1].setAreaName("mountain");

    areas[2].setConnectedAreas({"mountain"});
    areas[2].setAreaDescription("A lava stream blocks off your path \n");
    areas[2].setAreaName("lava");

    areas[3].setConnectedAreas({"button", "downpour"});
    areas[3].setAreaDescription("It suddenly got cold and there is a foot of snow on the ground\n");
    areas[3].setAreaName("snow");

    areas[4].setAreaName("forest");
    areas[4].setAreaDescription("You are standing in the center of a forest path splitting in 4 directions\n");
    areas[4].setConnectedAreas({"mountain", "river", "downpour", "lake"});

    areas[5].setAreaName("lake");
    areas[5].setAreaDescription("A massive lake spreads out in front of you\n");
    areas[5].setConnectedAreas({"forest"});
    areas[5].setLockedAreas({"cave"});
    areas[5].setAreaKey("boat");

    areas[6].setAreaName("river");
    areas[6].setAreaDescription("A river blocks off your path\n");
    areas[6].setConnectedAreas({"forest"});
    areas[6].setItemInArea("boat");

    areas[7].setAreaName("cave");
    areas[7].setAreaDescription("The path goes through a dark cave\n");
    areas[7].setConnectedAreas({"lake"});
    areas[7].setLockedAreas({"win"});

    areas[8].setAreaName("button");
    areas[8].setAreaDescription("");
    areas[8].setAreaKey("lightning rod");
    areas[8].setConnectedAreas({"snow"});


    currentArea = &areas[4];

    while(running){
       running = actions(currentArea, areas, inventory, lightningRodPlaced); 
    }

    freeInventory(&inventory);
    inventory = NULL;

    delete currentArea;
    delete[] areas;
    delete lightningRodPlaced;

    return 0;
}
