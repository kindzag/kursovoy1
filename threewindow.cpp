#include "threewindow.h"
#include "ui_threewindow.h"

threewindow::threewindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::threewindow)
{
    ui->setupUi(this);
}

threewindow::~threewindow()
{
    delete ui;
}

void threewindow::on_buttonBox_accepted()
{
    bool ok;
    kalories = ui->lineEdit->text();
    time = ui->lineEdit_2->text();
    kg = ui->lineEdit_3->text();
    pulse = ui->lineEdit_4->text();
    double num_kalories = kalories.toDouble(&ok);
    double num_time = time.toDouble(&ok);
    double num_kg = kg.toDouble(&ok);
    double num_pulse = pulse.toDouble(&ok);
    if(num_kalories == 0 || num_time == 0 || num_pulse == 0 || num_kg == 0)
    {
        QMessageBox::critical(this, "Ошибка", "Поля для ввода данных не могут быть пустыми");
    }
    else
    {
        double distance = num_kalories / (num_kg * num_pulse * num_time / 177);
        QMessageBox::information(nullptr, "Результат обратного рассчета", QString("Дистанция для достижения целевых калорий %1").arg(distance));
        QString desktopPath = "C:/file";
        QFile file(desktopPath + "/result.txt");
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream stream(&file);
            stream.setCodec("UTF-8");
            QLocale locale(QLocale::Russian);
            stream.setLocale(locale);
            stream << "Результат расчета дистанции:\n";
            stream << "Вес: " << kg << " кг\n";
            stream << "Время: " << time << " ч\n";
            stream << "Пульс: " << pulse << " уд/мин\n";
            stream << "Калории: " << kalories << "\n";
            stream << "Дистанция: " << distance << " км\n";
            file.close();
         }
        else
        {
            QMessageBox::critical(this, "Ошибка", "Ошибка открытия файла");
        }
    }
}
