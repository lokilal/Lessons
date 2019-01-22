#include <iostream>  //стандартная библиотека
#include <time.h> //случайные числа
#include <windows.h> // для HANDLE, курсора, цвета
#include <conio.h>  //для kbhit
#include <cmath>
using namespace std;

int sum = 0;int a = 0;
int key = 0, count = 0;
HANDLE hConsole;
HANDLE hStdout, hStdin; //o_O
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void GotoXY(int X, int Y)
{
    COORD coord = { X, Y };
    SetConsoleCursorPosition(hStdOut, coord);
}

//Цвет
enum ConsoleColor
{
        Black         = 0,
        Blue          = 1,
        Green         = 2,
        Cyan          = 3,
        Red           = 4,
        Magenta       = 5,
        Brown         = 6,
        LightGray     = 7,
        DarkGray      = 8,
        LightBlue     = 9,
        LightGreen    = 10,
        LightCyan     = 11,
        LightRed      = 12,
        LightMagenta  = 13,
        Yellow        = 14,
        White         = 15
};


void SetColor(ConsoleColor text, ConsoleColor background)
{
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 10) | text));
}
/**
  *@author
  *@author
  */
//Отрисовка всех вкладок.

int intro() {  // Прорисовка начального окна консоли.
    SetColor(White , Black);
 GotoXY(29,2);
    cout<<"Mathematical program";
    GotoXY(27,6);
    cout<<"Press any key to continue";//<<0x0a;
 GotoXY(54,20);
    cout<<"Created by user 'lokilal' ";
    _getch();
    return 0;
}

int writer1(){// Прорисовка начала ввода чисел для Математических операций.
    system("cls");
    GotoXY(1,0); cout<<"Enter numbers.When you want to stop press '0' ";
    GotoXY(0,1); cout<<"Numbers: ";
}
int writer2(int sum){ // Прорисовка результата.
    system("cls");
    GotoXY(0,0); cout<<"Your result is: ";SetColor(LightMagenta, Black);cout<<sum << endl;
    SetColor(White, Black);
    GotoXY(0,24);system("pause");

}

                    // Основные функции //
long double fact(int a) // Рекурсия для нахождения факториала.
{
    if(a < 0) // если пользователь ввел отрицательное число
        return 0; // возвращаем ноль
    if (a == 0)
        return 1; // возвращаем факториал от нуля
    else
        return a * fact(a - 1); // делаем рекурсию.
}

void operation(){ //Пользователь зашел во вкладку Математические операции.
    system("cls"); // Очищение экрана.
    GotoXY(1,0);cout<<"The functionality of the Mathematical operation(press the desired key) :";
    GotoXY(0,1);cout<<"1)Addition.";
    GotoXY(0,2);cout<<"2)Subtraction.";
    GotoXY(0,3);cout<<"3)Multiplication.";
    GotoXY(0,4);cout<<"4)Factorial.";
    key = _getch(); if( key == 49){ // Функция - сложение.
        writer1();cin>>a;
        while(a != 0){;cout<<" + ";sum+=a;cin >> a;}
        writer2(sum);
    }if(key == 50 ){//Функция - вычитание.
        writer1();cin >> a; sum = a;
        while(a != 0){cout<<" - ";cin>> a;sum-=a;}
        writer2(sum);
    }if(key == 51){ // Функция - умножение.
        writer1();cin>>a ;sum =1;
        while(a != 0){cout<<" * ";sum*=a;cin >> a;}
        writer2(sum);
    }if( key == 52){ //Функция - факториал.
        writer1(); cin>> a;
        sum = fact(a);
        writer2(sum);
    }
}

void equations(){ //Пользователь зашел во вкладку Уравнения.
    double a=0;double b=0; double c=0;double x1 =0; double x2=0; double d=0;
    system("cls");
    GotoXY(1,0); cout<< "The functionality of the equations(press the desired key) : ";
    GotoXY(0,1); cout<< "1)Quadratic equation";//Квадратные уравнения.
    key = _getch();
    if(key == 49){ // Квадратные уравнения.
        system("cls");SetColor(White , Black);
        GotoXY(10,0);cout<< "You have entered the section of square equations.";
        GotoXY(25,1);cout<< "ax^2 + bx + c = 0 ";
        GotoXY(0,3);cout<<  "Enter a:";cin>> a;//Ввод данных.
        GotoXY(15,3);cout<< "Enter b:";cin>> b;
        GotoXY(30,3);cout<< "Enter c:";cin>> c;
        d = b*b - 4 * a * c ; //Нахождение дискриминанта.
        x1= (-b + sqrt(d))/2*a; x2 = (-b - sqrt(d))/2*a; x2;//Нахождение корней.
        GotoXY(13,6); cout<< "The answers to your equations";SetColor(LightMagenta, Black);//Смена цвета для лучшего понимания ответа.
        GotoXY(0,7); cout<< "x1 = "<<x1;
        GotoXY(35,7); cout<< "x2 = "<<x2<<endl;SetColor(White, Black);//Возврат цвета
        GotoXY(0,24);system("pause");
    }

}


void drawing() //отрисовка всей информации на экране
{
    system("cls");
    SetColor(White , Black); // цвет текста, цвет фона текста
    GotoXY(1,0);cout <<  "The functionality of the program(press the desired key) :"  ; //
    GotoXY(0,1);cout <<  "1)Mathematical operation" << endl ;//Математические операции.
    GotoXY(0,2);cout <<  "2)Equations"<<endl;//Уравнения
}



int main()
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //получаем дескриптор консоли
    intro(); // Выводим на экран данные.
    int key = 0, count = 0;
    drawing();
    key = _getch();
    if(key == 49 )// Кнопка "1".
        operation();
    if(key == 50)//Кнопка "2".
        equations();


}

