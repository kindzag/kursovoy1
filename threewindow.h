#ifndef THREEWINDOW_H
#define THREEWINDOW_H

#include <QDialog>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QLocale>
#include <QMessageBox>


namespace Ui {
class threewindow;
}

class threewindow : public QDialog
{
    Q_OBJECT

public:
    explicit threewindow(QWidget *parent = 0);
    ~threewindow();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::threewindow *ui;
    QString kalories, time, pulse, kg;
};

#endif // THREEWINDOW_H
