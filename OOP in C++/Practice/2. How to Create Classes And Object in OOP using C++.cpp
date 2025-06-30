#include<iostream>
using namespace std;

class Test
{
    private:
        int n = 10;
    public:
        void show()
        {
            cout << "The value of n is : " << n << endl;
        }
};
main()
{
    Test t;

    t.show();

    return 0;
}