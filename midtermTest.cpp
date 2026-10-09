#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Class Date
class Date {
private:
    int day;
    int month;
    int year;

public:
    Date() {
        day = 1;
        month = 1;
        year = 2024;
    }

    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    void setDay(int d) { day = d; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }

    void displayDate() const {
        cout << day << "/" << month << "/" << year;
    }
};

// Class Category
class Category {
private:
    int categoryId;
    string categoryName;
    string description;

public:
    Category() {
        categoryId = 0;
        categoryName = "";
        description = "";
    }

    Category(int id, string name, string desc) {
        categoryId = id;
        categoryName = name;
        description = desc;
    }

    int getCategoryId() const { return categoryId; }
    string getCategoryName() const { return categoryName; }
    string getDescription() const { return description; }

    void setCategoryId(int id) { categoryId = id; }
    void setCategoryName(string name) { categoryName = name; }
    void setDescription(string desc) { description = desc; }

    void displayCategoryInfo() const {
        cout << "Category ID: " << categoryId 
             << " | Name: " << categoryName 
             << " | Description: " << description << endl;
    }
};

// Class Fish
class Fish {
private:
    int id;
    string name;
    string color;
    string characteristic;
    int categoryId;

public:
    Fish() {
        id = 0;
        name = "";
        color = "";
        characteristic = "";
        categoryId = 0;
    }
    Fish(int i) {
        id = i;
        name = "";
        color = "";
        characteristic = "";
        categoryId = 0;
    }
    Fish(int i, string n) {
        id = i;
        name = n;
        color = "";
        characteristic = "";
        categoryId = 0;
    }
    Fish(int i, string n, string c) {
        id = i;
        name = n;
        color = c;
        characteristic = "";
        categoryId = 0;
    }
    Fish(int i, string n, string c, string ch) {
        id = i;
        name = n;
        color = c;
        characteristic = ch;
        categoryId = 0;
    }
    Fish(int i, string n, string c, string ch, int catId) {
        id = i;
        name = n;
        color = c;
        characteristic = ch;
        categoryId = catId;
    }

    int getID() const { return id; }
    string getName() const { return name; }
    string getColor() const { return color; }
    string getCharacteristic() const { return characteristic; }
    int getCategoryId() const { return categoryId; }

    void setID(int i) { id = i; }
    void setName(string n) { name = n; }
    void setColor(string c) { color = c; }
    void setCharacteristic(string ch) { characteristic = ch; }
    void setCategoryId(int catId) { categoryId = catId; }

    void displayFishInfo() const {
        cout << " ID               : " << id << endl;
        cout << " | Name           : " << name << endl;
        cout << " | Color          : " << color << endl;
        cout << " | Characteristic : " << characteristic << endl;   
        cout << " | Category ID    : " << categoryId << endl;   
    }
};

// Question 1 & 2: Class FishShop
class FishShop {
private:
    int id;
    string name;
    string address;
    string owner;
    Date startdate;
    vector<Category> categories;
    vector<Fish> fishes;

public:
    FishShop() {
        id = 0;
        name = "";
        address = "";
        owner = "";
        startdate = Date();
    }

    FishShop(int i, string n, string addr, string o, Date d) {
        id = i;
        name = n;
        address = addr;
        owner = o;
        startdate = d;
    }

    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    string getAddress() const { return address; }
    string getOwner() const { return owner; }
    Date getStartDate() const { return startdate; }
    vector<Category> getCategories() const { return categories; }
    vector<Fish> getFishes() const { return fishes; }

    // Setters
    void setId(int i) { id = i; }
    void setName(string n) { name = n; }
    void setAddress(string addr) { address = addr; }
    void setOwner(string o) { owner = o; }
    void setStartDate(Date d) { startdate = d; }
    void setCategories(const vector<Category>& cats) { categories = cats; }
    void setFishes(const vector<Fish>& f) { fishes = f; }

    void addCategory(const Category& cat) {
        categories.push_back(cat);
    }

    void addFish(const Fish& f) {
        fishes.push_back(f);
    }

    // Display function
    void displayShopInfo() const {
        cout << "================ FISH SHOP INFORMATION ================\n";
        cout << "Shop ID     : " << id << endl;
        cout << "Shop Name   : " << name << endl;
        cout << "Address     : " << address << endl;
        cout << "Owner       : " << owner << endl;
        cout << "Start Date  : "; startdate.displayDate(); cout << endl;

        cout << "\n================ CATEGORIES LIST ================\n";
        for (const Category& cat : categories) {
            cat.displayCategoryInfo();
        }

        cout << "\n================ FISHES LIST ================\n";
        for (const Fish& f : fishes) {
            f.displayFishInfo();
            cout << "-----------------------------------------------\n";
        }
    }
};

// Question 3: Main function
int main() {
    // 1. Create a fish shop
    Date startDate(15, 10, 2024);
    FishShop shop(1, "AquaWorld Central", "123 Vo Van Ngan, Thu Duc", "Truong Tri Hung", startDate);

    // 2. Input 4 categories
    Category cat1(1, "Freshwater Fish", "Ca song o moi truong nuoc ngot");
    Category cat2(2, "Saltwater Fish", "Ca song o moi truong nuoc man");
    Category cat3(3, "Tropical Fish", "Ca canh xu nhiet doi mau sac ruc ro");
    Category cat4(4, "Predatory Fish", "Ca san moidac tinh hieu chien");

    shop.addCategory(cat1);
    shop.addCategory(cat2);
    shop.addCategory(cat3);
    shop.addCategory(cat4);

    // 3. Input around 10 fishes for each category
    // Category 1: Freshwater Fish
    shop.addFish(Fish(101, "Goldfish", "Red", "Friendly", 1));
    shop.addFish(Fish(102, "Guppy", "Multi-color", "Small size", 1));
    shop.addFish(Fish(103, "Koi", "Orange White", "Large size", 1));
    shop.addFish(Fish(104, "Molly", "Black", "Easy to care", 1));
    shop.addFish(Fish(105, "Swordtail", "Red", "Active swimmer", 1));
    shop.addFish(Fish(106, "Platy", "Yellow", "Peaceful", 1));
    shop.addFish(Fish(107, "Zebra Danio", "Striped", "Fast", 1));
    shop.addFish(Fish(108, "Corydoras", "Brown", "Bottom feeder", 1));
    shop.addFish(Fish(109, "Cherry Barb", "Red", "Schooling fish", 1));
    shop.addFish(Fish(110, "White Cloud", "Silver", "Cold water", 1));

    // Category 2: Saltwater Fish
    shop.addFish(Fish(201, "Clownfish", "Orange", "Swims in anemones", 2));
    shop.addFish(Fish(202, "Blue Tang", "Blue", "Fast swimmer", 2));
    shop.addFish(Fish(203, "Yellow Tang", "Yellow", "Herbivore", 2));
    shop.addFish(Fish(204, "Damselfish", "Blue", "Territorial", 2));
    shop.addFish(Fish(205, "Royal Gramma", "Purple Yellow", "Cave dweller", 2));
    shop.addFish(Fish(206, "Firefish", "Red White", "Shy", 2));
    shop.addFish(Fish(207, "Flame Angel", "Red Black", "Dwarf angel", 2));
    shop.addFish(Fish(208, "Mandarinfish", "Patterned", "Slow mover", 2));
    shop.addFish(Fish(209, "Banggai Cardinal", "Silver Black", "Peaceful", 2));
    shop.addFish(Fish(210, "Chromis", "Green", "Schooling", 2));

    // Category 3: Tropical Fish
    shop.addFish(Fish(301, "Betta", "Blue", "Aggressive", 3));
    shop.addFish(Fish(302, "Angelfish", "Yellow", "Long fins", 3));
    shop.addFish(Fish(303, "Neon Tetra", "Blue Red", "Glowing body", 3));
    shop.addFish(Fish(304, "Discus", "Yellow", "Flat body", 3));
    shop.addFish(Fish(305, "Gourami", "Pearl", "Labyrinth breather", 3));
    shop.addFish(Fish(306, "Cardinal Tetra", "Red Blue", "Schooling", 3));
    shop.addFish(Fish(307, "Harlequin Rasbora", "Copper", "Peaceful", 3));
    shop.addFish(Fish(308, "German Blue Ram", "Colorful", "Cichlid", 3));
    shop.addFish(Fish(309, "Kribensis", "Pink Yellow", "Cave spawner", 3));
    shop.addFish(Fish(310, "Rainbowfish", "Multicolor", "Active", 3));

    // Category 4: Predatory Fish
    shop.addFish(Fish(401, "Arowana", "Gold", "Top swimmer", 4));
    shop.addFish(Fish(402, "Red Snakehead", "Patterned", "Aggressive predator", 4));
    shop.addFish(Fish(403, "Piranha", "Silver Red", "Sharp teeth", 4));
    shop.addFish(Fish(404, "Oscar", "Tiger Red", "Intelligent", 4));
    shop.addFish(Fish(405, "Alligator Gar", "Spotted", "Large predator", 4));
    shop.addFish(Fish(406, "Peacock Bass", "Yellow Green", "Fast hunter", 4));
    shop.addFish(Fish(407, "Datnioides", "Gold Black", "Ambush predator", 4));
    shop.addFish(Fish(408, "Bichir", "Grey", "Prehistoric look", 4));
    shop.addFish(Fish(409, "Flowerhorn", "Red Pink", "Hump head", 4));
    shop.addFish(Fish(410, "Wolf Cichlid", "Blue Grey", "Very aggressive", 4));

    // 4. Display information
    shop.displayShopInfo();

    return 0;
}