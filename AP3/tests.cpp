#include "article.cpp"

void test_articles(Article a);

string name_global = "Pen";

Article pen(13463, name_global, 2.50);

int main(){
    string name1 = "Book";

    Article book(10110, name1, 12.50);

    book.setName("");

    book.print();

    test_articles(book);
    test_articles(pen);

    return 0;
}

void test_articles(Article a){
    cout << "The object is: " << '\n';
    a.print();

    static Article paper(33333, "Paper", 1.00);
    paper.print();

}


