#include <iostream>
#include <string>

namespace Abel {
    
    struct SnapchatFriend {
        std::string name;
        std::string status;

       
        SnapchatFriend(std::string n, std::string s) : name(n), status(s) {}
    };

  
    void displayValue(std::string item) {
        std::cout << "String value: " << item << '\n';
    }

    
    template <typename T>
    void displayValue(T item) {
        std::cout << ":) " << item << '\n';
    }

    
    void displayFriend(SnapchatFriend friendObj) {
        std::cout << "Friend: " << friendObj.name << " - Status: " << friendObj.status << '\n';
    }
}

int main() {
    Abel::SnapchatFriend friend1("Joe", "Online");
    Abel::SnapchatFriend friend2("Jovani", "Offline");
    Abel::SnapchatFriend friend3("Sophia", "Busy");

    
    Abel::displayFriend(friend1);
    Abel::displayFriend(friend2);
    Abel::displayFriend(friend3);

    
    Abel::displayValue("Hello, Snapchat!");

    return 0;
}