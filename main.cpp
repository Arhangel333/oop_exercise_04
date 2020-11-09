
#include <iostream>
#include <tuple>
#include <cmath>

template <class T>
struct Eight
{
    int count = 8;
    std::pair<T, T> a[8];
};

template <class T>
struct Square
{
    int count = 4;
    std::pair<T, T> a[4];
};

template <class T>
struct Triangle
{
    int count = 3;
    std::pair<T, T> a[3];
};

template <class Tf>
void PrintFig(Tf figure)
{
    //std::cout<< figure.count << std::endl;
    switch (figure.count)
    {
    case 3:
    {
        std::cout << "Вершины Треугольника:" << std::endl;
        PrintT(figure);
        break;
    }
    case 4:
    {
        std::cout << "Вершины Квадрата:" << std::endl;
        PrintSq(figure);
        break;
    }
    case 8:
    {
        std::cout << "Вершины Восьмиугольника:" << std::endl;
        PrintEight(figure);
        break;
    }
    default:
    {
        std::cout << "Введена непредусмотренная фигура или что-то пошло не так" << std::endl;
        break;
    }
    }
}

template <class T>
void PrintT(T figure)
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << "x = " << figure.a[i].first << "\ty = " << figure.a[i].second << std::endl;
    }
}

template <class T>
void PrintSq(T figure)
{
    for (int i = 0; i < 4; i++)
    {
        std::cout << "x = " << figure.a[i].first << "\ty = " << figure.a[i].second << std::endl;
    }
}

template <class T>
void PrintEight(T figure)
{
    for (int i = 0; i < 8; i++)
    {
        std::cout << "x = " << figure.a[i].first << "\ty = " << figure.a[i].second << std::endl;
    }
}

template <class Tf>
double ShowS(Tf figure)
{
    double Sqr = 0;
    //std::cout<< figure.count << std::endl;
    switch (figure.count)
    {
    case 3:
    {
        double s, a, h;
        a = sqrt((double)((figure.a[0].first - figure.a[1].first) * (figure.a[0].first - figure.a[1].first) - (figure.a[0].second - figure.a[1].second) * (figure.a[0].second - figure.a[1].second)));
        h = a * sin(3.14 / 3);
        s = (a * h) / 2;
        return s;
        break;
    }
    case 4:
    {
        double s, a;
        a = sqrt((double)((figure.a[0].first - figure.a[1].first) * (figure.a[0].first - figure.a[1].first) - (figure.a[0].second - figure.a[1].second) * (figure.a[0].second - figure.a[1].second)));
        s = a * a;
        return s;
        break;
    }
    case 8:
    {
        double s, a, h, ctg;
        a = sqrt((double)((figure.a[0].first - figure.a[1].first) * (figure.a[0].first - figure.a[1].first) - (figure.a[0].second - figure.a[1].second) * (figure.a[0].second - figure.a[1].second)));
        ctg = cos(3.14 / 8) / sin(3.14 / 8);
        h = ctg * a;
        s = a * h * 4;
        return s;
        break;
    }
    default:
    {
        std::cout << "Введена непредусмотренная фигура или что-то пошло не так" << std::endl;
        break;
    }
    }
}

/* template<class T>
void ST(T figure){

    
    
}

template<class T>
void SSq(T figure){
return
    
    
}

template<class T>
void SE(T figure){

    
    
} */

void help()
{
    printf("Для выполнения операции введите соответствующую цифру:\n ");
    printf("\t 1 - Вывести Координаты всех вершин для всех фигур\n ");
    printf("\t 2 - Вычислить общую площадь всех фигур\n ");
    printf("\t 0 - Выйти из программы\n ");
}

int main()
{
    int enter, number, c;

    FILE *fl = fopen("test_01.txt", "r");

    //считывание фигур
    Triangle<int> tr;
    Square<int> s;
    Eight<int> e;
    //считывание фигур из файла
    while (!feof(fl))
    {
        fscanf(fl, "%d", &c);
        //printf("%d\n", c);
        number++;
        switch (c)
        {
        case 3:
        {

            for (int i = 0; i < 3; i++)
            {
                fscanf(fl, "%d %d", &tr.a[i].first, &tr.a[i].second);
                //printf("%d %d\n", tr.a[i].first, tr.a[i].second);
            }
            //printf("\n");

            break;
        }
        case 4:
        {
            for (int i = 0; i < 4; i++)
            {
                fscanf(fl, "%d %d", &s.a[i].first, &s.a[i].second);
                //printf("%d %d\n", s.a[i].first, s.a[i].second);
            }
            //printf("\n");
            break;
        }
        case 8:
        {
            for (int i = 0; i < 8; i++)
            {
                fscanf(fl, "%d %d", &e.a[i].first, &e.a[i].second);
                //printf("%d %d\n", e.a[i].first, e.a[i].second);
            }
            //printf("\n");
            break;
        }
        default:
        {
            std::cout << "Некоректный ввод фигуры " << std::endl;
            std::cout << "Введено значение ";
            std::cout << c << std::endl;
            break;
        }
        }
    }
    std::tuple<Square<int>, Eight<int>, Triangle<int>> t(s, e, tr);
    //auto t = std::make_tuple(s, e, tr);
    fclose(fl);

    //std::cin >> enter;
    //взаимодействие
    help();
    while (1)
    {

        std::cin >> enter;

        switch (enter)
        {
        case 1:
        {
            PrintFig(std::get<0>(t));
            PrintFig(std::get<1>(t));
            PrintFig(std::get<2>(t));
            break;
        }
        case 2:
        {
            double S;
            S += ShowS(std::get<0>(t));
            S += ShowS(std::get<1>(t));
            S += ShowS(std::get<2>(t));
            printf("Общая площадь фигур = %lf\n", S);
            break;
        }
        case 0:
        {
            std::cout << "Выход из программы...\n " << std::endl;
            return 0;
        }
        default:
        {
            std::cout << "Некоректный ввод\n " << std::endl;
            help();
            break;
        }
        }
    }
    std::cout << "Похоже введена буква, ну в другой раз не промахнётесь по клавиатуре \n\n"
              << std::endl;
    return 0;
}