#include <iostream>
#include <cstring>
#include "account.h"
#include "savings.h"
#include "buisness.h"


using namespace std;

int main() {

    Account c1("A001", "Artem", 0.05, 20000);
    cout << "--- Account 01 ---" << endl;
    c1.print();

    SavingsAccount c2("A002", "Annia", 0.02, 50000, 10);
    cout << "--- Acount 02 ---" << endl;
    c2.print();

    BusinessAccount c3("A003", "Sergey", 0.01, 100000, 0.15);
    cout << "--- Account 03 ---" << endl;
    c3.print();

    return 0;
}