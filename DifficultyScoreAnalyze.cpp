#include "DifficultyScoreAnalyze.h"

DifficultyScoreAnalyze::DifficultyScoreAnalyze(QWidget *parent)
	: QWidget(parent)
{
    DSAui.setupUi(this);
    QLineSeries* lineseries = new QLineSeries();//ͼ������ݼ�
    lineseries->append(0, 5);//append��<<���ܲ��
    *lineseries << QPointF(13, 5) << QPointF(17, 6) << QPointF(20, 2);

    QChart* chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(lineseries);
    chart->createDefaultAxes();
    chart->setTitle("Simple line chart example");

    DSAui.difficultyScoreAnalyze->setChart(chart);
    DSAui.difficultyScoreAnalyze->setRenderHint(QPainter::Antialiasing);
    DSAui.difficultyScoreAnalyze->setVisible(true);
}

DifficultyScoreAnalyze::~DifficultyScoreAnalyze()
{}
