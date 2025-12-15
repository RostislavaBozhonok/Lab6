#include <iostream>
#include <limits>
#include <string>
using namespace std;

const int N = 50; // Максимальний розмір масиву

//  Прототипи функцій
int input_positive_int(const string& prompt);
int input_int(const string& prompt);
void input_array(int arr[N], int& n);
void output_array(const int arr[N], int n);

int find_first_local_min(const int arr[N], int n);
void task_array32();

bool is_unique(const int arr[N], int size, int value);
int remove_duplicates(const int in_arr[N], int n, int out_arr[N]);
void task_array96();

int main(); // головна функція

// ====================== MAIN ======================
int main() {
    int choice;
    do {
        cout << "\n===== МЕНЮ =====\n";
        cout << "1 - Array32: Перший локальний мінімум\n";
        cout << "2 - Array96: Видалення повторів\n";
        cout << "0 - Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;
        switch (choice) {
            case 1: task_array32(); break;
            case 2: task_array96(); break;
            case 0: cout << "Завершення програми.\n"; break;
            default: cout << "Невірний вибір! Спробуйте ще раз.\n";
        }
    } while (choice != 0);
    return 0;
}

// ====================== РЕАЛІЗАЦІЯ ======================

//  Введення коректного додатного цілого числа
int input_positive_int(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value <= 0 || value > N) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Помилка! Введіть ціле число в межах 1.." << N << endl;
        } else {
            return value;
        }
    }
}

//  Введення коректного цілого числа
int input_int(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Помилка! Введіть ціле число!" << endl;
        } else {
            return value;
        }
    }
}

//  Введення масиву
void input_array(int arr[N], int& n) {
    n = input_positive_int("Введіть кількість елементів масиву: ");
    for (int i = 0; i < n; i++) {
        arr[i] = input_int("Елемент " + to_string(i + 1) + ": ");
    }
}

//  Виведення масиву
void output_array(const int arr[N], int n) {
    cout << "Елементи масиву: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//  Завдання 1 — Array32: Перший локальний мінімум
int find_first_local_min(const int arr[N], int n) {
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
            return i + 1; // повертаємо номер (не індекс)
        }
    }
    return 0; // якщо немає локального мінімуму
}

void task_array32() {
    int arr[N], n;
    cout << "\n--- Завдання Array32 ---\n";
    // Перевірка розміру масиву
    do {
        n = input_positive_int("Введіть кількість елементів масиву (мінімум 3): ");
        if (n < 3) cout << "Помилка! Масив повинен мати принаймні 3 елементи.\n";
    } while (n < 3);

    for (int i = 0; i < n; i++) {
        arr[i] = input_int("Елемент " + to_string(i + 1) + ": ");
    }

    output_array(arr, n);
    int result = find_first_local_min(arr, n);
    cout << "Номер першого локального мінімуму: " << result << endl;
}

//  Завдання 2 — Array96: Видалення повторів
bool is_unique(const int arr[N], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) return false;
    }
    return true;
}

int remove_duplicates(const int in_arr[N], int n, int out_arr[N]) {
    int new_size = 0;
    for (int i = 0; i < n; i++) {
        if (is_unique(out_arr, new_size, in_arr[i])) {
            out_arr[new_size++] = in_arr[i];
        }
    }
    return new_size;
}

void task_array96() {
    int arr[N], n;
    cout << "\n--- Завдання Array96 ---\n";
    // Перевірка розміру масиву
    do {
        n = input_positive_int("Введіть кількість елементів масиву (мінімум 1): ");
        if (n < 1) cout << "Помилка! Масив повинен мати хоча б 1 елемент.\n";
    } while (n < 1);

    for (int i = 0; i < n; i++) {
        arr[i] = input_int("Елемент " + to_string(i + 1) + ": ");
    }

    output_array(arr, n);
    int unique_arr[N];
    int new_size = remove_duplicates(arr, n, unique_arr);
    cout << "Масив без повторів: ";
    output_array(unique_arr, new_size);
}
