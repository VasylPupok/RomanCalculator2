
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "RomeNumberAdapter.h"
#include "ArabNumberAdapter.h"

#include "visitors.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    _calculator(),
    _currOperation(nullptr)
{
    ui->setupUi(this);
    this->setDefaultButtonColors();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setEnabledArithmetics(bool isEnabled) {
    this->ui->plus->setEnabled(isEnabled);
    this->ui->minus->setEnabled(isEnabled);
    this->ui->mutiply->setEnabled(isEnabled);
    this->ui->divide->setEnabled(isEnabled);
}

void MainWindow::setFirstArgument() {
    if (
        this->ui->resultOutput->toPlainText().isEmpty() &&
        !this->ui->numberInput->text().isEmpty()
        )
    {
        this->ui->resultOutput->setText(this->ui->numberInput->text());
        this->setEnabledArithmetics(false);
        this->ui->proceedButton->setEnabled(true);
    }
}

void MainWindow::setDefaultButtonColors() {
    this->ui->plus->setStyleSheet("background: white");
    this->ui->minus->setStyleSheet("background: white");
    this->ui->divide->setStyleSheet("background: white");
    this->ui->mutiply->setStyleSheet("background: white");
    this->ui->power->setStyleSheet("background: white");
    this->ui->clearButton->setStyleSheet("background: white");
    this->ui->proceedButton->setStyleSheet("background: white");
}

void MainWindow::on_proceedButton_clicked() {
    if (
        !this->ui->resultOutput->toPlainText().isEmpty() &&
        !this->ui->numberInput->text().isEmpty() &&
        this->_currOperation != nullptr
        )
    {
        ArabNumberAdapter a(this->ui->resultOutput->toPlainText().toStdString());
        ArabNumberAdapter b(this->ui->numberInput->text().toStdString());
        int result = this->_calculator.acceptVisitor(this->_currOperation, a, b);
        std::string rome_result = RomeNumberAdapter(result);

        this->ui->resultOutput->setText(rome_result.c_str());
        this->setEnabledArithmetics(true);
    }
}

void MainWindow::on_plus_clicked() {
    setFirstArgument();
    setOperation(new AddVisitor());
    setDefaultButtonColors();
    this->ui->plus->setStyleSheet("background-color: blue");
}

void MainWindow::on_minus_clicked() {
    setFirstArgument();
    setOperation(new SubtractVisitor());
    setDefaultButtonColors();
    this->ui->minus->setStyleSheet("background-color: blue");
}

void MainWindow::on_divide_clicked() {
    setFirstArgument();
    setOperation(new DivideVisitor());
    setDefaultButtonColors();
    this->ui->divide->setStyleSheet("background-color: blue");
}

void MainWindow::on_mutiply_clicked() {
    setFirstArgument();
    setOperation(new MultiplyVisitor());
    setDefaultButtonColors();
    this->ui->mutiply->setStyleSheet("background-color: blue");
}

void MainWindow::on_power_clicked() {
    setFirstArgument();
    setOperation(new PowerVisitor());
    setDefaultButtonColors();
    this->ui->mutiply->setStyleSheet("background-color: blue");
}

void MainWindow::setOperation(const Calculator::OperationVisitor* op) {
    delete this->_currOperation;
    this->_currOperation = op;
}

void MainWindow::on_clearButton_clicked() {
    this->ui->resultOutput->setText("");
    this->setEnabledArithmetics(true);
    setDefaultButtonColors();
    this->ui->proceedButton->setEnabled(false);
}




