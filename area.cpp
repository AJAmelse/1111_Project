#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Area{
    private:
        string areaItem;
        string requiredKey;
        string description;
        vector<string> connectedAreas;
        string areaName;
        vector<string> lockedAreas;

    public: 
        string getItem(){
            return areaItem;
        }

        string getRequiredKey(){
            return requiredKey;
        }

        string getDescription(){
            return description;
        }

        string getAreaName(){
            return areaName;
        }

        vector<string> getConnectedAreas(){
            return connectedAreas;
        }

        void removeItem(){
            areaItem = "";
        }

        string getAreaDescription(){
            return description;
        }

        void setAreaDescription(string areaDescription){
            description = areaDescription;
        }


        void setItemInArea(string item){
            areaItem = item;
        }

        void setAreaName(string name){
            areaName = name;
        }
        
        vector<string> getLockedAreas(){
            return lockedAreas;
        }

        void setLockedAreas(vector<string> areas){
            lockedAreas = areas;
        }

        bool hasItem(){
            return !areaItem.empty();
        }

        void addLockedArea(string area){
            lockedAreas.push_back(area);
        }

        void disconnectFromArea(string area){
            connectedAreas.erase(remove(connectedAreas.begin(), connectedAreas.end(), area), connectedAreas.end());
        }

        void connectToArea(string area){
            connectedAreas.push_back(area);    
        }

};
