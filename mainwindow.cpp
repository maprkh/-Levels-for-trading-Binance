
#include "mainwindow.h"
#include "ui_mainwindow2.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTimer>
#include <QTextCursor>
#include <QtMultimedia/QSound>
#include <QSettings>
#include <QMessageBox>
#include<QtCore/qmath.h>
#include <QNetworkAccessManager>
#include <qcustomplot.h>
QVector<double> maq, maa;
float  arr[601][7];
QString Coin,limit,TimeFrame,dnew,dinput,dreg;
int limitint=48,dist=10,TT;
float m =1;
float c = 0;
int S=140000,qq=12;
float min=0,max=0;
float av=0;
int w,h,k,ooo,aaa;
int qqq,www,eee;
int q,g,a,b,cp,QQ,SS,SS2,WW2,WW21,QQ2;
QString d,AA,ZZ,sd,sd2,sd3;
QDate D,D2;
const int e=3,n=601;
float lvl1[n][3];
float lvl2[n][3];
float lvl3[n][3];
int nn =601;
int t=0;  int z=0;
QString type;
QVector<double> ckey(nn), copen(nn),chigh(nn),clow(nn),cclose(nn);
quint64 dnewint, dinputint,dregint;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    scene = new QGraphicsScene(this);
  //  ui->graphicsView->setScene(scene);
    Request = new QNetworkAccessManager();
    connect(Request, SIGNAL(finished(QNetworkReply*)),SLOT(getRequestFinished(QNetworkReply*)));
    qApp->setStyle(QStyleFactory::create("Fusion"));
    ui->pushButton1_6->setAutoFillBackground(true);
    ui->pushButton1_6->setStyleSheet("background-color: rgb(67,181,129);");
   /*  ui->god->setPlaceholderText(QString(" пример -> 2020"));
     ui->meslats->setPlaceholderText(QString(" пример -> 04"));
     ui->chislo->setPlaceholderText(QString(" пример -> 08"));
     //ui->label_4->setStyleSheet("background-color: yellow");
     ui->label_5->setText("Введите год сюда ->");
     ui->label_7->setText("Введите сегодняшее число сюда ->");
     ui->label_6->setText("Введите номер месяца сюда ->");*/

     ui->label_4->setText("Введите сгенерированный код сюда ->");



     ui->comboBox->addItem("1m");
     ui->comboBox->addItem("5m");
     ui->comboBox->addItem("15m");
     ui->comboBox->addItem("30m");
     ui->comboBox->addItem("1h");
     ui->comboBox->addItem("2h");
     ui->comboBox->addItem("4h");
     ui->comboBox->addItem("6h");
     ui->comboBox->addItem("12h");
     ui->comboBox->addItem("1d");
     ui->comboBox->addItem("1w");
     ui->comboBox->addItem("1M");


     ui->comboBox_2->addItem("BTCUSDT");
     ui->comboBox_2->addItem("LTCUSDT");
     ui->comboBox_2->addItem("BNBUSDT");
     ui->comboBox_2->addItem("ETHUSDT");
     ui->comboBox_2->addItem("BCHABCUSDT");
     ui->comboBox_2->addItem("XLMUSDT");

 //5






    /*ui->comboBox_17->addItem("50");
      ui->comboBox_17->addItem("100");
      ui->comboBox_17->addItem("150");
      ui->comboBox_17->addItem("200");
      ui->comboBox_17->addItem("250");
      ui->comboBox_17->addItem("300");*/



    /*ui->comboBox_18->addItem("0");
      ui->comboBox_18->addItem("0.01");
      ui->comboBox_18->addItem("0.1");
      ui->comboBox_18->addItem("0.2");
      ui->comboBox_18->addItem("0.3");*/

      ui->comboBox_3->addItem("Candles");
      ui->comboBox_3->addItem("Bars");
      ui->comboBox_3->addItem("Line");
}
void MainWindow::onMouseMove(QMouseEvent *event)
{
    customPlot->yAxis->setVisible(false);

    QCustomPlot* customPlot = qobject_cast<QCustomPlot*>(sender());

    int x = customPlot->xAxis->pixelToCoord(event->pos().x());
    double y = customPlot->yAxis2->pixelToCoord(event->pos().y());
    textItem->setText(QString("(%1)").arg(x));
   // textItem->position->setCoords(QPointF(x, min+0.0001));
   // textItem->setColor(255);
  //  textItem->setFont(QFont(font().family(), 10));
   // textItem->deleteLater();

    QCPItemLine *arrowQ = new QCPItemLine(customPlot);
    arrowQ->end->setCoords(x,11000000);
    arrowQ->start->setCoords(x,-3);
    arrowQ->setHead(QCPLineEnding::esSpikeArrow);
    textItem = new QCPItemText(customPlot);

    QCPItemLine *arrowQq = new QCPItemLine(customPlot);
    arrowQq-> end-> setCoords( 30000000000,y);
    arrowQq->start->setCoords(-30000000000,y);
    arrowQq->setHead(QCPLineEnding::esSpikeArrow);


    QPen blueDotPen;
    blueDotPen.setColor(QColor(255, 0, 55, 220));
    //blueDotPen.setColor(QColor(0, 255, 255, 0));

    blueDotPen.setStyle(Qt::DotLine);
    blueDotPen.setWidthF(1.5);
    QCPItemText *textLabel = new QCPItemText(customPlot);
    textLabel->setPositionAlignment(Qt::AlignTop|Qt::AlignHCenter);
  //  textLabel->position->setType(QCPItemPosition::ptAxisRectRatio);
    textLabel->position->setCoords(x,y); // place position at center/top of axis rect
    textLabel->setFont(QFont(font().family(), 16)); // make font a bit larger
    textLabel->setPen(QPen(Qt::black)); // show black border around text
    QString sx,sy;
    sx=QString::number(x);
    sy=QString::number(y);


    int v=0;
    v= sy.length();
  /* if(v==6)
   {    textLabel->setText(sy+".0");
}
    else if(v==5)
   {    textLabel->setText(sy+".00");
}
   else if(v==4)
  {    textLabel->setText(sy+".000");
}
    else*/
  // {
        textLabel->setText(sy);
//}

    arrowQq->setPen(blueDotPen);
    arrowQ->setPen(blueDotPen);
    arrowQq->deleteLater();
    arrowQ->deleteLater();
    textLabel->deleteLater();
    customPlot->replot();

}
MainWindow::~MainWindow()
{
    delete ui;

}
void MainWindow:: plot()
{
customPlot = new QCustomPlot();
ui->gridLayout->addWidget(customPlot,0,0,1,1);
customPlot->setInteraction(QCP::iRangeZoom,true);
customPlot->setInteraction(QCP::iRangeDrag, true);
customPlot->axisRect()->setRangeDrag(Qt::Horizontal);
customPlot->axisRect()->setRangeZoom(Qt::Horizontal);

//customPlot->legend->setVisible(true);
D=QDate::currentDate();
//


long long n = 500;
QDateTime start = QDateTime(D2);
start.setTimeSpec(Qt::UTC);
double startTime = start.toTime_t();

// create candlestick chart:
/*QCPFinancial *Candles = new QCPFinancial(customPlot->xAxis, customPlot->yAxis);
Candles->setName("Candlestick");
Candles->setChartStyle(QCPFinancial::csCandlestick);
Candles->setData(ckey,copen,chigh,clow,cclose,false);
//Candles->setWidth(binSize*0.4);
Candles->setTwoColored(true);
Candles->setBrushPositive(QColor(100, 180, 110));
Candles->setBrushNegative(QColor(180, 90, 90));
Candles->setPenPositive(QPen(QColor(0, 0, 0)));
Candles->setPenNegative(QPen(QColor(0, 0, 0)));*/
// create ohlc chart:
//customPlot->replot();


/*QCPFinancial *ohlc = new QCPFinancial(customPlot->xAxis, customPlot->yAxis);
ohlc->setName("OHLC");
ohlc->setChartStyle(QCPFinancial::csOhlc);
ohlc->setData(ckey,copen,chigh,clow,cclose,false);
//    ohlc->setWidth(binSize*0.4);
ohlc->setTwoColored(true);*/

customPlot->xAxis->scaleRange(1.025, customPlot->xAxis->range().center());
customPlot->yAxis2->scaleRange(1.1, customPlot->yAxis2->range().center());

// make axis rects' left side line up:
QCPMarginGroup *group = new QCPMarginGroup(customPlot);
customPlot->axisRect()->setMarginGroup(QCP::msRight|QCP::msLeft, group);

//customPlot->xAxis->setTickLabelFont(QFont(QFont().family(), 8));
//customPlot->yAxis->setTickLabelFont(QFont(QFont().family(), 8));

customPlot->xAxis2->setVisible(true);
customPlot->yAxis2->setVisible(true);
customPlot->xAxis2->setVisible(false);
customPlot->yAxis2->setVisible(true);
//customPlot->xAxis2->setTicks(false);
//customPlot->yAxis2->setTicks(false);
//customPlot->xAxis2->setTickLabels(false);
//customPlot->yAxis2->setTickLabels(false);

//customPlot->yAxis->setTickLabelColor(QColor(Qt::red)); // Красный цвет подписей тиков по Оси Y
//customPlot->legend->setVisible(true);   //Включаем Легенду графика
// Устанавливаем Легенду в левый верхний угол графика
customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignLeft|Qt::AlignTop);



textItem = new QCPItemText(customPlot);
   connect( customPlot, &QCustomPlot::mouseMove, this, &MainWindow::onMouseMove);
    //customPlot->replot();
}

void MainWindow::on_pushButton1_6_clicked()
{


   aaa=5;
    if(ooo==aaa){
    QProcess::startDetached(QApplication::applicationFilePath(), QStringList(), QApplication::applicationDirPath());
exit(0);
    }
    ooo=ooo+1;

plot();
    scene->clear();
        scene->update();

ui->textBrowser->setText("                                             ");
       TimeFrame = ui->comboBox->currentText();
       Coin = ui->comboBox_2->currentText();
        limit=("300");
        type=ui->comboBox_3->currentText();
        if(TimeFrame==("1w"))
{limit=("144");}
        else  if(TimeFrame==("1M"))
        {limit=("33");}


D.currentDate();
limitint=  limit.toInt();

/*QQ= ui->god->text().toInt();

SS= ui->meslats->text().toInt();

WW2= ui->chislo->text().toInt();

D=QDate::currentDate();

D.setDate(QQ,SS,WW2);//год дата месяц

D2 = D.addDays(-3);
if(TimeFrame==("1w"))
{
    D2 = D.addYears(-6);

}
else if(TimeFrame==("1d"))
{
    D2 = D.addMonths(-14);
}else if(TimeFrame==("1h"))
{
    D2 = D.addDays(-20);
}

else if(TimeFrame ==("5h"))
{
    D2 = D.addMonths(-3);

}
else if(TimeFrame==("month"))
{    D2 = D.addYears(-25);

}
    else if(TimeFrame==("30m"))
{ D2 = D.addDays(-11);
}
else
   { D2 = D.addDays(-3);}



ZZ=D2.toString("yyyy-M-d");*/
AA=D.toString("yyyy-M-d");
   QSettings settings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\DefaultProductKey2",   QSettings::Registry64Format);

 d= settings.value("ProductId").toString();


 QSettings settings2(ORGANIZATION_NAME, APPLICATION_NAME);


 dreg= settings2.value(SETTINGS_TRAY).toString();

    dregint=dreg.toULongLong();

int j =0;
     for(int i =0;i<d.size();++i){

         if(d.at(i)>=QChar('1') && d.at(i)<=QChar('9'))
            { dnew[j] = d.at(i);j++;}

     }
     g=dnew.toInt();
     g=g+88;
     g=g/2;
     g=g*g;
     //g=g*2000;
     g=g/110;
     g=g*25;
     g=g/15;
     g= qSqrt(g);
     g=g*3;
     g=g+1060;
if(dregint!=g)//0//dregint!=g
{
    ui->textBrowser->append(dnew+"    <-     отправьте этот код");
    dinput= ui->key->text();
    dinputint=dinput.toULongLong();
    if(dinputint!=g)
    {
        QMessageBox::information(this,
trUtf8("Проверка кода"),                        trUtf8("Отсутствует лицензия"));
limitint=0;
S=0;
    }
    else
    {
S=140000;
limitint=limit.toInt();
      settings2.setValue(SETTINGS_TRAY,QString::number(g) );
    }
}
for (int i=0; i<300; i++)
{
     arr[i][0]=0;
     arr[i][1]=0;
     arr[i][2]=0;
     arr[i][3]=0;
}


QNetworkRequest request;
request.setUrl(QUrl("https://api.binance.com/api/v3/klines?symbol="+Coin+"&interval="+TimeFrame+"&limit="+limit));

qDebug()<<"https://api.binance.com/api/v3/klines?symbol="+Coin+"&interval="+TimeFrame+"&limit="+limit;

    //request.setUrl(QUrl("https://fcsapi.com/api-v2/forex/history?symbol="+Coin+"&period="+TimeFrame+"&from="+ZZ+"&to="+AA+"&access_key=Li2AcjFcm5g5MXZ6eZBV63UnH6YBbYbijNHpQ0QHqausYAtNq5"));
Request->get(request);


}
void MainWindow::getRequestFinished(QNetworkReply* reply)
{
    ui->textBrowser->setTextColor("red");
ui->textBrowser->append("Уровни для ->" +Coin+     "              Time Frame -> "+TimeFrame);
ui->textBrowser->append("Дата -> "+AA);
   ui->textBrowser->setTextColor("black");
        QBrush greenBrush(Qt::green);
        QPen outlinePen(Qt::black);
        QBrush redBrush(Qt::red);
        QPen minPen(Qt::black);
         QPen maxPen(Qt::black);
        outlinePen.setWidth(2);


        QByteArray bytes = reply->readAll();



        QJsonDocument document = QJsonDocument::fromJson(bytes);

        QJsonObject root = document.object();
       //ui->textBrowser->append(root.value("msg").toString());
       //ui->textBrowser->append(root.value("code").toString());

QJsonValue arrayvalue = root.value("response");


        QJsonArray array = document.array();
        min=1000000;max=0;
        for(int i = 0; i < array.count(); i++){
        QJsonArray subtree_1 = array.at(i).toArray();


      /*  QByteArray bytes = reply->readAll();
        QJsonDocument document = QJsonDocument::fromJson(bytes);
        QJsonObject root = document.object();
QJsonValue arrayvalue = root.value("response");
QJsonArray array  = arrayvalue.toArray();
min=1000000;max=0;*/
/*for(int i = 0; i < array.count(); i++){
QJsonObject subtree_1 = array.at(i).toObject();
arr [i][0] = subtree_1.value("l").toString().toFloat();//min
clow[i]=arr[i][0];
if(arr[i][0]<min)
{min=arr[i][0];}
arr [i][1] = subtree_1.value("h").toString().toFloat();//max
chigh[i]=arr[i][1];
if(arr[i][1]>max)
{max=arr[i][1];}
arr [i][2] = subtree_1.value("o").toString().toFloat();//op
copen[i]=arr[i][2];
arr [i][3] = subtree_1.value("c").toString().toFloat();//cl
cclose[i] =arr[i][3];
 ckey [i]=i;*/
arr [i][0] = subtree_1.at(3).toString().toFloat();//min
clow[i]=arr[i][0];

if(arr[i][0]<min)

{min=arr[i][0];}
 arr [i][1] = subtree_1.at(2).toString().toFloat();//max
 chigh[i]=arr[i][1];

 if(arr[i][1]>max)

 {max=arr[i][1];}
 arr [i][2] = subtree_1.at(1).toString().toFloat();//op
 copen[i]=arr[i][2];

 arr [i][3] = subtree_1.at(4).toString().toFloat();//cl
 cclose[i] =arr[i][3];
  ckey [i]=i;
// * 900 1m
// * 88 5m
// * 68 15m
// * 28 30m
// * 14 1h
// * 3 5h
// / 1.5 1d
// / 12 1w
// / 25 month
/*if(TimeFrame==("1m")){
ckey[i]=10*900;
}
else if(TimeFrame==("5m"))
{ckey[i]=10*160;
}
else if(TimeFrame==("15m"))
{ckey[i]=10*68;
}
else if(TimeFrame==("30m"))
{ckey[i]=10*28;
}
else if(TimeFrame==("1h"))
{ckey[i]=10*14;
}
else if(TimeFrame==("5h"))
{ckey[i]=10*3;
}
else if(TimeFrame==("1d"))
{ckey[i]=10/1.5;
}
else if(TimeFrame==("1w"))
{ckey[i]=10/12;
}
else if(TimeFrame==("month"))
{ckey[i]=10/45;
}*/
        }
       /* if(SS==0&&WW2==0||SS==0||WW2==0){
        QMessageBox::information(this,
        trUtf8("Проверка даты"),
                         trUtf8("Дата введена некоректно или не введена, для коректной работы программы введите правильную дату"));
        limitint=0;
         for(int ee=1;ee!=300 ;ee++)
        {// ckey[0]=0;
        ckey [ee]=0;
        // ui->textBrowser->append(QString::number(ckey[ee]));
        }*/
        customPlot->replot();
        //}
        /*else{
        limitint=300;
         //customPlot->rescaleAxes();
        for(int ee=1;ee!=300 ;ee++)
        {//  ckey[0]=0;
        ckey [ee]=ee;
        }*/
        customPlot->replot();//}
        customPlot->xAxis->setRange(ckey[0],ckey[300]);
        customPlot->yAxis2->setVisible(true);
        customPlot->yAxis->setVisible(false);
        customPlot->yAxis->setRange(min,max);
        /*  customPlot->xAxis->setBasePen(QPen(cursor22));
        customPlot->yAxis2->setBasePen(QPen(cursor22));
        customPlot->xAxis->setSubTickPen(QPen(cursor22));
        customPlot->yAxis2->setSubTickPen(QPen(cursor22));*/
        customPlot->yAxis2->setRange(min,max);
        /*QLinearGradient axisRectGradient;
        axisRectGradient.setStart(0, 0);
        axisRectGradient.setFinalStop(0, 300);
        customPlot->axisRect()->setBackground(axisRectGradient);*/
        /* customPlot->xAxis->setBasePen(QPen(cursor22));
        customPlot->yAxis2->setBasePen(QPen(cursor22));
        customPlot->xAxis->setTickPen(QPen(cursor22));
        customPlot->yAxis2->setTickPen(QPen(cursor22));
        customPlot->xAxis->setSubTickPen(QPen(cursor22));
        customPlot->yAxis2->setSubTickPen(QPen(cursor22));
        customPlot->xAxis->setTickLabelColor(cursor22);
        customPlot->yAxis2->setTickLabelColor(cursor22);*/
        customPlot->xAxis->setRange(270,300);
        customPlot->replot();

        av=(max+min)/2.2; m=(max-min)/610;
        for(int i = 0; i < limitint; i++){
        if(arr[i][3]>arr[i][2]){
        rectangle=scene->addRect(i*dist,-1*(arr[i][2]-av)/m,6, (arr[i][2]-arr[i][3])/m,outlinePen,greenBrush);
        line=scene->addLine(i*dist+3,-1*(arr[i][0]-av)/m,i*dist+3,-1*(arr[i][1]-av)/m,outlinePen);
        }
        else{rectangle=scene->addRect(i*dist,-1*(arr[i][3]-av)/m,6,( arr[i][3]-arr[i][2])/m,outlinePen,redBrush);
        line=scene->addLine(i*dist+3,-1*(arr[i][0]-av)/m,i*dist+3,-1*(arr[i][1]-av)/m,outlinePen);}}
        k=0;
        for (int i = limitint-2; i >= 0; i--){
        if ((arr[i][0] - arr[limitint-1][0]) < S && (arr[i][0] - arr[limitint-1][1]) > -S){
        w=0;
        for (int j = limitint-2; j >= 0; j--){
        if (!((arr[i][0] - arr[j][1]) > c || (arr[i][0] - arr[j][1]) < -c)&&arr[j][6]!=1){
        w=j;
        arr[j][6]=1;//break;
        }
        }
        if(w>0){
        sd= QString::number(arr[i][1]);
        www= sd.length();
        /*if(arr[i-1][1]==0)
        break;
        if(arr[i][1]==arr[i-1][1])
        {if( www==6)
        {
        ui->textBrowser->append("Найден уровень на    "  + sd+"0"+"(100highlow)");//min
        }
        else if(www==5)
        ui->textBrowser->append("Найден уровень на    "  + sd+"00"+"(100highlow)");//min
        else if(www==4)
        ui->textBrowser->append("Найден уровень на    "  + sd+"000"+"(100highlow)");//min
        else
        ui->textBrowser->append("Найден уровень на    "  + sd+"(100highlow)");//min
        }*/
        //  else
       /* if( www==6)
        {
        ui->textBrowser->append("Найден уровень на    "  + sd+"0");//min
        }
        else if(www==5)
        ui->textBrowser->append("Найден уровень на    "  + sd+"00");//min
        else if(www==4)
        ui->textBrowser->append("Найден уровень на    "  + sd+"000");//min
        else if (www==3)
        ui->textBrowser->append("Найден уровень на    "  + sd+".000");//min
        else if (www==2)
        ui->textBrowser->append("Найден уровень на    "  + sd+"0.000");//min
        else*/
        ui->textBrowser->append("Найден уровень на    "  + sd);//min
        // ui->textBrowser->append("Найден уровень на   "      + sd +"                                               " +QString::number( www));//nimmax
        // line=scene->addLine(0,-1*(arr[i][0]-av)/m,limitint*10,-1*(arr[i][0]-av)/m,minPen);lvl1[k][0]=arr[i][0];k++;
        QCPItemLine *arrow = new QCPItemLine(customPlot);
        //arrow->setPen(Pen);
        arrow->end->setCoords(-2000,arr[i][1]);
        arrow->start->setCoords(2000,arr[i][1]); // point to (4, 1.6) in x-y-plot coordinates
        customPlot->replot();
        //arrow->set
        //arrow->setHead(QCPLineEnding::esSpikeArrow);    //customPlot->replot();
        }}}
        k=0;
        for (int i = limitint-2; i >= 0; i--){
        if ((arr[i][0] - arr[limitint-1][0]) < S && (arr[i][0] - arr[limitint-1][0]) > -S && arr[i][4]==0){
        w=0;
        for (int j = i-1; j >= 0; j--){
        if (!((arr[i][0] - arr[j][0]) > c || (arr[i][0] - arr[j][0]) < -c)){
        arr[j][4]=1;
        w=j;
        }
        }
        if(w>0){lvl2[k][1]=arr[i][0];k++;
        sd2= QString::number(arr[i][0]);
        eee= sd2.length();
        /* if(arr[i][0]==arr[i-1][0])
        { if(eee==6)
        {
        ui->textBrowser->append("Найден уровень на    "  + sd2+"0"+"(100low)");//min
        }
        else if(eee==5)
        ui->textBrowser->append("Найден уровень на    "  + sd2+"00"+"(100low)");//min
        else if(eee==4)
        ui->textBrowser->append("Найден уровень на    "  + sd2+"000"+"(100low)");//minё
        else
        ui->textBrowser->append("Найден уровень на    "  + sd2);//min
        }*/
        //else
       /* if(eee==6)
        {
        ui->textBrowser->append("Найден уровень на    "  + sd2+"0");//min
        }
        else if(eee==5)
        ui->textBrowser->append("Найден уровень на    "  + sd2+"00");//min
        else if(eee==4)
        ui->textBrowser->append("Найден уровень на    "  + sd2+"000");//min
        else if (eee==3)
        ui->textBrowser->append("Найден уровень на    "  + sd2+".000");//min
        else if (eee==2)
        ui->textBrowser->append("Найден уровень на    "  + sd2+"0.000");//min
        else*/
        ui->textBrowser->append("Найден уровень на    "  + sd2);//min

        //line=scene->addLine(0,-1*(arr[i][0]-av)/m,limitint*10,-1*(arr[i][0]-av)/m,minPen);
        QCPItemLine *arrow = new QCPItemLine(customPlot);
        //arrow->setPen(Pen);
        arrow->end->setCoords(-2000,arr[i][0]);
        arrow->start->setCoords(2000,arr[i][0]); // point to (4, 1.6) in x-y-plot coordinates
        //arrow->setHead(QCPLineEnding::esSpikeArrow);   // customPlot->replot();
        customPlot->replot();
        } } }
        k=0;
        for (int i = limitint-2; i >= 0; i--){          if ((arr[i][1] - arr[limitint-1][1]) < S && (arr[i][1] - arr[limitint-1][1]) > -S && arr[i][5]==0){
        w=0;
        for (int j = i-1; j >= 0; j--){
        if (!((arr[i][1] - arr[j][1]) > c || (arr[i][1] - arr[j][1]) < -c)){
        arr[j][5]=1;
        w=j;
        }
        }
        if(w>0){
        sd3= QString::number(arr[i][1]);
        qqq= sd3.length();
        //ui->textBrowser->setText(QString::number(qqq));
        /*if(arr[i][1]==arr[i-1][1])
        {if( qqq==6)          {
        ui->textBrowser->append("Найден уровень на    "  + sd3+"0"+" (100high)");//min
        }
        else if(qqq==5)
        ui->textBrowser->append("Найден уровень на    "  + sd3+"00"+" (100high)");//min
        else if(qqq==4)
        ui->textBrowser->append("Найден уровень на    "  + sd3+"000"+" (100high)");//min
        else
        ui->textBrowser->append("Найден уровень на    "  + sd3+" (100high)");//min
        }*/
        //else
        /*if( qqq==6)
        {
        ui->textBrowser->append("Найден уровень на    "  + sd3+"0");//min

        }
        else if(qqq==5)
        ui->textBrowser->append("Найден уровень на    "  + sd3+"00");//min
        else if(qqq==4)
        ui->textBrowser->append("Найден уровень на    "  + sd3+"000");//min
        else if (qqq==3)
        ui->textBrowser->append("Найден уровень на    "  + sd3+".000");//min
        else if (qqq==2)
        ui->textBrowser->append("Найден уровень на    "  + sd3+"0.000");//min
        else*/
        ui->textBrowser->append("Найден уровень на    "  + sd3);//min

        QCPItemLine *arrow = new QCPItemLine(customPlot);
        //arrow->setPen(Pen);
        arrow->end->setCoords(-2000,arr[i][1]);
        arrow->start->setCoords(2000,arr[i][1]); // point to (4, 1.6) in x-y-plot coordinates
        //  arrow->setHead(QCPLineEnding::esSpikeArrow);
        //customPlot->replot();
        customPlot->replot();
        //line=scene->addLine(0,-1*(arr[i][1]-av)/m,limitint*10,-1*(arr[i][1]-av)/m,maxPen);
        // lvl3[k][2]=arr[i][1];k++;
        }}}
        if(type==("Candles"))
        {
        QCPFinancial *Candles = new QCPFinancial(customPlot->xAxis, customPlot->yAxis2);
        Candles->setName("Candles");
        Candles->setChartStyle(QCPFinancial::csCandlestick);
        Candles->setData(ckey,copen,chigh,clow,cclose,false);

        QString high=("#64b46c");

        QString low=("#b45a5a" );
        Candles->setTwoColored(true);
        /*

        Candles->setPenPositive(QPen(QColor(okntt)));
        Candles->setPenNegative(QPen(QColor(oknttt)));*/
        Candles->setBrushPositive(QColor(high));
        Candles->setBrushNegative(QColor(low));
        Candles->setPenPositive(QPen(QColor(Qt::black)));
        Candles->setPenNegative(QPen(QColor(Qt::black)));
        customPlot->replot();
        }

        else if(type==("Bars")){
        QCPFinancial *Bars = new QCPFinancial(customPlot->xAxis, customPlot->yAxis2);
        Bars->setName("Bars");
        Bars->setChartStyle(QCPFinancial::csOhlc);
        Bars->setData(ckey,copen,chigh,clow,cclose,false);
        // Bars->setTwoColored(true);
       /* Bars->setBrushPositive(QColor(highh));
        Bars->setBrushNegative(QColor(loww));*/
        customPlot->replot();
        }
        else if(type==("Line")){
        QVector<double> yData, xData;
        for (int i = 0; i < 300; i++){
        xData.push_back(ckey[i]);
        yData.push_back(arr[i][3]);
        }
        // customPlot->graph(0)->setPen(Pen);
        customPlot->addGraph();
        customPlot->graph(0)->setData(xData, yData);
        }
        ui->textBrowser->append("                                             ");
        QString boolValue = QSslSocket::sslLibraryBuildVersionString();
        const QVariant varValue(boolValue);
        const QString strValue(varValue.toString());
        ui->textBrowser->append(strValue   );
       // QString f=arrayvalue2.toString();
        //ui->textBrowser->append(QString::number(s));
        //ui->textBrowser->append(f);
        /*ui->textBrowser->append(fonn);
        ui->textBrowser->append(highh);
        ui->textBrowser->append(loww);
        ui->textBrowser->append(cursor22);*/
        }
        //}//

        void MainWindow::on_MainWindow_iconSizeChanged(const QSize &iconSize)
        {}
