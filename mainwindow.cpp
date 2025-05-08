#include "mainwindow.h"
#include "./ui_mainwindow.h"

void MainWindow::argCleaner()
{
    arg1->clear();
    arg2->clear();
    arg3->clear();
}

void MainWindow::dataTransferArg1()
{
    argVector[0] = arg1->text().toDouble();

    emit arg1Changed();
}

void MainWindow::dataTransferArg2()
{
    argVector[1] = arg2->text().toDouble();

    emit arg2Changed();
}

void MainWindow::dataTransferArg3()
{
    argVector[2] = arg3->text().toDouble();

    emit arg3Changed();
}

void MainWindow::dynamicEquationArg1()
{
    if(argVector[0] == 1)
    {
        arg1Equation->hide();
    }
    else arg1Equation->show();

    arg1Equation->setText(arg1->text());
}

void MainWindow::dynamicEquationArg2()
{

    if(argVector[1] < 0)
    {
        firstSign->hide();
    }
    else firstSign->show();

    if(argVector[1] == 1)
    {
        arg2Equation->hide();
    }
    else arg2Equation->show();

    arg2Equation->setText(arg2->text());

}

void MainWindow::dynamicEquationArg3()
{
    if(argVector[2] < 0)
    {
        secondSign->hide();
    }
    else secondSign->show();

    arg3Equation->setText(arg3->text());
}

void MainWindow::launchStep1()
{
    int pos = 0;                                                            //данная секция кода отвечает за "валидацию"
    //QVector <QString> argChecker;                                           //введённых пользователем значений
                                                                            //реши проблему того, что при запуске с незаполнеными аргументами ошибка о невалидизации будет выскакивать, пока не сменишь метод.

    methodMenuIndexHolder = methodMenu->currentIndex();

    argChecker[0] = 0;
    argChecker[1] = 0;
    argChecker[2] = 0;

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

    emit engageStep2();

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

void MainWindow::extraLabelsHide()
{
    resultStep7->hide();
    resultStep8->hide();
    resultStep9->hide();
    resultStep10->hide();
    resultStep11->hide();
    resultStep12->hide();
    resultStep13->hide();
    resultStep14->hide();
    resultStep15->hide();
    resultStep16->hide();
    resultStep17->hide();
    resultStep18->hide();
    resultStep19->hide();
    resultStep20->hide();
    resultStep21->hide();
    resultStep22->hide();
    resultStep23->hide();
    resultStep24->hide();
    resultStep25->hide();
    resultStep26->hide();
    resultStep27->hide();
    resultStep28->hide();
    resultStep29->hide();
    resultStep30->hide();
    resultStep31->hide();
    resultStep32->hide();
    resultStep33->hide();
    resultStep34->hide();
}

void MainWindow::extraLabelsShow(int choice)
{
    if(choice == 0)
    {
        resultStep7->show();
        resultStep8->show();
        resultStep9->show();
        resultStep10->show();
        resultStep11->show();
        resultStep12->show();
        resultStep13->show();
        resultStep14->show();
        resultStep15->show();
        resultStep16->show();
        resultStep17->show();
        resultStep18->show();
        resultStep19->show();
        resultStep20->show();
        resultStep21->show();
        resultStep22->show();
        resultStep23->show();
        resultStep24->show();
        resultStep25->hide();
        resultStep26->hide();
        resultStep27->hide();
        resultStep28->hide();
        resultStep29->hide();
        resultStep30->hide();
        resultStep31->hide();
        resultStep32->hide();
        resultStep33->hide();
        resultStep34->hide();
    }
    else
    {
        resultStep7->show();
        resultStep8->show();
        resultStep9->show();
        resultStep10->show();
        resultStep11->show();
        resultStep12->show();
        resultStep13->show();
        resultStep14->show();
        resultStep15->show();
        resultStep16->show();
        resultStep17->show();
        resultStep18->show();
        resultStep19->show();
        resultStep20->show();
        resultStep21->show();
        resultStep22->show();
        resultStep23->show();
        resultStep24->show();
        resultStep25->show();
        resultStep26->show();
        resultStep27->show();
        resultStep28->show();
        resultStep29->show();
        resultStep30->show();
        resultStep31->show();
        resultStep32->show();
        resultStep33->show();
        resultStep34->show();
    }
    resultStep7->clear();
    resultStep8->clear();
    resultStep9->clear();
    resultStep10->clear();
    resultStep11->clear();
    resultStep12->clear();
    resultStep13->clear();
    resultStep14->clear();
    resultStep15->clear();
    resultStep16->clear();
    resultStep17->clear();
    resultStep18->clear();
    resultStep19->clear();
    resultStep20->clear();
    resultStep21->clear();
    resultStep22->clear();
    resultStep23->clear();
    resultStep24->clear();
    resultStep25->clear();
    resultStep26->clear();
    resultStep27->clear();
    resultStep28->clear();
    resultStep29->clear();
    resultStep30->clear();
    resultStep31->clear();
    resultStep32->clear();
    resultStep33->clear();
    resultStep34->clear();
}

void MainWindow::method1()
{
    resultTitle->setText("Выбранный метод: Решение квадратного уравнения через дискриминант");

    if(argVector[1] == 0 || argVector[2] == 0)
    {
        resultStep1->setText("Введённое вами уравнение не является полным. Вычисление корней данного уравнения данным методом не является возможным.");
        resultStep2->setText("Для его решения используйте метод для неполных квадратных уравнений.");

        return;
    }

    resultStep1->setText("Найдём дискриминант уравнения по формуле 'D = b^2 - 4ac':");
    resultStep2->setText(QString("D = %1^2 - 4 * %2 * %3 = %4").arg(argVector[1]).arg(argVector[0]).arg(argVector[2]).arg(roots[0]));

    if(roots[0] > 0)
    {
        resultStep3->setText(QString("Дискриминант уравнения равен %1 > 0  => уравнение имеет два корня.").arg(roots[0]));               // полный вариант объявления .arg(roots[0], 0, 'f', 2)
        resultStep4->setText("Найдём корни уравнения по формуле: 'X = (-b +- sqrt(D)) / 2a':");
        resultStep5->setText(QString("X1 = (-(%1) + sqrt(%2)) / 2 * %3 = %4").arg(argVector[1]).arg(roots[0]).arg(argVector[0]).arg(roots[1]));
        resultStep6->setText(QString("X2 = (-(%1) - sqrt(%2)) / 2 * %3 = %4").arg(argVector[1]).arg(roots[0]).arg(argVector[0]).arg(roots[2]));
        resultAnswer->setText(QString("Ответ: X1 = %1, X2 = %2.").arg(roots[1]).arg(roots[2]));                                         //большое время угробил на попытки исправить ошибку с вылетами приложения
    }                                                                                                                                   //которая была вызвана необъявлением нового QLabel к указателю
    else if
        (roots[0] == 0)
    {
        resultStep3->setText(QString("Дискриминант уравнения равен %1 = 0  => уравнение имеет один корень.").arg(roots[0]));
        resultStep4->setText("Найдём корень уравнения по формуле: 'X = (-b + sqrt(D)) / 2a':");
        resultStep5->setText(QString("X = (-(%1) + sqrt(%2)) / 2 * %3 = %4").arg(argVector[1]).arg(roots[0]).arg(argVector[0]).arg(roots[1]));
        resultAnswer->setText(QString("Ответ: X = %1.").arg(roots[1]));
    }
    else
    {
        resultStep3->setText(QString("Дискриминант уравнения равен %1 < 0  => уравнение не имеет корней.").arg(roots[0]));
        resultAnswer->setText("Ответ: корней нет.");
    }
    return;
}

void MainWindow::method2()
{
    resultTitle->setText("Выбранный метод: Решение по корням квадратного уравнения при чётном коэфициенте 'b'");

    extraLabelsHide();

    int b_int = static_cast<int>(argVector[1]);

    if(argVector[1] == 0 || argVector[2] == 0)
    {
        resultStep1->setText("Введённое вами уравнение не является полным. Вычисление корней данного уравнения данным методом не является возможным.");
        resultStep2->setText("Для его решения используйте метод для неполных квадратных уравнений.");

        return;
    }

    if(b_int % 2 != 0)
    {
        resultStep1->setText("Решение данного уравнения данным способом невозможно вследствие того, что аргумент 'b' не является чётным числом.");
        resultStep2->setText("Рекомендуется использовать иные методы решения для данного уравнения.");

        return;;
    }

    resultStep1->setText("Найдём четверть дискриминанта уравнения по формуле 'D/4 = k^2 - ac',    где k = b/2:");
    resultStep2->setText(QString("D/4 = %1^2 - %2 * %3 = %4").arg(argVector[1]/2).arg(argVector[0]).arg(argVector[2]).arg(roots[0]/4));

    if(roots[0] > 0)
    {
        resultStep3->setText(QString("Четверть дискриминанта уравнения равно %1 > 0  => уравнение имеет два корня.").arg(roots[0]/4));
        resultStep4->setText("Найдём корни уравнения по формуле: 'X = (-k +- sqrt(D/4)) / a':");
        resultStep5->setText(QString("X1 = (-(%1) + sqrt(%2)) / %3 = %4").arg(argVector[1]/2).arg(roots[0]/4).arg(argVector[0]).arg(roots[1]));
        resultStep6->setText(QString("X2 = (-(%1) - sqrt(%2)) / %3 = %4").arg(argVector[1]/2).arg(roots[0]/4).arg(argVector[0]).arg(roots[2]));
        resultAnswer->setText(QString("Ответ: X1 = %1, X2 = %2.").arg(roots[1]).arg(roots[2]));
    }
    else if
        (roots[0] == 0)
    {
        resultStep3->setText(QString("Четверть дискриминанта уравнения равно %1 = 0  => уравнение имеет один корень.").arg(roots[0]/4));
        resultStep4->setText("Найдём корень уравнения по формуле: 'X = (-k + sqrt(D/4)) / a':");
        resultStep5->setText(QString("X = (-(%1) + sqrt(%2)) / %3 = %4").arg(argVector[1]/2).arg(roots[0]/4).arg(argVector[0]).arg(roots[1]));
        resultAnswer->setText(QString("Ответ: X = %1.").arg(roots[1]));
    }
    else
    {
        resultStep3->setText(QString("Четверть дискриминанта уравнения равно %1 < 0  => уравнение не имеет корней.").arg(roots[0]/4));
        resultAnswer->setText("Ответ: корней нет.");
    }
    return;
}

void MainWindow::method3()
{
    double method3_x;

    resultTitle->setText("Выбранный метод: Решение неполных квадратных уравнений");

    extraLabelsHide();

    if(argVector[1] == 0 && argVector[2] == 0)
    {
        resultStep1->setText("В данном уравнении индексы 'b' и 'c' равны нулю  =>  преобразуем уравнение следующим образом:");
        resultStep2->setText(QString("%1X^2 = 0").arg(argVector[0]));
        resultStep3->setText(QString("Сократим обе части уравнения на %1:").arg(argVector[0]));
        resultStep4->setText("X^2 = 0");
        resultStep5->setText("Осталось взять квадратный корень из X:");
        resultStep6->setText("X = 0");
        resultAnswer->setText("Ответ: X = 0");
    }
    else if(argVector[1] == 0)
    {
        resultStep1->setText("В данном уравнении индекс 'b' равен нулю  =>  преобразуем уравнение следующим образом:");
        resultStep2->setText(QString("%1X^2 + (%2) = 0;         Перенесём свободный член через равно:").arg(argVector[0]).arg(argVector[2]));
        resultStep3->setText(QString("%1X^2 = %2;       Перенесём индекс 'a' через равно:").arg(argVector[0]).arg(-argVector[2]));
        resultStep4->setText(QString("X^2 = %1 / %2").arg(-argVector[2]).arg(argVector[0]));

        if(-argVector[2] / argVector[0] > 0)
        {
            method3_x = sqrt(-argVector[2] / argVector[0]);

            resultStep5->setText(QString("%1 / %2   больше нуля  =>  уравнение имеет два корня:").arg(-argVector[2]).arg(argVector[0]));
            resultStep6->setText(QString("X1 = sqrt(%1 / %2) = %3").arg(-argVector[2]).arg(argVector[0]).arg(method3_x));
            resultAnswer->setText(QString("X2 = -sqrt(%1 / %2) = %3").arg(-argVector[2]).arg(argVector[0]).arg(-method3_x));
        }
        else
        {
            resultStep5->setText(QString("%1 / %2   меньше нуля  =>  уравнение не имеет корней:").arg(-argVector[2]).arg(argVector[0]));
            resultAnswer->setText(QString("Ответ: уравнение не имеет корней."));
        }
    }
    else if(argVector[2] == 0)
    {
        method3_x = -argVector[1] / argVector[0];

        resultStep1->setText("В данном уравнении индекс 'c' равен нулю  =>  преобразуем уравнение следующим образом:");
        resultStep2->setText(QString("%1X^2 + (%2)X = 0;        Вынесем X за скобки:").arg(argVector[0]).arg(argVector[1]));
        resultStep3->setText(QString("X * (%1X + %2) = 0;        Данное уравнение всегда имеет два корня, один из них равен нулю:").arg(argVector[0]).arg(argVector[1]));
        resultStep4->setText(QString("X1 = 0;       X2 = -b / a = %1 / %2 = %3;").arg(-argVector[1]).arg(argVector[0]).arg(method3_x));
        resultAnswer->setText(QString("Ответ: X1 = 0;  X2 = %1").arg(method3_x));
    }
    else
    {
        resultStep1->setText("Введённое вами уравнение является полным  =>  решение его данным методом не представляется возможным");
    }
    return;
}

void MainWindow::method4()
{
    resultTitle->setText("Выбранный метод: Решение используя частные соотношения коэфициентов");

    extraLabelsHide();

    double method4_x;

    if(argVector[1] == 0 || argVector[2] == 0)
    {
        resultStep1->setText("Введённое вами уравнение не является полным. Вычисление корней данного уравнения данным методом не является возможным.");
        resultStep2->setText("Для его решения используйте метод для неполных квадратных уравнений.");

        return;
    }

    if(argVector[0] + argVector[2] == argVector[1])
    {
        method4_x = -argVector[2] / argVector[0];

        resultStep1->setText("Сумма первого коэфициента 'a' и свободного члена 'c' == коэфициенту 'b'  =>  корнями уравнения являются -1 и -(c/a)");
        resultStep2->setText(QString("X = %1 / %2 = %3").arg(-argVector[2]).arg(argVector[0]).arg(method4_x));
        resultAnswer->setText(QString("Ответ: X1 = -1;  X2 = %1;").arg(method4_x));
    }
    else if(argVector[0] + argVector[1] + argVector[2] == 0)
    {
        method4_x = argVector[2] / argVector[0];

        resultStep1->setText("Сумма всех коэфициентов == 0  =>  корнями уравнения являются 1 и c/a");
        resultStep2->setText(QString("X = %1 / %2 = %3").arg(argVector[2]).arg(argVector[0]).arg(method4_x));
        resultAnswer->setText(QString("Ответ: X1 = 1;  X2 = %1;").arg(method4_x));
    }
    else
    {
        resultStep1->setText("Невозможно решить заданное уравнение данным методом: отсутствуют частные соотношения аргументов:");
        resultStep2->setText("a + c = b;    a + b + c = 0;      Воспользуйтесь иным методом решения.");
    }
    return;
}

void MainWindow::method5()
{
    resultTitle->setText("Выбранный метод: Иcпользование прямой и обратной теоремы Виета");

    if(argVector[1] == 0 || argVector[2] == 0)
    {
        resultStep1->setText("Введённое вами уравнение не является полным. Вычисление корней данного уравнения данным методом не является возможным.");
        resultStep2->setText("Для его решения используйте метод для неполных квадратных уравнений.");

        return;
    }

    if(argVector[0] != 1)
    {
        resultStep1->setText("Данное уравнение не является приведённым (коэфициент 'a' != 0). Для вычисления уравнения по теореме Виета необходимо свести уравнение к приведённому виду. Используйте метод '6'для его решения;");

        return;
    }

    resultStep1->setText("Согласно обратной теореме Виета, всякая пара чисел (число) x1, x2, будучи решением системы уравнений");
    resultStep2->setText("x1 + x2 = -p;     x1 * x2 = q;");
    resultStep3->setText("Являются корнями уравнения X^2 + px + q = 0. Используем данную теорему, чтобы подобрать нужные числа:");

    if(argVector[1] + argVector[2] >= 0)
    {
        extraLabelsShow(0);
        resultWindow->resize(1.1 * mWWidth, 1.95 * mWHeight);
        resultWindow->move(mWWidth * 0.75, 0);

        roots[2] = -sqrt(argVector[1] + argVector[2]);
        roots[1] = -argVector[1] - roots[2];

        resultStep4->setText("Подберём x1 и x2, чтобы они удовлетворяли данной системе уравнений;");
        resultStep5->setText(QString("X1 + X2 = %1").arg(-argVector[1]));
        resultStep6->setText(QString("X1 * X2 = %1").arg(argVector[2]));

        resultStep7->setText("Выведем x1 из первого уравнения:");
        resultStep8->setText(QString("X1 = %1 - X2").arg(-argVector[1]));
        resultStep9->setText(QString("X1 * X2 = %1").arg(argVector[2]));

        resultStep10->setText("Теперь заменим x1 во втором выражении;");
        resultStep11->setText(QString("X1 = %1 - X2").arg(-argVector[1]));
        resultStep12->setText(QString("%1 - X2 * X2 = %2").arg(-argVector[1]).arg(argVector[2]));

        resultStep13->setText("Перенесём все числа без 'x' за равно;");
        resultStep14->setText(QString("X1 = %1 - X2").arg(-argVector[1]));
        resultStep15->setText(QString("-X2^2 = %1 + %2").arg(argVector[2]).arg(argVector[1]));

        resultStep16->setText(QString("X1 = %1 - X2").arg(-argVector[1]));
        resultStep17->setText(QString("-X2^2 = %1").arg(argVector[2] + argVector[1]));

        resultStep18->setText("Возьмём корень из второго выражения и умножим на -1;");
        resultStep19->setText(QString("X1 = %1 - X2").arg(-argVector[1]));
        resultStep20->setText(QString("-X2^2 = %1").arg(roots[2]));

        resultStep21->setText("Мы нашли значение x2;");

        resultStep22->setText("Теперь мы найдём значение x1, используя формулу, которую мы вывели в самом начале:");
        resultStep23->setText(QString("X1 = %1 - (%2) = %3").arg(-argVector[1]).arg(roots[2]).arg(roots[1]));

        resultStep24->setText(QString("Ответ: X1 = %1;  X2 = %2").arg(roots[1]).arg(roots[2]));
    }

    else if(argVector[1] + argVector[2] < 0)
    {
        resultStep4->setText("Данное уравнение невозможно решить данным методом (сумма аргументов 'b' и 'c' < 0);");
        resultStep5->setText("Воспользуйтесь иными методами решения");
    }
    return;
}

void MainWindow::method6()
{
    resultTitle->setText("Выбранный метод: Метод переброски");

    if(argVector[1] == 0 || argVector[2] == 0)
    {
        resultStep1->setText("Введённое вами уравнение не является полным. Вычисление корней данного уравнения данным методом не является возможным.");
        resultStep2->setText("Для его решения используйте метод для неполных квадратных уравнений.");

        return;
    }

    if(argVector[0] == 1)
    {
        resultStep1->setText("Данное уравнение является приведённым (коэфициент 'a' == 0). Для вычисления данного уравнения более целесообразно использовать метод '5'для его решения. Суть метода преброски состоит в сведении уравнения к приведённому виду, после чего производятся вычисления по теореме Виета");
    }

    resultStep1->setText("Суть метода преброски состоит в сведении уравнения к приведённому виду, после чего производятся вычисления по теореме Виета");

    resultStep2->setText("Умножим все члены исходного уравнения на коэфициент 'a':");
    resultStep3->setText(QString("(%1X)^2 + (%1 * (%2X)) + (%1) * (%3) = 0").arg(argVector[0]).arg(argVector[1]).arg(argVector[2]));

    resultStep4->setText("Заменим Y = AX:");
    resultStep5->setText(QString("Y^2 + (%2)Y + (%1)*(%3)").arg(argVector[0]).arg(argVector[1]).arg(argVector[2]));

    resultStep6->setText("Теперь решаем уравнение по теореме Виета");

    if(argVector[1] + argVector[2] >= 0)
    {
        extraLabelsShow(1);
        resultWindow->resize(1.1 * mWWidth, 1.95 * mWHeight);
        resultWindow->move(mWWidth * 0.75, 0);

        double y1, y2;

        y2 = -sqrt(argVector[1] + argVector[2]);
        y1 = -argVector[1] - y2;

        roots[1] = y1 / argVector[0];
        roots[2] = y2 / argVector[0];

        resultStep7->setText("Согласно обратной теореме Виета, всякая пара чисел (число) y1, y2, будучи решением системы уравнений:");
        resultStep8->setText("y1 + y2 = -p;     y1 * y2 = q;");
        resultStep9->setText("Являются корнями уравнения X^2 + px + q = 0. Используем данную теорему, чтобы подобрать нужные числа:");

        resultStep10->setText("Подберём x1 и x2, чтобы они удовлетворяли данной системе уравнений;");
        resultStep11->setText(QString("Y1 + Y2 = %1").arg(-argVector[1]));
        resultStep12->setText(QString("Y1 * Y2 = %1").arg(argVector[2]));

        resultStep13->setText("Выведем x1 из первого уравнения:");
        resultStep14->setText(QString("Y1 = %1 - Y2").arg(-argVector[1]));
        resultStep15->setText(QString("Y1 * Y2 = %1").arg(argVector[2]));

        resultStep16->setText("Теперь заменим Y1 во втором выражении;");
        resultStep17->setText(QString("Y1 = %1 - Y2").arg(-argVector[1]));
        resultStep18->setText(QString("%1 - Y2 * Y2 = %2").arg(-argVector[1]).arg(argVector[2]));

        resultStep19->setText("Перенесём все числа без 'Y' за равно;");
        resultStep20->setText(QString("Y1 = %1 - Y2").arg(-argVector[1]));
        resultStep21->setText(QString("-Y2^2 = %1 + %2").arg(argVector[2]).arg(argVector[1]));

        resultStep22->setText(QString("Y1 = %1 - Y2").arg(-argVector[1]));
        resultStep23->setText(QString("-Y2^2 = %1").arg(argVector[2] + argVector[1]));

        resultStep24->setText("Возьмём корень из второго выражения и умножим на -1;");
        resultStep25->setText(QString("Y1 = %1 - Y2").arg(-argVector[1]));
        resultStep26->setText(QString("-Y2^2 = %1").arg(y2));

        resultStep27->setText("Мы нашли значение Y2;");

        resultStep28->setText("Теперь мы найдём значение x1, используя формулу, которую мы вывели в самом начале:");
        resultStep29->setText(QString("Y1 = %1 - (%2) = %3").arg(-argVector[1]).arg(y2).arg(y1));

        resultStep30->setText(QString("Y1 = %1;   Y2 = %2").arg(y1).arg(y2));

        resultStep31->setText("Теперь найдём X1 и X2  соответственно, используя формулу X = Y/A:");
        resultStep32->setText(QString("X1 = %1 / %2 = %3").arg(y1).arg(argVector[0]).arg(roots[1]));
        resultStep33->setText(QString("X2 = %1 / %2 = %3").arg(y2).arg(argVector[0]).arg(roots[2]));

        resultStep34->setText(QString("Ответ: X1 = %1;  X2 = %2").arg(roots[1]).arg(roots[2]));
    }
    else if(argVector[1] + argVector[2] < 0)
    {
        resultStep4->setText("Данное уравнение невозможно решить данным методом (сумма аргументов 'b' и 'c' < 0);");
        resultStep5->setText("Воспользуйтесь иными методами решения");
    }
    return;
}

void MainWindow::launchStep2()
{
    resultWindow->show();
    resultWindow->resize(0.9 * mWWidth, 0.9 * mWHeight);

    extraLabelsHide();

    resultTitle->clear();
    resultStep1->clear();
    resultStep2->clear();
    resultStep3->clear();
    resultStep4->clear();
    resultStep5->clear();
    resultStep6->clear();
    resultAnswer->clear();

    if(methodMenuIndexHolder == -1)
    {
        resultTitle->setText("Вы не произвели выбор метода.");

        return;
    }

    else if(methodMenuIndexHolder == -2)
    {
        resultTitle->setText("Первый аргумент  не введён или выходит за рамки допустимых значений.");

        return;
    }

    else if(methodMenuIndexHolder == -3)
    {
        resultTitle->setText("Второй аргумент не введён или выходит за рамки допустимых значений.");

        return;
    }

    else if(methodMenuIndexHolder == -4)
    {
        resultTitle->setText("Третий аргумент не введён или выходит за рамки допустимых значений.");

        return;
    }

    else if(argVector[0] == 0)
    {
        resultTitle->setText("Введённое вами уравнение не является квадратным (индекс а = 0).");

        return;
    }

    switch (methodMenuIndexHolder) {
    case 0:
        method1();
    break;


    case 1:
    {                   //фигурные скобки необходимы если в данном кейсе производится объявление переменной
        method2();
    }
        break;


    case 2:
        method3();
    break;


    case 3:
        method4();
    break;

    case 4:
        method5();
    break;

    case 5:
        method6();
    break;

    default:
        resultTitle->setText("произошла ошибка при передаче выбранного индекса меню в функцию. Перевыберите пункт меню.");
    break;
    }

    argVector[0] = 0;
    argVector[1] = 0;
    argVector[2] = 0;
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
    argVector.resize(3);                                                    //"объявляю" размер векторов заранее;
    argChecker.resize(3);

    mainWidget = new QWidget(this);                                         //"разлиновка" расположения элементов будущего приложения
    mainWidgetUpperPart = new QWidget;
    mainWidgetLowerPart = new QWidget;
    //mainWidget->setStyleSheet("background-color: purple;");

    this->setCentralWidget(mainWidget);

    mWWidth = (this->width());
    mWHeight = (this->height());

    QVBoxLayout *mainLayout = new QVBoxLayout;                              //разделение окна на верхнюю и нижнюю часть
    mainLayout->addWidget(mainWidgetUpperPart);
    mainLayout->addWidget(mainWidgetLowerPart);

    mainWidget->setLayout(mainLayout);


    QVBoxLayout *upperPartLayout = new QVBoxLayout;                         //расположение виджетов в верхней части экрана
    methodChoice = new QLabel;
    methodMenu = new QComboBox;
    methodMenuIndexHolder = 0;                                              //по умолчанию индекс выбора содержит в себе первый метод решения

    methodChoice->setText("Выберите метод решения квадратного уравнения");

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
    argCleanerButton = new QPushButton;

    argValidator = new QDoubleValidator(-100000, 100000, 10);

    argSection->setText("Введение аргументов уравнения:");
    argCleanerButton->setText("очистить");

    lowerPartLeftLayout->addWidget(argSection);
    lowerPartLeftLayout->addSpacing(5);
    lowerPartLeftLayout->addWidget(arg1Widget);
    lowerPartLeftLayout->addSpacing(5);
    lowerPartLeftLayout->addWidget(arg2Widget);
    lowerPartLeftLayout->addSpacing(5);
    lowerPartLeftLayout->addWidget(arg3Widget);
    lowerPartLeftLayout->addSpacing(5);
    lowerPartLeftLayout->addWidget(argCleanerButton);

    lowerPartLeftLayout->setAlignment(Qt::AlignLeft);
    argCleanerButton->setMaximumWidth(90);

    mainWidgetLowerPartLeft->setLayout(lowerPartLeftLayout);

    connect(argCleanerButton, SIGNAL(clicked(bool)), this, SLOT(argCleaner()));


    QHBoxLayout* lowerPartLeftLayoutRow1 = new QHBoxLayout;                 //виджет, отвечающий за первую строку в нижней левой части экрана
    arg1Description = new QLabel;
    arg1 = new QLineEdit;

    arg1->setValidator(argValidator);
    arg1->setMaxLength(9);
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
    arg2->setMaxLength(9);
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
    arg3->setMaxLength(9);
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

    //mainWidgetLowerPartRight->setStyleSheet("background-color: orange;");
    //equation->setStyleSheet("background-color: purple;");

    launchButton->setText("Вычислить");
    launchButton->setMinimumWidth(90);
    launchButton->setMaximumWidth(90);

    lowerPartRightLayout->addWidget(equation);
    lowerPartRightLayout->addWidget(launchButton);

    lowerPartRightLayout->setAlignment(Qt::AlignRight);
    lowerPartRightLayout->setAlignment(equation, Qt::AlignTop);
    //lowerPartRightLayout->setAlignment(launchButton, Qt::AlignRight);
    lowerPartRightLayout->setAlignment(launchButton, Qt::AlignBottom);

    mainWidgetLowerPartRight->setLayout(lowerPartRightLayout);

    connect(this, SIGNAL(arg1Changed()), this, SLOT(dynamicEquationArg1()));     //слот dataTransfer издаёт сигнал, вызывающий изменение динамического уравнения
    connect(this, SIGNAL(arg2Changed()), this, SLOT(dynamicEquationArg2()));
    connect(this, SIGNAL(arg3Changed()), this, SLOT(dynamicEquationArg3()));

    connect(arg1, SIGNAL(textEdited(QString)), this, SLOT(dataTransferArg1()));   //любое изменение arg меняет уравнение в правой части экрана
    connect(arg2, SIGNAL(textEdited(QString)), this, SLOT(dataTransferArg2()));
    connect(arg3, SIGNAL(textEdited(QString)), this, SLOT(dataTransferArg3()));

    connect(this, SIGNAL(engageStep2()), this, SLOT(launchStep2()));

    connect(launchButton, SIGNAL(clicked(bool)), this, SLOT(dataTransferArg1()));
    connect(launchButton, SIGNAL(clicked(bool)), this, SLOT(dataTransferArg2()));
    connect(launchButton, SIGNAL(clicked(bool)), this, SLOT(dataTransferArg3()));

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

    resultWindow->setMinimumSize(0.9 * mWWidth, 0.9 * mWHeight);

    resultWindowMain = new QVBoxLayout;
    resultTitle = new QLabel;
    resultStep1 = new QLabel;
    resultStep2 = new QLabel;
    resultStep3 = new QLabel;
    resultStep4 = new QLabel;
    resultStep5 = new QLabel;
    resultStep6 = new QLabel;
    resultAnswer = new QLabel;

    resultStep7 = new QLabel();
    resultStep8 = new QLabel();
    resultStep9 = new QLabel();
    resultStep10 = new QLabel();
    resultStep11 = new QLabel();
    resultStep12 = new QLabel();
    resultStep13 = new QLabel();
    resultStep14 = new QLabel();
    resultStep15 = new QLabel();
    resultStep16 = new QLabel();
    resultStep17 = new QLabel();
    resultStep18 = new QLabel();
    resultStep19 = new QLabel();
    resultStep20 = new QLabel();
    resultStep21 = new QLabel();
    resultStep22 = new QLabel();
    resultStep23 = new QLabel();
    resultStep24 = new QLabel();
    resultStep25 = new QLabel();
    resultStep26 = new QLabel();
    resultStep27 = new QLabel();
    resultStep28 = new QLabel();
    resultStep29 = new QLabel();
    resultStep30 = new QLabel();
    resultStep31 = new QLabel();
    resultStep32 = new QLabel();
    resultStep33 = new QLabel();
    resultStep34 = new QLabel();

    resultWindowMain->addWidget(resultTitle);
    resultWindowMain->addSpacing(10);
    resultWindowMain->addWidget(resultStep1);
    resultWindowMain->addWidget(resultStep2);
    resultWindowMain->addWidget(resultStep3);
    resultWindowMain->addWidget(resultStep4);
    resultWindowMain->addWidget(resultStep5);
    resultWindowMain->addWidget(resultStep6);
    resultWindowMain->addWidget(resultAnswer);

    resultWindowMain->addWidget(resultStep7);
    resultWindowMain->addWidget(resultStep8);
    resultWindowMain->addWidget(resultStep9);
    resultWindowMain->addSpacing(10);
    resultWindowMain->addWidget(resultStep10);
    resultWindowMain->addWidget(resultStep11);
    resultWindowMain->addWidget(resultStep12);
    resultWindowMain->addSpacing(10);
    resultWindowMain->addWidget(resultStep13);
    resultWindowMain->addWidget(resultStep14);
    resultWindowMain->addWidget(resultStep15);
    resultWindowMain->addSpacing(10);
    resultWindowMain->addWidget(resultStep16);
    resultWindowMain->addWidget(resultStep17);
    resultWindowMain->addWidget(resultStep18);
    resultWindowMain->addSpacing(10);
    resultWindowMain->addWidget(resultStep19);
    resultWindowMain->addWidget(resultStep20);
    resultWindowMain->addWidget(resultStep21);
    resultWindowMain->addSpacing(10);
    resultWindowMain->addWidget(resultStep22);
    resultWindowMain->addWidget(resultStep23);
    resultWindowMain->addSpacing(10);
    resultWindowMain->addWidget(resultStep24);
    resultWindowMain->addWidget(resultStep25);
    resultWindowMain->addWidget(resultStep26);
    resultWindowMain->addSpacing(10);
    resultWindowMain->addWidget(resultStep27);
    resultWindowMain->addSpacing(10);
    resultWindowMain->addWidget(resultStep28);
    resultWindowMain->addWidget(resultStep29);
    resultWindowMain->addSpacing(10);
    resultWindowMain->addWidget(resultStep30);
    resultWindowMain->addSpacing(10);
    resultWindowMain->addWidget(resultStep31);
    resultWindowMain->addWidget(resultStep32);
    resultWindowMain->addWidget(resultStep33);
    resultWindowMain->addSpacing(10);
    resultWindowMain->addWidget(resultStep34);

    resultTitle->setWordWrap(true);
    resultStep1->setWordWrap(true);
    resultStep2->setWordWrap(true);
    resultStep3->setWordWrap(true);
    resultStep4->setWordWrap(true);
    resultStep5->setWordWrap(true);
    resultStep6->setWordWrap(true);
    resultAnswer->setWordWrap(true);

    resultTitle->setMinimumWidth(0.85 * mWWidth);

    resultWindowMain->setSpacing(0);
    resultWindowMain->setContentsMargins(10, 0, 10, 0);
    resultWindowMain->setAlignment(Qt::AlignTop);
    resultWindowMain->setAlignment(Qt::AlignLeft);

    resultWindow->setLayout(resultWindowMain);

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
