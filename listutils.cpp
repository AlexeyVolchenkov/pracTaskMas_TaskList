#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
};

// Инициализации элемента односвязного списка нулями

void init(Node* node, int n) {
    node->val = n;
    node->next = NULL;
}

// Отображения односвязного списка на экран
void show(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

// Добавления элемента в односвязный список
void pushNode(Node* head, Node* node) {
    Node* newElement = head;
    while (newElement->next != NULL) {
        newElement = newElement->next;
    }
    newElement->next = new Node;
    newElement = newElement->next;
    newElement->val = node->val;
    newElement->next = NULL;
}




// Написать функцию инициализации size элементов списка заданным значением val.
void initList(Node* head, int size, int val) {

}

// Написать функцию копирования элементов массива source в новый массив dest
void copyMas(Node* source, Node* dest) {

}


// Написать функцию сравнение списков source и dest. Если списки равны 0, если не равны -1
int compareMas(Node* source, Node* dest) {
    return 0;
}


// Написать функцию удаления со сдвигом влево n-го элемента списка.
void deleteList(Node* head, int n) {

}


// Написать функцию сдвига значений вправо на n-элементов с заполнением крайних элементов нулями
void rShiftList(Node* head, int n) {

}



// Написать функцию сдвига значений влево на n-элементов с заполнением крайних элементов нулями.
void lShiftList(Node* head, int n) {

}

//Variant 7
//Написать функцию сдвига значений влево на n-элементов с переносом вытесненных элементов в конец
void lRoundShiftMas(Node* head, int n, int size) {
    for (int i = 0; i < n; i++)
    {
        Node* elem = head;
        int num = elem->val;

        for (int i = 0; i < size - 1; i++)
        {
            elem->val = elem->next->val;
            elem = elem->next;
        }

        elem->val = num;
    }
}


// Написать функцию вычисления среднего значения элементов списка.
int averageList(Node* head, int size) {
    return 0;
}



// Написать функцию вычисления средне квадратического отклонения элементов списка.
int skoFromList(Node* head, int size) {
    return 0;
}

//тесты
bool compareMas(int* a, int* b, int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}
bool testlRoundShiftMas(Node* a, int* b, int size) {
    int* c = new int[size];
    Node* temp = a;
    lRoundShiftMas(a, 1, 5);
    for (int i = 0; i < size; i++) {
        c[i] = temp->val;
        temp = temp->next;
    }
    return compareMas(b, c, size);
}


static void runTest(Node* a, int* mas)
{
    if (testlRoundShiftMas(a, mas, 5) != 0)
        std::cout << "Test - OK" << std::endl;
    else
        std::cout << "Test - FAIL" << std::endl;
}



int main() {
    const int size = 5;
    int mas[size] = { 2, 3, 4, 5, 1 };
    Node* head = new Node;
    Node* temp = new Node;
    Node* temp1 = new Node;
    Node* temp2 = new Node;
    Node* temp3 = new Node;
    init(head, 1);
    init(temp, 2);
    init(temp1, 3);
    init(temp2, 4);
    init(temp3, 5);
    pushNode(head, temp);
    pushNode(head, temp1);
    pushNode(head, temp2);
    pushNode(head, temp3);
    runTest(head, mas);
    return 0;
}