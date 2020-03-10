//Ejecutamos la función cuando el programa esté cargado.

window.addEventListener('load', function(){
  
  
    var b_login = this.document.getElementById("login");
    var i_pass = document.getElementById("pass");
    //Solo comprobará las credenciales cuando se haga click en login.
    i_pass.addEventListener('keydown',function(event){
      if(event.keyCode === 13){
        b_login.click();
      }
    });

    //

    b_login.addEventListener('click', function(){
        console.log("click");
      leeJson()
    });

  });
  
  
  // Funcion para leer el JSON.
  
  function leeJson(){
  
    //Hacemos un fetch, utilizando la direccion del archivo como direccion para la petición.
  
    fetch("js/temp.json")
  
        //Si hay una respuesta, la convertimos a json.
       .then(response => response.json()
  
        //Luego, cogemos el json y lo metemos como parametro en la función de comprobación.
       .then(function (data){
  
        //Si los campos no estan vacios entonces...
        if(!isEmpty()){
  
  
          //Recorremos el json
         for (var i = 0; i< data.length; i++){
           //console.log(data[i].user);
  
           // Si cada par coincide en usuario y contraseña, daremos la clase nueva al contenedor 
           // para que este desparezca.
           if (data[i].user == leeUser() && data[i].password == leePass()){
              document.getElementById("loginloader").classList.add("dimissloader");
            }
          }
        }
          
     })
  );
  
  }
  
  
  // Función que devuelve el valor del input user.
  function leeUser(){
    var user = "";
    var element = document.getElementById("user");
    if (element.value != "" && element.value != null){
      user = element.value;
    }
    return user.toLowerCase();
  }
  
  
  // Función que devuelve el valor del input password.
  function leePass(){
    var pass = "";
    var element = document.getElementById("pass");
    if (element.value != "" && element.value != null){
      pass = element.value;
    }
  
    return pass;
  }
  
  
  // Función que comprueba si los inputs vacios.
  function isEmpty(){
  
    return leeUser() == "" && leePass() == "";
  }