#include "mainwindow.h"
#include "./ui_mainwindow.h"

void MainWindow::changeSavedMenuIndex(int newIndex)
{
    methodMenuIndexHolder = newIndex;
    /*
    qDebug() << newIndex;
    qDebug() << methodMenuIndexHolder;
    */
}

void MainWindow::dataTransferArg1()
{
    argVector[0] = arg1->text().toDouble();
    argVector[1] = arg2->text().toDouble();
    argVector[2] = arg3->text().toDouble();

    emit argsChanged();
}

void MainWindow::dataTransferArg2()
{
    argVector[1] = arg2->text().toDouble();

    emit argsChanged();
}

void MainWindow::dataTransferArg3()
{
    argVector[2] = arg3->text().toDouble();

    emit argsChanged();
}

void MainWindow::dynamicEquation()
{
    if(argVector[0] == 1)
    {
        arg1Equation->hide();
    }
    else arg1Equation->show();

    if(argVector[1] < 0)
    {
        firstSign->hide();
    }
    else firstSign->show();

    if(argVector[2] < 0)
    {
        secondSign->hide();
    }
    else secondSign->show();

    arg1Equation->setText(arg1->text());
    arg2Equation->setText(arg2->text());
    arg3Equation->setText(arg3->text());
}

void MainWindow::launchStep1()
{
    int pos = 0;                                                            //данная секция кода отвечает за "валидацию"
    //QVector <QString> argChecker;                                           //введённых пользователем значений
    argChecker.resize(3);

    argChecker[0] = arg1->text();
    argChecker[1] = arg2->text();
    argChecker[2] = arg3->text();

    //QVector <QValidator::State> validatorState;
    validatorState.resize(3);

    validatorState[0] = argValidator->validate(argChecker[0], pos);
    validatorState[1] = argValidator->validate(argChecker[1], pos);
    validatorState[2] = argValidator->validate(argChecker[2], pos);

    if(validatorState[0] != QValidator::Acceptable)
    {
        methodMenuIndexHolder = -2;
    }
    else if(validatorState[1] != QValidator::Acceptable)
    {
        methodMenuIndexHolder = -3;
    }
    else if(validatorState[2] != QValidator::Acceptable)
    {
        methodMenuIndexHolder = -4;
    }
    else roots = results(argVector);                    //вычисления производятся, только если все введённые аргументы соответствуют нормам

    emit engageStep2(argVector, roots, methodMenuIndexHolder);

    /*
    argVector[0] = arg1->text().toDouble();             //устаревший код, если метод dataTransfer работает безперебойно
    argVector[1] = arg2->text().toDouble();
    argVector[2] = arg3->text().toDouble();
    */
    /*
    qDebug() << argVector[0] << "\n";
    qDebug() << argVector[1] << "\n";
    qDebug() << argVector[2] << "\n";
    */

    //roots = results(argVector);

    /*
    qDebug() << roots[0] << "\n";                        //вроде бы, все считает правильно
    qDebug() << roots[1] << "\n";
    qDebug() << roots[2] << "\n";
    */
}


void MainWindow::launchStep2(QVector<double> argVector, QVector<double> roots, int menuIndex)
{
    if(menuIndex == -2)
    {
        resultTitle->setText("Введённое вами выражение не является квадратным (отсутствует X^2).");
    }

    if(menuIndex == 0)
    {
        resultTitle->setText("индекс = 0");
    }

    resultWindow->show();
}


QVector<double> MainWindow::results(QVector<double> &argVector)             //функция, вычисляющая корни
{
    QVector<double> roots;                  //Discr, root1, root2;
    roots.resize(3);                        // необходимо объявить размер массива, чтобы обращатся к какому-либо из его элементов

    roots[0] = pow(argVector[1], 2) - 4 * argVector[0] * argVector[2];

    if(roots[0] > 0)
    {
        roots[1] = (-(argVector[1]) + sqrt(roots[0])) / (2*argVector[0]);
        roots[2] = (-(argVector[1]) - sqrt(roots[0])) / (2*argVector[0]);
    }
    else if(roots[0] == 0)
    {
        roots[1] = -(argVector[1]) / (2*argVector[0]);
        roots[2] = roots[1];
    }
    else if(roots[0] < 0)
    {
        roots[1] = 0;
        roots[2] = 0;
    }
    else
    {
        roots[1] = 505;
        roots[2] = 505;
    }

    return roots;
}


void MainWindow::startingScreen()                                           //основная функция
{
    argVector.resize(3);                                                    //"объявляю" размер вектора заранее;

    mainWidget = new QWidget(this);                                         //"разлиновка" расположения элементов будущего приложения
    mainWidgetUpperPart = new QWidget;
    mainWidgetLowerPart = new QWidget;
    //mainWidget->setStyleSheet("background-color: purple;");

    this->setCentralWidget(mainWidget);

    int mWWidth = (this->width());
    int mWHeight = (this->height());

    QVBoxLayout *mainLayout = new QVBoxLayout;                              //разделение окна на верхнюю и нижнюю часть
    mainLayout->addWidget(mainWidgetUpperPart);
    mainLayout->addWidget(mainWidgetLowerPart);

    mainWidget->setLayout(mainLayout);


    QVBoxLayout *upperPartLayout = new QVBoxLayout;                         //расположение виджетов в верхней части экрана
    methodChoice = new QLabel;
    methodMenu = new QComboBox;
    methodMenuIndexHolder = -1;

    methodChoice->setText("Выберите метод решения");

    methodMenu->addItem("Решение через дискриминант");
    methodMenu->addItem("Решение по корням квадратного уравнения при чётном коэфициенте 'b'");
    methodMenu->addItem("Решение неполных квадратных уравнений");
    methodMenu->addItem("Решение используя частные соотношения коэфициентов");
    methodMenu->addItem("Иcпользование прямой и обратной теоремы Виета");
    methodMenu->addItem("Метод переброски");

    upperPartLayout->addWidget(methodChoice);
    upperPartLayout->addWidget(methodMenu);

    upperPartLayout->setContentsMargins(0.03 * mWWidth, 0.04 * mWHeight, 0.03 * mWWidth, 0.04 * mWHeight);
    //mainWidgetUpperPart->setStyleSheet("background-color: red;");         //для проверки расположения виджетов их можно красить следующим образом
    upperPartLayout->setAlignment(Qt::AlignTop);

    mainWidgetUpperPart->setLayout(upperPartLayout);

    connect(methodMenu, SIGNAL(currentIndexChanged(int)), this, SLOT(changeSavedMenuIndex(int)));       //при выборе пункта меню его индекс передаётся переменной 'methodMenuIndexHolder'


    mainWidgetLowerPartLeft = new QWidget;                                  //разделение нижней части экрана на левую и правую сторону
    mainWidgetLowerPartRight = new QWidget;

    QHBoxLayout *lowerPartLayout = new QHBoxLayout;
    lowerPartLayout->addWidget(mainWidgetLowerPartLeft);
    lowerPartLayout->addSpacing(0.03 * mWWidth);
    lowerPartLayout->addWidget(mainWidgetLowerPartRight);

    mainWidgetLowerPartLeft->setMaximumWidth(0.45 * mWWidth);
    mainWidgetLowerPartLeft->setMinimumWidth(0.45 * mWWidth);
    //mainWidgetLowerPartLeft->setStyleSheet("background-color: orange;");
    mainWidgetLowerPartRight->setMaximumWidth(0.45 * mWWidth);
    mainWidgetLowerPartRight->setMinimumWidth(0.45 * mWWidth);
    //mainWidgetLowerPartRight->setStyleSheet("background-color: lime;");

    lowerPartLayout->setContentsMargins(0.03 * mWWidth, 0.04 * mWHeight, 0.03 * mWWidth, 0.04 * mWHeight);

    lowerPartLayout->setAlignment(Qt::AlignJustify);

    mainWidgetLowerPart->setLayout(lowerPartLayout);


    QVBoxLayout* lowerPartLeftLayout = new QVBoxLayout;                     //расположение виджетов в нижней левой части экрана
    argSection = new QLabel;
    arg1Widget = new QWidget;
    arg2Widget = new QWidget;
    arg3Widget = new QWidget;

    argValidator = new QDoubleValidator(-100000, 100000, 10);

    argSection->setText("Введение аргументов уравнения:");

    lowerPartLeftLayout->addWidget(argSection);
    lowerPartLeftLayout->addSpacing(5);
    lowerPartLeftLayout->addWidget(arg1Widget);
    lowerPartLeftLayout->addSpacing(5);
    lowerPartLeftLayout->addWidget(arg2Widget);
    lowerPartLeftLayout->addSpacing(5);
    lowerPartLeftLayout->addWidget(arg3Widget);

    lowerPartLeftLayout->setAlignment(Qt::AlignLeft);

    mainWidgetLowerPartLeft->setLayout(lowerPartLeftLayout);


    QHBoxLayout* lowerPartLeftLayoutRow1 = new QHBoxLayout;                 //виджет, отвечающий за первую строку в нижней левой части экрана
    arg1Description = new QLabel;
    arg1 = new QLineEdit;

    arg1->setValidator(argValidator);
    arg1->setMaxLength(10);
    arg1Description->setText("Первый аргумент:");
    arg1->setMaximumWidth(90);
    arg1->setToolTip("Принимает числа от '-100000' до '100000'");

    lowerPartLeftLayoutRow1->addWidget(arg1Description);
    lowerPartLeftLayoutRow1->addWidget(arg1);

    lowerPartLeftLayoutRow1->setAlignment(Qt::AlignLeft);

    arg1Widget->setLayout(lowerPartLeftLayoutRow1);


    QHBoxLayout* lowerPartLeftLayoutRow2 = new QHBoxLayout;                 //виджет, отвечающий за вторую строку в нижней левой части экрана
    arg2Description = new QLabel;
    arg2 = new QLineEdit;

    arg2->setValidator(argValidator);
    arg2->setMaxLength(10);
    arg2Description->setText("Второй аргумент:");
    arg2->setMaximumWidth(90);
    arg2->setToolTip("Принимает числа от '-100000' до '100000'");

    lowerPartLeftLayoutRow2->addWidget(arg2Description);
    lowerPartLeftLayoutRow2->addWidget(arg2);

    lowerPartLeftLayoutRow2->setAlignment(Qt::AlignLeft);

    arg2Widget->setLayout(lowerPartLeftLayoutRow2);


    QHBoxLayout* lowerPartLeftLayoutRow3 = new QHBoxLayout;                 //виджет, отвечающий за третью строку в нижней левой части экрана
    arg3Description = new QLabel;
    arg3 = new QLineEdit;

    arg3->setValidator(argValidator);
    arg3->setMaxLength(10);
    arg3Description->setText("Третий аргумент:");
    arg3->setMaximumWidth(90);
    arg3->setToolTip("Принимает числа от '-100000' до '100000'");

    lowerPartLeftLayoutRow3->addWidget(arg3Description);
    lowerPartLeftLayoutRow3->addWidget(arg3);

    lowerPartLeftLayoutRow3->setAlignment(Qt::AlignLeft);

    arg3Widget->setLayout(lowerPartLeftLayoutRow3);


    QVBoxLayout* lowerPartRightLayout = new QVBoxLayout;                    //расположение виджетов в нижней правой части экрана
    equation = new QWidget;
    launchButton = new QPushButton;

    launchButton->setText("Вычислить");
    launchButton->setMinimumWidth(90);

    lowerPartRightLayout->addWidget(equation);
    lowerPartRightLayout->addWidget(launchButton);

    lowerPartRightLayout->setAlignment(Qt::AlignRight);
    lowerPartRightLayout->setAlignment(equation, Qt::AlignTop);
    lowerPartRightLayout->setAlignment(launchButton, Qt::AlignBottom);

    mainWidgetLowerPartRight->setLayout(lowerPartRightLayout);

    connect(this, SIGNAL(argsChanged()), this, SLOT(dynamicEquation()));     //слот dataTransfer издаёт сигнал, вызывающий изменение динамического уравнения

    connect(arg1, SIGNAL(textEdited(QString)), this, SLOT(dataTransferArg1()));   //любое изменение arg меняет уравнение в правой части экрана
    connect(arg2, SIGNAL(textEdited(QString)), this, SLOT(dataTransferArg2()));
    connect(arg3, SIGNAL(textEdited(QString)), this, SLOT(dataTransferArg3()));

    connect(this, SIGNAL(engageStep2(QVector<double>,QVector<double>,int)), this, SLOT(launchStep2(QVector<double>,QVector<double>,int)));
    connect(launchButton, SIGNAL(clicked(bool)), this, SLOT(launchStep1()));


    QHBoxLayout* lowerPartRightLayoutEquation = new QHBoxLayout;            //расположение виджетов в уравнении
    arg1Equation = new QLabel;
    firstX = new QLabel;
    powNum = new QLabel;
    firstSign = new QLabel;
    arg2Equation = new QLabel;
    secondX = new QLabel;
    secondSign = new QLabel;
    arg3Equation = new QLabel;
    equality = new QLabel;

    arg1Equation->setText("0");
    firstX->setText("X");
    powNum->setText("2");
    firstSign->setText("+");
    arg2Equation->setText("0");
    secondX->setText("X");
    secondSign->setText("+");
    arg3Equation->setText("0");
    equality->setText("= 0");

    QFont powFont = powNum->font();                                         // изменяю размер шрифта элемента, отвечающего за отображение степени X
    powFont.setPointSize(5);
    powNum->setFont(powFont);

    lowerPartRightLayoutEquation->addWidget(arg1Equation);
    lowerPartRightLayoutEquation->addWidget(firstX);
    lowerPartRightLayoutEquation->addWidget(powNum);
    lowerPartRightLayoutEquation->addWidget(firstSign);
    lowerPartRightLayoutEquation->addWidget(arg2Equation);
    lowerPartRightLayoutEquation->addWidget(secondX);
    lowerPartRightLayoutEquation->addWidget(secondSign);
    lowerPartRightLayoutEquation->addWidget(arg3Equation);
    lowerPartRightLayoutEquation->addWidget(equality);

    //lowerPartRightLayoutEquation->setContentsMargins(0, 0, 0, 50);
    lowerPartRightLayoutEquation->setSpacing(0);
    lowerPartRightLayoutEquation->setAlignment(Qt::AlignRight);
    lowerPartRightLayoutEquation->setAlignment(powNum, Qt::AlignTop);

    equation->setLayout(lowerPartRightLayoutEquation);


    resultWindow = new QWidget;                                         //оформление окна вывода результатов

    resultWindow->setMinimumSize(0.5 * mWWidth, 0.5 * mWHeight);
    resultWindow->resize(0.5 * mWWidth, 0.5 * mWHeight);

    QVBoxLayout* resultWindowMain = new QVBoxLayout;
    resultTitle = new QLabel;

    resultWindowMain->addWidget(resultTitle);

    resultWindowMain->setAlignment(Qt::AlignLeading);

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setMinimumSize(600, 400);

    this->resize(600, 400);

    startingScreen();
}

MainWindow::~MainWindow()
{
    delete ui;
}
