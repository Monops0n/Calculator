#include "Functions.h"
const int WIDTH = 1080;
const int HEIGHT = 720;
/*============================================ОБЩИЕ ФУНКЦИИ==========================================*/
/*============================================ОБЩИЕ ФУНКЦИИ==========================================*/
/*============================================ОБЩИЕ ФУНКЦИИ==========================================*/
void createPolynom(int degree, double* coeffs)
{
    for (int i = 0; i <= degree; i++)
    {
        cout << "Введите " << i + 1 << "-й коэффициент: " << endl;
        cin >> coeffs[i];
    }
}
void inputDegreePolynom(int& degree)
{
    do
    {
        cout << "Введите степень полинома: " << endl;
        cin >> degree;
        if (degree < 0) {
            cout << "Введите корректные данные!" << endl;
        }
    } while (degree < 0);
}
void inputCoeffs3(double* coeff)
{
    int i = 0;
    cout << "Введите a:" << endl;
    cin >> coeff[i++];
    cout << "Введите b:" << endl;
    cin >> coeff[i++];
    cout << "Введите c:" << endl;
    cin >> coeff[i];
}
void inputCoeffs4(double *coeff)
{
    cout << "Введите a:" << endl;
    cin >> coeff[0];
    cout << "Введите b:" << endl;
    cin >> coeff[1];
    cout << "Введите c:" << endl;
    cin >> coeff[2];
    cout << "Введите d:" << endl;
    cin >> coeff[3];
}
void inputRangeForDeg(double &a, double &b)
{
    do
    {
        cout << "Введите левый край a:" << endl;
        cin >> a;
        cout << "Введите правый край b:" << endl;
        cin >> b;
        if(b <= a or a <0)
        {
            cout << "Введите корректные значения! " << endl;
        }
    }while(b <= a or a <0);
}
double functionPolinom(double x, double* coeffs, int degree) {
    double result = 0;
    for (int i = 0; i <= degree; i++) {
        result += coeffs[i] * pow(x, i);
    }
    return result;
}
double functionDegree(double x, double a, double b, double c) {
    return a * pow(x, b) + c;
}
double functionInd(double x, double a, double b, double c, double d) {
    return a * pow(b, c * x) + d;
}
double functionLog(double x, double a, double b, double c) {
    return a*log(b*x)+c;
}
double functionSin(double x, double a, double b, double c, double d)
{
    return a * sin(b * x + c) + d;
}
double functionCos(double x, double a, double b, double c, double d)
{
    return a * cos(b * x + c) + d;
}
/*============================================ИНТЕГРАЛЫ==========================================*/
/*============================================ИНТЕГРАЛЫ==========================================*/
/*============================================ИНТЕГРАЛЫ==========================================*/
void inputCoeffsForLog(double *coeffs, double a, double b)
{
    do
    {
        int i = 0;
        cout << "Введите a:" << endl;
        cin >> coeffs[i++];
        cout << "Введите b:" << endl;
        cin >> coeffs[i++];
        cout << "Введите c:" << endl;
        cin >> coeffs[i];
        if(b*coeffs[1] <= 0 or a*coeffs[1] <= 0)
        {
            cout << "Введите корректные значения!" << endl;
        }
    }while(b*coeffs[1] <= 0 or a*coeffs[1] <= 0);
}
void inputRange(double& a, double& b)
{
    do {

        cout << "Введите нижний предел интегрирования: " << endl;
        cin >> a;

        cout << "Введите верхний предел интегрирования: " << endl;
        cin >> b;
        if (b <= a) {
            cout << "Введите корректные значения!" << endl;
        }
    } while (b <= a);
}
double integratePolynom(double a, double b, double* coeffs, int degree)
{
    double result = 0;
    for (int i = 0; i <= degree; i++)
    {
        result += coeffs[i] * (pow(b, i + 1) / (i + 1) - pow(a, i + 1) / (i + 1));
    }
    return result;
}
double integrateDegree(double* coeffs, double A, double B, int num_intervals)
{
    int j = 0;
    double a = coeffs[j++];
    double b = coeffs[j++];
    double c = coeffs[j++];
    double result = 0;
    double h = (B - A) / num_intervals;

    for (int i = 1; i <= num_intervals; ++i) {
        double x0 = A + (i - 1) * h;
        double x1 = A + i * h;
        result += (functionDegree(x0, a, b, c) + functionDegree(x1, a, b, c)) * h / 2.0;
    }
    return result;
}
double integrateInd(double (*f)(double, double, double, double, double), double a, double b, double n, double *coeffs)
{
    int j = 0;
    double A = coeffs[j++];
    double B = coeffs[j++];
    double C = coeffs[j++];
    double D = coeffs[j++];
    
    double h = (b - a) / n;
    double sum = 0.5 * (f(a, A, B, C, D) + f(b, A, B, C, D));
    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        sum += f(x, A, B, C, D);
    }
    return sum * h;
}
double integrateLog(double (*f)(double, double, double, double), double A, double B, double n, double *coeffs)
{
    int j = 0;
    double a = coeffs[j++];
    double b = coeffs[j++];
    double c = coeffs[j++];
    
    double h = (B - A) / n;
    double result = 0.0;
    for (int i = 0; i < n; ++i) {
        double x = A + i * h;
        result += f(x, a, b, c);
    }
    return result * h;
}
double integrateSin(double (*f)(double, double, double, double, double), double A, double B, double n, double *coeffs)
{
    int j = 0;
    double a = coeffs[j++];
    double b = coeffs[j++];
    double c = coeffs[j++];
    double d = coeffs[j++];
    double h = (B - A) / n;
    double result = 0.0;
    for (int i = 0; i < n; ++i) {
        double x = A + (i + 0.5) * h;
        result += f(x, a, b, c, d);
    }
    return result * h;
}
double integrateCos(double (*f)(double, double, double, double, double), double A, double B, double n, double *coeffs)
{
    int j = 0;
    double a = coeffs[j++];
    double b = coeffs[j++];
    double c = coeffs[j++];
    double d = coeffs[j++];
    double h = (B - A) / n;
    double result = 0.0;
    for (int i = 0; i < n; ++i) {
        double x = A + (i + 0.5) * h;
        result += f(x, a, b, c, d);
    }
    return result * h;
}
void DefiniteIntegral()
{
    int choice;
    do
    {
        cout << "\t+----------------------------------------------------------------------------------+" << endl;
        cout << "\t|                                                                                  |" << endl;
        cout << "\t|                     Интеграл какой функции будем считать?                        |" << endl;
        cout << "\t|                                                                                  |" << endl;
        cout << "\t+----------------------------------------------------------------------------------+" << endl;
        cout << "\t|                                                                                  |" << endl;
        cout << "\t|    1 - Полином степени N(a0+a1*x+a2*x^2+...aN*x^N).                              |" << endl;
        cout << "\t|    2 - Степенная(a*x^b+c).                                                       |" << endl;
        cout << "\t|    3 - Показательная(a*b^(c*x)+d).                                               |" << endl;
        cout << "\t|    4 - Логарифмическая(a*ln(b*x)+c).                                             |" << endl;
        cout << "\t|    5 - Синусоида(a*sin(b*x+c)+d).                                                |" << endl;
        cout << "\t|    6 - Косинусоида(a*sin(b*x+c)+d).                                              |" << endl;
        cout << "\t|    7 - Назад.                                                                    |" << endl;
        cout << "\t|                                                                                  |" << endl;
        cout << "\t+----------------------------------------------------------------------------------+" << endl << endl << endl;

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            choice = 0;
        }
        double a, b;
        if (choice != 7)
        {
            inputRange(a, b);
        }
        switch (choice)
        {
        case 1:
            int degree;
            double coeffsPol[1000];
            inputDegreePolynom(degree);
            createPolynom(degree, coeffsPol);
            cout << "Определённый интеграл на отрезке от " << a << " до " << b << " = " << integratePolynom(a, b, coeffsPol, degree) << "!" << endl << endl;
            break;
        case 2:
            double coeffsDeg[3];
            inputCoeffs3(coeffsDeg);
            cout << "Определённый интеграл на отрезке от " << a << " до " << b << " = " << integrateDegree(coeffsDeg, a, b, 1000) << "!" << endl << endl;
            break;
        case 3:
            double coeffsInd[4];
            inputCoeffs4(coeffsInd);
            cout << "Определённый интеграл на отрезке от " << a << " до " << b << " = " << integrateInd(functionInd,a,b, 5000, coeffsInd) << "!" << endl << endl;
            break;
        case 4:
            double coeffsLog[3];
            inputCoeffsForLog(coeffsLog, a, b);
            cout << "Определённый интеграл на отрезке от " << a << " до " << b << " = " << integrateLog(functionLog, a, b, 5000, coeffsLog) << "!" << endl << endl;
            break;
        case 5:
            double coeffsSin[4];
            inputCoeffs4(coeffsSin);
            cout << "Определённый интеграл на отрезке от " << a << " до " << b << " = " << integrateSin(functionSin, a, b, 5000, coeffsSin) << "!" << endl << endl;
            break;
        case 6:
            double coeffsCos[4];
            inputCoeffs4(coeffsCos);
            cout << "Определённый интеграл на отрезке от " << a << " до " << b << " = " << integrateCos(functionCos, a, b, 5000, coeffsCos) << "!" << endl << endl;
            break;
        case 7:
            cout << "Возврат назад..." << endl;
            Sleep(1000);
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 7);
}
/*============================================SDL==========================================*/
/*============================================SDL==========================================*/
/*============================================SDL==========================================*/
void drawBasic(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, 0, HEIGHT / 2, WIDTH, HEIGHT / 2);
    SDL_RenderDrawLine(renderer, WIDTH / 2, 0, WIDTH / 2, HEIGHT);

    //стрелка оси y
    int temp = 0;
    for(int y=0; y <= 5; y++)
    {
        SDL_RenderDrawPoint(renderer, (WIDTH/2-temp), y);
        SDL_RenderDrawPoint(renderer, (WIDTH/2+temp), y);
        temp++;
    }
    //стрелка оси x
    temp = 6;
    for(int x=6; x >= 0; x--)
    {
        SDL_RenderDrawPoint(renderer, WIDTH-x, (HEIGHT/2)+temp);
        SDL_RenderDrawPoint(renderer, WIDTH-x, (HEIGHT/2)-temp);
        temp--;
    }
    SDL_RenderPresent(renderer);

    
}
void drawSDLPol(double *coeffs,int degree)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cerr << "Ошибка при инициализации SDL: " << SDL_GetError() << endl;
    }

    SDL_Window* window = SDL_CreateWindow("Показательная", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        cerr << "Ошибка при создании окна: " << SDL_GetError() << endl;
        SDL_Quit();
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    drawBasic(renderer);
    const int plot = 100;
    const int step = 1;
    for (double x = -WIDTH / 2; x < WIDTH / 2; x += step) {
        double y = functionPolinom(x / plot, coeffs, degree) * plot;
        int screenX = x + WIDTH / 2;
        int screenY = HEIGHT / 2 - static_cast<int>(y);
        SDL_RenderDrawPoint(renderer, screenX, screenY);
    }
    SDL_RenderPresent(renderer);
    
    //Окно не закроется, пока не нажать на крестик
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}
void drawSDLDeg(double *coeffs)
{
    int a = coeffs[0];
    int b = coeffs[1];
    int c = coeffs[2];
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cerr << "Ошибка при инициализации SDL: " << SDL_GetError() << endl;
    }

    SDL_Window* window = SDL_CreateWindow("Показательная", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        cerr << "Ошибка при создании окна: " << SDL_GetError() << endl;
        SDL_Quit();
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    drawBasic(renderer);
    const int plot = 100;
    const int step = 1;
    for (double x = -WIDTH / 2; x < WIDTH / 2; x += step) {
        double y = functionDegree(x / plot, a, b, c) * plot;
        int screenX = x + WIDTH / 2;
        int screenY = HEIGHT / 2 - static_cast<int>(y);
        SDL_RenderDrawPoint(renderer, screenX, screenY);
    }
    SDL_RenderPresent(renderer);
    
    //Окно не закроется, пока не нажать на крестик
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}
void drawSDLInd(double *coeffs)
{
    int a = coeffs[0];
    int b = coeffs[1];
    int c = coeffs[2];
    int d = coeffs[3];
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cerr << "Ошибка при инициализации SDL: " << SDL_GetError() << endl;
    }

    SDL_Window* window = SDL_CreateWindow("Показательная", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        cerr << "Ошибка при создании окна: " << SDL_GetError() << endl;
        SDL_Quit();
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    drawBasic(renderer);
    const int plot = 100;
    const int step = 1;
    for (double x = -WIDTH / 2; x < WIDTH / 2; x += step) {
        double y = functionInd(x / plot, a, b, c, d) * plot;
        int screenX = x + WIDTH / 2;
        int screenY = HEIGHT / 2 - static_cast<int>(y);
        SDL_RenderDrawPoint(renderer, screenX, screenY);
    }
    SDL_RenderPresent(renderer);
    
    //Окно не закроется, пока не нажать на крестик
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}
void drawSDLLog(double *coeffs)
{
    int a = coeffs[0];
    int b = coeffs[1];
    int c = coeffs[2];
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cerr << "Ошибка при инициализации SDL: " << SDL_GetError() << endl;
    }

    SDL_Window* window = SDL_CreateWindow("Показательная", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        cerr << "Ошибка при создании окна: " << SDL_GetError() << endl;
        SDL_Quit();
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    drawBasic(renderer);
    const int plot = 150;
    const int step = 1;
    for (double x = -WIDTH / 2; x < WIDTH / 2; x += step) {
        double y = functionLog(x / plot, a, b, c) * plot;
        int screenX = x + WIDTH / 2;
        int screenY = HEIGHT / 2 - static_cast<int>(y);
        SDL_RenderDrawPoint(renderer, screenX, screenY);
    }
    SDL_RenderPresent(renderer);
    
    //Окно не закроется, пока не нажать на крестик
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}
void drawSDLSin(double *coeffs)
{
    int a = coeffs[0];
    int b = coeffs[1];
    int c = coeffs[2];
    int d = coeffs[3];
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cerr << "Ошибка при инициализации SDL: " << SDL_GetError() << endl;
    }

    SDL_Window* window = SDL_CreateWindow("Показательная", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        cerr << "Ошибка при создании окна: " << SDL_GetError() << endl;
        SDL_Quit();
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    drawBasic(renderer);
    const int plot = 150;
    const int step = 1;
    for (double x = -WIDTH / 2; x < WIDTH / 2; x += step) {
        double y = functionSin(x / plot, a, b, c, d) * plot;
        int screenX = x + WIDTH / 2;
        int screenY = HEIGHT / 2 - static_cast<int>(y);
        SDL_RenderDrawPoint(renderer, screenX, screenY);
    }
    SDL_RenderPresent(renderer);
    
    //Окно не закроется, пока не нажать на крестик
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}
void drawSDLCos(double *coeffs)
{
    int a = coeffs[0];
    int b = coeffs[1];
    int c = coeffs[2];
    int d = coeffs[3];
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cerr << "Ошибка при инициализации SDL: " << SDL_GetError() << endl;
    }

    SDL_Window* window = SDL_CreateWindow("Показательная", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        cerr << "Ошибка при создании окна: " << SDL_GetError() << endl;
        SDL_Quit();
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    drawBasic(renderer);
    const int plot = 150;
    const int step = 1;
    for (double x = -WIDTH / 2; x < WIDTH / 2; x += step) {
        double y = functionCos(x / plot, a, b, c, d) * plot;
        int screenX = x + WIDTH / 2;
        int screenY = HEIGHT / 2 - static_cast<int>(y);
        SDL_RenderDrawPoint(renderer, screenX, screenY);
    }
    SDL_RenderPresent(renderer);
    
    //Окно не закроется, пока не нажать на крестик
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}
void inputCoeffsLog(double *coeff)
{
    cout << "Введите a:" << endl;
    cin >> coeff[0];
    do
    {
        cout << "Введите b:" << endl;
        cin >> coeff[1];
        if(coeff[1] <= 0)
        {
            cout << "Введите корректное значение! " << endl;
        }
    }while(coeff[1] <= 0);
    cout << "Введите c:" << endl;
    cin >> coeff[2];
}
void graphics()
{
    double a, b;
    int choice;
    do
    {
        cout << "\t+----------------------------------------------------------------------------------+" << endl;
        cout << "\t|                                                                                  |" << endl;
        cout << "\t|                       График какой функции будем строить?                        |" << endl;
        cout << "\t|                                                                                  |" << endl;
        cout << "\t+----------------------------------------------------------------------------------+" << endl;
        cout << "\t|                                                                                  |" << endl;
        cout << "\t|    1 - Полином степени N(a0+a1*x+a2*x^2+...aN*x^N).                              |" << endl;
        cout << "\t|    2 - Степенная(a*x^b+c).                                                       |" << endl;
        cout << "\t|    3 - Показательная(a*b^(c*x)+d).                                               |" << endl;
        cout << "\t|    4 - Логарифмическая(a*ln(b*x)+c).                                             |" << endl;
        cout << "\t|    5 - Синусоида(a*sin(b*x+c)+d).                                                |" << endl;
        cout << "\t|    6 - Косинусоида(a*sin(b*x+c)+d).                                              |" << endl;
        cout << "\t|    7 - Назад.                                                                    |" << endl;
        cout << "\t|                                                                                  |" << endl;
        cout << "\t+----------------------------------------------------------------------------------+" << endl << endl << endl;

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            choice = 0;
        }

        switch (choice) {
        case 1:
            int degree;
            double coeffsPol[1000];
            inputDegreePolynom(degree);
            createPolynom(degree, coeffsPol);
            drawSDLPol(coeffsPol, degree);
            break;
        case 2:
            double coeffsDeg[3];
            inputCoeffs3(coeffsDeg);
            drawSDLDeg(coeffsDeg);
            break;
        case 3:
            double coeffsInd[4];
            inputCoeffs4(coeffsInd);
            drawSDLInd(coeffsInd);
            break;
        case 4:
            double coeffsLog[3];
            inputCoeffsLog(coeffsLog);
            drawSDLLog(coeffsLog);
            break;
        case 5:
            double coeffsSin[4];
            inputCoeffs4(coeffsSin);
            drawSDLSin(coeffsSin);
            break;
        case 6:
            double coeffsCos[4];
            inputCoeffs4(coeffsCos);
            drawSDLCos(coeffsCos);
            break;
        case 7:
            cout << "Возврат назад..." << endl;
            Sleep(1000);
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 7);
}
/*============================================ПОИСК Y=0 НА ОТРЕЗКЕ==========================================*/
/*============================================ПОИСК Y=0 НА ОТРЕЗКЕ==========================================*/
/*============================================ПОИСК Y=0 НА ОТРЕЗКЕ==========================================*/
void inputCoeffsLog(double *coeffs, double a, double b)
{
    cout << "Введите a: " << endl;
    cin >> coeffs[0];
    do
    {
        cout << "Введите b:" << endl;
        cin >> coeffs[1];
        if(coeffs[1] == 0 or (coeffs[1] < 0 and a > 0 and b > 0) or (coeffs[1] > 0 and a < 0 and b < 0))
        {
            cout <<"Введите корректный коэффициент!" << endl;
        }
    }while(coeffs[1] == 0 or (coeffs[1] < 0 and a > 0 and b > 0) or (coeffs[1] > 0 and a < 0 and b < 0));
    cout << "Введите с: " << endl;
    cin >> coeffs[2];
}
void inputRangeForSquare(double &a, double &b)
{
    do
    {
        cout << "Введите начало отрезка а: " << endl;
        cin >> a;
        cout << "Введите конец отрезка b: " << endl;
        cin >> b;
        if(b <= a)
        {
            cout << "Введите корректные данные!" << endl;
        }
    }while(b <= a);
}
void inputRangeForSquareLog(double &a, double &b)
{
    do
    {
        cout << "Введите начало отрезка а: " << endl;
        cin >> a;
        cout << "Введите конец отрезка b: " << endl;
        cin >> b;
        if(b <= a or a*b<=0)
        {
            cout << "Введите корректные данные!" << endl;
        }
    }while(b <= a or a*b<=0);
}
void inputEpsilonForSquare(double &epsilon)
{
    do
    {
        cout << "Введите желаемую точность(от 0.1...1 до 0.9....9): " << endl;
        cin >> epsilon;
        if(epsilon >= 1 or epsilon <= 0)
        {
            cout << "Введите корректную точность!" << endl;
        }
    }while(epsilon >= 1 or epsilon <= 0);
}
double findSquarePolinom(double *coeffs, int degree, double a, double b, double epsilon)
{
    if (functionPolinom(a, coeffs, degree) * functionPolinom(b, coeffs, degree) >= 0)
    {
        return NAN;
    }
    double c = (a + b) / 2;
    while ((b - a)/2 >= epsilon) {
        if (functionPolinom(c, coeffs, degree) == 0.0) {
            break;
        } else if (functionPolinom(c, coeffs, degree) * functionPolinom(a, coeffs, degree) < 0) {
            b = c;
        } else {
            a = c;
        }
        c = (a + b) / 2;
    }
    return c;
}
double findSquareDeg(double *coeffs, double A, double B, double epsilon)
{
    int j = 0;
    int a = coeffs[j++];
    int b = coeffs[j++];
    int c = coeffs[j++];
    if(functionDegree(A, a, b, c)*functionDegree(B, a, b, c)>=0)
    {
        return NAN;
    }
    double C = (A + B) / 2;
    while ((B - A) >= epsilon) {
        if (functionDegree(C, a, b, c) == 0.0) {
            break;
        } else if (functionDegree(C, a, b, c) * functionDegree(A, a, b, c) < 0) {
            B = C;
        } else {
            A = C;
        }
        C = (A + B) / 2;
    }
    return C;
}
double findSquareInd(double *coeffs, double A, double B, double epsilon)
{
    int j = 0;
    int a = coeffs[j++];
    int b = coeffs[j++];
    int c = coeffs[j++];
    int d = coeffs[j++];
    if (functionInd(A, a, b, c, d) * functionInd(B, a, b, c, d) >= 0) {
        return NAN;
    }

    double C = ( A + B) / 2;
    while ((B - A) >= epsilon)
        {
            if (functionInd(C, a, b, c, d) == 0.0)
            {
                break;
            }
        else if (functionInd(C, a, b, c, d) * functionInd(A, a, b, c, d) < 0)
        {
            B = C;
        }
        else
        {
            A = C;
        }
        C = ( A + B) / 2;
    }

    return C;
}
double findSquareLog(double *coeffs, double A, double B, double epsilon)
{
    int j = 0;
    int a = coeffs[j++];
    int b = coeffs[j++];
    int c = coeffs[j++];
    if (functionLog(A, a, b, c) * functionLog(B, a, b, c) >= 0) {
        return NAN;
    }

    double C = ( A + B) / 2;
    while ((B - A) >= epsilon)
    {
        if (functionLog(C, a, b, c) == 0.0)
        {
            break;
        }
        else if (functionLog(C, a, b, c) * functionLog(A, a, b, c) < 0)
        {
            B = C;
        }
        else
        {
            A = C;
        }
        C = ( A + B) / 2;
    }
    
    return C;
}

double findSquareSin(double a, double b, double c, double d, double A, double B, double epsilon)
{
    if(abs(a) < abs(d))return NAN;
    double C = (A + B) / 2;
    double x;
    if (abs(functionSin(C, a, b, c, d)) < epsilon) return C;
    else if ((B - A) < epsilon) return NAN;
    else
    {
        if (functionSin(A, a, b, c, d) * functionSin(C, a, b, c, d) < 0) return findSquareSin(a, b, c, d, A, C, epsilon);
        else return findSquareSin(a, b, c, d, C, B, epsilon);
    }
}
double findSquareCos(double a, double b, double c, double d, double A, double B, double epsilon)
{
    double C = (A + B) / 2;
    double x;
    if (abs(functionCos(C, a, b, c, d)) < epsilon) return C;
    else if ((B - A) < epsilon) return NAN;
    else
    {
        if (functionCos(A, a, b, c, d) * functionCos(C, a, b, c, d) < 0) return findSquareCos(a, b, c, d, A, C, epsilon);
        else return findSquareCos(a, b, c, d, C, B, epsilon);
    }
}
void squareOnRange()
{
    int choice, j = 0;
    double A, B, epsilon, result;
    do
    {
        cout << "\t+----------------------------------------------------------------------------------+" << endl;
        cout << "\t|                                                                                  |" << endl;
        cout << "\t|                 Корень Y=0 на отрезке какой функции будем искать?                |" << endl;
        cout << "\t|                                                                                  |" << endl;
        cout << "\t+----------------------------------------------------------------------------------+" << endl;
        cout << "\t|                                                                                  |" << endl;
        cout << "\t|    1 - Полином степени N(a0+a1*x+a2*x^2+...aN*x^N).                              |" << endl;
        cout << "\t|    2 - Степенная(a*x^b+c).                                                       |" << endl;
        cout << "\t|    3 - Показательная(a*b^(c*x)+d).                                               |" << endl;
        cout << "\t|    4 - Логарифмическая(a*ln(b*x)+c).                                             |" << endl;
        cout << "\t|    5 - Синусоида(a*sin(b*x+c)+d).                                                |" << endl;
        cout << "\t|    6 - Косинусоида(a*sin(b*x+c)+d).                                              |" << endl;
        cout << "\t|    7 - Назад.                                                                    |" << endl;
        cout << "\t|                                                                                  |" << endl;
        cout << "\t+----------------------------------------------------------------------------------+" << endl << endl << endl;

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            choice = 0;
        }
        switch (choice) {
        case 1:
            int degree;
            double coeffsPol[1000];
            inputRangeForSquare(A, B);
            inputEpsilonForSquare(epsilon);
            inputDegreePolynom(degree);
            createPolynom(degree, coeffsPol);

            result = findSquarePolinom(coeffsPol, degree, A, B, epsilon);
            if(isnan(result))
            {
                cout << "На заданном интервале корень не найден или не выполнено условие теоремы!" << endl;
            }
            else
            {
             cout << "Корень уравнения Y=0 на заданном интервале: " << result << endl;   
            }
            break;
        case 2:
            double coeffsDeg[3];
            inputRangeForDeg(A, B);// раньше здесь было inputRageForSquare(), я поменял и не проверил, возможна ошибка
            inputEpsilonForSquare(epsilon);
            inputCoeffs3(coeffsDeg);
            result = findSquareDeg(coeffsDeg, A, B, epsilon);
            if(isnan(result))
            {
                cout << "На заданном интервале корень не найден или не выполнено условие теоремы!" << endl;
            }
            else
            {
                cout << "Корень уравнения Y=0 на заданном интервале: " << result << endl;   
            }
            break;
        case 3:
            double coeffsInd[4];
            inputRangeForSquare(A, B);
            inputEpsilonForSquare(epsilon);
            inputCoeffs4(coeffsInd);
            result = findSquareInd(coeffsInd,A, B, epsilon);
            if(isnan(result))
            {
                cout << "На заданном интервале корень не найден или не выполнено условие теоремы!" << endl;
            }
            else
            {
                cout << "Корень уравнения Y=0 на заданном интервале: " << result << endl;   
            }
            break;
        case 4:
            double coeffsLog[3];
            inputRangeForSquareLog(A, B);
            inputEpsilonForSquare(epsilon);
            inputCoeffsLog(coeffsLog, A, B);
            result = findSquareLog(coeffsLog,A, B, epsilon);
            if(isnan(result))
            {
                cout << "На заданном интервале корень не найден или не выполнено условие теоремы!" << endl;
            }
            else
            {
                cout << "Корень уравнения Y=0 на заданном интервале: " << result << endl;   
            }
            break;
        case 5:
            double coeffsSin[4];
            inputRangeForSquare(A, B);
            inputEpsilonForSquare(epsilon);
            inputCoeffs4(coeffsSin);
            result = findSquareSin(coeffsSin[0], coeffsSin[1], coeffsSin[2], coeffsSin[3] ,A, B, epsilon);
            if(isnan(result))
            {
                cout << "На заданном интервале корень не найден или не выполнено условие теоремы!" << endl;
            }
            else
            {
                cout << "Корень уравнения Y=0 на заданном интервале: " << result << endl;   
            }
            break;
        case 6:
            double coeffsCos[4];
            inputRangeForSquare(A, B);
            inputEpsilonForSquare(epsilon);
            inputCoeffs4(coeffsCos);
            result = findSquareCos(coeffsCos[0], coeffsCos[1], coeffsCos[2], coeffsCos[3] ,A, B, epsilon);
            if(isnan(result))
            {
                cout << "На заданном интервале корень не найден или не выполнено условие теоремы!" << endl;
            }
            else
            {
                cout << "Корень уравнения Y=0 на заданном интервале: " << result << endl;   
            }
            break;
        case 7:
            cout << "Возврат назад..." << endl;
            Sleep(1000);
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 7);
}
/*============================================ПОИСК ЭКСТРЕМУМОВ НА ОТРЕЗКЕ==========================================*/
/*============================================ПОИСК ЭКСТРЕМУМОВ НА ОТРЕЗКЕ==========================================*/
/*============================================ПОИСК ЭКСТРЕМУМОВ НА ОТРЕЗКЕ==========================================*/
void findExtremumsPol(double *coeffs, int degree, double A, double B, double epsilon)
{
    double x = A;
    double prev_diff = 0;
    int Extr = 0;
    
    while (x <= B) {
        double diff = functionPolinom(x + epsilon, coeffs, degree) - functionPolinom(x, coeffs, degree); 
        if (diff * prev_diff < 0) { 
            Extr++;
            double extremum = x - epsilon / 2;
            cout << "Экстремум в точке x = " << extremum << ", значение функции f(x) = " << functionPolinom(extremum, coeffs, degree) << endl;
        }
        prev_diff = diff;
        x += epsilon;
    }
    if(Extr == 0)
    {
        cout << "Точек экстремума нет!" << endl;
    }
    Sleep(2000);
}
void findExtremumsDeg(double *coeffs, double A, double B, double epsilon)
{
    double a = coeffs[0];
    double b = coeffs[1];
    double c = coeffs[2];

    double x = A;
    double prev_diff = 0;
    int Extr = 0;
    
    while (x <= B) {
        double diff = functionDegree(x + epsilon, a, b, c) - functionDegree(x, a, b, c); 
        if (diff * prev_diff < 0) { 
            Extr++;
            double extremum = x - epsilon / 2;
            cout << "Экстремум в точке x = " << extremum << ", значение функции f(x) = " << functionDegree(extremum, a, b, c) << endl;
        }
        prev_diff = diff;
        x += epsilon;
    }
    if(Extr == 0)
    {
        cout << "Точек экстремума нет!" << endl;
    }
    Sleep(2000);
}
void findExtremumsInd(double *coeffs, double A, double B, double epsilon)
{
    double a = coeffs[0];
    double b = coeffs[1];
    double c = coeffs[2];
    double d = coeffs[3];

    double x = A;
    double prev_diff = 0;
    int Extr = 0;
    
    while (x <= B) {
        double diff = functionInd(x + epsilon, a, b, c, d) - functionInd(x, a, b, c, d); 
        if (diff * prev_diff < 0) { 
            Extr++;
            double extremum = x - epsilon / 2;
            cout << "Экстремум в точке x = " << extremum << ", значение функции f(x) = " << functionInd(extremum, a, b, c, d) << endl;
        }
        prev_diff = diff;
        x += epsilon;
    }
    if(Extr == 0)
    {
        cout << "Точек экстремума нет!" << endl;
    }
    Sleep(2000);
}
void findExtremumsLog(double *coeffs, double A, double B, double epsilon)
{
    double a = coeffs[0];
    double b = coeffs[1];
    double c = coeffs[2];

    double x = A;
    double prev_diff = 0;
    int Extr = 0;
    while (x <= B) {
        double diff = functionLog(x + epsilon, a, b, c) - functionLog(x, a, b, c); 
        if (diff * prev_diff < 0) { 
            double extremum = x - epsilon / 2;
            Extr++;
            cout << "Экстремум в точке x = " << extremum << ", значение функции f(x) = " << functionLog(extremum, a, b, c) << endl;
        }
        prev_diff = diff;
        x += epsilon;
    }
    if(Extr == 0)
    {
        cout << "Точек экстремума нет!" << endl;
    }
    Sleep(2000);
}
void findExtremumsSin(double *coeffs,double A, double B, double  epsilon)
{
    double a = coeffs[0];
    double b = coeffs[1];
    double c = coeffs[2];
    double d = coeffs[3];

    double x = A;
    double prev_diff = 0;
    int Extr = 0;
    
    while (x <= B) {
        double diff = functionSin(x + epsilon, a, b, c, d) - functionSin(x, a, b, c, d); 
        if (diff * prev_diff < 0) {
            Extr++;
            double extremum = x - epsilon / 2;
            cout << "Экстремум в точке x = " << extremum << ", значение функции f(x) = " << functionSin(extremum, a, b, c, d) << endl;
        }
        prev_diff = diff;
        x += epsilon;
    }
    if(Extr == 0)
    {
        cout << "Точек экстремума нет!" << endl;
    }
    Sleep(2000);
}
void findExtremumsCos(double *coeffs,double A, double B, double  epsilon)
{
    double a = coeffs[0];
    double b = coeffs[1];
    double c = coeffs[2];
    double d = coeffs[3];

    double x = A;
    double prev_diff = 0;
    int Extr = 0;
    
    while (x <= B) {
        double diff = functionCos(x + epsilon, a, b, c, d) - functionCos(x, a, b, c, d); 
        if (diff * prev_diff < 0) { 
            Extr++;
            double extremum = x - epsilon / 2;
            cout << "Экстремум в точке x = " << extremum << ", значение функции f(x) = " << functionCos(extremum, a, b, c, d) << endl;
        }
        prev_diff = diff;
        x += epsilon;
    }
    if(Extr == 0)
    {
        cout << "Точек экстремума нет!" << endl;
    }
    Sleep(2000);
}
void extremumsOnRange()
{
    double a, b, epsilon;
    int choice;
    bool hasExtremum = false;
    double prevDerivative = 0;
    do
    {
        cout << "\t+----------------------------------------------------------------------------------+" << endl;
        cout << "\t|                                                                                  |" << endl;
        cout << "\t|                    Экстремумы какой функции будем искать?                        |" << endl;
        cout << "\t|                                                                                  |" << endl;
        cout << "\t+----------------------------------------------------------------------------------+" << endl;
        cout << "\t|                                                                                  |" << endl;
        cout << "\t|    1 - Полином степени N(a0+a1*x+a2*x^2+...aN*x^N).                              |" << endl;
        cout << "\t|    2 - Степенная(a*x^b+c).                                                       |" << endl;
        cout << "\t|    3 - Показательная(a*b^(c*x)+d).                                               |" << endl;
        cout << "\t|    4 - Логарифмическая(a*ln(b*x)+c).                                             |" << endl;
        cout << "\t|    5 - Синусоида(a*sin(b*x+c)+d).                                                |" << endl;
        cout << "\t|    6 - Косинусоида(a*sin(b*x+c)+d).                                              |" << endl;
        cout << "\t|    7 - Назад.                                                                    |" << endl;
        cout << "\t|                                                                                  |" << endl;
        cout << "\t+----------------------------------------------------------------------------------+" << endl << endl << endl;

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            choice = 0;
        }

        switch (choice) {
        case 1:
            int degree;
            double coeffsPol[1000];
            inputRangeForSquare(a, b);
            inputEpsilonForSquare(epsilon);
            inputDegreePolynom(degree);
            createPolynom(degree, coeffsPol);
            findExtremumsPol(coeffsPol, degree, a, b, epsilon);
            break;
        case 2:
            double coeffsDeg[3];
            inputRangeForDeg(a, b);
            inputEpsilonForSquare(epsilon);
            inputCoeffs3(coeffsDeg);
            findExtremumsDeg(coeffsDeg, a, b, epsilon);
            break;
        case 3:
            double coeffsInd[4];
            inputRangeForSquare(a, b);
            inputEpsilonForSquare(epsilon);
            inputCoeffs4(coeffsInd);
            findExtremumsInd(coeffsInd, a, b, epsilon);
            break;
        case 4:
            double coeffsLog[3];
            inputRangeForSquareLog(a, b);
            inputEpsilonForSquare(epsilon);
            inputCoeffsLog(coeffsLog, a, b);
            findExtremumsLog(coeffsLog, a, b, epsilon);
            break;
        case 5:
            double coeffsSin[4];
            inputRangeForSquare(a, b);
            inputEpsilonForSquare(epsilon);
            inputCoeffs4(coeffsSin);
            findExtremumsSin(coeffsSin, a, b, epsilon);
            break;
        case 6:
            double coeffsCos[4];
            inputRangeForSquare(a, b);
            inputEpsilonForSquare(epsilon);
            inputCoeffs4(coeffsCos);
            findExtremumsCos(coeffsCos, a, b, epsilon);
            break;
        case 7:
            cout << "Возврат назад..." << endl;
            Sleep(1000);
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 7);
}