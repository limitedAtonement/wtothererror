#include "webcontainer.hpp"
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WLink.h>
#include <Wt/WDate.h>
#include <Wt/WBreak.h>
#include <Wt/Chart/WAbstractChartModel.h>
#include <Wt/Chart/WCartesianChart.h>

struct my_model : public Wt::Chart::WAbstractChartModel
{
    double data(int row, int column) const
    {
        if (!column)
        {
            Wt::WDate d {2017,1,1};
            d = d.addDays(row*row);
            return (double)d.toJulianDay();
        }
        return row*15;
    }
    int columnCount() const
    {
        return 2;
    }
    int rowCount() const
    {
        return 15;
    }
};

web_container::web_container()
{
    auto chart{std::make_unique<Wt::Chart::WCartesianChart>(Wt::Chart::ChartType::Scatter)};
    chart->setModel(std::make_shared<my_model>());
    chart->setXSeriesColumn(0);
    chart->addSeries(std::make_unique<Wt::Chart::WDataSeries>(1, Wt::Chart::SeriesType::Point));
    chart->axis(Wt::Chart::Axis::X).setScale(Wt::Chart::AxisScale::Date);
    chart->resize(500,250);
    chart->setAutoLayoutEnabled(true);
    chart->setType(Wt::Chart::ChartType::Scatter);
    this->addWidget(std::move(chart));
}
