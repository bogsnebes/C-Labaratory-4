#include "Client.h"
#include <string.h>

class ListClients {
    public:
    ListClients(int value) {
        list = new Client[value];
        free = new bool[value];
        for (int i = 0; i < value; i++) {
            free[i] = false;
            Client NewClient = Client(_strdup("0"), _strdup("0"), -1);
            list[i] = NewClient;
        }
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
        Client NewClient = Client(_strdup("0"), _strdup("0"), -1);
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

    int find(int type, char *value) {
        if (type == 1) {
            for (int i = 0; i < count; i++) {
                if (free[i] == true) {
                    char* name = list[i].getFio();
                    if (*name == *value) {
                        return i;
                    }
                }
            }
            return NULL;
        }
        if (type == 2) {
            for (int i = 0; i < count; i++) {
                if (free[i] == true) {
                    char* name = list[i].getAdress();
                    if (*name == *value) {
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

    int* findAll(int type, char *value) {
        bool *ch = new bool[count];
        int cells = 0;
        if (type == 1) {
            for (int i = 0; i < count; i++) {
                if (free[i] == true) {
                    char* name = list[i].getFio();
                    if (*name == *value) {
                        ch[i] = true;
                        cells += 1;
                    }
                    else {
                        ch[i] = false;
                    }
                }
            }
        }
        if (type == 2) {
            for (int i = 0; i < count; i++) {
                if (free[i] == true) {
                    char* name = list[i].getAdress();
                    if (*name == *value) {
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

    int* findAll(int value) {
        bool *ch = new bool[count];
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

    void sortList(int type) {
        if (type == 1) {
            for (int i = 0; i <= (count - 2); i++) {
                for (int j = 0; j <= (count - i - 2); j++) {
                    char* name_1 = list[j].getFio();
                    char* name_2 = list[j + 1].getFio();
                    if (*name_1 > *name_2) {
                        Client buffer = list[j];
                        bool bufferBool = free[j];
                        list[i] = list[j + 1];
                        list[j + 1] = buffer;
                        free[j] = free[j + 1];
                        free[j + 1] = free[j];
                    }
                }
            }
        }
        else if (type == 2) {
            for (int i = 0; i <= (count - 2); i++) {
                for (int j = 0; j <= (count - i - 2); j++) {
                    char* name_1 = list[j].getAdress();
                    char* name_2 = list[j + 1].getAdress();
                    if (*name_1 > *name_2) {
                        Client buffer = list[j];
                        bool bufferBool = free[j];
                        list[i] = list[j + 1];
                        list[j + 1] = buffer;
                        free[j] = free[j + 1];
                        free[j + 1] = free[j];
                    }
                }
            }
        }
        else if (type == 3)
        {
            for (int i = 0; i <= (count - 2); i++) {
                for (int j = 0; j <= (count - i - 2); j++) {
                    if (list[j].getDiscount() < list[j + 1].getDiscount()) {
                        Client buffer = list[j];
                        bool bufferBool = free[j];
                        list[j] = list[j + 1];
                        list[j + 1] = buffer;
                        free[j] = free[j + 1];
                        free[j + 1] = free[j];
                    }
                }
            }
        }
    }

    Client operator[](int value) {
        if (free[value] == false) {
            Client NewClient = Client(_strdup("0"), _strdup("0"), 0);
            return NewClient;
        }
        return list[value];
    }


    private:
    Client *list;
    bool *free;
    int countFree = 0;
    int count;
    int countFreeList;
};