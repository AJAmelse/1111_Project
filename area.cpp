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
        /*
         * Returns string with the item in the area
         * Returns empty string if no item
         */
        string getItem(){
            return areaItem;
        }

        /*
         *Returns the string of the required item to get through the area
         *
         */
        string getRequiredKey(){
            return requiredKey;
        }

        /*
         * returns a string that is the name of the area
         */
        string getAreaName(){
            return areaName;
        }

        /*
         * returns vector of strings with all connected areas
         */
        vector<string> getConnectedAreas(){
            return connectedAreas;
        }

        /*
         * sets the item in the area to an empty string
         */
        void removeItem(){
            areaItem = "";
        }

        /*
         *  returns the string that is the area description
         */
        string getAreaDescription(){
            return description;
        }

        /*
         * sets the area description
         * @param string description
         */
        void setAreaDescription(string areaDescription){
            description = areaDescription;
        }

        /*
         * sets the item stored in the area
         * @param string item name
         */
        void setItemInArea(string item){
            areaItem = item;
        }

        /*
         * sets what key is required to open the lock
         *  @param string key name
         */
        void setAreaKey(string key){
            requiredKey = key;
        }

        /*
         * sets the areas name
         * @param string item name
         */
        void setAreaName(string name){
            areaName = name;
        }

        /*
         * sets all areas connected to this one
         * @param vector<string> connected area names
         */
        void setConnectedAreas(vector<string> connections){
            connectedAreas = connections;
        }
        
        /*
         * return vector string of all the locked areas
         */
        vector<string> getLockedAreas(){
            return lockedAreas;
        }

        /*
         * sets all locked areas
         * @param vector<string> locked area names
         */
        void setLockedAreas(vector<string> areas){
            lockedAreas = areas;
        }

        /*
         * returns true if the area has an item
         */
        bool hasItem(){
            return !areaItem.empty();
        }

        /*
         * add an area to locked areas
         * @param string area name
         */
        void addLockedArea(string area){
            lockedAreas.push_back(area);
        }

        /*
         * removes area from connected areas
         * returns false if area isn't connected
         * @param string area
         */
        bool disconnectFromArea(string area){
            for(string a : connectedAreas){
                if(a == area){
                    connectedAreas.erase(remove(connectedAreas.begin(), connectedAreas.end(), area), connectedAreas.end());
                    return true;
                }
            }
            return false;
        }

        /*
         * adds an area to connected areas
         * returns false if area isn't in locked areas
         * @param string area name
         */
        bool connectToArea(string area){
            for(string a : lockedAreas){
                if(a == area){
                    lockedAreas.erase(remove(lockedAreas.begin(), lockedAreas.end(), area), lockedAreas.end());
                    connectedAreas.push_back(area);
                    return true;
                }
            }
            return false;
        }

};
