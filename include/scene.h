#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QPainter>
#include <QLineF>
#include <QKeyEvent>
#include <QMessageBox>
#include <QPair>
#include <QStandardItemModel>
#include <QTimer>
#include <QFile>
#include <QMessageBox>

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QComboBox>

#include "../include/mark.h"
#include "../include/config.h"
#include "../include/dialog.h"

enum Sides
{
    Top,
    Bottom,
    Left,
    Right
};

class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    Scene();
    ~Scene();
    void resize(double, double, Sides, Sides);
    QStandardItemModel* getMarkHandler();

private:
    void showError(QString);
    Dialog dialogWidget;
    Mark* addMarkNoCheck(double x , double y, int id, int angular);

protected:
    QWidget* parentWidget;

    void setUpMarkHandler();
    void removeMark(Mark*);

    void narrowingScene(QGraphicsItem*);
    void drawBackground(QPainter* painter, const QRectF& rect) override;
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;

    void checkSceneSize(double, double);
    bool checkId(int);
    bool checkInputMark(qreal, qreal);

    QPair<double, double> toCoords(double x, double y);
    QPair<double, double> toPixels(double x, double y);

public slots:
    void rotateMark();
    void addMark(double x , double y, int id, int angular);
    void moveToMark(double x, double y);
    void removeMark();
    void loadTable(QString);

    void duplicate(int);
    void saveInFile(QString filePath);

signals:
    void markAdded(int, qreal, qreal, int);
    void markUpdated(int, int);
    void markCoordsUpdated(int, double, double);
    void markRemoved(int);
    void setRubberBandDrag();
    void setScrollHandDrag();
    void keyPressEvent_(QKeyEvent*);
};

#endif // SCENE_H
