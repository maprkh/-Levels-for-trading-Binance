#ifndef MAINWINDOW_H
#define MAINWINDOW_H




#define ORGANIZATION_NAME "EVILEG"
#define ORGANIZATION_DOMAIN "www.evileg.ru"
#define APPLICATION_NAME "QSettings Program"
#define SETTINGS_TRAY "settings/tray"



#include <QMainWindow>
#include <QDebug>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QXmlStreamReader>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QtCore>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <qcustomplot.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
void getRequestFinished(QNetworkReply* reply);
private slots:
void on_pushButton1_6_clicked();
private slots:
void plot();

void on_MainWindow_iconSizeChanged(const QSize &iconSize);

private:
QNetworkAccessManager* Request;


private:
QCPLayer* cursorLayer;
QCPItemText *textItem;
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsLineItem *line;
    QGraphicsRectItem *rectangle;
    QCustomPlot *customPlot;
QCPGraph *points;



    QCPGraph *graph;
    QCPCurve *verticalLine;     // Объявляем объект для вертикальной линии
    QCPItemTracer *tracer;      // Трасировщик по точкам графика
    QVector<double>qv_x,qv_y;

private slots:
void onMouseMove(QMouseEvent* event);
};

#endif // MAINWINDOW_H
