/**
 *  Javascript file for index.html functions
 */




var lineChartData = [
    // First series
    {
        label: "Temperature",
        values: [
            {time: 1370044800, y: 100},
            {time: 1370044801, y: 90},
            {time: 1370044802, y: 10},
            {time: 1370044803, y: 75},
            {time: 1370044804, y: 80},
            {time: 1370044805, y: 40}
            ]
    }
];

var lineChart = $('#lineChart').epoch({
        type: 'time.line',
        data: lineChartData
});