
 //(Your web app's Firebase configuration
 // Recordar cambiar rules y establecer read y write en true

 // Copiarse todo el json de firebase aqui

 // Ejemplo
 const firebaseConfig = {
  apiKey: "", // copiar y pegar api key de firebase
  authDomain: "appiot-e3566.firebaseapp.com",
  databaseURL: "", // copiar y pegar url de api
  projectId: "appiot-e3566",
  storageBucket: "appiot-e3566.appspot.com",
  messagingSenderId: "482165357259",
  appId: "1:482165357259:web:abbf4b0b3d57f16fa7b94e",
  measurementId: "G-23TQJHQND7"
};


  firebase.initializeApp(firebaseConfig);
  firebase.analytics();

  console.log("Firebase: ",firebase);

  var ref = firebase.database().ref('/');

  console.log('Ref: ',ref);

  ref.on("value", function(snapshot){
    var data = snapshot.val();

    console.log('Data: ',data);

    if (data.Humedad == "No"){
      document.getElementById("humidity").innerHTML = "No hay humedad";
    }else{
      document.getElementById("humidity").innerHTML = "Hay humedad";
    }
    if (data.Gas == "No"){
      document.getElementById("gas").innerHTML = "No hay gas";
    }else{
      document.getElementById("gas").innerHTML = "Hay gas";
    }
    if (data.Luz == "No"){
      document.getElementById("light").innerHTML = "No hay luz";
    }else{
      document.getElementById("light").innerHTML = "Hay luz";
    }
  });

  $(function() {
    $('#led').change(function() {
      var sw = $(this).prop('checked');
      if (sw == false){
        document.getElementById('iconLed').style.color = "#2962FF";
        document.getElementById('iconLed').style.transition = "0.5s";
        firebase.database().ref('/').child('wLed').set("1");
      }else{
        document.getElementById('iconLed').style.color = "#9E9E9E";
        firebase.database().ref('/').child('wLed').set('0');
      }
    })
  })
  