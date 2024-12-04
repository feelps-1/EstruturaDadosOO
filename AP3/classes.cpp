#include "article.h"
#include <iomanip>
#include <iostream>

int Article::obj_counter = 0; 

Article::Article(long i_number, const string& i_name, double i_price)
{
    setNumber(i_number); setName(i_name); setPrice(i_price); 
    obj_counter++;
    cout << "An object of type Article " << name << " is created." << '\n'
         << "This is the " << obj_counter << " Article." << '\n';
}

Article::Article( const Article& art)
    : number(art.number), name(art.name), price(art.price) {

    obj_counter++;
    cout << "A copy object of type Article " << name << " is created." << '\n'
         << "This is the " << obj_counter << " Article." << '\n';
}

Article::~Article(){
    obj_counter--;
    cout << "An object of type Article " << name << " is destroyed." << '\n'
         << "There are still " << obj_counter << " Articles." << '\n';
}

void Article::print(){
    cout << fixed << setprecision(2)
         << "-----------------------" << '\n'
         << "Article name " << name << '\n'
         << "Article number " << number << '\n'
         << "Article price " << price << '\n';

    cout << "Press enter to continue.";
    cin.get();
}
