#include "secondwindow.h"
#include "ui_secondwindow.h"

secondwindow::secondwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondwindow)
{
    ui->setupUi(this);
}

secondwindow::~secondwindow()
{
    delete ui;
}

void secondwindow::on_buttonBox_accepted()
{
    bool ok;
    distance = ui->lineEdit->text();
    time = ui->lineEdit_2->text();
    kg = ui->lineEdit_3->text();
    pulse = ui->lineEdit_4->text();
    //speed = ui->lineEdit_4->text();
    double num_distance = distance.toDouble(&ok);
    double num_time = time.toDouble(&ok);
    double num_kg = kg.toDouble(&ok);
    double num_pulse = pulse.toDouble(&ok);
    if(num_distance == 0 || num_time == 0 || num_kg == 0)
    {
        QMessageBox::critical(this, "Ошибка", "Поля для ввода данных не могут быть пустыми");
    }
    else
    {
        double energy = num_kg * num_distance * num_pulse * num_time / 117;
        QMessageBox::information(nullptr, "Результат рассчета", QString("Количество затраченных калорий: %1").arg(energy));
        QString desktopPath = "C:/file";
        QFile file(desktopPath + "/result.txt");
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream stream(&file);
            stream.setCodec("UTF-8");
            QLocale locale(QLocale::Russian);
            stream.setLocale(locale);
            stream << "Результат расчета калории:\n";
            stream << "Вес: " << kg << " кг\n";
            stream << "Время: " << time << " ч\n";
            stream << "Пульс: " << pulse << " уд/мин\n";
            stream << "Дистанция: " << distance << " км\n";
            stream << "Калории: " << energy << "\n";
            file.close();
         }
         else
         {

            QMessageBox::critical(this, "Ошибка", "Ошибка открытия файла");
         }
    }
}
