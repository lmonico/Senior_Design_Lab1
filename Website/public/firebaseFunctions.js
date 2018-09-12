/* Functions for interacting with Firebase */


/* Firebase Initialization */

var config = {
    apiKey: "AIzaSyCUt1rpCq1dix9CMZmKL0hJB0un6jU0hmc",
    authDomain: "senior-design-lab-1.firebaseapp.com",
    databaseURL: "https://senior-design-lab-1.firebaseio.com",
    projectId: "senior-design-lab-1",
    storageBucket: "senior-design-lab-1.appspot.com",
    messagingSenderId: "841086660846"
};

firebase.initializeApp(config);

var database = firebase.database().ref();

console.log("Firebase initialized");

database.once("value")
    .then(function(snapshot){
        snapshot.forEach(function(tempSnapshot){
            tempSnapshot.forEach(function(dataSnapshot) {
                var currentTemp = dataSnapshot.val();
                console.log(currentTemp);
                lineChart.push([{time: Math.round((new Date()).getTime() / 1000), y: currentTemp}]);
            })
        })

    });