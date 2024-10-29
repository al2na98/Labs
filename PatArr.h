#pragma once

#ifndef PATARR_H
#define PATARR_H

#include <iostream>

template <class B>
class PatArr {
private:
    B* a; // Óêàçàòåëü íà ìàññèâ ýëåìåíòîâ òèïà B
    int n; // Ðàçìåð ìàññèâà

public:
    // Êîíñòðóêòîðû
    PatArr(); // Êîíñòðóêòîð ïî óìîë÷àíèþ
    PatArr(int N); // Êîíñòðóêòîð ñ ïàðàìåòðîì äëÿ çàäàíèÿ ðàçìåðà
    PatArr(const PatArr& x); // Êîíñòðóêòîð êîïèðîâàíèÿ
    PatArr (PatArr* b, int n); //êîíñòðóêòîð ñ àðãóìåíòîì(n - ÷èñëî ýë - òîâ â b)
    // Äåñòðóêòîð
    ~PatArr(); 

    // ×ëåíû êëàññà
    int Size(); // Óñòàíàâëèâàåò è âîçâðàùàåò íîâûé ðàçìåð ìàññèâà
    int CheckSize() const; // Ïðîâåðÿåì ðàçìåð ìàññèâà, ìåòîä íå èçìåíÿåò îáúåêò
    void Scan(int m); // Ñ÷èòûâàåò ìàññèâ èç âõîäíîãî ïîòîêà
    void Print(int m) const; // Ïå÷àòàåò ìàññèâ, ìåòîä íå èçìåíÿåò îáúåêò
    int Findkey(B key); // Èùåò çàäàííûé êëþ÷ â ìàññèâå

    // Ïåðåãðóçêà îïåðàòîðîâ
    PatArr<B> operator+(B key); // Ïåðåãðóçêà îïåðàòîðà ñëîæåíèÿ ñ ýëåìåíòîì
    PatArr<B>& operator+=(B key); // Ïåðåãðóçêà îïåðàòîðà += äëÿ äîáàâëåíèÿ ýëåìåíòà

    PatArr<B>& operator=(const PatArr<B>& x); // Ïåðåãðóçêà îïåðàòîðà ïðèñâàèâàíèÿ

    PatArr<B>& operator+=(PatArr<B> x); // Ïåðåãðóçêà îïåðàòîðà += äëÿ ñëîæåíèÿ äâóõ ìàññèâîâ
    PatArr<B> operator+(PatArr<B> x); // Ïåðåãðóçêà îïåðàòîðà + äëÿ ñëîæåíèÿ äâóõ ìàññèâîâ

    PatArr<B>& operator-=(B key); // Ïåðåãðóçêà îïåðàòîðà -= äëÿ óäàëåíèÿ ýëåìåíòà
    PatArr<B> operator-(B key); // Ïåðåãðóçêà îïåðàòîðà - äëÿ ñîçäàíèÿ íîâîãî ìàññèâà áåç óêàçàííîãî ýëåìåíòà

    PatArr<B>& DelPosEq(int pos); // Óäàëÿåò ýëåìåíò ïî óêàçàííîé ïîçèöèè èç òåêóùåãî ìàññèâà
    PatArr<B> DelPosNew(int pos); // Ñîçäàåò íîâûé ìàññèâ áåç ýëåìåíòà ïî óêàçàííîé ïîçèöèè

    bool operator==(PatArr<B> x) const; // Ïåðåãðóçêà îïåðàòîðà == äëÿ ñðàâíåíèÿ ìàññèâîâ
    bool operator!=(PatArr<B> x) const; // Ïåðåãðóçêà îïåðàòîðà != äëÿ ñðàâíåíèÿ ìàññèâîâ

    int Max(); // Âîçâðàùàåò ìàêñèìàëüíûé ýëåìåíò â ìàññèâå
    int Min(); // Âîçâðàùàåò ìèíèìàëüíûé ýëåìåíò â ìàññèâå
    void Sorting(); // Ñîðòèðóåò ìàññèâ

    B operator[](int index) const; // Ïåðåãðóçêà îïåðàòîðà [] äëÿ äîñòóïà ê ýëåìåíòàì ìàññèâà (êîíñòàíòíàÿ âåðñèÿ)
    B Get(int index) const; // Ìåòîä äëÿ ïîëó÷åíèÿ ýëåìåíòà ïî èíäåêñó (êîíñòàíòíàÿ âåðñèÿ)
    void Set(int index, B value); // Ìåòîä äëÿ óñòàíîâêè çíà÷åíèÿ ýëåìåíòà ïî èíäåêñó
    friend std::ostream& operator<<(std::ostream& r, const PatArr<B>& x) {
        for (const auto& elem : x.a) {
            r << "[" << elem << "]";
        }
        return r;
    }

    friend std::istream& operator>>(std::istream& r, PatArr<B>& x) {
        for (auto& elem : x.a) {
            r >> elem;
        }
        return r;
    }
};

// Ðåàëèçàöèþ ìåòîäîâ
template <class B>
PatArr<B>::PatArr() {
    n = 10; 
    a = new B[n]; // Âûäåëÿåì ïàìÿòü äëÿ ìàññèâà
    for (int i = 0; i < n; i++) {
        a[i] = 0; 
    }
}

template <class B>
PatArr<B>::PatArr(int N) {
    n = N; 
    a = new B[n]; // Âûäåëÿåì ïàìÿòü äëÿ ìàññèâà
    for (int i = 0; i < n; i++) {
        a[i] = 0; 
    }
}

template <class B>
PatArr<B>::PatArr(const PatArr& x) {
    n = x.n; // Êîïèðóåì ðàçìåð ìàññèâà
    a = new B[n]; // Âûäåëÿåì ïàìÿòü äëÿ íîâîãî ìàññèâà
    for (int i = 0; i < n; i++) {
        a[i] = x.a[i]; // Êîïèðóåì ýëåìåíòû èç èñõîäíîãî ìàññèâà
    }
}

template<class B>
PatArr<B>::PatArr(PatArr* b, int n)
{
    if (b == nullptr || n <= 0) {
        throw std::invalid_argument("Óêàçàòåëü íà ìàññèâ íå äîëæåí áûòü íóëåâûì, è ðàçìåð äîëæåí áûòü ïîëîæèòåëüíûì.");
    }

    // Óñòàíàâëèâàåì ðàçìåð âåêòîðà íà n
    a.resize(n);

    // Êîïèðóåì ýëåìåíòû èç ïåðåäàííîãî ìàññèâà
    for (int i = 0; i < n; ++i) {
        a[i] = b->Get(i); // Èñïîëüçóåì ìåòîä Get äëÿ äîñòóïà ê ýëåìåíòàì
    }
}

template <class B>
PatArr<B>::~PatArr() {
    delete[] a; // Îñâîáîæäàåì ïàìÿòü, çàíÿòóþ ìàññèâîì
}

template <class B>
int PatArr<B>::Size() {
    std::cin >> n; // Ñ÷èòûâàåì íîâûé ðàçìåð ìàññèâà
    return n;
}

template <class B>
int PatArr<B>::CheckSize() const {
    return n;
}

template <class B>
void PatArr<B>::Scan(int m) {
    std::cout << "Ââåäèòå ìàññèâ :" << std::endl; 
    for (int i = 0; i < m; i++) {
        std::cin >> a[i];
    }
}

template <class B>
void PatArr<B>::Print(int m) const {
    for (int i = 0; i < m; i++) {
        std::cout << "[" << a[i] << "]";
    }
    std::cout << std::endl << std::endl; 
}


template<class B>
int PatArr<B>::Findkey(B key)
{
    // Ïðîõîäèì ïî âñåì ýëåìåíòàì ìàññèâà
    for (int i = 0; i < n; i++)
    {
        // Ïðîâåðÿåì, ðàâåí ëè òåêóùèé ýëåìåíò èñêîìîìó
        if (a[i] == key)
        {
            std::cout << "Ýëåìåíò íàõîäèòñÿ íà " << i << "-îé ïîçèöèè" << std::endl;
            return i;
        }
    }
    std::cout << "Â ìàññèâå îòñóòñòâóåò äàííûé ýëåìåíò" << std::endl; 
    return -1; // Âîçâðàùàåì -1, åñëè ýëåìåíò íå íàéäåí
}

template <class B>
PatArr<B> PatArr<B>::operator+(B key) {
    // Ñîçäàåì âðåìåííûé ìàññèâ äëÿ íîâîãî ðàçìåðà
    int* r = new int[n + 1];
    for (int i = 0; i < n; i++) {
        r[i] = a[i]; // Êîïèðóåì ñóùåñòâóþùèå ýëåìåíòû â íîâûé ìàññèâ
    }
    r[n] = key; // Äîáàâëÿåì íîâûé ýëåìåíò â êîíåö ìàññèâà
    n++; 

    PatArr b(n); // Ñîçäàåì íîâûé îáúåêò PatArr
    for (int i = 0; i < n; i++) {
        b.a[i] = r[i]; // Êîïèðóåì ýëåìåíòû èç âðåìåííîãî ìàññèâà â íîâûé îáúåêò
    }
    delete[] r; 
    return b; 
}

template <class B>
PatArr<B>& PatArr<B>::operator+=(B key) {
    // Ñîçäàåì âðåìåííûé ìàññèâ äëÿ íîâîãî ðàçìåðà
    int* r = new int[n + 1];
    for (int i = 0; i < n; i++) {
        r[i] = a[i]; // Êîïèðóåì ñóùåñòâóþùèå ýëåìåíòû â íîâûé ìàññèâ
    }
    r[n] = key; // Äîáàâëÿåì íîâûé ýëåìåíò â êîíåö ìàññèâà

    delete[] a; 
    a = r; 
    n += 1;

    return *this;
}

template <class B>
PatArr<B>& PatArr<B>::operator=(const PatArr<B>& x) {
    // Ïðîâåðÿåì, íå ïðèñâàèâàåì ëè ìû ñàìîìó ñåáå
    if (this != &x) {
        delete[] a;
        n = x.n; // Êîïèðóåì êîëè÷åñòâî ýëåìåíòîâ
        a = new B[n]; 
        for (int i = 0; i < n; i++) {
            a[i] = x.a[i]; // Êîïèðóåì ýëåìåíòû èç äðóãîãî ìàññèâà
        }
    }
    return *this;
}

template <class B>
PatArr<B>& PatArr<B>::operator+=(PatArr<B> x) {
    // Ñîçäàåì âðåìåííûé ìàññèâ äëÿ êîìáèíèðîâàííîãî ðàçìåðà
    int* r = new int[n + x.n];
    for (int i = 0; i < n; i++) {
        r[i] = a[i]; // Êîïèðóåì ñóùåñòâóþùèå ýëåìåíòû
    }
    for (int i = n; i < (n + x.n); i++) {
        r[i] = x.a[i - n]; // Êîïèðóåì ýëåìåíòû èç äðóãîãî ìàññèâà
    }

    delete[] a;
    a = r; // Ïåðåíàïðàâëÿåì óêàçàòåëü íà íîâûé ìàññèâ
    n += x.n; 
    return *this; 
}

template <class B>
PatArr<B> PatArr<B>::operator+(PatArr<B> x) {
    // Ñîçäàåì íîâûé ðàçìåð äëÿ êîìáèíèðîâàííîãî ìàññèâà
    int n2 = n + x.n;
    int* r = new int[n2];
    for (int i = 0; i < n; i++) {
        r[i] = a[i]; // Êîïèðóåì ñóùåñòâóþùèå ýëåìåíòû
    }
    for (int i = n; i < n2; i++) {
        r[i] = x.a[i - n]; // Êîïèðóåì ýëåìåíòû èç äðóãîãî ìàññèâà
    }

    PatArr b(n2); // Ñîçäàåì íîâûé îáúåêò PatArr ñ íîâûì ðàçìåðîì
    for (int i = 0; i < n2; i++) {
        b.a[i] = r[i]; // Êîïèðóåì ýëåìåíòû èç âðåìåííîãî ìàññèâà â íîâûé îáúåêò
    }
    delete[] r; 
    return b; 
}

template <class B>
PatArr<B>& PatArr<B>::operator-=(B key) {
    int* r = new int[n - 1]; // Ñîçäàåì íîâûé ìàññèâ äëÿ õðàíåíèÿ ýëåìåíòîâ, îòëè÷íûõ îò key
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != key) { // Åñëè ýëåìåíò íå ðàâåí key, äîáàâëÿåì åãî â íîâûé ìàññèâ
            r[j++] = a[i];
        }
    }
    delete[] a; 
    a = r; // Óêàçûâàåì íà íîâûé ìàññèâ
    n = j; // Îáíîâëÿåì ðàçìåð ìàññèâà

    return *this; 
}

template <class B>
PatArr<B> PatArr<B>::operator-(B key) {
    int* r = new int[n - 1]; // Ñîçäàåì íîâûé âðåìåííûé ìàññèâ
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != key) { // Åñëè ýëåìåíò íå ðàâåí key, äîáàâëÿåì åãî â íîâûé ìàññèâ
            r[j++] = a[i];
        }
    }

    PatArr b(n - 1); // Ñîçäàåì íîâûé îáúåêò ìàññèâà ñ óìåíüøåííûì ðàçìåðîì
    for (int i = 0; i < n - 1; i++) {
        b.a[i] = r[i]; // Êîïèðóåì ýëåìåíòû âî âíîâü ñîçäàííûé ìàññèâ
    }
    delete[] r; 
    return b;
}

template <class B>
PatArr<B>& PatArr<B>::DelPosEq(int pos) {
    if (pos < 0 || pos >= n) {
        return *this; // Åñëè èíäåêñ íåêîððåêòåí, âîçâðàùàåì òåêóùèé îáúåêò
    }

    int* r = new int[n - 1]; 
    for (int i = 0; i < pos; i++) {
        r[i] = a[i]; // Êîïèðóåì ýëåìåíòû äî ïîçèöèè óäàëåíèÿ
    }
    for (int i = pos; i < n - 1; i++) {
        r[i] = a[i + 1]; // Êîïèðóåì îñòàâøèåñÿ ýëåìåíòû, ïðîïóñêàÿ óäàëÿåìûé
    }

    delete[] a;
    a = r; // Óêàçûâàåì íà íîâûé ìàññèâ
    n--; 

    return *this; 
}

template <class B>
PatArr<B> PatArr<B>::DelPosNew(int pos) {
    if (pos < 0 || pos >= n) {
        return *this; // Åñëè èíäåêñ íåêîððåêòåí, âîçâðàùàåì òåêóùèé îáúåêò
    }

    int* r = new int[n - 1]; // Ñîçäàåì íîâûé âðåìåííûé ìàññèâ ðàçìåðîì íà 1 ìåíüøå
    for (int i = 0; i < pos; i++) {
        r[i] = a[i]; // Êîïèðóåì ýëåìåíòû äî ïîçèöèè óäàëåíèÿ
    }
    for (int i = pos; i < n - 1; i++) {
        r[i] = a[i + 1]; // Êîïèðóåì îñòàâøèåñÿ ýëåìåíòû, ïðîïóñêàÿ óäàëÿåìûé
    }

    PatArr b(n - 1); // Ñîçäàåì íîâûé îáúåêò ìàññèâà ñ óìåíüøåííûì ðàçìåðîì
    for (int i = 0; i < n - 1; i++) {
        b.a[i] = r[i]; // Êîïèðóåì ýëåìåíòû â íîâûé ìàññèâ
    }
    delete[] r; 
    return b; 
}

template <class B>
bool PatArr<B>::operator==(PatArr<B> x) const {
    if (n != x.n) { // Ñðàâíèâàåì ðàçìåðû ìàññèâîâ
        return false; 
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != x.a[i]) { // Ñðàâíèâàåì ýëåìåíòû ìàññèâîâ
            return false; 
        }
    }
    std::cout << "Ìàññèâû ðàâíû" << std::endl; 
    return true; // Åñëè âñå ýëåìåíòû ðàâíû, ìàññèâû ðàâíû
}

template <class B>
bool PatArr<B>::operator!=(PatArr<B> x) const {
    return !(*this == x);
}

template<class B>
int PatArr<B>::Max() {
    if (n == 0) throw std::runtime_error("Массив пуст"); // Проверяем, не пуст ли массив

    B maxVal = a[0]; // Инициализируем максимальное значение первым элементом
    for (int i = 1; i < n; i++) {
        if (a[i] > maxVal) {
            maxVal = a[i]; // Находим максимальный элемент
        }
    }
    return maxVal; // Возвращаем максимальное значение
}

template<class B>
int PatArr<B>::Min() {
    if (n == 0) throw std::runtime_error("Массив пуст"); // Проверяем, не пуст ли массив

    B minVal = a[0]; // Инициализируем минимальное значение первым элементом
    for (int i = 1; i < n; i++) {
        if (a[i] < minVal) {
            minVal = a[i]; // Находим минимальный элемент
        }
    }
    return minVal; // Возвращаем минимальное значение
}

template<class B>
void PatArr<B>::Sorting() {
    // Ñîðòèðîâêà ìàññèâà ìåòîäîì ïóçûðüêà 
    int tmp;
    for (int i = 0; i < n; i++) {
        tmp = a[i];
        for (int j = i; j < n; j++)
            if (tmp > a[j]) {
                // Îáìåí ýëåìåíòîâ
                tmp = a[j];
                a[j] = a[i];
                a[i] = tmp;
            }
    }
    // Âûâîäèì îòñîðòèðîâàííûé ìàññèâ
    for (int i = 0; i < n; i++) {
        std::cout << "[" << a[i] << "]";
    }
}

template <class B>
B PatArr<B>::operator[](int index) const {
    // Ïðîâåðêà íà âûõîä çà ãðàíèöû ìàññèâà
    if (index < 0 || index >= n) {
        std::cout << "Îøèáêà: èíäåêñ çà ïðåäåëàìè äèàïàçîíà!" << std::endl;
        return 0; // Èëè âûáðîñèòü èñêëþ÷åíèå
    }
    return a[index];
}

template <class B>
B PatArr<B>::Get(int index) const {
    // Ïðîâåðêà íà âûõîä çà ãðàíèöû ìàññèâà
    if (index < 0 || index >= n) {
        std::cout << "Îøèáêà: èíäåêñ çà ïðåäåëàìè äèàïàçîíà!" << std::endl;
        return 0; 
    }
    return a[index];
}

template <class B>
void PatArr<B>::Set(int index, B value) {
    if (index < 0 || index >= a.size()) {
        throw std::out_of_range("Èíäåêñ çà ïðåäåëàìè äèàïàçîíà!");
    }
    a[index] = value;
}
#endif
