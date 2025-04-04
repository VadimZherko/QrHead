#include "../include/mark.h"

Mark::Mark(double x, double y, int id, int angular)
{
    this->setPos(x, y);
    this->angular = angular;

    QPixmap QrImage(":/new/prefix1/markIcon.png");
    if(angular == 90) QrImage.load(":/new/prefix1/markIcon_90.png");
    else if(angular == 180) QrImage.load(":/new/prefix1/markIcon_180.png");
    else if (angular == 270) QrImage.load(":/new/prefix1/markIcon_270.png");

    this->setPixmap(QrImage);
    this->setFlag(QGraphicsItem::ItemIsSelectable);

    this->id = id;
    this->angular = angular;

    QString* text_id = new QString;
    text_id->setNum(id);
    textItem = new QGraphicsTextItem(*text_id,this);
    textItem->setDefaultTextColor(Qt::white);
    textItem->setPos(this->boundingRect().center().x() - textItem->boundingRect().width() / 2, this->boundingRect().bottom() - 5);
}

int Mark::getAngular()
{
    return this->angular;
}

int Mark::getId()
{
    return id;
}
void Mark::setAngular(int angular)
{
    this->angular = angular;
    QPixmap newPixmap;

    if(angular == 0) newPixmap.load(":/new/prefix1/markIcon.png");
    else if(angular == 90) newPixmap.load(":/new/prefix1/markIcon_90.png");
    else if(angular == 180) newPixmap.load(":/new/prefix1/markIcon_180.png");
    else if (angular == 270) newPixmap.load(":/new/prefix1/markIcon_270.png");

    this->setPixmap(newPixmap);
}
