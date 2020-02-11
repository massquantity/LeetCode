#include <iostream>
#include "ListNode.h"
using namespace std;

template <typename T>
class VST {
public:
    void operator()(T & e) {
        cout << e << " ";
    }
};

template <typename T>
void visit(T & e) {
    cout << e << " ";
}

template <typename T>
class List {
private:
    int _size;
    Posi(T) header;
    Posi(T) trailer;
protected:
    void init();
    void copyNodes(Posi(T) p, int n);
    void clear();
    Posi(T) selectMax(Posi(T) p, int n);
    void merge(Posi(T) & p, int n, List<T> & l, Posi(T) q, int m);
public:
    List() { init(); }
    List(const List & L);
    List(const List & L, int r, int n);
    ~List();
    int size() { return _size; }
    int size2() { return 2; }
    void setHeader(int n) { header->data = n; }
    void setTrailer(int n) { trailer->data = n; }

    Posi(T) first() const { return header->succ; }
    Posi(T) last() const { return trailer->pred; }
    T operator[] (Rank r) const;
    Posi(T) find(const T & e, int n, Posi(T) p) const;
    Posi(T) find(const T & e) const;
    Posi(T) insertAsFirst(const T & e);
    Posi(T) insertAsLast(const T & e);
    Posi(T) insertA(Posi(T) p, const T & e);
    Posi(T) insertB(Posi(T) p, const T & e);
    T remove(Posi(T) p);
    int deduplicate();
    void traverse(void (*)(T &));
    template <typename VST>
    void traverse(VST&);
    int uniquify();
    Posi(T) search(const T & e, int n, Posi(T) p);
    void selectionSort(Posi(T) p, int n);
    void insertionSort(Posi(T) p, int n);
    void mergeSort(Posi(T) p, int n);
};


template <typename T>
void List<T>::init() {
    header = new ListNode<T>;
    trailer = new ListNode<T>;
    header->succ = trailer;
    header->pred = nullptr;
    trailer->pred = header;
    trailer->succ = nullptr;
    _size = 0;
}

template <typename T>
List<T>::List(const List & L) {
    copyNodes(L.first(), L._size);
    _size = L._size;
}

template <typename T>
List<T>::List(const List & L, int r, int n) {
    copyNodes(L[r], n);
    _size = n;
}

template <typename T>
List<T>::~List() {
    clear();
    delete header;
    delete trailer;
}

template <typename T>
T List<T>::operator[] (Rank r) const {
    Posi(T) p = first();
    while (0 < r--) p = p->succ;
    return p->data;
}

template <typename T>
Posi(T) List<T>::find(const T & e, int n, Posi(T) p) const {
        while (0 < n--) {
            if (e == (p = p->pred)->data)
                return p;
        }
        return nullptr;
}

template <typename T>
Posi(T) List<T>::find(const T & e) const {
    return find(e, _size, trailer);
}

template <typename T>
Posi(T) List<T>::insertAsFirst(const T & e) {
    _size++;
    return header->insertAsSucc(e);
}

template <typename T>
Posi(T) List<T>::insertAsLast(const T & e) {
    _size++;
    return trailer->insertAsPred(e);
}

template <typename T>
Posi(T) List<T>::insertA(Posi(T) p, const T & e) {
    _size++;
    return p->insertAsSucc(e);
}

template <typename T>
Posi(T) List<T>::insertB(ListNode<T> *p, const T &e) {
    _size++;
    return p->insertAsPred(e);
}

template <typename T>
void List<T>::copyNodes(ListNode<T> *p, int n) {
    init();
    while (n--) {
        insertAsLast(p->data);
        p = p->succ;
    }
}

template <typename T>
T List<T>::remove(Posi(T) p) {
    T e = p->data;
    p->pred->succ = p->succ;
    p->succ->pred = p->pred;
    delete p;
    _size--;
    return e;
}

template <typename T>
void List<T>::clear() {
    int oldSize = _size;
    while (_size > 0)
        remove(header->succ);
}

template <typename T>
int List<T>::deduplicate() {
    if (_size < 2) return 0;
    int oldSize = _size;
    Posi(T) p = first();
    Rank r = 1;
    while (trailer != (p = p->succ)) {
        Posi(T) q = find(p->data, r, p);
        q ? remove(q) : r++;
    }
    return oldSize - _size;
}

template <typename T>
void List<T>::traverse(void (* visit)(T &)) {
    Posi(T) p = header;
    while ((p = p->succ) != trailer)
        visit(p->data);
}

template <typename T> template <typename VST>
void List<T>::traverse(VST & visit) {
    for (Posi(T) p = header->succ; p != trailer; p = p->succ)
        visit(p->data);
}

template <typename T>
int List<T>::uniquify() {
    if (_size < 2) return 0;
    int oldSize = _size;
    Posi(T) p = header->succ;
    Posi(T) q;
    while ((q = p->succ) != trailer) {
        if (p->data != q->data)
            p = q;
        else
            remove(q);
    }
    return oldSize - _size;
}

template <typename T>
Posi(T) List<T>::search(const T & e, int n, Posi(T) p) {
    do {
        p = p->pred;
        n--;
    } while (n > -1 && p->data > e && p != header);
    return p;
}

template <typename T>
void List<T>::selectionSort(ListNode<T> *p, int n) {
    Posi(T) head = p->pred;
    Posi(T) tail = p;
    for (int i = 0; i < n; ++i)
        tail = tail->succ;
    while (n > 1) {
        insertB(tail, remove(selectMax(head->succ, n)));
        tail = tail->pred;
        n--;
    }
}

template <typename T>
Posi(T) List<T>::selectMax(ListNode<T> *p, int n) {
    Posi(T) max = p;
    for (Posi(T) cur = p; n > 1; n--) {
        if ((cur = cur->succ)->data >= max->data)
            max = cur;
    }
    return max;
}

template <typename T>
void List<T>::insertionSort(ListNode<T> *p, int n) {
    for (int r = 0; r < n; ++r) {
        insertA(search(p->data, r, p), p->data);
        p = p->succ;
        remove(p->pred);
    }
}

template <typename T>
void List<T>::mergeSort(Posi(T) p, int n) {
    if (n < 2) return;
    Posi(T) q = p;
    int m = n >> 1;
    for (int i = 0; i < m; ++i)
        q = q->succ;
    mergeSort(p, m);
    mergeSort(q, n - m);
    merge(p, m, *this, q, n - m);
}

template <typename T>
void List<T>::merge(Posi(T) & p, int n, List<T> & L, Posi(T) q, int m) {
    while (m > 0)
        if ((n > 0) && (p->data <= q->data)) {
            if (q == (p = p->succ))
                break;
            n--;
        }
        else {
            insertB(p, L.remove((q = q->succ)->pred));
            m--;
        }
}



int main() {
    List<int> l;
    l.setHeader(-666);
    l.setTrailer(666);
    l.insertAsFirst(1);
    l.insertAsLast(10);
    l.insertA(l.first(), 2);
    l.insertA(l.find(2), 7);
    l.insertB(l.find(10), l.size());
    cout << "traverse first round: " << endl;
    l.traverse(visit);
    cout << endl << "*********" << endl;
    l.remove(l.find(2, 7, l.last()));
    l.mergeSort(l.first(), l.size());
    VST<int> vst;
    cout << "traverse second sorted: " << endl;
    l.traverse(vst);
    cout << endl << (l.search(-1, 10, l.last()))->data;
}



