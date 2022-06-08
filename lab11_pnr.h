#ifndef LAB11_PNR_H
#define LAB11_PNR_H

#include <QMainWindow>
#include <set>
#include <vector>
#include <ctime>

QT_BEGIN_NAMESPACE
namespace Ui { class Lab11_PNR; }
QT_END_NAMESPACE

class Lab11_PNR : public QMainWindow
{
    Q_OBJECT

public:
    Lab11_PNR(QWidget *parent = nullptr);
    ~Lab11_PNR();

    void printAll();

private slots:
    void on_btnAdd_PNR_clicked();

    void on_btnDelete_PNR_clicked();

    void on_btnCopyAndAdd_PNR_clicked();

    void on_btnSortDecrease_PNR_clicked();

    void on_btnSortIncrease_PNR_clicked();

    void on_btnUnite_PNR_clicked();

    void on_btnFindElement_PNR_clicked();

    void on_btnFindAndAdd_PNR_clicked();

    void on_btnFindAndCount_PNR_clicked();

private:
    Ui::Lab11_PNR *ui;

    std::multiset<double> MltSet;
    std::vector<double> Vect;
    std::multiset<double> MltSet2;
    std::vector<double> Vect2;
};
#endif // LAB11_PNR_H
