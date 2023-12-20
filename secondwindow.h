#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QLocale>
#include <QMessageBox>

namespace Ui {
class secondwindow;
}

class secondwindow : public QDialog
{
    Q_OBJECT

public:
    explicit secondwindow(QWidget *parent = 0);
    ~secondwindow();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::secondwindow *ui;
    QString distance, time, kg, pulse;
};

#endif // SECONDWINDOW_H
