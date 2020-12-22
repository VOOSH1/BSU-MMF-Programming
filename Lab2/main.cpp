#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

using namespace std;

sf::RenderWindow window(sf::VideoMode(800, 800), "Figures");

class Point {
public:
    float x;
    float y;

    Point() {
        x = 0;
        y = 0;
    }

    Point(const Point& point) {
        this->x = point.x;
        this->y = point.y;
    }

    Point(float x, float y) {
        this->x = x;
        this->y = y;
    }

    Point& operator=(const Point& point) {
        if (this == &point)
            return *this;
        this->x = point.x;
        this->y = point.y;
        return *this;
    }
};

class Figure {
public:
    Figure() {};

    virtual void cinNew() {};
};

class Square : public Figure {
public:
    float ldx;
    float ldy;
    float sqr_len;
    float rotation_angle;

    Square() {};

    Square(float, float, float, float rotation_angle = 0);

    Square operator+(const Point& point) const {
        Square ans(*this);
        ans.ldx += point.x;
        ans.ldy += point.y;
        return ans;
    }

    Square& operator+=(const Point& point) {
        this->ldx += point.x;
        this->ldy += point.y;
        return *this;
    }

    Square operator-(const Point& point) const {
        Square ans(*this);
        ans.ldx -= point.x;
        ans.ldy -= point.y;
        return ans;
    }

    Square& operator-=(const Point& point) {
        this->ldx -= point.x;
        this->ldy -= point.y;
        return *this;
    }

    Square& operator=(const Square& square) {
        if (this == &square)
            return *this;
        this->ldx = square.ldx;
        this->ldy = square.ldy;
        this->sqr_len = square.sqr_len;
        this->rotation_angle = square.rotation_angle;
        return *this;
    }

    Square& operator*=(float new_len) {
        if (new_len > 0)
            this->sqr_len = new_len;
        else
            cout << "Ошибка! Длина должна быть положительной" << endl;
        return *this;
    }

    Square operator*(float new_len) {
        Square ans(*this);
        if (new_len > 0)
            ans.sqr_len = new_len;
        else
            cout << "Ошибка! Длина должна быть положительной" << endl;
        return ans;
    }

    Square& operator/=(float angle) {
        while (angle < 0)
            angle += 360;
        this->rotation_angle += angle;
        while (this->rotation_angle > 360)
            this->rotation_angle -= 360;
        return *this;
    }

    Square operator/(float angle) {
        Square ans(*this);
        while (angle < 0)
            angle += 360;
        ans.rotation_angle += angle;
        while (ans.rotation_angle > 360)
            ans.rotation_angle -= 360;
        return ans;
    }

    float area_sqr();

    void moveTo(float X, float Y);

    void rotate(float angle);

    void change_len(float new_len);

    float perim_sqr();

    float diagonal_sqr();

    void cinNew() override;
};

Square::Square(float ldX, float ldY, float length, float rotation_angle) {
    this->ldx = ldX;
    this->ldy = ldY;
    this->sqr_len = length;
    this->rotation_angle = rotation_angle;
}

void Square::moveTo(float X, float Y) {
    ldx = X;
    ldy = Y;
}

float Square::perim_sqr() {
    return sqr_len * 4;
}

float Square::area_sqr() {
    return sqr_len * sqr_len;
}

float Square::diagonal_sqr() {
    return sqrt(sqr_len * sqr_len * 2);
}

void Square::cinNew() {
    int a = 0, b = 0;
    sf::RectangleShape rectangle1(sf::Vector2f(this->sqr_len, this->sqr_len));
    rectangle1.setFillColor(sf::Color::Black);
    rectangle1.setPosition(this->ldx, this->ldy);
    rectangle1.setRotation(this->rotation_angle);
    window.draw(rectangle1);
    cout << "Периметр квадрата: " << fixed << this->perim_sqr() << "\nПлощадь квадрата: " << fixed << this->area_sqr()
         << "\nДиагональ квадрата: " << fixed << this->diagonal_sqr() << "\nНачальные координаты квадрата: " << endl;
    cout << "Координаты левого нижнего угла: " << "X: " << this->ldx << " Y: " << this->ldy << endl;
    cout << "Координаты правого нижнего угла: " << "X: " << this->ldx + sqr_len << " Y: " << this->ldy << endl;
    cout << "Координаты правого верхнего угла: " << "X: " << this->ldx + sqr_len << " Y: " << this->ldy + sqr_len
         << endl;
    cout << "Координаты левого верхнего угла: " << "X: " << this->ldx << " Y: " << this->ldy + sqr_len << endl;
    a = this->ldx;
    b = this->ldy;
    float new_x, new_y, new_len, angle;
    cout << "\nВведите координаты для перемещения квадрата: " << endl;
    cin >> new_x >> new_y;
    this->moveTo(new_x, new_y);
    cout << "Введите новое значение длины стороны квадрата: " << endl;
    cin >> new_len;
    this->change_len(new_len);
    cout << "Введите угол поворота (в градусах): " << endl;
    cin >> angle;
    this->rotate(angle);
    sf::RectangleShape rectangle2(sf::Vector2f(this->sqr_len, this->sqr_len));
    rectangle2.setFillColor(sf::Color::Red);
    rectangle2.setPosition(this->ldx, this->ldy);
    rectangle2.setRotation(this->rotation_angle);
    window.draw(rectangle2);
    cout << "Координаты левого нижнего угла: " << "X: " << this->ldx << " Y: " << this->ldy << endl;
    cout << "Координаты правого нижнего угла: " << "X: " << this->ldx + sqr_len << " Y: " << this->ldy << endl;
    cout << "Координаты правого верхнего угла: " << "X: " << this->ldx + sqr_len << " Y: " << this->ldy + sqr_len
         << endl;
    cout << "Координаты левого верхнего угла: " << "X: " << this->ldx << " Y: " << this->ldy + sqr_len << endl;

    cout << "Расстояние перемещения " << "X: " << this->ldx - a << " " << " Y: " << this->ldy - b << endl;
}

void Square::rotate(float angle) {
    while (angle < 0)
        angle += 360;
    this->rotation_angle += angle;
    while (this->rotation_angle > 360)
        this->rotation_angle -= 360;
}

void Square::change_len(float new_len) {
    if (new_len > 0)
        this->sqr_len = new_len;
    else
        cout << "Ошибка! Длина должна быть положительной" << endl;
}

class Rectangle : public Figure {
public:
    float ldx;
    float ldy;
    float Length_A;
    float Length_B;
    float rotation_angle;

    Rectangle() {};

    Rectangle(float, float, float, float, float rotation_angle = 0);

    Rectangle operator+(const Point& point) const {
        Rectangle ans(*this);
        ans.ldx += point.x;
        ans.ldy += point.y;
        return ans;
    }

    Rectangle& operator+=(const Point& point) {
        this->ldx += point.x;
        this->ldy += point.y;
        return *this;
    }

    Rectangle operator-(const Point& point) const {
        Rectangle ans(*this);
        ans.ldx -= point.x;
        ans.ldy -= point.y;
        return ans;
    }

    Rectangle& operator-=(const Point& point) {
        this->ldx -= point.x;
        this->ldy -= point.y;
        return *this;
    }

    Rectangle& operator=(const Rectangle& rectangle) {
        if (this == &rectangle)
            return *this;
        this->ldx = rectangle.ldx;
        this->ldy = rectangle.ldy;
        this->Length_A = rectangle.Length_A;
        this->Length_B = rectangle.Length_B;
        return *this;
    }

    Rectangle& operator*=(pair<float, float> new_len) {
        if (new_len.first > 0 && new_len.second > 0) {
            this->Length_A = new_len.first;
            this->Length_B = new_len.second;
        } else
            cout << "Ошибка! Длины должны быть положительными" << endl;
        return *this;
    }

    Rectangle operator*(pair<float, float> new_len) {
        Rectangle ans(*this);
        if (new_len.first > 0 && new_len.second > 0) {
            ans.Length_A = new_len.first;
            ans.Length_B = new_len.second;
        } else
            cout << "Ошибка! Длины должны быть положительными" << endl;
        return ans;
    }

    Rectangle& operator/=(float angle) {
        while (angle < 0)
            angle += 360;
        this->rotation_angle += angle;
        while (this->rotation_angle > 360)
            this->rotation_angle -= 360;
        return *this;
    }

    Rectangle operator/(float angle) {
        Rectangle ans(*this);
        while (angle < 0)
            angle += 360;
        ans.rotation_angle += angle;
        while (ans.rotation_angle > 360)
            ans.rotation_angle -= 360;
        return ans;
    }

    float area_rec();

    void moveTo(float X, float Y);

    void rotate(float angle);

    void change_len(float new_len1, float new_len2);

    void cinNew() override;

    float perim_rec();

    float diagonal_rec();
};

Rectangle::Rectangle(float ldX, float ldY, float length_A, float length_B, float rotation_angle) {
    this->ldx = ldX;
    this->ldy = ldY;
    this->Length_A = length_A;
    this->Length_B = length_B;
    this->rotation_angle = rotation_angle;
}

float Rectangle::area_rec() {
    return Length_A * Length_B;
}

void Rectangle::moveTo(float X, float Y) {
    ldx = X;
    ldy = Y;
}

float Rectangle::perim_rec() {
    return (Length_A + Length_B) * 2;
}

float Rectangle::diagonal_rec() {
    return sqrt(Length_A * Length_A + Length_B * Length_B);
}

void Rectangle::cinNew() {
    sf::RectangleShape rectangle1(sf::Vector2f(this->Length_A, this->Length_B));
    rectangle1.setFillColor(sf::Color::Black);
    rectangle1.setPosition(this->ldx, this->ldy);
    rectangle1.setRotation(this->rotation_angle);
    window.draw(rectangle1);
    cout << "Периметр прямоугольника: " << fixed << this->perim_rec()
         << "\nПлощадь прямоугольника: " << fixed << this->area_rec()
         << "\nДиагональ прямоугольника: " << fixed << this->diagonal_rec()
         << "\nНачальные координаты прямоугольника: " << endl;
    cout << "Координаты левого угла:  " << "X:" << this->ldx << " Y: " << this->ldy << endl;
    cout << "Координаты правого нижнего угла: " << "X: " << this->ldx + this->Length_B << " Y: " << this->ldy << endl;
    cout << "Координаты правого верхнего угла: " << "X: " << this->ldx + this->Length_B << " Y: "
         << this->ldy + this->Length_A << endl;
    cout << "Координаты левого верхнего угла: " << "X: " << this->ldx << " Y: " << this->ldy + this->Length_A << endl;
    float new_x, new_y, new_len1, new_len2, angle;
    cout << "\nВведите координаты для перемещения прямоугольника: " << endl;
    cin >> new_x >> new_y;
    this->moveTo(new_x, new_y);
    cout << "Введите новые значения длин сторон прямоугольника: " << endl;
    cin >> new_len1 >> new_len2;
    this->change_len(new_len1, new_len2);
    cout << "Введите угол поворота (в градусах): " << endl;
    cin >> angle;
    this->rotate(angle);
    sf::RectangleShape rectangle2(sf::Vector2f(this->Length_A, this->Length_B));
    rectangle2.setFillColor(sf::Color::Red);
    rectangle2.setPosition(this->ldx, this->ldy);
    rectangle2.setRotation(this->rotation_angle);
    window.draw(rectangle2);
    cout << "Координаты угла X: " << this->ldx << " Y: " << this->ldy << endl;
    cout << "Координаты правого нижнего угла:" << " X: " << this->ldx + this->Length_B << " Y: " << this->ldy << endl;
    cout << "Координаты правого верхнего угла:" << " X:" << this->ldx + this->Length_B << " Y: "
         << this->ldy + this->Length_A << endl;
    cout << "Координаты левого верхнего угла:" << " X:" << this->ldx << " Y: " << this->ldy + this->Length_A << endl;
}

void Rectangle::rotate(float angle) {
    while (angle < 0)
        angle += 360;
    this->rotation_angle += angle;
    while (this->rotation_angle > 360)
        this->rotation_angle -= 360;
}

void Rectangle::change_len(float new_len1, float new_len2) {
    if (new_len1 > 0 && new_len2 > 0) {
        this->Length_A = new_len1;
        this->Length_B = new_len2;
    } else
        cout << "Ошибка! Длины должны быть положительными" << endl;
}

class Circle : public Figure {
public:
    float X;
    float Y;
    float R;

    Circle() {};

    Circle(float, float, float);

    Circle operator+(const Point& point) const {
        Circle ans(*this);
        ans.X += point.x;
        ans.Y += point.y;
        return ans;
    }

    Circle& operator+=(const Point& point) {
        this->X += point.x;
        this->Y += point.y;
        return *this;
    }

    Circle operator-(const Point& point) const {
        Circle ans(*this);
        ans.X -= point.x;
        ans.Y -= point.y;
        return ans;
    }

    Circle& operator-=(const Point& point) {
        this->X -= point.x;
        this->Y -= point.y;
        return *this;
    }

    Circle& operator=(const Circle& circle) {
        if (this == &circle)
            return *this;
        this->X = circle.X;
        this->Y = circle.Y;
        this->R = circle.R;
        return *this;
    }

    Circle& operator*=(float new_R) {
        if (new_R > 0)
            this->R = new_R;
        else
            cout << "Ошибка! Длина должна быть положительной" << endl;
        return *this;
    }

    Circle operator*(float new_R) {
        Circle ans(*this);
        if (new_R > 0)
            ans.R = new_R;
        else
            cout << "Ошибка! Длина должна быть положительной" << endl;
        return ans;
    }

    void moveTo(float x, float y);

    void change_r(float new_R);

    float area_crl();

    float perim_crl();

    void cinNew() override;
};

Circle::Circle(float x, float y, float r) {
    this->X = x;
    this->Y = y;
    this->R = r;
}

void Circle::moveTo(float x, float y) {
    X = x;
    Y = y;
}

float Circle::area_crl() {
    return (3.14 * R * R);
}

float Circle::perim_crl() {
    return (2 * 3.14 * R);
}

void Circle::cinNew() {
    sf::CircleShape circle1(this->R);
    circle1.setFillColor(sf::Color::Black);
    circle1.setPosition(this->X, this->Y);
    window.draw(circle1);
    cout << "Периметр круга: " << fixed << this->perim_crl() << "\nПлощадь круга: " << fixed << this->area_crl();
    float new_X, new_Y, new_R;
    cout << "\nВведите координаты для перемещения круга: " << endl;
    cin >> new_X >> new_Y;
    this->moveTo(new_X, new_Y);
    cout << "Введите новое значение радиуса: " << endl;
    cin >> new_R;
    this->change_r(new_R);
    sf::CircleShape circle2(this->R);
    circle2.setFillColor(sf::Color::Red);
    circle2.setPosition(this->X, this->Y);
    window.draw(circle2);
    cout << "Координаты центра X: " << this->X << " Y: " << this->Y << endl;
}

void Circle::change_r(float new_R) {
    if (new_R > 0) {
        this->R = new_R;
    } else
        cout << "Ошибка! Длины должны быть положительными" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        int vibor;

        float sqr_x, sqr_y, sqr_len;
        float rec_x, rec_y, rec_len_A, rec_len_B;
        float X, Y, R;
        window.clear(sf::Color::White);
        while (1) {
            cout << "\n__________________________________________" << endl;
            cout << "Введите номер пукта: \n";
            cout << "--->1 Тестировать квадрат" << endl;
            cout << "--->2 Тестировать прямоугольник" << endl;
            cout << "--->3 Тестировать круг" << endl;
            cout << "--->4 Создать массив из трёх элементов" << endl;
            cout << "--->5 Закрыть программу" << endl;
            cin >> vibor;
            window.clear(sf::Color::White);
            switch (vibor) {
                case 1: {
                    cout << "\nВведите координаты начального угла квадрата X и Y: " << endl;
                    cin >> sqr_x >> sqr_y;
                    cout << "Введите длину ребра: " << endl;
                    cin >> sqr_len;
                    if (sqr_len <= 0) {
                        while (sqr_len <= 0) {
                            cout << "Длинна ребра должна быть больше нуля!" << endl;
                            cin >> sqr_len;
                        }
                    }
                    Square sqr(sqr_x, sqr_y, sqr_len);
                    cout.precision(2);
                    sqr.cinNew();
                    window.display();
                    break;
                }
                case 2: {
                    cout << "\nВведите координаты левого угла прямоугольника X и Y:" << endl;
                    cin >> rec_x >> rec_y;
                    cout << "Введите длинну рёбер A и B: " << endl;
                    cin >> rec_len_A >> rec_len_B;
                    if (rec_len_A <= 0 || rec_len_B <= 0) {
                        while (rec_len_A <= 0 || rec_len_B <= 0) {
                            cout << "Длинна ребра должна быть больше нуля!" << endl;
                            cin >> rec_len_A >> rec_len_B;
                        }
                    }
                    Rectangle rec(rec_x, rec_y, rec_len_A, rec_len_B);
                    cout.precision(2);
                    rec.cinNew();
                    window.display();
                    break;
                }
                case 3: {
                    cout << "\nВведите координаты центра круга X и Y: " << endl;
                    cin >> X >> Y;
                    cout << "Введите длинну радиуса: " << endl;
                    cin >> R;
                    if (R <= 0) {
                        while (R <= 0) {
                            cout << "Длинна радиуса должна быть больше нуля!" << endl;
                            cin >> R;
                        }
                    }
                    Circle crl(X, Y, R);
                    cout.precision(2);
                    crl.cinNew();
                    window.display();
                    break;
                }
                case 4: {
                    cout << "\nВведите координаты центра круга X и Y: " << endl;
                    cin >> X >> Y;
                    cout << "Введите длинну радиуса: " << endl;
                    cin >> R;
                    if (R <= 0) {
                        while (R <= 0) {
                            cout << "Длинна радиуса должна быть больше нуля!" << endl;
                            cin >> R;
                        }
                    }
                    cout << "\nВведите координаты начального угла квадрата X и Y: " << endl;
                    cin >> sqr_x >> sqr_y;
                    cout << "Введите длину ребра: " << endl;
                    cin >> sqr_len;
                    if (sqr_len <= 0) {
                        while (sqr_len <= 0) {
                            cout << "Длинна ребра должна быть больше нуля!" << endl;
                            cin >> sqr_len;
                        }
                    }
                    cout << "\nВведите координаты левого угла прямоугольника X и Y:" << endl;
                    cin >> rec_x >> rec_y;
                    cout << "Введите длинну рёбер A и B: " << endl;
                    cin >> rec_len_A >> rec_len_B;
                    if (rec_len_A <= 0 || rec_len_B <= 0) {
                        while (rec_len_A <= 0 || rec_len_B <= 0) {
                            cout << "Длинна ребра должна быть больше нуля!" << endl;
                            cin >> rec_len_A >> rec_len_B;
                        }
                    }
                    cout << endl << endl;
                    Figure** arr = new Figure* [3];
                    arr[0] = new Circle(X, Y, R);
                    arr[1] = new Square(sqr_x, sqr_y, sqr_len);
                    arr[2] = new Rectangle(rec_x, rec_y, rec_len_A, rec_len_B);
                    cout.precision(2);
                    for (int i = 0; i < 3; i++) {
                        arr[i]->cinNew();
                        cout << endl;
                    }
                    window.display();
                    for (int i = 0; i < 3; i++)
                        delete arr[i];
                    delete[] arr;
                    break;
                }
                case 5:
                    system("pause");
                    return 0;
                default:
                    break;
            }
        }
    }
    system("pause");
    return 0;
}