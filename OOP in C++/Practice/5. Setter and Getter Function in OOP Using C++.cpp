#include<iostream>
#include<cstring>

using namespace std;

class Book
{
    private:
        int page;
        float price;
        char name[50];
    public:
        void setPage(int p)
        {
            page = p;
        }
        void setPrice(float pr)
        {
            price = pr;
        }
        void setName(const char* n)
        {
            strcpy(name, n);
        }
        int getPage()
        {
            return page;
        }
        float getPrice()
        {
            return price;
        }
        string getName()
        {
            return name;
        }
};
int main()
{
    Book b1, b2;

    b1.setPage(300);
    b1.setPrice(29.99);
    b1.setName("C++ Programming");

    b2.setPage(900);
    b2.setPrice(999);
    b2.setName("Java Programming"); 

    cout << "Book Name: " << b1.getName() << endl;
    cout << "Number of Pages: " << b1.getPage() << endl;
    cout << "Price: $" << b1.getPrice() << endl;

    cout << "Book Name: " << b2.getName() << endl;
    cout << "Number of Pages: " << b2.getPage() << endl;
    cout << "Price: $" << b2.getPrice();

    return 0;
}