#include <iostream>
#include <string.h>
#include "Client.h"
#include "ListClients.h"

using namespace std;

int main() {
    setlocale(0, "");
    ListClients list = ListClients(3);
    Client object = Client(_strdup("Cantik"), _strdup("Boscow"), 23);
    list.add(object);
    list.add(_strdup("Bogdan"), _strdup("Moscow"), 40);
    list[list.find(1, _strdup("Bogdan"))].ShowClient();
    list[list.find(2, _strdup("Moscow"))].ShowClient();
    cout << list.find(25) << endl;
    list.showList();
    list.sortList(3);
    list.showList();
    list.sortList(2);
    list.showList();
    list.sortList(1);
    list.showList();
    system("pause");
}
