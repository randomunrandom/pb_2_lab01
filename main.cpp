#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;

struct tovar{
    string name;
    float price;
    int amount;
    tovar* next;
};

void add_first(tovar *&bufet, string nm, float price, int amount) {
    auto *newtovar = new tovar;
    newtovar->name = nm;
    newtovar->amount = amount;
    newtovar->price = price;
    newtovar->next = bufet;
    bufet = newtovar;
}
void print_list(tovar *bufet){
    if(bufet == NULL) cout << "The list is empty";
    else{
        tovar *tmp = bufet;
        while(tmp != NULL){
            cout << "Product: " << tmp->name << "\nAmount: " << tmp->amount << "\nPrice: " << tmp->price << "\n\n";
            tmp = tmp->next;
        }
    }
    return;
}
void add_last(tovar *&bufet, string nm, float price, int amount){
    if (bufet == NULL) add_first(bufet, nm, price, amount);
    else{
        tovar *tmp = bufet;
        while(tmp -> next) tmp = tmp->next;
        tovar* newtovar = new tovar;
        newtovar->name = nm;
        newtovar->amount = amount;
        newtovar->price = price;
        newtovar->next = NULL;
        tmp->next = newtovar;
    }
    return;
}
int add_after(tovar *&bufet, string nm, float price, int amount, string nmafter){
    if (bufet == NULL) return 2;
    else{
        tovar *tmp = bufet;
        while (tmp->next != NULL && tmp->name != nmafter) tmp = tmp->next;
        if (tmp->next == NULL && tmp->name != nmafter) return 1;
        else {
            tovar* newtovar = new tovar;
            newtovar->name = nm;
            newtovar->amount = amount;
            newtovar->price = price;
            newtovar->next = tmp->next;
            tmp->next = newtovar;
            return 0;
        }
    }
}
int add_before(tovar *&bufet, string nm, float price, int amount, string nmbefore){
    if (bufet == NULL) return 2;
    if (bufet->name == nmbefore){
        add_first(bufet, nm, price, amount);
        return 0;
    }
    if(bufet->next == NULL) return 1;
    tovar *tmp = bufet;
    tovar *previous = bufet;
    while(tmp->next != NULL && tmp->name != nmbefore){
        if (tmp->next->name == nmbefore) previous = tmp;
        tmp = tmp->next;
    }
    if (tmp->next == NULL && tmp->name != nmbefore) return 1;
    tovar* newtovar = new tovar;
    newtovar->name = nm;
    newtovar->amount = amount;
    newtovar->price = price;
    newtovar->next = tmp;
    previous->next = newtovar;
    return 0;
}
int delete_element(tovar *&bufet, string nm){
    tovar *tmp = bufet;
    tovar *previous = bufet;
    if (bufet == NULL) return 2;
    while(tmp->next != NULL && tmp->name != nm){
        if (tmp->next->name == nm) previous = tmp;
        tmp = tmp->next;
    }
    if (tmp->next == NULL && tmp->name != nm)return 1;
    if (tmp == bufet){
        bufet = tmp->next;
        delete tmp;
        return 0;
    }
    if (tmp->next == NULL){
        previous->next = NULL;
        delete tmp;
        return 0;
    }
    previous->next = tmp->next;
    delete tmp;
    return 0;
}
int create_by_user(tovar *&bufet) {
    string input;
    cout << "choose operation:\nadd_first,\tadd_last,\tadd_after,\tadd_before,\tdelete_element" << endl;
    cin >> input;
    if(input == "delete_element") {
        string name;
        cout << "input name:" << endl;
        cin >> name;
        delete_element(bufet, name);
    }
    if (input == "add_first") {
        string name;
        cout << "input name:" << endl;
        cin >> name;
        double price;
        int amount;
        cout << "input price" << endl;
        cin >> price;
        cout << "input amount:" << endl;
        cin >> amount;
        add_first(bufet, name, price, amount);
    }
    if (input == "add_last") {
        string name;
        cout << "input name:" << endl;
        cin >> name;
        double price;
        int amount;
        cout << "input price" << endl;
        cin >> price;
        cout << "input amount:" << endl;
        cin >> amount;
        add_last(bufet, name, price, amount);
    }
    if (input == "add_after") {
        string name;
        cout << "input name:" << endl;
        cin >> name;
        double price;
        int amount;
        cout << "input price" << endl;
        cin >> price;
        cout << "input amount:" << endl;
        cin >> amount;
        string specialname;
        cout << "input name to add after:" << endl;
        cin >> specialname;
        add_after(bufet, name, price, amount, specialname);
    }
    if (input == "add_before") {
        string name;
        cout << "input name:" << endl;
        cin >> name;
        double price;
        int amount;
        cout << "input price" << endl;
        cin >> price;
        cout << "input amount:" << endl;
        cin >> amount;
        string specialname;
        cout << "input name to add before:" << endl;
        cin >> specialname;
        add_before(bufet, name, price, amount, specialname);
    }
    else {
        cout << "ERROR" << endl << endl;
        return 1;
    }
    return 0;
}

int main() {
    tovar *bufet = NULL;
    cout << "1" << endl;
    add_first(bufet, "tea", 10.5, 123);
    print_list(bufet);
    cout << "2" << endl;
    add_last(bufet, "tea2", 12.5, 321);
    print_list(bufet);
    cout << "3" << endl;
    add_after(bufet, "tea3", 15, 210, "tea");
    print_list(bufet);
    cout << "4" << endl;
    add_before(bufet, "tea4", 2, 750, "tea");
    print_list(bufet);
    cout << "5" << endl;
    delete_element(bufet, "tea4");
    print_list(bufet);
    cout << "6" << endl;
    create_by_user(bufet);
    print_list(bufet);
    return 0;
}