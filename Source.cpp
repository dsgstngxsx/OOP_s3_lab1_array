#include <iostream>

using namespace std;

class arrays  //создаем класс
{
private:
    int* arr;  
    int size; //текущий размер массива
    int capacity; //вместительность массива

    //увеличение вместительности массива
    void increase()
    {
        capacity++;
        int* newArr = new int[capacity]; //создается новый массив с увел. вместительностью

        for (int i = 0; i < size; i++)
        {
            newArr[i] = arr[i]; //копируем по элементу в новый из старого
        }

        delete[] arr; //освобождение памяти старого массива
        arr = newArr; //указатель на новый массив
    }

public:
    //конструктор 
    //изначальная вместительность 1 по умолчанию
    arrays(int initialCapacity = 1) : size(0), capacity(initialCapacity)
    {
        arr = new int[capacity]; //выделяем динамическую память для массива 
    }
    
    //деструктор
    ~arrays() 
    {
        delete[] arr; //освобождение памяти
    }

    // добавление одного элемента в конец массива
    void add(int element)
    {
        if (size >= capacity) //если размер массива больше или равен вместительности
        {
            increase(); // то увеличиваем вместительность
        }
        arr[size] = element; //добавляем новый элемент в конец массива
        size++; // увеличиваем текущий размер
    }

    //ввод элементов массива
    void enter(int n)
    {
        int k;
        if (n <= 0)
        {
        here2:
            cout << "the amount of the elements must be > 0" << endl;
            cout << "how many elements: ";
            cin >> k;
            if (k <= 0)
            {
                goto here2;
            }
            n = k;
        }
        for (int i = 0; i < n; i++)
        {
            int value;
            cout << "enter the element " << (i + 1) << ": ";
            cin >> value;
            add(value); 

        }
    }

    //добавление нескольких элементов в конец массива
    void new_elemenets()
    {
        int m;
        cout << "\nhow many of the new elements: ";
        cin >> m;

        if (m <= 0)
        {
            cout << "\nthe amount of the new elements must be > 0" << endl;
            new_elemenets();
        }

        for (int i = 0; i < m; i++)
        {
            int value;
            cout << "enter the new elements " << (i + 1) << ": ";
            cin >> value;
            add(value);

        }

    }

    //print
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    //метод копирования
    arrays copy() const
    {
        arrays arr2(size); //массив2 с размером как у первого массива
        for (int i = 0; i < size; i++)
        {
            arr2.add(arr[i]); //добавляем элементы из первого в новый массив
        }
        return arr2;

    }

    //вставка массивов
    void double_arr(const arrays& arr3) //(ссылка на массив)
    {
        cout << "\nin which space do you want to place the copy of array? " << endl;
        int pos;

    here:

        cin >> pos;

        if (pos <= 0 || pos > size + 1) //если вышли за пределы
        {
            cout << "wrong position" << endl; 
            goto here;
        }

        while (size + arr3.size > capacity) //если сумма размеров массивов больше вместительности
        {
            increase(); //то увеличиваем вместительность 
        }
        for (int i = size - 1; i >= pos - 1; i--) // сдвигаем вправо часть массива1 
        {
            arr[i + arr3.size] = arr[i]; //элементы массива1 копируются на новые позиции
        }
        for (int i = 0; i < arr3.size; i++) //копируем элементы массива2 в массив1
        {
            arr[pos - 1 + i] = arr3.arr[i]; //копируем элементы массива2 в позицию
        }
        size += arr3.size; //обнвовляем размер массива 
    }

    //максимальный элемент массива
    int maxim()
    {
        int maxim = arr[0]; //первый элемент максимальный
        for (int i = 0; i < size; i++)
        {
            if (arr[i] > maxim) //если следующий элемент больше максимального
            {
                maxim = arr[i]; //то этот этот элемент максимальный
            }
        }
        return maxim;
    }
};

void line()
{
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~";
}
int main() {

    arrays myArray; //создаем новый массив 
    int n; //кол-во элементов

    cout << "how many elements: ";
    cin >> n;

    myArray.enter(n); //вводим элементы

    cout << "\n" << "array: ";
    myArray.print(); //вывод массива на экран

    line();

    arrays arr2 = myArray.copy(); //создаем массив2, который будет являться копией первого

    cout << "\n" << "copy of array: ";

    arr2.print(); //вывод копии на экран

    line();
    cout << "\n";

    myArray.new_elemenets(); //в первый массив добавляем новые элементы в конец
    cout << "\n" << "final array: "; 

    myArray.print(); //вывод обновленного массива

    line();
    cout << "\n";

    myArray.double_arr(arr2); //вставка копии в обновленный массив

    cout << "\ndouble: ";

    myArray.print(); //вывод большого массива 

    line();
    int maxx = myArray.maxim(); //поиск макс. элемента в большом массиве
    cout << "\n" << "the max element is : " << maxx << endl; //вывод макс.элемента
    return 0;
}