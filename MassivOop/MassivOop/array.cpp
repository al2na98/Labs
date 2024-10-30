
#include "array.h"
#include <iostream>
#include <stdio.h>
#include <exception>

using std::cout;
using std::cin;
using std::endl;

array::array()
{
    size = 1;
    arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = 0;
}

array::array(int n) {
    this->size = n;
    arr = new int[size];
    set(size);
}

array::array(int* b, int m)
{
    size = m;
    arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = b[i];
    }
}

array::array(const array& other)
{
    size = other.size;
    arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = other.arr[i];
    }
}

array& array::operator=(const array& other)
{
    if (this != &other) { // Проверка на самоприсваивание
        delete[] arr;
        size = other.size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            this->arr[i] = other.arr[i];
        }
    }
    return *this;
}

void array::set(int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = 1 + rand() % 100;
    }
}

int array::getsize()
{
    return size;
}

void array::print()
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void array::scan(int size)
{
    cout << "Введите массив :" << " ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

array::~array()
{
    delete[] arr;
}
int array::find(int key) {

    for (int i = 0; i < size; i++) {
        if (key == arr[i]) {
            return i;
        }
    }
    return -1;
}

array& array::operator+=(int key) 
{
    int* newArr = new int[size + 1]; 
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i]; 
    }
    newArr[size] = key; 
    delete[] arr; 
    arr = newArr; 
    size++;
    return *this;
}

array& array::operator+(int key) 
{
    array result(*this); 
    result += key; 
    return result; 
}
array& array::operator+=(const array& other) {

    array time(this->size);
    time = *this;
    delete[] this->arr;
    size = time.size + other.size;
    arr = new int[size];


    for (int i = 0; i < time.size; i++) {
        arr[i] = time.arr[i];
    }


    for (int i = time.size; i < (time.size + other.size); i++) {
        arr[i] = other.arr[i - time.size];
    }

    return *this;
}

array& array::operator+(const array& other)
{
    array result(*this); 
    result += other; 
    return result; 
}
bool array::operator!=(const array& other) {

    return !operator==(other);
}

bool array::operator==(const array& other) {
    if (this->size != other.size) {
        return false;
    }

    for (int i = 0; i < this->size; i++) {
        if (this->arr[i] != other.arr[i]) {
            return false;
        }
    }

    return true;
}

int array::max()
{
    if (size == 0) throw std::runtime_error("Пустой массив");
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}
int array::min()
 {
    if (size == 0) throw std::runtime_error("Пустой массив");
    int minVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

void array::sorting() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int& array::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Индекс за пределами");
    }
    return arr[index];
}

array& array::operator-=(int key) {
    int index = find(key);
    if (index == -1) {
        throw std::runtime_error("Ключ не найден");
    }

    int* newArr = new int[size - 1]; 
    for (int i = 0, j = 0; i < size; i++) {
        if (i != index) { 
            newArr[j++] = arr[i];
        }
    }
    delete[] arr; 
    arr = newArr;
    size--;
    return *this;
}

array& array::operator-(int key) 
{
    array result(*this); 
    result -= key; 
    return result; 
}
std::ostream& operator<<(std::ostream& r, const array& other) {
    for (int i = 0; i < other.size; i++) {
        r << other.arr[i] << " ";
    }
    return r;
}

std::istream& operator>>(std::istream& r, array& other) {
    for (int i = 0; i < other.size; i++) {
        r >> other.arr[i];
    }
    return r;
}
