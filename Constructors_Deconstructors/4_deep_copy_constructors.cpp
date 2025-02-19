#include <iostream>
using namespace std;

class Book {
    public:
        string Title;
        string Author;
        float *Rates;
        int RatesCounter;

        Book(string title, string author){
            Title = title;
            Author = author;

            RatesCounter = 2;
            Rates = new float[RatesCounter];
            Rates[0] = 1;
            Rates[1] = 2;

            cout << Title << " Constructor " << endl;
        }

        ~Book(){
            delete[] Rates;
            Rates = nullptr;
            cout << Title << " Destructor " << endl;
        }
        Book(const Book& original){
        //Book(Book original){
        /*
            if we want to copy 1 object using passing by value, we need to have copy constructor
            but we are creating an copy constructor -> logical error
            -> we need to pass by reference
            const Book& original -> like a pointer to const, indicates that no changes can be made to the original
        */
            Title = original.Title;
            Author = original.Author;
            //Rates = original.Rates; -> face the problem because of dealing with dynamically allocated memroy
            RatesCounter = original.RatesCounter; 

            Rates = new float[RatesCounter];
            for(int i = 0; i < RatesCounter; i++){
                Rates[i] = original.Rates[i];
            }
            cout << Title << " Custom copy constructor " << endl;
        }
    private:

};

void printBook(Book book){
    cout << book.Title << endl;
    cout << book.Author << endl;
    float sum = 0.0f;
    for(int i = 0; i <book.RatesCounter; i++){
        sum += book.Rates[i];
    }
    cout << sum/(book.RatesCounter) << endl;

}


int main(){
    Book book1("Book1", "person1");
    Book book2("Book2", "person2");
    //Book book3(book1);
    Book book3 = book1; //not assignment operator.
                        //se copy constructor
    //book3 = book2; //assignment operator
    printBook(book1);
    printBook(book2);
    printBook(book3);
}