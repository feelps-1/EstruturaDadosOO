#ifndef _ACCOUNT_
#define _ACCOUNT_

#include <iostream>
#include <string>
using namespace std;

class Article
{
    private:
        long number;
        string name;
        double price;
        static int obj_counter;

    public:
        Article(long number = 0, const string& name = "noname", double price = 0.0);
        Article( const Article& anArticle);
        ~Article();
        void print();
        
        const string& getName() {return name;}
        bool setName(const string& s){
            if(s.size() < 1){
                return false;
            }

            name = s;
            return true;
        }
        
        long getNumber() {return number;}
        void setNumber(long n) {number = n;} 

        double getPrice() {return price;}
        void setPrice(double p) {
            p < 0 ? price = 0.0 : price = p;
        };

        static int getObjCounter() {return obj_counter;}
};

#endif
