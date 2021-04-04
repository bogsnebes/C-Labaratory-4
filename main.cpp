#include <iostream>
#include <string.h>
#include "Client.h"
#include "ListClients.h"

using namespace std;

int main() {
    setlocale(0, "");
    ListClients list = ListClients(3);
    Client object = Client(strdup("Cantik"), strdup("Moscow"), 23);
    list.add(object);
    list.add(strdup("Bogdan"), strdup("Moscow"), 25);
    list.addKey();
    list.deleteClient(0);
    cout << "\nList: " << list.checkList() << endl;
    list.showList();
    system("pause");
}
