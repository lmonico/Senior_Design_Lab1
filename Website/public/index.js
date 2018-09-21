/**
 *  Javascript file for index.html functions
 */
var rightRange = [10, 50];

var lineChartData = [
    // First series
    {
        label: "Temperature",
        values: [
            {time: 1370044800, y: 10},
            {time: 1370044801, y: 20},
            {time: 1370044802, y: 10},
            {time: 1370044803, y: 40},
            {time: 1370044804, y: 25},
            {time: 1370044805, y: 50}
          ],
            range: rightRange
    }

];

var lineChart = $('#lineChart').epoch({
        range: rightRange,
        type: 'time.line',
        data: lineChartData,
        axes: ['bottom', 'right']
});

$('#power').change(function(){
  if ($(this).is(':checked')) {
    firebase.database().ref().set({
      Power: 1,
    });
  }
  else
  {
    window.alert('Power is off')
    firebase.database().ref().set({
      Power: 0,
    });
  }
});

//window.alert("HI");
