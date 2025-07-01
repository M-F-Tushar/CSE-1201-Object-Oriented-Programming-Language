#include "sep.h"
main()
{
    Test T1, T2;
    
    T1.setvalue(20);

    T2.setvalue(30);

    cout << "Value retrived: " << T1.getvalue() << endl;
    cout << "Value retrived: " << T2.getvalue() << endl;
    return 0;

}