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
                cout << "Name client: ";
                cin >> name;
                cout << "\nAdress client: ";
                cin >> adress;
                cout << "\nDiscount client: ";
                cin >> discount;
                cout << "\n";
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
        Client NewClient = Client(strdup("0"), strdup("0"), 0);
        list[value] = NewClient;
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

    int find(char *type, char *value) {
        if (type == "fio") {
            for (int i = 0; i < count; i++) {
                if (free[i] == true) {
                    if (list[i].getFio() == value) {
                        return i;
                    }
                }
            }
            return NULL;
        }
        if (type == "adress") {
            for (int i = 0; i < count; i++) {
                if (free[i] == true) {
                    if (list[i].getAdress() == value) {
                        return i;
                    }
                }
            }
            return NULL;
        }
    }

    int find(int value) {
        for (int i = 0; i < count; i++) {
            if (free[i] == true) {
                if (list[i].getDiscount() == value) {
                    return i;
                }
            }
        }
        return NULL;
    }

    int* findAll(char *type, char *value) {
        bool ch[count];
        int cells = 0;
        if (type == "fio") {
            for (int i = 0; i < count; i++) {
                if (free[i] == true) {
                    if (list[i].getFio() == value) {
                        ch[i] = true;
                        cells += 1;
                    }
                }
            }
        }
        if (type == "adress") {
            for (int i = 0; i < count; i++) {
                if (free[i] == true) {
                    if (list[i].getAdress() == value) {
                        ch[i] = true;
                        cells += 1;
                    }
                }
            }
        }
        int *returningInt = new int[cells];
        for(int i = 0; i < count; i++) {
            if (ch[i] == true) {
                returningInt[i] = i;
            }
        }
        return returningInt;
    }

    int* findAll(char *type, int value) {
        bool ch[count];
        int cells = 0;
            for (int i = 0; i < count; i++) {
                if (free[i] == true) {
                    if (list[i].getDiscount() == value) {
                        ch[i] = true;
                        cells += 1;
                    }
                }
            }
        int *returningInt = new int[cells];
        for(int i = 0; i < count; i++) {
            if (ch[i] == true) {
                returningInt[i] = i;
            }
        }
        return returningInt;
    }

    Client operator[](int value) {
        if (free[value] != false) {
            return list[value];
        }
        throw "The cell is empty";
    }


    private:
    Client *list;
    bool *free;
    int countFree = 0;
    int count;
    int countFreeList;
};