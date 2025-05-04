#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<vector>
#include<cmath>

#include <QMainWindow>
#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private:
    Ui::MainWindow *ui;


    void startingScreen();                              //основная функция


    QVector<double> results (QVector<double> &argVector);       //функция, вычисляющая корни


    QVector<double> argVector;                          //arg1, arg2, arg3;     вектор аргументов, введённых пользователем;
    QVector<double> roots;                              //Discr, root1, root2;  вектор, хранящий решение уравнения;

    QVector <QString> argChecker;                       //вектор принимающий в себя значения аргументов, введённых пользователем в типе QString (для последующей валидации);
    QVector <QValidator::State> validatorState;         //вектор, принимающий в себя значение, возвращаемое валидатором;

    QWidget* mainWidget;                                //базовые разделения областей
    QWidget* mainWidgetUpperPart;
    QWidget* mainWidgetLowerPart;
    QWidget* mainWidgetLowerPartLeft;
    QWidget* mainWidgetLowerPartRight;

    //QPushButton* methodMenuButton;

    QComboBox* methodMenu;                               //виджеты верхней части экрана
    QLabel* methodChoice;
    int methodMenuIndexHolder;

    /*
    QAction* method1;
    QAction* method2;
    QAction* method3;
    QAction* method4;
    QAction* method5;
    QAction* method6;
    */

    /*
    method1 = new QAction;
    method2 = new QAction;
    method3 = new QAction;
    method4 = new QAction;
    method5 = new QAction;
    method6 = new QAction;
    */

    /*
    methodMenu->addItem(method1);                                         //рассмотри возможность использования группы для таких типов данных
    method1->setText("Решение через дискриминант");
    methodMenu->addItem(method2);
    method2->setText("Решение по корням квадратного уравнения при чётном коэфициенте 'b'");
    methodMenu->addItem(method3);
    method3->setText("Решение неполных квадратных уравнений");
    methodMenu->addItem(method4);
    method4->setText("Решение используя частные соотношения коэфициентов");
    methodMenu->addItem(method5);
    method5->setText("Иcпользование прямой и обратной теоремы Виета");
    methodMenu->addItem(method6);
    method6->setText("Метод переброски");
    */

    //methodMenu->setText("Выберите метод решения квадратного уравнения");
    //methodMenuButton->show();

    QLabel* argSection;                             //виджеты нижней левой части экрана
    QWidget* arg1Widget;
    QWidget* arg2Widget;
    QWidget* arg3Widget;

    QDoubleValidator* argValidator;

    QLineEdit* arg1;                                //виджеты строк аргументов
    QLineEdit* arg2;
    QLineEdit* arg3;
    QLabel* arg1Description;
    QLabel* arg2Description;
    QLabel* arg3Description;

    QWidget* equation;                               //виджеты нижней правой части экрана
    QPushButton* launchButton;

    QLabel* arg1Equation;                          //виджеты, входящие в состав динамической конструкции уравнения
    QLabel* firstX;
    QLabel* powNum;
    QLabel* firstSign;
    QLabel* arg2Equation;
    QLabel* secondX;
    QLabel* secondSign;
    QLabel* arg3Equation;
    QLabel* equality;


    QWidget* resultWindow;                          //новое окно, в котором будет заключаться решение уравнения и его виджеты
    QLabel* resultTitle;


signals:
    void argsChanged();

    void engageStep2(QVector<double> argVector, QVector<double> roots, int menuIndex);

private slots:
    void changeSavedMenuIndex(int newIndex);        //меняет сохранённый индекс выбранного пункта меню

    void dataTransferArg1();                            //передаёт информацию из конкретного arg в массив argVector
    void dataTransferArg2();
    void dataTransferArg3();

    void dynamicEquation();                         //динамическое изменение equation с целью отображения текущего уравнения

    void launchStep1();

    void launchStep2(QVector<double> argVector, QVector<double> roots, int menuIndex);

};
#endif // MAINWINDOW_H
