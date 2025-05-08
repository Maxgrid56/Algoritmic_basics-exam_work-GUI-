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

    int mWWidth;                                        //переменные, хранящие в себе размеры основного окна
    int mWHeight;

    QVector<double> results (QVector<double> &argVector);       //функция, вычисляющая корни

    void extraLabelsHide();                             //скрывает лейблы, используемые  только в 5-м и 6-м методах
    void extraLabelsShow(int choice);                              //показывает скрытые лейблы

    void method1();
    void method2();
    void method3();
    void method4();
    void method5();
    void method6();

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
    QPushButton* argCleanerButton;

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
    QVBoxLayout* resultWindowMain;
    QLabel* resultTitle;
    QLabel* resultStep1;
    QLabel* resultStep2;
    QLabel* resultStep3;
    QLabel* resultStep4;
    QLabel* resultStep5;
    QLabel* resultStep6;
    QLabel* resultAnswer;

    QLabel* resultStep7;
    QLabel* resultStep8;
    QLabel* resultStep9;
    QLabel* resultStep10;
    QLabel* resultStep11;
    QLabel* resultStep12;
    QLabel* resultStep13;
    QLabel* resultStep14;
    QLabel* resultStep15;
    QLabel* resultStep16;
    QLabel* resultStep17;
    QLabel* resultStep18;
    QLabel* resultStep19;
    QLabel* resultStep20;
    QLabel* resultStep21;
    QLabel* resultStep22;
    QLabel* resultStep23;
    QLabel* resultStep24;
    QLabel* resultStep25;
    QLabel* resultStep26;
    QLabel* resultStep27;
    QLabel* resultStep28;
    QLabel* resultStep29;
    QLabel* resultStep30;
    QLabel* resultStep31;
    QLabel* resultStep32;
    QLabel* resultStep33;
    QLabel* resultStep34;

signals:
    void arg1Changed();
    void arg2Changed();
    void arg3Changed();

    void engageStep2();

private slots:
    void argCleaner();                              //очищает ввод пользователя

    void dataTransferArg1();                        //передаёт информацию из конкретного arg в массив argVector
    void dataTransferArg2();
    void dataTransferArg3();

    void dynamicEquationArg1();                         //динамическое изменение equation с целью отображения текущего уравнения
    void dynamicEquationArg2();
    void dynamicEquationArg3();

    void launchStep1();

    void launchStep2();

};
#endif // MAINWINDOW_H
