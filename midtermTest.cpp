#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Category {
private:
    int categoryId;
    string categoryName;
    string description;

public:
   // Default constructor
    Category() {
        categoryId = 0;
        categoryName = "";
        description = "";
    }

    // Constructor with parameters
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

class Fish {
private:
    int id;
    string name;
    string color;
    string characteristic;
    int categoryId; // Q7: Thuoc tinh moi

public:
    // Constructors: các hàm khởi tạo dữ liệu
    Fish() {
        id = 0;
        name = "";
        color = "";
        characteristic = "";
        categoryId = 0;
    }
    // A constructor with 1 parameter
    Fish(int i) {
        id = i;
        name = "";
        color = "";
        characteristic = "";
        categoryId = 0;
    }
    // A constructor with 2 parameters
    Fish(int i, string n) {
        id = i;
        name = n;
        color = "";
        characteristic = "";
        categoryId = 0;
    }
    // A constructor with 3 parameters
    Fish(int i, string n, string c) {
        id = i;
        name = n;
        color = c;
        characteristic = "";
        categoryId = 0;
    }
    // A constructor with all 4 parameters
    Fish(int i, string n, string c, string ch) {
        id = i;
        name = n;
        color = c;
        characteristic = ch;
        categoryId = 0;
    }
    // A constructor with 5 parameters (including categoryId)
    Fish(int i, string n, string c, string ch, int catId) {
        id = i;
        name = n;
        color = c;
        characteristic = ch;
        categoryId = catId;
    }

    // Getter
    int getID() const { return id; }
    string getName() const { return name; }
    string getColor() const { return color; }
    string getCharacteristic() const { return characteristic; }
    int getCategoryId() const { return categoryId; }

    // Setter
    void setID(int i) { id = i; }
    void setName(string n) { name = n; }
    void setColor(string c) { color = c; }
    void setCharacteristic(string ch) { characteristic = ch; }
    void setCategoryId(int catId) { categoryId = catId; }

    // Display
    void displayFishInfo() const {
        cout << " ID               : " << id << endl;
        cout << " | Name           : " << name << endl;
        cout << " | Color          : " << color << endl;
        cout << " | Characteristic : " << characteristic << endl;   
        cout << " | Category ID    : " << categoryId << endl;   
    }
};

int main() {
    // Q7: Tao 3 Category
    vector<Category> categories = {
        Category(1, "Freshwater Fish", "Ca nuoc ngot"),
        Category(2, "Saltwater Fish", "Ca nuoc man"),
        Category(3, "Tropical Fish", "Ca nhiet doi")
    };

    // 5 ca ban dau
    vector<Fish> fishList = {
        Fish(100, "Kevin", "Purple", "Wearing glasses", 1),
        Fish(113, "N/A", "N/A", "N/A", 1),
        Fish(114, "Olise", "N/A", "N/A", 2),
        Fish(115, "Iniesta", "Blue", "N/A", 3),
        Fish(116, "Musiala", "Red", "Curly Hair", 3)
    };

    // Q6: Them 10 loai ca canh moi
    fishList.push_back(Fish(101, "Goldfish", "Red", "Friendly", 1));
    fishList.push_back(Fish(102, "Betta", "Blue", "Aggressive", 3));
    fishList.push_back(Fish(103, "Guppy", "Red", "Small size", 1));
    fishList.push_back(Fish(104, "Angelfish", "Yellow", "Long fins", 3));
    fishList.push_back(Fish(105, "Neon Tetra", "Blue", "Glowing body", 3));
    fishList.push_back(Fish(106, "Clownfish", "Orange", "Active", 2));
    fishList.push_back(Fish(107, "Blue Tang", "Blue", "Fast swimmer", 2));
    fishList.push_back(Fish(108, "Discus", "Yellow", "Flat body", 3));
    fishList.push_back(Fish(109, "Koi", "Orange", "Large size", 1));
    fishList.push_back(Fish(110, "Molly", "Black", "Easy to care", 1));

    // Q6: Nhom va hien thi ca theo mau sac
    cout << "\n===== GROUP FISH BY COLOR =====\n";
    vector<string> colors;
    for (const Fish& f : fishList) {
        bool exists = false;
        for (const string& c : colors) {
            if (c == f.getColor()) {
                exists = true;
                break;
            }
        }
        if (!exists && f.getColor() != "" && f.getColor() != "N/A") {
            colors.push_back(f.getColor());
        }
    }

    for (const string& color : colors) {
        cout << "\n--- COLOR: " << color << " ---\n";
        for (const Fish& f : fishList) {
            if (f.getColor() == color) {
                f.displayFishInfo();
            }
        }
    }

    // Q7: Hien thi tat ca Category
    cout << "\n===== ALL CATEGORIES =====\n";
    for (const Category& cat : categories) {
        cat.displayCategoryInfo();
    }

    // Q7: Hien thi ca theo Category đuoc chon (ID = 3)
    int selectedCatId = 3;
    cout << "\n===== FISH IN CATEGORY ID " << selectedCatId << " =====\n";
    for (const Fish& f : fishList) {
        if (f.getCategoryId() == selectedCatId) {
            f.displayFishInfo();
        }
    }

    return 0;
}