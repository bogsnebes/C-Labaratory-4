#include <iostream>
#include <string.h>
#include "Client.h"
#include "ListClients.h"

using namespace std;

int main() {
    setlocale(0, "");
    ListClients list = ListClients(3);
    Client object = Client(strdup("Кантик"), strdup("Москва"), 23);
    list.add(object);
    list.add(strdup("Богдан"), strdup("Москва"), 25);
    list.addKey();
    list.deleteClient(0);
    cout << "Заполненость списка: " << list.checkList();
    list.showList();
    system("pause");
}
