#pragma once

#include <QWidget>
#include <vector>
#include "Kleimenov_Dish.h"

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    std::vector<shared_ptr<Kleimenov_Dish>> ptrsDishes;

    explicit MyWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    void load(const QString& path);
    void save(const QString& path);
    void clean();

//public slots:
    void onSetWidth(int);
    void onSetHeight(int);
};

