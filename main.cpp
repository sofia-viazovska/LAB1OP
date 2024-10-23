#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

//Завдання 1

int inc1(int n) {
    return n + 1;
}

struct Num {
    int n;
};

int inc2(Num num) {
    return num.n + 1;
}


int main() {
    //Завдання 1
    int a = 5;
    int b = inc1(a);
    cout<<"Варіант 1: "<<a<<"->"<<b<<endl;

    Num obj = {5};
    int c = inc2(obj);
    cout<<"Варіант 2: "<<5<<"->"<<c<<endl;

    //Завдання 2
    vector<variant<bool, const char*, int, double, nullptr_t>>elements= {true, "hello", 5, 12, -200, false, false, "word", 3.14, nullptr};
    unordered_map<string, int>types = {{"number", 0}, {"string", 0}, {"boolean", 0}, {"nullptr", 0}};

    for (int i=0; i<elements.size(); i++) {
        string type = elements[i].index() == 0 ? "boolean" :
                      elements[i].index() == 1 ? "string" :
                      elements[i].index() == 2 ? "number" :
                      elements[i].index() == 3 ? "number" :
                      "nullptr";
        types[type]++;
    }

    cout<<"\nВаріант 1: "<<endl;
    for (auto&[key, value]: types) {
        cout<<key<<": "<<value<<endl;
    }

    unordered_map<string, int>types2;

    for (int i = 0; i < elements.size(); i++) {
        string type = elements[i].index() == 0 ? "boolean" :
                      elements[i].index() == 1 ? "string" :
                      elements[i].index() == 2 ? "number" :
                      elements[i].index() == 3 ? "number" :
                      "nullptr";

        if (types2.find(type) == types2.end()) {
            types2[type] = 0;
        }
        types2[type]++;
    }

    cout<<"\nВаріант 2: "<<endl;
    for (auto&[key, value]: types2) {
        cout<<key<<": "<<value<<endl;
    }

}