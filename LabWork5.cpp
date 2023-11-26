#include <iostream>
using namespace std;

//Список
class List {
public:
    //Конструктор за замовчуванням
    List() {
        begin = end = nullptr;
        size = 0;
    }

    //Додавання нового елемента в кінець списку
    void Add(int x) {
        Element* elem = new Element;
        elem->data = x;
        elem->next = nullptr;

        if (begin == nullptr) {
            begin = end = elem;
        }
        else {
            end->next = elem;
            end = elem;
        }

        size++;
    }

    //Виведення розміру списка
    int Size() { return size; }

    //Виведення списку
    void Show() {
        Element* current = this->begin;
        for (int i = 0; i < size; i++) {
            cout << current->data << ' ';
            current = current->next;
        }
        cout << endl;
    }

    //Видалення пешого елементу списку
    void pop_front() {
        Element* temp = begin;
        begin = begin->next;
        delete temp;
        size--;
    }

    //Видалення всіх елементів списку
    void clear() {
        while (size) {
            pop_front();
        }
    }

    int countElementsLessThanAverage() {
        if (size == 0) {
            return 0;
        }

        // Обчислюємо середнє арифметичне значення
        int sum = 0;
        Element* current = begin;
        while (current != nullptr) {
            sum += current->data;
            current = current->next;
        }
         double average = static_cast<double>(sum) / size;

        cout << "Average: " << average << endl;
        // Пораховуємо кількість елементів, які менші за середнє значення
        int count = 0;
        current = begin;
        while (current != nullptr) {
            if (current->data < average) {
                count++;
            }
            current = current->next;
        }

        return count;
    }


    //Деструктор
    ~List() {
        clear();
    }

private:
    struct Element {
        int data;
        Element* next;
    };
    Element* begin;
    Element* end;
    int size;
};

void Line() {
    for (int i = 0; i < 30; i++)
        cout << '-';
    cout << endl;
}

int main() {
    srand(time(NULL));
    List a;
    int size = 10;

    //Ініціалізація списку
    for (int i = 0; i < size; i++)
        a.Add(1 + rand() % size);

    a.Show();


    cout << "Number of elements less than average: " << a.countElementsLessThanAverage() << endl;

    cout << endl;
    system("pause");
    return 0;
}
