#include "Client.h"
#include <string.h>

class ListClients {
    public:
    ListClients(int value) {
        list = new Client[value];
        free = new bool[value];
        this->count = value;
    }

        int checkList() {
        countFreeList = 0;
        for(int i = 0; i < count; i++) {
            if (free[i] == false) {
                countFreeList += 1;
            }
        return (count - countFreeList);
    }
    }

    void add(Client &value) {
        for(int i = 0; i < count; i++) {
            if (free[i] == false) {
                list[i] = value;
                free[i] = true;
                return;
            }
        }
            throw "Ячейки в памяти закончились!";
    }
    void add(char *name, char *adress, int discount) {
        for(int i = 0; i < count; i++) {
            if (free[i] == false) {
                Client NewClient = Client(name, adress, discount);
                list[i] = NewClient;
                free[i] = true;
                return;
            }
        }
            throw "Ячейки в памяти закончились!";
    }
    void addKey() {
        setlocale(0, "");
        for(int i = 0; i < count; i++) {
            if (free[i] == false) {
                char name, adress;
                int discount;
                cout << "Введите имя клиента: ";
                cin >> name;
                cout << "Введите адресс клиента: ";
                cin >> adress;
                cout << "Введите скидку клиента: ";
                cin >> discount;
                Client NewClient = Client(&name, &adress, discount);
                list[i] = NewClient;
                free[i] = true;
                return;
            }
        }
            throw "Ячейки в памяти закончились!";
        }

    void deleteClient(int value) {
        setlocale(0, "");
        if (value > (sizeof(list) - 1) and value < 0)
            throw "Данной ячейки нет в массиве";
        list[value] = Client(strdup("0"), strdup("0"), 0);
        free[value] = false;
    }

    void showList() {
        for(int i = 0; i < count; i++) {
            if (free[i] == true) {
            list[i].ShowClient();
            cout << "------------------------" << endl;
            }
        }
    }
    private:
    Client *list;
    bool *free;
    int countFree = 0;
    int count;
    int countFreeList;
};