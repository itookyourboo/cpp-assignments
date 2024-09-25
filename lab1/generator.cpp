#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void generateFunction(const vector<string>& types, const string& operationsFile) {
    ofstream fout("func_1.cpp");

    fout << "#include <iostream>" << endl;
    fout << "void f() {" << endl;

    for (size_t i = 0; i < types.size(); ++i) {
        fout << types[i] << " var" << i + 1 << " = " << (i + 1) << ";" << endl;
    }

    ifstream operations(operationsFile);
    string operation;
    while (getline(operations, operation)) {
        fout << "std::cout << (";
        for (size_t i = 0; i < types.size(); ++i) {
            fout << "var" << i + 1;
            if (i < types.size() - 1) {
                fout << " " << operation << " ";
            }
        }
        fout << ") << std::endl;" << endl;
    }

    fout << "}" << endl;
    fout.close();
}

int main() {
    string type1, type2, type3;

    vector<string> types;
    cout << "Введите первый тип данных: ";
    getline(cin, type1);
    cout << "Введите второй тип данных: ";
    getline(cin, type2);

    types.push_back(type1);
    types.push_back(type2);

    cout << "Если хотите ввести третий тип данных, введите его (иначе оставьте пустым): ";
    getline(cin, type3);
    if (!type3.empty()) {
        types.push_back(type3);
    }

    generateFunction(types, "operations.txt");

    ofstream mainProgram("main.cpp");
    mainProgram << "#include <iostream>" << endl;
    mainProgram << "#include \"func_1.cpp\"" << endl;
    mainProgram << "int main() {" << endl;
    mainProgram << "    f();" << endl;
    mainProgram << "    return 0;" << endl;
    mainProgram << "}" << endl;
    mainProgram.close();

    return 0;
}