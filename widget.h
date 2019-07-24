#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void ChangeMoney(int n);
    int money {0};
    int cnt10 {0};
    int cnt50 {0};
    int cnt100 {0};
    int cnt500 {0};
    int res {0};
private slots:
    void on_pb10_clicked();

    void on_pb50_clicked();

    void on_pb100_clicked();

    void on_pb500_clicked();

    void on_pbCoffee_clicked();

    void on_pbTea_clicked();

    void on_pbCoke_clicked();

    void on_pbReset_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
