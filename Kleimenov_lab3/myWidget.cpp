#include "MyWidget.h"
#include <QPainter>
#include "boost.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget{parent}
{
}

void MyWidget::paintEvent(QPaintEvent*)
{
    if(ptrsDishes.empty())
        return;

    QPainter painter(this);
    /// отрисовка будет тут
}

void MyWidget::load(const QString& path)
{
    std::ifstream in(path.toStdWString(), std::ifstream::binary);
    boost::archive::binary_iarchive ar(in);
    ar >> ptrsDishes;
    update();
}

void MyWidget::save(const QString& path)
{
    std::ofstream out(path.toStdWString(), std::ofstream::binary);
    boost::archive::binary_oarchive ar(out);
    ar << ptrsDishes;
}

void MyWidget::clean()
{
    ptrsDishes.clear();
    update();
}

void MyWidget::onSetWidth(int w)
{
    resize(w, height());
}

void MyWidget::onSetHeight(int h)
{
    resize(width(), h);
}
