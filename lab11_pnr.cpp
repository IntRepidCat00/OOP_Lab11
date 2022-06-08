#include "lab11_pnr.h"
#include "ui_lab11_pnr.h"

Lab11_PNR::Lab11_PNR(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Lab11_PNR)
{
    ui->setupUi(this);
}

Lab11_PNR::~Lab11_PNR()
{
    delete ui;
}

void Lab11_PNR::printAll()
{
    std::multiset<double>::iterator msptr = MltSet.begin();
    std::vector<double>::iterator vptr = Vect.begin();

    ui->listWidMultiset_PNR->clear();
    ui->listWidVector_PNR->clear();
    ui->listWidMultiset2_PNR->clear();
    ui->listWidVector2_PNR->clear();

    while(msptr != MltSet.end())
    {
        ui->listWidMultiset_PNR->addItem(QString::number(*msptr));
        msptr++;
    }
    while(vptr != Vect.end())
    {
        ui->listWidVector_PNR->addItem(QString::number(*vptr));
        vptr++;
    }
    msptr = MltSet2.begin();
    vptr = Vect2.begin();
    while(msptr != MltSet2.end())
    {
        ui->listWidMultiset2_PNR->addItem(QString::number(*msptr));
        msptr++;
    }
    while(vptr != Vect2.end())
    {
        ui->listWidVector2_PNR->addItem(QString::number(*vptr));
        vptr++;
    }
}


void Lab11_PNR::on_btnAdd_PNR_clicked()
{
    int ammount = ui->spinBoxAmmountAdd_PNR->value();
    srand(time(NULL));
    if(ui->radioBtnMultiset_PNR->isChecked())
    {
        for(int i{0}; i < ammount; i++)
        {
            double num = (rand()%100) + static_cast<double>((rand()%10))/10;
            MltSet.insert(num);
        }
    } else
    {
        for(int i{0}; i < ammount; i++)
        {
            double num = (rand()%100) + static_cast<double>((rand()%10))/10;
            Vect.push_back(num);
        }
    }
    printAll();
}


void Lab11_PNR::on_btnDelete_PNR_clicked()
{
    int from = ui->spinBoxFromDelete_PNR->value();
    int ammount = ui->spinBoxAmmountDelete_PNR->value();

    if(ui->radioBtnMultiset_PNR->isChecked())
    {
        std::multiset<double>::iterator msptr = MltSet.begin();

        for(int i{1}; i < from; i++)
        {
            if(msptr == MltSet.end())
            {
                return;
            }
            msptr++;
        }

        int count{};
        while(msptr != MltSet.end() && count < ammount)
        {
            double elemToDelete = *msptr;
            count++;
            msptr++;
            MltSet.erase(elemToDelete);
        }
    } else
    {
        std::vector<double>::iterator vptr = Vect.begin();
        for(int i{1}; i < from; i++)
        {
            if(vptr == Vect.end())
            {
                return;
            }
            vptr++;
        }
        int count{0};
        std::vector<double>::iterator vptr2 = vptr;
        while(vptr2 != Vect.end() && count < ammount)
        {
            vptr2++;
            count++;
        }
        Vect.erase(vptr, vptr+count);
    }
    printAll();
}


void Lab11_PNR::on_btnCopyAndAdd_PNR_clicked()
{
    if(ui->radioBtnMultiset_PNR->isChecked())
    {
        std::vector<double>::iterator vptr = Vect.begin();
        while(vptr != Vect.end())
        {
            MltSet.insert(*vptr);
            vptr++;
        }
    } else
    {
        std::multiset<double>::iterator msptr = MltSet.begin();
        while(msptr != MltSet.end())
        {
            Vect.push_back(*msptr);
            msptr++;
        }
    }
    printAll();
}


void Lab11_PNR::on_btnSortDecrease_PNR_clicked()
{
    if(ui->radioBtnVector_PNR->isChecked())
    {
        std::sort(Vect.rbegin(), Vect.rend());
    }
    printAll();
}


void Lab11_PNR::on_btnSortIncrease_PNR_clicked()
{
    if(ui->radioBtnVector_PNR->isChecked())
    {
        std::sort(Vect.begin(), Vect.end());
    }
    printAll();
}


void Lab11_PNR::on_btnUnite_PNR_clicked()
{
    if(ui->radioBtnMultiset_PNR->isChecked())
    {
        MltSet2.clear();
        std::multiset<double>::iterator msptr = MltSet.begin();
        std::vector<double>::iterator vptr = Vect.begin();

        while(msptr != MltSet.end())
        {
            MltSet2.insert(*msptr);
            msptr++;
        }
        while(vptr != Vect.end())
        {
            MltSet2.insert(*vptr);
            vptr++;
        }
    } else
    {
        Vect2.clear();
        std::multiset<double>::iterator msptr = MltSet.begin();
        std::vector<double>::iterator vptr = Vect.begin();

        while(msptr != MltSet.end())
        {
            Vect2.push_back(*msptr);
            msptr++;
        }
        while(vptr != Vect.end())
        {
            Vect2.push_back(*vptr);
            vptr++;
        }
    }
    printAll();
}


void Lab11_PNR::on_btnFindElement_PNR_clicked()
{
    double foundElem;
    bool isFound{false};
    if(ui->radioBtnVector_PNR->isChecked())
    {
        std::vector<double>::iterator vptr = Vect.begin();
        while(vptr != Vect.end())
        {
            if(ui->doubleSpinBoxFrom_PNR->value() < (*vptr) && (*vptr) < ui->doubleSpinBoxTo_PNR->value())
            {
                foundElem = *vptr;
                isFound = true;
                break;
            }
            vptr++;
        }
    }else
    {
        std::multiset<double>::iterator msptr = MltSet.begin();
        while(msptr != MltSet.end())
        {
            if(ui->doubleSpinBoxFrom_PNR->value() < (*msptr) && (*msptr) < ui->doubleSpinBoxTo_PNR->value())
            {
                foundElem = *msptr;
                isFound = true;
                break;
            }
            msptr++;
        }
    }
    if(isFound)
    {
        ui->lblFoundElementValue_PNR->setText(QString::number(foundElem));
    } else
    {
        ui->lblFoundElementValue_PNR->setText("Element wasn't found");
    }
}


void Lab11_PNR::on_btnFindAndAdd_PNR_clicked()
{
    if(ui->radioBtnMultiset_PNR->isChecked())
    {
        std::multiset<double>::iterator msptr = MltSet.begin();
        while(msptr != MltSet.end())
        {
            if(ui->doubleSpinBoxFrom_PNR->value() < (*msptr) && (*msptr) < ui->doubleSpinBoxTo_PNR->value())
            {
                double foundElem = *msptr;
                MltSet2.insert(foundElem);
            }
            msptr++;
        }
    }else
    {
        std::vector<double>::iterator vptr = Vect.begin();
        while(vptr != Vect.end())
        {
            if(ui->doubleSpinBoxFrom_PNR->value() < (*vptr) && (*vptr) < ui->doubleSpinBoxTo_PNR->value())
            {
                double foundElem = *vptr;
                Vect2.push_back(foundElem);
            }
            vptr++;
        }
    }
    printAll();
}


void Lab11_PNR::on_btnFindAndCount_PNR_clicked()
{
    int foundCount{};
    if(ui->radioBtnVector_PNR->isChecked())
    {
        std::vector<double>::iterator vptr = Vect.begin();
        while(vptr != Vect.end())
        {
            if(ui->doubleSpinBoxFrom_PNR->value() < (*vptr) && (*vptr) < ui->doubleSpinBoxTo_PNR->value())
            {
                foundCount++;
            }
            vptr++;
        }
    }else
    {
        std::multiset<double>::iterator msptr = MltSet.begin();
        while(msptr != MltSet.end())
        {
            if(ui->doubleSpinBoxFrom_PNR->value() < (*msptr) && (*msptr) < ui->doubleSpinBoxTo_PNR->value())
            {
                foundCount++;
            }
            msptr++;
        }
    }
    if(foundCount > 0)
    {
        ui->lblCountOfFoundValue_PNR->setText(QString::number(foundCount));
    } else
    {
        ui->lblCountOfFoundValue_PNR->setText("There aren't such elements");
    }
}

