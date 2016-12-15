#include <iostream>
#include <fstream>

using namespace std;

template <typename myType>
class Array{
    myType* arr;
    int length;

public:
    Array(int number){
        length = number;
        arr = new myType[number];
    }
    void read_arr(){
        for(int i = 0; i < length; i++)
            cin >> arr[i];
    }
    int get_size() const{return length;}
    myType* get_array() const{return arr;}
    myType operator[](int i){
        return arr[i];
    }

    //ОБРАЩЕНИЕ МАССИВА
    void reverse(){
        for(int i = 0; i < length/2; i++){
            myType tmp = arr[length - 1 - i];
            arr[length - 1 - i] = arr[i];
            arr[i] = tmp;
        }
    }

    //ЦИКЛИЧЕСКИЙ СДВИГ
    void cyclic_move(int times){
        for(int i = 0; i < times; i++) {
            myType last = arr[0];
            for (int j = 0; j < length - 1; j++)
                arr[j] = arr[j+1];
            arr[length-1] = last;
        }
    }

    //переставляем каждый раз максимальный элемент,
    //суем в конец, двигаемся вправо
    void bubble_sort(){
        for(int i = 1; i < length; i++)
            for(int j = 0; j < length-i; j++)
                if(arr[j] > arr[j+1]){
                    int tmp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = tmp;
                }
    }

    //переставляем минимальный, суем влево,
    //двигаемся влево
    void insert_sort(){
        for(int i=1; i<length; i++)
            for(int j=i-1; j>=0; j--) {
                if (arr[j] > arr[j + 1]) {
                    int tmp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = tmp;
                }
                else break;
            }
    }

    void choice_sort(){
        for(int i = 0; i < length; i++)
            for(int j=i+1; j < length; j++)
                if(arr[i] > arr[j]){
                    int tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
    }
};

template <typename myType>
ostream& operator<<(ostream& out, const Array<myType>& arr){
    out << "[";
    for(int i = 0; i < arr.get_size()-1; i++)
        out << arr.get_array()[i] << ", ";
    out << arr.get_array()[arr.get_size()-1] << "]";
    return out;
}

template <typename myType>
void print(myType obj, string end = "\n"){
    cout << obj << end;
}

//НАИВНЫЙ ПОИСК ПОДСТРОКИ
int search(string str, string sub){
    int k = 0;
    while(k <= str.length() - sub.length()){
        bool ok = true;
        for(int i = 0; i < sub.length(); i++){
            if(sub[i] != str[k+i]){
                ok = false;
                break;
            }
        }
        if(ok) return k;
        k += 1;
    }
    return -1;
}

//ТЕСТ ПРОСТОТЫ ЧИСЛА
bool prime_test(unsigned int integer){
    for(int i = 2; i < integer; i++)
        if((integer%i == 0) && (i != integer))
            return false;
    return true;
}

//РАЗЛОЖЕНИЕ НА МНОЖИТЕЛИ
void decompose(unsigned int a){
    int mult;
    for (int i = 2; i <= a; i++)
        if(a%i == 0){
            mult = i;
            break;
        }
    if(a/mult != 1) {
        cout << mult << "*";
        decompose(a / mult);
    }
    else
        cout << mult;
}

//ПОИСК НАИБОЛЬШЕГО ТРЕХЗНАЧНОГО ЧИСЛА В ПОТОКЕ
void biggest_3(){
    int integer;
    cin>>integer;
    int max = 100;
    while(integer != 0){
        if((integer/1000 == 0) && (integer/100 > 0) && (integer > max))
            max = integer;
        cin >> integer;
    }
    cout << max;
}

//ПОИСК НАИБОЛЬШЕГО НЕЧЕТНОГО В ПОТОКЕ
void biggest_odd(){
    int integer;
    cin>>integer;
    int max = 0;
    while(integer != 0){
        if((integer%2 == 1) && (integer > max))
            max = integer;
        cin>>integer;
    }
    cout<<max;
}

//ПОИСК НАИБОЛЬШЕЙ ЧЕТНОЙ ЦИФРЫ ЧИСЛА
int biggest_even_digit(int integer){
    int max = 0;
    while(integer%10 > 0 | integer/10>0){
        int digit = integer%10;
        if((digit%2 == 0) && (digit > max))
            max = digit;
        integer /= 10;
    }
    return max;
}

//НАИМЕНЬШАЯ ЦИФРА В 5 СИСТЕМЕ
int smallest_in_5(int integer){
    int min = 4;
    while(integer%5 > 0 | integer/10>0){
        int digit = integer%5;
        if(digit < min)
            min = digit;
        integer /= 5;
    }
    return min;
}

//СЧИТЫВАНИЕ И РАСПЕЧАТКА МАТРИЦЫ M*N
int** read_matrix(int m, int n){ //m - rows, n - columns
    int** matr = new int*[m];
    for (int i = 0; i < m; i++){
        matr[i] = new int[n];
    }
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin>> matr[i][j];
    return matr;
}

void print_matrix(int** matr, int m, int n){
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << matr[i][j] << " ";
        cout << "\n";
    }
}

//ТРАНСПОНИРОВАНИЕ МАТРИЦЫ N*N
void transpose_matrix(int** matr, int N){
    for(int i = 0; i < N; i++)
        for (int j = 0; j < i; j++) {
            int tmp = matr[i][j];
            matr[i][j] = matr[j][i];
            matr[j][i] = tmp;
        }
}
//НАСЛЕДОВАНИЕ В С++
class Parent{
    int a;
    double b;

public:
    Parent(int _a, double _b){
        a = _a;
        b = _b;
    }

    void print(){
        cout << "instance created";
    }
};

class Child: private Parent{
    string c;

    Child(int _a, double _b, string _c):Parent(_a, _b){

    }

};

int main(){

    //ИСКЛЮЧЕНИЯ
    /*double number = 5;
    for(int i = 0; i < 5; i++){
        try {
            if(i == 0)
                throw 1000;
            cout << number/i << " ";
        }catch(int code){
            cout << 1000 << " ";
        }

    }*/

    //РАБОТА С ФАЙЛАМИ
    /*ifstream input("kek1.txt");
    ofstream output("kek2.txt");
    for(int i = 0; i < 5; i++){
        string str;
        input>>str;
        output<<str<<" ";
    }*/


    int size;
    cin >> size;
    Array<int> my_arr(size);
    my_arr.read_arr();
    print(my_arr);
    my_arr.choice_sort();
    print(my_arr);
    /*my_arr.reverse();
    print(my_arr);
    my_arr.cyclic_move(2);
    print(my_arr);*/

    /*string str1 = "aaabbbaaaaa";
    string str2 = "bbb";
    cout << search(str1, str2);*/

    /*int integer;
    cin >> integer;
    cout << prime_test(integer);*/

    /*unsigned int integer;
    cin >> integer;
    decompose(integer);*/

    /*biggest_3();*/

    /*biggest_odd();*/

    /*int integer;
    cin>>integer;
    cout << biggest_even_digit(integer);*/

    /*int integer;
    cin>>integer;
    cout<<smallest_in_5(integer);*/

    /*int size; cin>>size;
    int** myMatrix = read_matrix(size, size);
    print_matrix(myMatrix, size, size);
    transpose_matrix(myMatrix, size);
    print_matrix(myMatrix, size, size);*/

    return 0;
}
