#include <cstdio>

// The purpose of the below code is to demonstrate the creation of an enum class, example altered from C++ crash course.
enum class Race {
    Human,
    Turian,
    Salarian,
    Krogan,
    Asari,
    Geth,
    Quarian,
};

// The purpose of the below code is to demonstrate initializing an enumeration variable to a value.
Race garrus_race = Race::Turian;

//The below function's purpose is to demonstrate the use of a switch statement with an enumeration class.
void ME_party_member_quote(){
    Race character_race = Race::Human;

    switch(character_race) {
        case Race::Human: {
            printf("I'm Commander Shepherd, and this is my favorite store on the Citadel.\n");
        } break;
        case Race::Turian: {
            printf("I'm Garrus Vakarian. It's so much easier to see the world in black and white. Gray? What do I do with that?\n");
        } break;
        case Race::Salarian: {
            printf("I'm Mordin. I am the very model of a scientist salarian, I’ve studied species turian, asari, and batarian.\n");
        } break;
        case Race::Krogan: {
            printf("I'm Urdnot Wrex. Why shoot something once when you can shoot it 46 more times?\n");
        } break;
        case Race::Asari: {
            printf("I'm Liara T'Soni. It doesn't have any weapons, Shephard. It's a taxi, it has a fare meter!\n");
        } break;
        case Race::Geth: {
            printf("We are Legion. Geth do not infilitrate. Geth do not..intentionally infiltrate.\n");
        } break;
        case Race::Quarian: {
            printf("I am Tali'Zorah vas Normandy. I am getting drunk very carefully. Turian brandy, triple filtered, then introduced into the suit through an emergency induction port.\n");
        } break;
        default: {
            printf("Error: unknown race!\n");
        }
    }   
}

// The purpose of the below code is to demonstrate the creation of a plain-old-data class using struct and then accessing it with a function.

struct Book {
    char name[256];
    int year;
    int pages;
    bool hardcover;
};

void favorite_book(){
    Book dune;
    dune.pages = 704;
    printf("Dune has %d pages in it.\n", dune.pages);
}


int main(){
    ME_party_member_quote();
    favorite_book();
}
