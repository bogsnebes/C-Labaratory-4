#include "Client.h"
#include <string.h>

class ListClients {
    public:
    ListClients(int value) {
        Client *list = new Client[value];
        int *free = new int[value];
        this->count = value;
    }

        int checkList() {
        countFreeList = 0;
        for(int i = 0; i < sizeof(list); i++) {
            if (list[i].getFio() == "0") {
                countFreeList += 1;
                free[i] = 1;
            }
            else
            free[i] = 0;
        }
        return (count - countFreeList);
    }

    void add(Client &value) {
        this->checkList();
        for(int i = 0; i < count; i++) {
            if (free[i] = 1) {
                list[i] = value;
                free[i] = 0;
                return;
            }
        }
        if (countFree != count) {
            list[countFree] = value;
            this->countFree += 1;
        }
        else
            throw "Ячейки в памяти закончились!";
    }
    void add(char *name, char *adress, int discount) {
        this->checkList();
        for(int i = 0; i < count; i++) {
            if (free[i] = 1) {
                Client NewClient = Client(name, adress, discount);
                list[i] = NewClient;
                free[i] = 0;
                return;
            }
        }
        if (countFree != count) {
            Client NewClient = Client(name, adress, discount);
            list[countFree] = NewClient;
            this->countFree += 1;
        }
        else
            throw "Ячейки в памяти закончились!";
    }
    void addKey() {
        setlocale(0, "");
        this->checkList();
        for(int i = 0; i < count; i++) {
            if (free[i] = 1) {
                char *name, *adress;
                int discount;
                cout << "Введите имя клиента: ";
                cin >> *name;
                cout << "Введите адресс клиента: ";
                cin >> *adress;
                cout << "Введите скидку клиента: ";
                cin >> discount;
                Client NewClient = Client(name, adress, discount);
                list[i] = NewClient;
                free[i] = 0;
                return;
            }
        }
        if (countFree != count) {
                        char *name, *adress;
                int discount;
                cout << "Введите имя клиента: ";
                cin >> *name;
                cout << "Введите адресс клиента: ";
                cin >> *adress;
                cout << "Введите скидку клиента: ";
                cin >> discount;
                Client NewClient = Client(name, adress, discount);
        list[countFree] = NewClient;
        this->countFree += 1;
    }
            else
            throw "Ячейки в памяти закончились!";
        }
    void deleteClient(int value) {
        setlocale(0, "");
        if (value > (sizeof(list) - 1) and value < 0)
            throw "Данной ячейки нет в массиве";
        list[value] = Client(strdup("0"), strdup("0"), 0);
    }

    void showList() {
        for(int i = 0; i < count; i++) {
            list[i].ShowClient();
            cout << "------------------------";
        }
    }
    private:
    Client *list;
    int *free;
    int countFree = 0;
    int count;
    int countFreeList;
};